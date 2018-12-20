#include "Player.cpp"
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>


class PlayerList {

public:


    static void
    addPlayerNodeOrGoal(Player **currentNode, string name, string teamName, string awayTeam, int minOfGoal, int matchId)
    {
        if (*currentNode == NULL)
        {
            (*currentNode) = new Player(name, teamName);
            (*currentNode)->setGoalsHead(NULL);
            (*currentNode)->addGoal((*currentNode)->getGoalsHeadAddress(), awayTeam, minOfGoal, matchId);
            (*currentNode)->setNextPlayer(NULL);
            (*currentNode)->setPreviousPlayer(NULL);
        }
        else
        {
            if(isPlayerExists((*currentNode), name,awayTeam,minOfGoal,matchId) )
            {
                Player *temp = (*currentNode);
                while((*currentNode)!= NULL)
                {
                    if((*currentNode)->getName() == name)
                    {
                        addGoalToExistingPlayer((*currentNode), awayTeam, minOfGoal, matchId);
                    }
                    *currentNode = (*currentNode)->getNextPlayer();
                }
                (*currentNode) = temp;
            }
            else
            {
                Player * tempHead = (*currentNode);
                Player * newAddingPlayer = new Player(name,teamName);
                newAddingPlayer->setGoalsHead(NULL);
                newAddingPlayer->addGoal(newAddingPlayer->getGoalsHeadAddress(),awayTeam,minOfGoal,matchId);

                while(continueToTraverse(*currentNode))
                {
                    *currentNode = (*currentNode)->getNextPlayer();
                }

                newAddingPlayer->setPreviousPlayer(*currentNode);
                newAddingPlayer->setNextPlayer((*currentNode)->getNextPlayer());
                (*currentNode)->setNextPlayer(newAddingPlayer);

                if(newAddingPlayer->getNextPlayer() != NULL)
                {
                    newAddingPlayer->getNextPlayer()->setPreviousPlayer(newAddingPlayer);
                }
                *currentNode = tempHead;
            }
        }



    }
    static void op6(Player * player, string name1, string name2, ofstream &output)
    {
        Player *temp = player;        
        output << "MATCHES OF GIVEN FOOTBALLER" <<endl;

        while(player != NULL)
        {


            if(player->getName() == name1)
            {
                output << "Matces of ";
                output << name1 << endl;
                while(player->getGoalsHead() != NULL)
                {
                    output << "Footballer Name: ";
                    output << player->getName();
                    output << ",";
                    output << "Away Team: ";
                    output << player->getGoalsHead()->getAwayTeam();
                    output << ",";
                    output << "Min of Goal: ";
                    output << player->getGoalsHead()->getMinuteOfGoal();
                    output << ",";
                    output << "Match ID: ";
                    output << player->getGoalsHead()->getMatchId() << endl;
                    player->setGoalsHead(player->getGoalsHead()->getNextGoal());
                }

                break;
            }


            player = player->getNextPlayer();
        }
        player = temp;

        while(player != NULL)
        {
            Goal * tempG1 = player->getGoalsHead();
            if(player->getName() == name2)
            {
                output << "Matces of ";
                output << name2 << endl;
                while(player->getGoalsHead() != NULL)
                {
                    output << "Footballer Name: ";
                    output << player->getName();
                    output << ",";
                    output << "Away Team: ";
                    output << player->getGoalsHead()->getAwayTeam();
                    output << ",";
                    output << "Min of Goal: ";
                    output << player->getGoalsHead()->getMinuteOfGoal();
                    output << ",";
                    output << "Match ID: ";
                    output << player->getGoalsHead()->getMatchId() << endl;
                    player->setGoalsHead(player->getGoalsHead()->getNextGoal());
                }
                player->setGoalsHead(tempG1);
                break;
            }
            player->setGoalsHead(tempG1);
            player = player->getNextPlayer();

        }

        player = temp;
    }

    static void op7(Player * player, string name1, string name2, ofstream &output)
    {
        output  << "ASCENDING ORDER ACCORDING TO MATCH ID" << endl;
        Player *temp = player;
        Goal *tempG = player->getGoalsHead();
        while(player != NULL)
        {
            if(player->getName() == name1)
            {
                vector<int> ids;
                int control =0;
                while(player->getGoalsHead() != NULL)
                {
                    unsigned int i;
                    for(i=0; i<ids.size();i++)
                    {
                        if(player->getGoalsHead()->getMatchId() == ids.at(i))
                        {
                            control=1;
                            break;
                        }
                    }
                    if (control == 0)
                    {
                        ids.push_back(player->getGoalsHead()->getMatchId());
                        output << "footballer Name: ";
                        output << player->getName();
                        output << ",";
                        output<< "Match ID: ";
                        output << player->getGoalsHead()->getMatchId() <<endl;

                    }
                    player->setGoalsHead(player->getGoalsHead()->getNextGoal());
                }
                break;
            }
            player = player->getNextPlayer();
        }

        player = temp;
        player->setGoalsHead(tempG);

        while(player != NULL)
        {
            if(player->getName() == name2)
            {
                vector<int> ids;
                int control =0;
                while(player->getGoalsHead() != NULL)
                {
                    unsigned int i;
                    for(i=0; i<ids.size();i++)
                    {
                        if(player->getGoalsHead()->getMatchId() == ids.at(i))
                        {
                            control=1;
                            break;
                        }
                    }
                    if (control == 0)
                    {
                        ids.push_back(player->getGoalsHead()->getMatchId());
                        output << "footballer Name: ";
                        output << player->getName();
                        output << ",";
                        output<< "Match ID: ";
                        output << player->getGoalsHead()->getMatchId() <<endl;

                    }
                    player->setGoalsHead(player->getGoalsHead()->getNextGoal());
                }
                break;
            }
            player = player->getNextPlayer();
        }

        player = temp;
        player->setGoalsHead(tempG);
    }

