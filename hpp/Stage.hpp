#ifndef STAGE_H
#define STAGE_H
#include <bits/stdc++.h>

class Stage
{
public:
    Stage();
    void input();

    int sizeX, sizeY, boxNum;
    std::vector<std::string> map;
    std::vector<std::pair<int, int>> goal;
};

#endif