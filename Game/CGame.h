#pragma once
#include <iostream>
#include <conio.h>
#include "CPlayer.h"
#include "CMonster.h"

class CGame
{
private:
    CPlayer* m_opPlayer;
    CMonster* m_opMonster;
    int m_iFinishingLevel;

public:
    CGame(CPlayer* a_opPlayer, int a_iFinishingLevel = 20)
        :m_opPlayer(a_opPlayer), m_iFinishingLevel(a_iFinishingLevel)
    {}

    ~CGame();

    void mainLoop();
    void playTheGame();

    void fightAMonster();
    void makeAChoice();
    void playerHasDied();
    void playerHasWon();
    void monsterBeaten();
    void createNewMonster();
};