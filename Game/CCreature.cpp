#include "stdafx.h"
#include "CCreature.h"

const std::string& CCreature::getName()
{
    return m_strName;
}

char CCreature::getSymbol()
{
    return m_cSymbol;
}

int CCreature::getHealth()
{
    return m_iHealth;
}

int CCreature::getDamage()
{
    return m_iDamage;
}

int CCreature::getGold()
{
    return m_iGold;
}

void CCreature::reduceHealth(int a_iValue)
{
    m_iHealth -= a_iValue;
}

bool CCreature::isDead()
{
    return (0>=m_iHealth);
}

void CCreature::addGold(int a_iValue)
{
    m_iGold += a_iValue;
}

void CCreature::increaseDamage(int a_iValue)
{
    m_iDamage += a_iValue;
}

int CCreature::getRandomNumber(int a_iMin, int a_iMax)
{
        static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
                                                                                     // evenly distribute the random number across our range
        return static_cast<int>(rand() * fraction * (a_iMax - a_iMin + 1) + a_iMin);
}
