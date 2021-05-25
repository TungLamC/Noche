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

namespace moonfall::reference {

struct raw_index {
  raw_index(int index): index(index) {}
  operator int() const { return index; }
  int index;
};

struct upvalue_index {
  upvalue_index(int index): index(lua_upvalueindex(index)) {}
  operator int() const { return index; }
  int index;
};

struct absolute_index {
  absolute_index(lua_State* state, int index): index(lua_absindex(state, index)) {}
  operator int() const { return index; }
  int index;
};

inline bool xmovable(lua_State* left, lua_State* right) {
  return left == nullptr || right == nullptr || left == right ?
         false : lua_topointer(left, LUA_REGISTRYINDEX) == lua_topointer(right, LUA_REGISTRYINDEX);
}

class stack_reference {
public:
  stack_reference() noexcept = default;
  stack_reference(raw_index index) noexcept: index(index) {}
  stack_reference(absolute_index index) noexcept: index(index) {}
  stack_reference(lua_State* state, raw_index index) noexcept: state(state), index(index) {}
  stack_reference(lua_State* state, absolute_index index) noexcept: state(state), index(index) {}
  stack_reference(lua_State* state, int index) noexcept: state(state), index(absolute_index(state, index)) {}

  stack_reference(lua_State* state, const stack_reference& other) noexcept: state(state) {
    if (!other.is_valid()) {
      index = 0;
      return;
    }
    if (xmovable(state, other.lua_state())) {
      lua_pushvalue(other.lua_state(), other.stack_index());
      lua_xmove(other.lua_state(), state, 1);
      index = absolute_index(state, -1);
    } else {
      index = other.stack_index();
    }
  }

public:
  int stack_index() const noexcept { return index; }
  lua_State* lua_state() const noexcept { return state; }

  bool is_valid() const noexcept {
    return true;
  }

private:
  lua_State* state = nullptr;

  int index = 0;
};
}

#endif //NOCHE_MOONFALL_HPP
