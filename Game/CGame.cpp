#include "stdafx.h"
#include "CGame.h"

CGame::~CGame()
{
    delete m_opPlayer;
    delete m_opMonster;
}

void CGame::mainLoop()
{
    createNewMonster();

    while (true)
    {
        makeAChoice();

        if (m_opPlayer->isDead())
        {
            playerHasDied();
            break;
        }
        if (m_opMonster->isDead())
        {
            monsterBeaten();

            if (m_opPlayer->hasWon(m_iFinishingLevel))
            {
                playerHasWon();
                break;
            }
            else
            {
                createNewMonster();
            }
        }
        //if none of the above then keep fighting          
    }
}

void CGame::playTheGame()
{
    std::cout << "\t\t\tINSTRUCTION\n\n"
        << "- You start at level 1 with 20HP.\n"
        << "- You encounter various monsters(now 3 xD)\n"
        << "- With every monster you can choose to fight him or to flee.\n"
        << "  BUT!! you only have 50% chance to run and if you fail, the monster will have a free hit on you so BE CAREFUL!\n"
        << "- You lvl up every time you beat monster up and then your damage increases and you regain 2HP\n"
        << "-The goal is to get to lvl "<< m_iFinishingLevel <<" without dying and acquire as much gold as you can. Sounds easy, eh?\n\n"
        << "So I hope you're ready. Let's begin...\n\n";

    std::cout << "\t\tTABLE WITH MONSTERS STATS\n\n"
        << " -----------------------------\n"
        << "| TYPE   |HEALTH|DAMAGE| GOLD |\n"
        << "|--------|------|------|------|\n"
        << "| DRAGON |  20  |  4   | 100  |\n"
        << "|--------|--------------------|\n"
        << "| ORC    |  4   |  2   |  25  |\n"
        << "|-----------------------------|\n"
        << "| SLIME  |  1   |  1   |  10  |\n"
        << " -----------------------------\n"
        <<"\n\n\n\n"
        <<"\t\tDO MYCIA - THE GAME\n\n";
    mainLoop();
}

void CGame::makeAChoice()
{
    std::cout << "(R)un or (F)ight: ";

    while (true)
    {
        char _cChoice = _getch();

        if ('r' == _cChoice)
        {
            if(m_opPlayer->run())
            {
                std::cout << "\nYou have escaped!\n\n";
                createNewMonster();
            }
            else
            {
                std::cout << "\nYou have failed to escape, " << m_opPlayer->getName() << " :(\n\n";
                m_opPlayer->receiveDamage(m_opMonster);
            }
            break;
        }
        else if ('f' == _cChoice)
        {
            m_opPlayer->fight(m_opMonster);
            break;
        }
        else
        {
            std::cout << "\nYou have entered the wrong character. Please try again...\n";
        }
    }

}

void CGame::playerHasDied()
{
    std::cout << "YOU DIED!\nGame over. You, " << m_opPlayer->getName()
        << ", have fought bravely, but failed.\nYou have died at LVL "
        << m_opPlayer->getLevel() << std::endl
        << "and had " << m_opPlayer->getGold() << " gold.\n";
}

void CGame::playerHasWon()
{
    std::cout << "\n\nCongratulations!!! You have managed to become a GOD at lvl " << m_iFinishingLevel << "\nYou had " << m_opPlayer->getHealth() << " hp left and acquired " << m_opPlayer->getGold() << " gold.\n";
}

void CGame::monsterBeaten()
{
    std::cout << "You have killed the " << m_opMonster->getName() << ".\n";
    m_opPlayer->loot(m_opMonster->getGold());
    m_opPlayer->levelUp();
}

void CGame::createNewMonster()
{
    m_opMonster = CMonster::getRandomMonster();
    std::cout << "You have encountered a(n) " << m_opMonster->getName() << " (" << m_opMonster->getSymbol() << ").\n";
}
