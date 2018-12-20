#include <string>
#include "Goal.cpp"

using namespace std;
class Player{
    Player * nextPlayer;
    Player * previousPlayer;
public:
    Player *getNextPlayer() const {
        return nextPlayer;
    }

    void setNextPlayer(Player *nextPlayer) {
        Player::nextPlayer = nextPlayer;
    }

    Player *getPreviousPlayer() const {
        return previousPlayer;
    }

    void setPreviousPlayer(Player *previousPlayer) {
        Player::previousPlayer = previousPlayer;
    }

    Goal *getGoalsHead() {
        return goalsHead;
    }

    Goal ** getGoalsHeadAddress() {
        return &goalsHead;
    }


    void setGoalsHead(Goal *goalsHead) {
        Player::goalsHead = goalsHead;
    }

private:
    string name;
    string teamName;
    Goal * goalsHead;
    int goalCount;
public:
    int getGoalCount() const {
        return goalCount;
    }

    void setGoalCount(int goalCount) {
        Player::goalCount = goalCount;
    }

public:
    Player(const string &name, const string &teamName) : name(name), teamName(teamName)
    {
        goalCount = 0;
        goalsHead = NULL;
    }



public:
    const string &getName() const
    {
        return name;
    }

    void setName(const string &name)
    {
        Player::name = name;
    }

    void addGoal(Goal ** goalsHead, const string awayTeam, int minOfGoal, int matchId)
    {
        goalCount ++;
        if(*goalsHead == NULL)
        {
            *goalsHead = new Goal(awayTeam,minOfGoal,matchId);
            (*goalsHead)->setNextGoal(NULL);
            (*goalsHead)->setPreviousGoal(NULL);
        }
        else
        {
            Goal * addingGoal = new Goal(awayTeam,minOfGoal,matchId);
            Goal * tempHead = *goalsHead;
            while(continueTraverse(*goalsHead))
            {
                (*goalsHead) = (*goalsHead)->getNextGoal();
            }

            addingGoal->setNextGoal((*goalsHead)->getNextGoal() );

            addingGoal->setPreviousGoal((*goalsHead));

            (*goalsHead)->setNextGoal(addingGoal);

            if(addingGoal->getNextGoal() != NULL)
            {
                addingGoal->getNextGoal()->setPreviousGoal(addingGoal);
            }

            (*goalsHead) = tempHead;
        }

    }
    const string &getTeamName() const
    {
        return teamName;
    }

    void setTeamName(const string &teamName)
    {
        Player::teamName = teamName;
    }

private :bool continueTraverse(Goal * goalsHead)
    {
        if((goalsHead)->getNextGoal()==NULL)
        {
            return false;
        }
        else
        {
            if((goalsHead)->getPreviousGoal() != NULL)
            {
                if((goalsHead)->getMatchId()> (goalsHead)->getPreviousGoal()->getMatchId())
                {
                    return false;
                }
            }
            return true;
        }
    }

};