#ifndef NOCHE_MOONFALL_HPP
#define NOCHE_MOONFALL_HPP

#include <debug/log.h>

extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

#include <type_traits>
#include <functional>

namespace moonfall {
enum class lua_type: int {
  none          = LUA_TNONE,
  nil           = LUA_TNIL,
  string        = LUA_TSTRING,
  number        = LUA_TNUMBER,
  thread        = LUA_TTHREAD,
  boolean       = LUA_TBOOLEAN,
  function      = LUA_TFUNCTION,
  userdata      = LUA_TUSERDATA,
  lightuserdata = LUA_TLIGHTUSERDATA,
  table         = LUA_TTABLE,
  poly          = -0xFFFF
};

enum class lua_kind: int {
  none          = LUA_TNONE,
  nil           = LUA_TNIL,
  string        = LUA_TSTRING,
  number        = LUA_TNUMBER,
  thread        = LUA_TTHREAD,
  boolean       = LUA_TBOOLEAN,
  function      = LUA_TFUNCTION,
  userdata      = LUA_TUSERDATA,
  lightuserdata = LUA_TLIGHTUSERDATA,
  table         = LUA_TTABLE,
  poly          = -0xFFFF 
};

inline lua_type lua_type_at(lua_State* state, int index = -1) {
  return static_cast<moonfall::lua_type>(::lua_type(state, index));
}
}

namespace moonfall::traits {
template<typename T>
using unqualified_t = std::remove_cv_t<std::remove_reference_t<T>>;
}

namespace moonfall::stack {

template<typename T, lua_kind expected_kind>
class unqualified_checker {
  using check_fail_callback = std::function<int(lua_State*, int, lua_kind, lua_kind, const char*)>;

  static bool check(lua_State* state, int index, check_fail_callback&& fail_callback) {
  }
};

template<typename T>
struct unqualified_pusher;

template<typename T, typename... Args>
int push(lua_State* state, T&& t, Args&& ... args) {
  using UNQUALIFIED_T = traits::unqualified_t<T>;
  return unqualified_pusher<UNQUALIFIED_T>::push(state, std::forward<T>(t), std::forward<Args>(args)...);
}

}

namespace moonfall {

inline bool xmovable(lua_State* left, lua_State* right) {
  if (left == nullptr || right == nullptr || left == right)
    return false;
  else
    return lua_topointer(left, LUA_REGISTRYINDEX) == lua_topointer(right, LUA_REGISTRYINDEX);
}

struct raw_index {
  raw_index(int index) noexcept: index(index) {}
  operator int() const { return index; }
  int index;
};

struct absolute_index {
  absolute_index(lua_State* state, int index) noexcept: index(lua_absindex(state, index)) {}
  operator int() const { return index; }
  int index;
};

class stack_reference {
public:
  stack_reference() noexcept = default;
  stack_reference(lua_State* state, int index) noexcept: state(state), index(lua_absindex(state, index)) {}
  stack_reference(lua_State* state, raw_index index) noexcept: state(state), index(index) {}
  stack_reference(lua_State* state, absolute_index index) noexcept: state(state), index(index) {}

  stack_reference(const stack_reference& other) noexcept = default;
  stack_reference& operator=(const stack_reference& other) noexcept = default;
  stack_reference(stack_reference&& other) noexcept = default;
  stack_reference& operator=(stack_reference&& other) noexcept = default;

public:
  int push(lua_State* state = nullptr) const noexcept {
    state == nullptr ? this->state : state;
    lua_pushvalue(state, index);
    return 1;
  }

public:
  lua_type lua_type() const noexcept {
    return lua_type_at(state, index);
  }

  lua_State* lua_state() const noexcept {
    return state;
  }

  int stack_index() const noexcept {
    return index;
  }

  bool is_valid() const noexcept {
    return lua_type() != lua_type::nil && lua_type() != lua_type::none;
  }

  const void* pointer() const noexcept {
    return lua_topointer(state, index);
  }

public:


private:
  lua_State* state = nullptr;

  int index = 0;
};

inline bool operator==(const stack_reference& lhs, const stack_reference& rhs) {
  return lua_compare(lhs.lua_state(), lhs.stack_index(), rhs.stack_index(), LUA_OPEQ) == 1;
}

inline bool operator!=(const stack_reference& lhs, const stack_reference& rhs) {
  return !operator==(lhs, rhs);
}

template<bool only_main_thread = false>
class registry_reference {
public:

private:
  lua_State* state = nullptr;

  int index = LUA_NOREF;
};
}

#endif //NOCHE_MOONFALL_HPP
