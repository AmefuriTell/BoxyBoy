#include "hpp/Entity.hpp"

Entity::Entity(){}
Entity::Entity(int argsizeX,int argsizeY)
{
    stageInit(argsizeX, argsizeY);
}

void Entity::stageInit(int argsizeX, int argsizeY)
{
    sizeX = argsizeX;
    sizeY = argsizeY;

    stageStatus.resize(sizeY, std::vector<int>(sizeX, 0));
    
}

void Entity::input()
{
    std::cerr << "箱の数を入力してください" << std::endl;
    std::cin >> boxNum;
    std::cerr << "箱の座標を入力してください" << std::endl;
    for(int i = 0; i < boxNum; i++)
    {
        int inX, inY;
        std::cin >> inX >> inY;

        stageStatus[inY][inX] = 1;
    }
    std::cerr << "Playerの座標を入力してください" << std::endl;
    std::cin >> player.first >> player.second;
    stageStatus[player.second][player.first] = 2;
}

void Entity::print()
{
    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
        {
            std::cout << stageStatus[i][j];
        }
        std::cout << std::endl;
    }
    
}