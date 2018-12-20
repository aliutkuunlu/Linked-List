#include <fstream>
#include <vector>
#include <iostream>
#include "PlayerList.cpp"
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[])
{
    ifstream inFile(argv[1]);
    ifstream opFile(argv[2]);
    ofstream output(argv[3]);
    

    string line;
    string lineOp;
    vector<string> inputLines;
    vector<string> opLines;
    Player *player = NULL;
    while(getline(opFile,lineOp))
    {
        opLines.push_back(lineOp);
    }
    while (getline(inFile, line))
    {
        inputLines.push_back(line);
    }
    unsigned int i;
    for (i =0; i < inputLines.size(); i++)
    {
        vector<string> result;
        stringstream ss(inputLines.at(i));
        while(ss.good())
        {
            string substr;
            getline(ss, substr, ',');
            result.push_back(substr);
        }
        PlayerList::addPlayerNodeOrGoal(&player, result.at(0), result.at(1), result.at(2),
                                        std::stoi(result.at(3)),std::stoi(result.at(4)) );

        result.clear();
    }


    unsigned int j;
    vector<string> ops;
    for(j=0; j<opLines.size(); j++)
    {

        stringstream ssOp(opLines.at(j));
        while(ssOp.good())
        {
            string substr;
            getline(ssOp, substr, ',');
            ops.push_back(substr);
        }
    }

    cout << "Enter command for followings:" << endl;
    cout << "Enter 1 for most scored half" << endl;
    cout << "Enter 2 for top scorer player" << endl;
    cout << "Enter 3 for hat-trick player " << endl;
    cout << "Enter 4 for all teams in the league" << endl;
    cout << "Enter 5 for all players who scored" << endl;
    cout << "Enter 6 for matches and goals of given footbaler. ";
    cout << "which are: " << ops.at(0) << " and " << ops.at(1) << endl;
    cout << "Enter 7 for sort by matchID of given footbaler. ";
    cout << "which are: " << ops.at(2) << " and " << ops.at(3) << endl;

    int input = 0;
    cin >> input;
    if(input == 1)
    {
        PlayerList::op1(&player, output);
    }
    else if ( input == 2)
    {
        PlayerList::op2(player, output);
    }
    else if ( input == 3)
    {
        PlayerList::op3(player, output);
    }
    else if ( input == 4)
    {
        PlayerList::op4(&player, output);
    }
    else if ( input == 5)
    {
        PlayerList::op5(player, output);
    }
    else if ( input == 6)
    {
        PlayerList::op6(player, ops.at(0), ops.at(1), output);
    }
    else if ( input == 7)
    {
        PlayerList::op7(player, ops.at(2), ops.at(3), output);
    }
    else
    {
        output << "Wrong command entered." << endl;
    }



    cout << "Result in the output.txt file." << endl;
    inFile.close();
    opFile.close();
    output.close();
    return 0;

}



