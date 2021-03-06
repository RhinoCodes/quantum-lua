#ifndef QUAMTUM_libs_Package_Package_HPP_
#define QUAMTUM_libs_Package_Package_HPP_

#include <iostream>
#include <string>
#include <vector>

extern "C"
{
#include "../lua535/include/lua.h"
#include "../lua535/include/lauxlib.h"
#include "../lua535/include/lualib.h"
}


void tokenize(std::string const &str, const char delim,
			std::vector<std::string> &out);

struct Package{
    Package(lua_State *L) : L(L) {};

    std::string name;
    std::string version;
    std::string summary;
    std::string description;
    std::string source;
    std::string checksum;
    std::string installDir;
    bool git;
    lua_State *L;

    bool download();
    bool build();
    bool install();
    bool uninstall();
    void clear();
};

#endif // QUAMTUM_libs_Package_Package_HPP_
