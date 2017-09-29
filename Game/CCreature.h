#pragma once
#include <string>

class CCreature
{
protected:
    std::string m_strName;
    char m_cSymbol;
    int m_iHealth;
    int m_iDamage;
    int m_iGold;

public:
    const std::string& getName();
    char getSymbol();
    int getHealth();
    int getDamage();
    int getGold();

    void reduceHealth(int a_iValue);
    bool isDead();
    void addGold(int a_iValue);
    void increaseDamage(int a_iValue);

    static int getRandomNumber(int a_iMin, int a_iMax);


    CCreature(std::string a_strName, char a_cSymbol, int a_iHealth, int a_iDamage, int a_iGold = 0)
        :m_strName(a_strName), m_cSymbol(a_cSymbol), m_iHealth(a_iHealth), m_iDamage(a_iDamage), m_iGold(a_iGold)
    {}
};