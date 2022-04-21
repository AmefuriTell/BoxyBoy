
#ifndef ENTITY_H
#define ENTITY_H
#include <bits/stdc++.h>

class Entity
{
public:
    Entity();
    Entity(int, int);
    void stageInit(int, int);
    void input();
    void print();

    int boxNum;
    int sizeX, sizeY;
    std::pair<int, int> player;
    std::vector<std::vector<int>> stageStatus;
};

#endif