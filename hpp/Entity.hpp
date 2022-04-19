
#ifndef ENTITY_H
#define ENTITY_H
#include <bits/stdc++.h>

class Entity
{
public:
    Entity();
    void input();

    int boxNum;
    std::vector<std::pair<int, int>> box;
    std::pair<int, int> player;
};

#endif