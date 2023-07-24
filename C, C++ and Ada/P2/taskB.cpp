#include <iostream>
#include <string>

class SQUAD_CLASS;

class PLAYER_CLASS
{
public:
    // pola
    std::string identifier;
    unsigned int maxHealth;
    unsigned int remainingHealth;
    unsigned int damage;
    unsigned int agility;
    PLAYER_CLASS *next;
    PLAYER_CLASS *prev;
    PLAYER_CLASS *squad;
    // metody publiczne
    virtual unsigned int getRemainingHealth() = 0;

    virtual unsigned int getDamage() = 0;

    virtual unsigned int getAgility() = 0;

    virtual void takeDamage(unsigned int) = 0;

    virtual void applyWinnerReward() = 0;

    virtual void cure() = 0;

    virtual void printParams() = 0;

    virtual std::string getId() = 0;

private:
    // zaprzyjazniona metoda prywatna
    virtual void die() = 0;

    // klasy zaprzyjaznione
    friend class CAESAR_CLASS;

    friend class SQUAD_CLASS;

    friend class ARENA_CLASS;
};

// klasy dziedziczace po PLAYER_CLASS:
//----------------------------------------
// czlowiek
class HUMAN_CLASS : virtual public PLAYER_CLASS
{
public:
    // metody i skladowe publiczne
    std::string identifier;
    unsigned int defense;

    HUMAN_CLASS()
    {
        identifier = "";
        maxHealth = 200;
        remainingHealth = 200;
        damage = 30;
        agility = 10;
        defense = 10;
        squad = NULL;
        next = NULL;
        prev = NULL;
    }

    HUMAN_CLASS(std::string humanIdentifier)
    {
        identifier = humanIdentifier;
        maxHealth = 200;
        remainingHealth = 200;
        damage = 30;
        agility = 10;
        defense = 10;
        squad = NULL;
        next = NULL;
        prev = NULL;
    }

    void die()
    {
        remainingHealth = 0;
    }

    unsigned int getAgility()
    {
        return agility;
    }

    unsigned int getDamage()
    {
        return damage;
    }
    std::string getId()
    {
        return identifier;
    }
    unsigned int getRemainingHealth()
    {
        return 100 * remainingHealth / maxHealth;
    }

    void applyWinnerReward()
    {
        agility += 2;
        damage += 2;
    }

    void cure()
    {
        remainingHealth = maxHealth;
    }

    void takeDamage(unsigned int damageDealt)
    {
        if (damageDealt < defense + agility)
            return;
        if (damageDealt - (defense + agility) >= remainingHealth)
        {
            die();
            return;
        }
        remainingHealth -= damageDealt - (defense + agility);
    }

    void printParams()
    {
        if (getRemainingHealth() > 0)
        {
            std::cout << identifier << ":" << maxHealth << ":" << remainingHealth << ":"
                      << getRemainingHealth()
                      << "%:" << getDamage() << ":" << agility << ":" << defense << "\n";
            return;
        }
        std::cout << identifier << ":"
                  << "R.I.P.\n";
    }
};

// bestia
class BEAST_CLASS : virtual public PLAYER_CLASS
{
public:
    // metody i skladowe publiczne
    std::string identifier;

    BEAST_CLASS()
    {
        identifier = "";
        maxHealth = 150;
        remainingHealth = 150;
        damage = 40;
        agility = 20;
        squad = NULL;
        next = NULL;
        prev = NULL;
    }

    BEAST_CLASS(std::string beastIdentifier)
    {
        identifier = beastIdentifier;
        maxHealth = 150;
        remainingHealth = 150;
        damage = 40;
        agility = 20;
        squad = NULL;
        next = NULL;
        prev = NULL;
    }

    void die()
    {
        remainingHealth = 0;
    }

    void applyWinnerReward()
    {
        agility += 2;
        damage += 2;
    }

    void cure()
    {
        remainingHealth = maxHealth;
    }

    unsigned int getRemainingHealth()
    {
        return 100 * remainingHealth / maxHealth;
    }
    std::string getId()
    {
        return identifier;
    }
    unsigned int getAgility()
    {
        return agility;
    }

    unsigned int getDamage()
    {
        if (getRemainingHealth() < 25)
            return 2 * damage;
        return damage;
    }

