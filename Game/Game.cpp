// The_Lonely_Adventure
//

#include "stdafx.h"
#include "CCreature.h"
#include "CGame.h"
#include <iostream>
#include <ctime>

CPlayer* createPlayer();
void startTheGame();

int main()
{
    srand(static_cast<unsigned int>(time(NULL)));
    rand(); // getting rid of first result because of Visual Studio

    CPlayer *opAvatar;
    CGame *opGame;

    std::cout << "Welcome. Wanna play a game?\n"
        << "(Y)es\n(N)o\n";
    startTheGame();
    opAvatar = createPlayer();
    opGame = new CGame(opAvatar);

    while (true)
    {

        opGame->playTheGame();
        delete opGame;
        opAvatar = nullptr;

        std::cout << "Do you want to play again?\n"
            << "(Y)es\n(N)o\n";
        startTheGame();
        opAvatar = createPlayer();
        opGame = new CGame(opAvatar, 20);
    }

    return 0;
}

CPlayer* createPlayer()
{
    std::cout << "Enter your name: ";
    std::string strName;
    std::getline(std::cin, strName);
    
    return new CPlayer(strName);
}

void startTheGame()
{
    while (true)
    {
        char _cChoice = _getch();
        if ('n' == _cChoice)
        {
            std::cout << "Okay then. See you later!\n";
            exit(0);
        }
        else if ('y' != _cChoice)
        {
            std::cout << "\nYou have entered the wrong character! Please try again...\n";
        }
        else
        {
            system("cls");
            break;
        }
    }
}
