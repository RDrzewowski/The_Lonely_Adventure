#include "stdafx.h"
#include "CMonster.h"

CMonster::MonsterDataS CMonster::m_tmonsterData[NUMBER_OF_TYPES]
{
    {"dragon", 'D', 20, 4, 100},
    {"orc", 'o', 4, 2, 25},
    {"slime", 's', 1, 1, 10}
};

CMonster* CMonster::getRandomMonster()
{
    return new CMonster(static_cast<TypeE>(CCreature::getRandomNumber(0, NUMBER_OF_TYPES-1)));
}