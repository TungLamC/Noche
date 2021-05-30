#ifndef NOCHE_MOONFALL_HPP
#define NOCHE_MOONFALL_HPP

extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
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
  int push() const noexcept {
    
  }
  
 

private:
  lua_State* state = nullptr;

  int index = 0;
};

}

#endif //NOCHE_MOONFALL_HPP