    void takeDamage(unsigned int damageDealt)
    {
        if (damageDealt < agility / 2)
            return;
        if (damageDealt - (agility / 2) >= remainingHealth)
        {
            die();
            return;
        }
        remainingHealth -= damageDealt - (agility / 2);
    }

    void printParams()
    {
        if (getRemainingHealth() > 0)
        {
            std::cout << identifier << ":" << maxHealth << ":" << remainingHealth << ":"
                      << getRemainingHealth() << "%:" << getDamage() << ":" << agility << "\n";
            return;
        }
        std::cout << identifier << ":"
                  << "R.I.P.\n";
    }
};

// berserker
class BERSERKER_CLASS : public HUMAN_CLASS, public BEAST_CLASS
{
public:
    // metody publiczne
    BERSERKER_CLASS()
    {
        HUMAN_CLASS::identifier = "";
        BEAST_CLASS::identifier = "";
        maxHealth = 200;
        remainingHealth = 200;
        damage = 35;
        agility = 5;
        defense = 15;
        squad = NULL;
        next = NULL;
        prev = NULL;
    }

    BERSERKER_CLASS(std::string humanIdentifier, std::string beastIdentifier)
    {
        HUMAN_CLASS::identifier = humanIdentifier;
        BEAST_CLASS::identifier = beastIdentifier;
        maxHealth = 200;
        remainingHealth = 200;
        damage = 35;
        agility = 5;
        defense = 15;
        squad = NULL;
        next = NULL;
        prev = NULL;
    }

    void die()
    {
        remainingHealth = 0;
    }

    void cure()
    {
        remainingHealth = maxHealth;
    }

    void applyWinnerReward()
    {
        agility += 2;
        damage += 2;
    }
    std::string getId()
    {
        if (getRemainingHealth() >= 25 || getRemainingHealth() == 0)
            return HUMAN_CLASS::identifier;
        else
            return BEAST_CLASS::identifier;
    }
    unsigned int getAgility()
    {
        return agility;
    }

    unsigned int getRemainingHealth()
    {
        return 100 * remainingHealth / maxHealth;
    }

    unsigned int getDamage()
    {
        if (getRemainingHealth() >= 25 || getRemainingHealth() == 0)
            return HUMAN_CLASS::getDamage();
        else
            return BEAST_CLASS::getDamage();
    }

    void takeDamage(unsigned int damageDealt)
    {
        if (getRemainingHealth() >= 25 || getRemainingHealth() == 0)
            HUMAN_CLASS::takeDamage(damageDealt);
        else
            BEAST_CLASS::takeDamage(damageDealt);
    }

    void printParams()
    {
        if (getRemainingHealth() >= 25 || getRemainingHealth() == 0)
            HUMAN_CLASS::printParams();
        else
            BEAST_CLASS::printParams();
    }
};

// sklad
class SQUAD_CLASS : public PLAYER_CLASS
{
public:
    // publiczne skladowe i metody
    PLAYER_CLASS *firstMember;
    std::string identifier;
    int membersAmount;

    SQUAD_CLASS()
    {
        identifier = "";
        membersAmount = 0;
        firstMember = NULL;
        squad = NULL;
        next = NULL;
        prev = NULL;
    }

    SQUAD_CLASS(std::string squadIdentifier)
    {
        identifier = squadIdentifier;
        firstMember = NULL;
        membersAmount = 0;
        squad = NULL;
        next = NULL;
        prev = NULL;
    }

    std::string getId()
    {
        return identifier;
    }

