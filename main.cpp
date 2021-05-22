#include <iostream>

extern "C"
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

int main()
{
  lua_State* state = luaL_newstate();
  luaL_openlibs(state);
  luaL_dostring(state, "print('fuck')");
  return 0;
}
