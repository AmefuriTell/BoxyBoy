#include "hpp/Stage.hpp"

Stage::Stage(){}

void Stage::input()
{
    std::cin >> sizeX >> sizeY;
    map.resize(sizeY);
    for (auto in : map)std::cin >> in;

    std::cin >> boxNum;
    for(auto in : goal)std::cin >> in.first >> in.second;
}