    bool comparePlayers(PLAYER_CLASS *player1, PLAYER_CLASS *player2)
    {
        if (player1->getId() > player2->getId())
            return true;
        else if (player1->getId() < player2->getId())
            return false;
        else if (player1->maxHealth > player2->maxHealth)
            return true;
        else if (player1->maxHealth < player2->maxHealth)
            return false;
        else if (player1->remainingHealth > player2->remainingHealth)
            return true;
        else if (player1->remainingHealth < player2->remainingHealth)
            return false;
        else if (player1->getRemainingHealth() > player2->getRemainingHealth())
            return true;
        else if (player1->getRemainingHealth() < player2->getRemainingHealth())
            return false;
        else if (player1->getDamage() > player2->getDamage())
            return true;
        else if (player1->getDamage() < player2->getDamage())
            return false;
        else if (player1->getAgility() > player2->getAgility())
            return true;
        else if (player1->getAgility() <= player2->getAgility())
            return false;
    }
    void swapPlayers(PLAYER_CLASS *player1, PLAYER_CLASS *player2, PLAYER_CLASS **head)
    {
        if (player1 == player2)
            return;

        if (player1->prev == player2)
        {
            player1->prev = player2->prev;
            player2->prev = player1;
            player2->next = player1->next;
            player1->next = player2;
        }
        else if (player2->prev == player1)
        {
            player2->prev = player1->prev;
            player1->prev = player2;
            player1->next = player2->next;
            player2->next = player1;
        }
        else
        {
            PLAYER_CLASS *temp = player1->prev;
            player1->prev = player2->prev;
            player2->prev = temp;

            temp = player1->next;
            player1->next = player2->next;
            player2->next = temp;
        }

        if (player1->prev != NULL)
        {
            player1->prev->next = player1;
        }
        if (player1->next != NULL)
        {
            player1->next->prev = player1;
        }
        if (player2->prev != NULL)
        {
            player2->prev->next = player2;
        }
        if (player2->next != NULL)
        {
            player2->next->prev = player2;
        }

        if (*head == player1)
        {
            *head = player2;
        }
        else if (*head == player2)
        {
            *head = player1;
        }
    }
    void selectionSort()
    {
        if (firstMember == NULL)
            return;

        PLAYER_CLASS *current = firstMember;
        while (current->next != NULL)
        {
            PLAYER_CLASS *minNode = current;
            PLAYER_CLASS *temp = current->next;

            while (temp != NULL)
            {
                if (!comparePlayers(temp, minNode))
                    minNode = temp;
                temp = temp->next;
            }

            if (minNode != current)
            {
                swapPlayers(current, minNode, &firstMember);
            }

            current = minNode->next;
        }
    }

    unsigned int getDamage()
    {
        if (firstMember != NULL)
        {
            PLAYER_CLASS *tmp = firstMember;
            unsigned int dmgSum = 0;
            while (tmp != NULL)
            {
                dmgSum += tmp->getDamage();
                tmp = tmp->next;
            }
            return dmgSum;
        }
        return 0;
    }

    unsigned int getAgility()
    {
        if (firstMember != NULL)
        {
            PLAYER_CLASS *tmp = firstMember;
            unsigned int currentMin = firstMember->getAgility();
            while (tmp != NULL)
            {
                if (tmp->agility < currentMin)
                    currentMin = tmp->getAgility();
                tmp = tmp->next;
            }
            return currentMin;
        }
        return 0;
    }

    unsigned int getRemainingHealth()
    {
        if (firstMember != NULL)
        {
            PLAYER_CLASS *tmp = firstMember;
            unsigned int currentMax = firstMember->getRemainingHealth();
            while (tmp != NULL)
            {
                if (tmp->getRemainingHealth() > currentMax)
                    currentMax = tmp->getRemainingHealth();
                tmp = tmp->next;
            }
            return currentMax;
        }
        return 0;
    }

    void applyWinnerReward()
    {
        if (firstMember == NULL)
            return;
        else
        {
            PLAYER_CLASS *tmp = firstMember;
            while (tmp != NULL)
            {
                tmp->applyWinnerReward();
                tmp = tmp->next;
            }
        }
    }

    void cure()
    {
        if (firstMember == NULL)
            return;
        else
        {
            PLAYER_CLASS *tmp = firstMember;
            while (tmp != NULL)
            {
                tmp->cure();
                tmp = tmp->next;
            }
        }
    }

    void die()
    {
        if (firstMember == NULL)
            return;
        else
        {
            PLAYER_CLASS *tmp;
            while (firstMember != NULL)
            {
                tmp = firstMember;
                firstMember = firstMember->next;
                tmp->die();
                tmp->next = NULL;
                tmp->prev = NULL;
                if (membersAmount != 0)
                    membersAmount--;
            }
        }
    }

    void addPlayer(PLAYER_CLASS *member)
    {
        if (member->getRemainingHealth() == 0 || member->squad != NULL)
            return;

        if (firstMember == NULL)
        {
            member->squad = this;
            firstMember = member;
            firstMember->squad = this;
            membersAmount++;
        }
        else if (firstMember->next == NULL)
        {
            member->squad = this;
            firstMember->next = member;
            firstMember->next->prev = firstMember;
            firstMember->squad = this;
            membersAmount++;
        }
        else
        {
            member->squad = this;
            PLAYER_CLASS *tmp = firstMember;
            while (tmp->next != NULL)
                tmp = tmp->next;
            tmp->next = member;
            tmp->next->squad = this;
            tmp->next->prev = tmp;
            tmp = NULL;
            membersAmount++;
        }
    }

