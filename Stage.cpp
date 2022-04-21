#include "hpp/Stage.hpp"

Stage::Stage(){}

void Stage::input()
{
    std::cerr << "マップの大きさはなんですか？x yの順で入力してください" << std::endl;
    std::cin >> sizeX >> sizeY;
    map.resize(sizeY);
    std::cerr << "mapチップを入力してください" << std::endl;
    for (auto in : map)std::cin >> in;

    std::cerr << "箱の数を入力してください" << std::endl;
    std::cin >> boxNum;
    std::cerr << "ゴールの座標を入力してください" << std::endl;
    for(auto in : goal)std::cin >> in.first >> in.second;
}