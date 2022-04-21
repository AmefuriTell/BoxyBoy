#include "hpp/Entity.hpp"

Entity::Entity(){}

void Entity::input()
{
    std::cin >> boxNum;
    box.resize(boxNum);
    for(auto &in : box)std::cin >> in.first >> in.second;
    std::cin >> player.first >> player.second;
}