    void takeDamage(unsigned int damageDealt)
    {
        if (membersAmount != 0)
        {
            PLAYER_CLASS *tmp = firstMember;
            int denominator = membersAmount;
            while (tmp != NULL)
            {
                tmp->takeDamage(damageDealt / denominator);
                if (tmp->getRemainingHealth() == 0)
                {
                    if (tmp->next != NULL)
                        tmp->next->prev = tmp->prev;
                    if (tmp->prev != NULL)
                        tmp->prev->next = tmp->next;
                    if (tmp == firstMember)
                        firstMember = firstMember->next;
                    tmp->squad = NULL;
                    membersAmount--;
                }
                tmp = tmp->next;
            }
        }
    }

    void printParams()
    {
        if (membersAmount == 0)
        {
            std::cout << identifier << ":nemo\n";
            return;
        }
        else
        {
            std::cout << identifier << ":" << membersAmount << ":" << getRemainingHealth() << "%:"
                      << getDamage() << ":" << getAgility() << "\n";
            selectionSort();
            PLAYER_CLASS *tmp = firstMember;
            while (tmp != NULL)
            {
                tmp->printParams();
                tmp = tmp->next;
            }
        }
    }
};
// klasy nie dziedziczace po PLAYER_CLASS
//----------------------------------------

class CAESAR_CLASS
{
public:
    // publiczne metody i skladowe
    unsigned int attacksTotal;
    unsigned int judgements;
    CAESAR_CLASS()
    {
        judgements = 0;
        attacksTotal = 0;
    }
    void judgeDeathorLife(PLAYER_CLASS *judgedPlayer)
    {
        judgements++;
        if (attacksTotal % 2 == 0 && judgements % 3 == 0)
            judgedPlayer->die();
    }
};

class ARENA_CLASS
{
public:
    // konstrutkor areny
    ARENA_CLASS(CAESAR_CLASS *caesar)
    {
        caesarOfArena = *caesar;
    }

    // publiczna metoda walki
    void fight(PLAYER_CLASS *playerOne, PLAYER_CLASS *playerTwo)
    {
        if (playerOne->getRemainingHealth() == 0 || playerTwo->getRemainingHealth() == 0)
            return;
        else
        {
            PLAYER_CLASS *first, *second;
            if (playerOne->getAgility() >= playerTwo->getAgility())
            {
                first = playerOne;
                second = playerTwo;
            }
            else
            {
                first = playerTwo;
                second = playerOne;
            }
            first->printParams();
            second->printParams();
            int i;
            for (i = 1; i <= 40; i++)
            {
                if (i % 2 == 1)
                {
                    second->takeDamage(first->getDamage());
                    second->printParams();
                    if (second->getRemainingHealth() < 10)
                        break;
                }
                else
                {
                    first->takeDamage(second->getDamage());
                    first->printParams();
                    if (first->getRemainingHealth() < 10)
                        break;
                }
            }
            caesarOfArena.attacksTotal = i;
            if (first->getRemainingHealth() > 0)
            {
                caesarOfArena.judgeDeathorLife(first);
                first->printParams();
            }
            if (second->getRemainingHealth() > 0)
            {
                caesarOfArena.judgeDeathorLife(second);
                second->printParams();
            }
            if (first->getRemainingHealth() > 0)
            {
                first->applyWinnerReward();
                first->cure();
            }
            if (second->getRemainingHealth() > 0)
            {
                second->applyWinnerReward();
                second->cure();
            }
            first->printParams();
            second->printParams();
        }
    }

private:
    CAESAR_CLASS caesarOfArena;
};
// int main() {
//    HUMAN_CLASS human1("warrior");
// HUMAN_CLASS human2("warrior");
// HUMAN_CLASS human3("warrior");
// HUMAN_CLASS human4("warrior");
// HUMAN_CLASS human5("warrior");
// HUMAN_CLASS human6("warrior");
// HUMAN_CLASS human7("warrior");
// HUMAN_CLASS human8("warrior");
// HUMAN_CLASS human9("awarrior");
// HUMAN_CLASS human10("warrio");

