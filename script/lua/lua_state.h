#ifndef NOCHE_LUA_STATE_H
#define NOCHE_LUA_STATE_H

#include <sol/sol.hpp>

namespace noche
{
class lua_state: public sol::state
{
};

static lua_state lua_state;
}


#endif //NOCHE_LUA_STATE_H
