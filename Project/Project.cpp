#include <iostream>
#include <random>
#include <windows.h>

#include "Console.h"
#include "GameManager.h"
#include "Design.h"

int main()
{
    srand(time(0));

    Console console;
    console.ConsoleSize();

    GameManager gamemanager;
    gamemanager.Play();
    
}