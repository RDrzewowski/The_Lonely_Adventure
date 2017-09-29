#include "stdafx.h"
#include "CPlayer.h"

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
                                                                                 // evenly distribute the random number across our range
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int CPlayer::getLevel()
{
    return m_iLevel;
}

void CPlayer::levelUp()
{
    m_iLevel++;
    m_iDamage++;
    m_iHealth += 2;
    std::cout << "You have leveled up!\nYou are now level " << m_iLevel << " and deal " << m_iDamage << " damage.\n"
        << "You have " << m_iHealth << "HP left.\n\n";
}

bool CPlayer::hasWon(int a_iFinishingLevel)
{
    return a_iFinishingLevel<=m_iLevel;
}

bool CPlayer::run()
{
    return getRandomNumber(0, 1);;
}

void CPlayer::fight(CMonster *a_opMonster)
{
    a_opMonster->reduceHealth(m_iDamage);
    std::cout << "\nYou hit " << a_opMonster->getName() << " for " << m_iDamage << " damage.\n";

    if (!a_opMonster->isDead())
    {
        receiveDamage(a_opMonster);
    }
}

void CPlayer::receiveDamage(CMonster * a_opMonster)
{
    int _iDamage = a_opMonster->getDamage();
    m_iHealth -= _iDamage;
    std::cout << "The " << a_opMonster->getName() << " hit you for " << _iDamage << " damage.\n\n";
}

void CPlayer::loot(int a_iValue)
{
    m_iGold += a_iValue;
}
