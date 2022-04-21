#include "hpp/BoxyBoy.hpp"

BoxyBoy::BoxyBoy()
{
    init();
}

void BoxyBoy::init()
{
    stage = Stage();
    stage.input();

    Entity e = Entity(stage.sizeX, stage.sizeY);
    entity = e;
    entity.input();
    
    ans = "";
}

void BoxyBoy::solve()
{
    std::queue<std::pair<Entity, std::string>> que;
    std::set<std::vector<std::vector<int>>> seen;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int dc[] = {'S', 'D', 'W', 'A'};

    que.push({entity, ans});
    while (!que.empty())
    {
        std::pair<Entity, std::string> now = que.front();
        que.pop();
        entity = now.first;
        ans = now.second;

        std::cout << "これを探索" << std::endl;
        std::cout << ans << std::endl;
        entity.print();
        if(seen.count(entity.stageStatus))continue;

        //終了条件:すべてのgoalが埋まっている。
        bool is_end = true;
        for (int i = 0; i < stage.boxNum; i++)
        {
            if(entity.stageStatus[stage.goal[i].second][stage.goal[i].first] != 1)is_end = false;
        }
        if(is_end)break;
        
        seen.insert(entity.stageStatus);

        //queに入れにかかる
        for (int i = 0; i < 4; i++)
        {
            Entity buf = entity;
            std::string bufans = ans;
            int nextPlayerX = entity.player.first + dx[i];
            int nextPlayerY = entity.player.second + dy[i];

            if(nextPlayerX < 0 || nextPlayerX >= stage.sizeX)continue;
            if(nextPlayerY < 0 || nextPlayerY >= stage.sizeY)continue;

            std::cout << stage.map[nextPlayerY][nextPlayerX] << std::endl;
            if(stage.map[nextPlayerY][nextPlayerX] == '#')continue;

            if(buf.stageStatus[nextPlayerY][nextPlayerX] == 1)
            {
                //箱が動かせるかどうかチェックする
                int nextBoxX = nextPlayerX + dx[i];
                int nextBoxY = nextPlayerY + dy[i];

                if(nextBoxX < 0 || nextBoxX >= stage.sizeX)continue;
                if(nextBoxY < 0 || nextBoxY >= stage.sizeY)continue;

                if(stage.map[nextBoxY][nextBoxX] == '#')continue;
                if(buf.stageStatus[nextBoxY][nextBoxX] == 1)continue;

                buf.stageStatus[nextBoxY][nextBoxX] = 1;
                buf.stageStatus[nextPlayerY][nextPlayerX] = 0;
            }

            buf.stageStatus[buf.player.second][buf.player.first] = 0;
            buf.player.first = nextPlayerX;
            buf.player.second = nextPlayerY;
            buf.stageStatus[nextPlayerY][nextPlayerX] = 2;

            bufans += dc[i];

            que.push({buf, bufans});
        }
        
    }
    
}