    static void op5(Player * players, ofstream &output)
    {
        output  << "LIST OF FOOTBALLERS" <<endl;
        while (players != NULL)
        {
            output << players->getName() << endl;
            players = players->getNextPlayer();
        }
    }
    static void op3 (Player * players, ofstream &output)
    {
        output << "THE NAMES OF FOOTBALLERS WHO SCORED HAT-TRICK" <<endl;
        vector<string> hatTricks;
        while (players != NULL)
        {
            int matchID = players->getGoalsHead()->getMatchId();

            int count = 0;
            while(players->getGoalsHead() != NULL)
            {
                if(players->getGoalsHead()->getMatchId() == matchID)
                {
                    count++;
                }
                else
                {
                    matchID = players->getGoalsHead()->getMatchId();
                    count =1;
                }

                players->setGoalsHead(players->getGoalsHead()->getNextGoal());
            }
            if(count > 2)
            {
                hatTricks.push_back(players->getName());
            }
            players = players->getNextPlayer();

        }

        unsigned int i;
        for(i=0; i < hatTricks.size(); i++)
        {
            output << hatTricks.at(i) << endl;
        }

    }
    static void op2(Player *players, ofstream &output)
    {
        Player * temp = players;
        int top =0 ;
        output << "TOP SCORER" << endl;
        vector<string> kings;
        while(players != NULL)
        {
            if(players->getGoalCount() < top)
            {
                players = players->getNextPlayer();
                continue;
            }
            else if (players->getGoalCount() > top)
            {
                top = players->getGoalCount();
                if(kings.size() != 0)
                {
                    kings.clear();
                }
                kings.push_back(players->getName());
            }
            else
            {
                kings.push_back(players->getName());
            }
            players = players->getNextPlayer();
        }
        unsigned int i;
        for (i=0; i< kings.size();i++)
        {
            output << kings.at(i) << endl; 
        }
        kings.clear();
        players = temp;
    }
    static void op1(Player **players, ofstream &output)
    {
        output << "THE MOST SCORED HALF" << endl;
        int result;
        int firstHalf = 0;
        int secondHalf = 0;
        Player * temp = *players;
        while((*players) != NULL)
        {
            while((*players)->getGoalsHead() != NULL)
            {
                if((*players)->getGoalsHead()->getMinuteOfGoal() < 46)
                    firstHalf ++;
                else
                    secondHalf++;
                (*players)->setGoalsHead((*players)->getGoalsHead()->getNextGoal());
            }
            (*players) = (*players)->getNextPlayer();

        }

        *players = temp;

        if(firstHalf > secondHalf)
            output << "First Half" << endl;
        else if(secondHalf > firstHalf)
            output << "Second Half" << endl;
        else
            output << "They are equal" << endl;


    }
    static void op4(Player ** player, ofstream &output)
    {
        Player *temp = *player;
        output << "LIST OF TEAMS" << endl;
        vector<string> teams;

        while ((*player) != NULL)
        {
            if(teams.size() == 0 )
            {
                teams.push_back((*player)->getTeamName());
            }
            else
            {
                int control = 0;
                unsigned int i;
                for(i = 0; i < teams.size() ; i++)
                {
                    if(teams.at(i) == (*player)->getTeamName() )
                    {
                        control = 1;
                        break;
                    }
                }
                if(control == 0)
                {
                    teams.push_back((*player)->getTeamName());
                }

            }
            (*player) = (*player)->getNextPlayer();
        }
        unsigned int j ;
        for (j=0; j<teams.size();j++)
        {
            output  << teams.at(j) << endl;
        }
        *player = temp;
    }

private:
    static bool continueToTraverse(Player *playerNode) {

        if((playerNode)->getNextPlayer()==NULL )
        {
            return false;
        }
        else if((playerNode)->getPreviousPlayer() != NULL)
        {
            if ((playerNode)->getName().compare( (playerNode)->getPreviousPlayer()->getName() )  > 0)
            {
                return false;
            }
        }
        else
        {
            return true;
        }
    }

private:
    static bool isPlayerExists(Player *headOfPlayers, string playerName,  string awayTeam, int minOfGoal,
                                int matchId) {
        if (headOfPlayers == NULL)
            return false;

        while (headOfPlayers != NULL)
        {
            if (headOfPlayers->getName() == playerName)
            {
                //Player exists, just add the goal
                return true;
            }
            headOfPlayers = headOfPlayers->getNextPlayer();
        }
        return false;

    }

    static void addGoalToExistingPlayer(Player * player, string awayTeam, int minOfGoal, int matchId)
    {
        player->addGoal(player->getGoalsHeadAddress(),awayTeam, minOfGoal, matchId);
    }


};


