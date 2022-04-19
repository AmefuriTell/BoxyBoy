#ifndef BOXYBOY_H
#define BOXYBOY_H
#include <bits/stdc++.h>
#include "Stage.hpp"
#include "Entity.hpp"

class BoxyBoy
{
public:
    BoxyBoy();
    void init();

    void solve();
    Stage stage;
    Entity entity;
    std::string ans;
};


#endif