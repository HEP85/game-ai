 extern "C"
{
  #include <lua.h>
  #include <lualib.h>
  #include <lauxlib.h>
}

//include the lua libraries. If your compiler doesn't support this pragma
//then don't forget to add the libraries in your project settings!
//#pragma comment(lib, "lua.lib")
//#pragma comment(lib, "lualib.lib")
 #pragma comment(lib, "lua5.1.lib")

#include <iostream>

int main()
{
  //create a lua state
  lua_State* pL = lua_open();

  //enable access to the standard libraries
 /* luaopen_base(pL);
  luaopen_string(pL);
  luaopen_table(pL);
  luaopen_math(pL);
  luaopen_io(pL);*/

  //open the lua libaries - new in lua5.1
  luaL_openlibs(pL);
  
  if (int error = luaL_dofile(pL, "your_first_lua_script.lua") != 0)
  {
    std::cout << "\n[C++]: ERROR(" << error << "): Problem with lua script file!\n\n" << std::endl;

    return 0;
  }

  //tidy up
  lua_close(pL);

  return 0;
}