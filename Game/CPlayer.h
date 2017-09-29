#pragma once
#include "CCreature.h"
#include "CMonster.h"
#include <iostream>

class CPlayer : public CCreature
{
private:
    int m_iLevel = 1;

public:
    CPlayer(std::string a_strName)
        :CCreature(a_strName, '@', 20, 1)
    {}

    int getLevel();
    void levelUp();
    bool hasWon(int a_iFinishingLevel);
    bool run();
    void fight(CMonster *a_opMonster);
    void receiveDamage(CMonster *a_opMonster);
    void loot(int a_iValue);

};