// SQUAD_CLASS avengers("avengers");
// avengers.addPlayer(&human1);
// avengers.addPlayer(&human2);
// avengers.addPlayer(&human3);
// avengers.addPlayer(&human4);
// avengers.addPlayer(&human5);
// avengers.addPlayer(&human6);
// avengers.addPlayer(&human7);
// avengers.addPlayer(&human8);
// avengers.addPlayer(&human9);
// avengers.addPlayer(&human10);

// avengers.printParams();

// human1.takeDamage(50);
// human2.takeDamage(50);
// human3.takeDamage(50);
// human4.takeDamage(50);
// human5.takeDamage(50);
// human6.takeDamage(50);
// human7.takeDamage(60);
// human10.takeDamage(10);

// avengers.printParams();

// human1.applyWinnerReward();
// human2.applyWinnerReward();
// human3.applyWinnerReward();
// human4.applyWinnerReward();

// avengers.printParams();

// BERSERKER_CLASS berserker1("warrior", "warrior");
// BERSERKER_CLASS berserker2("warrior", "warrior");
// BERSERKER_CLASS berserker3("warrior", "warrior");
// BERSERKER_CLASS berserker4("warrior", "warrior");
// BERSERKER_CLASS berserker5("warrior", "warrior");
// BERSERKER_CLASS berserker6("warrior", "warrior");
// BERSERKER_CLASS berserker7("warrior", "warrior");
// BERSERKER_CLASS berserker8("warrior", "warrior");
// BERSERKER_CLASS berserker9("warrior", "warrior");
// BERSERKER_CLASS berserker10("warrior", "warrior");

// avengers.addPlayer(&berserker1);
// avengers.addPlayer(&berserker2);
// avengers.addPlayer(&berserker3);
// avengers.addPlayer(&berserker4);
// avengers.addPlayer(&berserker5);
// avengers.addPlayer(&berserker6);
// avengers.addPlayer(&berserker7);
// avengers.addPlayer(&berserker8);
// avengers.addPlayer(&berserker9);
// avengers.addPlayer(&berserker10);

// avengers.printParams();

// berserker1.takeDamage(190);
// berserker2.takeDamage(190);
// berserker3.takeDamage(195);
// berserker4.takeDamage(170);
// berserker5.takeDamage(175);
// berserker6.takeDamage(10);
// berserker10.takeDamage(10);

// avengers.printParams();

// berserker1.applyWinnerReward();
// berserker2.applyWinnerReward();
// berserker3.applyWinnerReward();
// berserker4.applyWinnerReward();
// berserker6.applyWinnerReward();
// berserker7.applyWinnerReward();

// avengers.printParams();

// BEAST_CLASS beast1("warrior");
// BEAST_CLASS beast2("warrior");
// BEAST_CLASS beast3("warrior");
// BEAST_CLASS beast4("warrior");
// BEAST_CLASS beast5("warrior");
// BEAST_CLASS beast6("warrior");
// BEAST_CLASS beast7("warrior");
// BEAST_CLASS beast8("warrior");
// BEAST_CLASS beast9("awarrior");
// BEAST_CLASS beast10("warrio");

// avengers.addPlayer(&beast1);
// avengers.addPlayer(&beast2);
// avengers.addPlayer(&beast3);
// avengers.addPlayer(&beast4);
// avengers.addPlayer(&beast5);
// avengers.addPlayer(&beast6);
// avengers.addPlayer(&beast7);
// avengers.addPlayer(&beast8);
// avengers.addPlayer(&beast9);
// avengers.addPlayer(&beast10);

// avengers.printParams();

// beast1.takeDamage(130);
// beast2.takeDamage(145);
// beast3.takeDamage(155);
// beast4.takeDamage(100);
// beast5.takeDamage(149);
// beast10.takeDamage(10);

// avengers.printParams();

// beast1.applyWinnerReward();
// beast3.applyWinnerReward();
// beast4.applyWinnerReward();
// beast5.applyWinnerReward();
// beast6.applyWinnerReward();
// beast10.applyWinnerReward();

// avengers.printParams();

// human1.cure();
// berserker1.cure();
// beast1.cure();

// avengers.printParams();

// avengers.takeDamage(1000);

// avengers.printParams();
// return 0;
// }
