#include <iostream>
#include <random>

#include "GameManager.h"
#include "Player.h"
#include "Enemy.h"

#include "Champion.h"

int main()
{
    srand(time(0));

    GameManager gamemanager;
    gamemanager.Play();
    
}