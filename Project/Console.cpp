#include "Console.h"

#include <windows.h>
#include <iostream>

void Console::ConsoleSize()
{
	system("mode con:cols=40 lines=41");
}
