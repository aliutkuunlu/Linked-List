#include <string>
using namespace std;
class Goal
{
    Goal * nextGoal;
    Goal * previousGoal;
    string awayTeam;
    int minuteOfGoal;
    int matchId;
public:
    int getMinuteOfGoal() const
    {
        return minuteOfGoal;
    }

    void setMinuteOfGoal(int minuteOfGoal)
    {
        Goal::minuteOfGoal = minuteOfGoal;
    }

    int getMatchId() const
    {
        return matchId;
    }

    void setMatchId(int matchId)
    {
        Goal::matchId = matchId;
    }

    Goal *getNextGoal() const
    {
        return nextGoal;
    }

    void setNextGoal(Goal *nextGoal)
    {
        Goal::nextGoal = nextGoal;
    }

    Goal *getPreviousGoal() const
    {
        return previousGoal;
    }

    void setPreviousGoal(Goal *previousGoal)
    {
        Goal::previousGoal = previousGoal;
    }

    Goal(const string &awayTeam, int minuteOfGoal, int matchId) : awayTeam(awayTeam), minuteOfGoal(minuteOfGoal), matchId(matchId)
    {}

    const string &getAwayTeam() const
    {
        return awayTeam;
    }

    void setAwayTeam(const string &awayTeam)
    {
        Goal::awayTeam = awayTeam;
    }
};