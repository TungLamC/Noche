#ifndef NOCHE_MOONFALL_HPP
#define NOCHE_MOONFALL_HPP

extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include <type_traits>

namespace moonfall {
template<typename T>
struct unqualified_pusher;
}

namespace moonfall::traits {
template<typename T>
using unqualified_t = std::remove_cv_t<std::remove_reference_t<T>>;
}

namespace moonfall::stack {
template<typename Object, typename... Args>
int push(lua_State* state, Object&& object, Args&& ... args) {
  using pusher = unqualified_pusher<traits::unqualified_t<Object>>;
  pusher::push(state, std::forward<Object>(object), std::forward<Args>(args)...);
}

template<typename T>
struct unqualified_pusher {
  static int push(lua_State* state) { return 0; }
};

template<>
struct unqualified_pusher<const char*> {
  static int push(lua_State* state, const char* string) {
    lua_pushstring(state, string);
    return 1;
  }
};
}

namespace moonfall {
class registry_reference {
public:
  registry_reference() noexcept = default;

  registry_reference(lua_State* state, const registry_reference& other) noexcept {
    if (state == nullptr || other.index == LUA_REFNIL || other.index == LUA_REFNIL) {
      index = state == nullptr ? LUA_NOREF : other.index;
    }
  }

public:
  int push(lua_State* state) const noexcept {
    lua_rawgeti(state, LUA_REGISTRYINDEX, index);
    return 1;
  }

  int copy(lua_State* state) const noexcept {
    if (index == LUA_NOREF) return LUA_NOREF;
    push(state);
    return luaL_ref(state, LUA_REGISTRYINDEX);
  }

private:
  int index = LUA_NOREF;
};
}

#endif //NOCHE_MOONFALL_HPP
