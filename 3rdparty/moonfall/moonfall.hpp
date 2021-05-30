#ifndef NOCHE_MOONFALL_HPP
#define NOCHE_MOONFALL_HPP

extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

namespace moonfall {
enum class lua_type: int {
  none          = LUA_TNONE,
  lua_nil       = LUA_TNIL,
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
    return static_cast<moonfall::lua_type>(::lua_type(state, index));
  }
  
  lua_State* lua_state() const noexcept {
    return state;
  }
  
  int stack_index() const noexcept {
    return index;
  }
  
  bool is_valid() const noexcept {
    return lua_type() != lua_type::lua_nil && lua_type() != lua_type::none;
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
}

#endif //NOCHE_MOONFALL_HPP
