#include <iostream>
#include <random>

#include "Player.h"
#include "Enemy.h"

int main()
{
   // srand(time(0));

    Player player;
    //player.PlayerArray();

    Enemy enemy;
    enemy.Throw(20);
    enemy.EnemyArray();

    
    //RPG를 가장한 야구게임
    /*
    플레이어와 상대의 스트라이크존 존재
    상대는 공을 던지고 플레이어는 공을 치는 시스템

    진루 시스템 - 궁극기를 위한 스텍 개념
    */ 
}