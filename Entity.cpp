#include "hpp/Entity.hpp"

Entity::Entity(){}

void Entity::input()
{
    std::cerr << "箱の数を入力してください" << std::endl;
    std::cin >> boxNum;
    box.resize(boxNum);
    std::cerr << "箱の座標を入力してください" << std::endl;
    for(auto &in : box)std::cin >> in.first >> in.second;
    std::cerr << "Playerの座標を入力してください" << std::endl;
    std::cin >> player.first >> player.second;
}