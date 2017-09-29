#pragma once
#include "CCreature.h"

class CMonster : public CCreature
{
public:

    enum TypeE
    {
        DRAGON,
        ORC,
        SLIME,
        NUMBER_OF_TYPES
    };

    struct MonsterDataS
    {
        std::string strName;
        char cSymbol;
        int iHealth;
        int iDamage;
        int iGold;
    };

    static MonsterDataS m_tmonsterData[NUMBER_OF_TYPES];

    CMonster(TypeE a_oType)
        :CCreature(m_tmonsterData[a_oType].strName, m_tmonsterData[a_oType].cSymbol,
            m_tmonsterData[a_oType].iHealth, m_tmonsterData[a_oType].iDamage, m_tmonsterData[a_oType].iGold)
    {}

    static CMonster* getRandomMonster();
};