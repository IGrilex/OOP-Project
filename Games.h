#ifndef GAMES
#define GAMES

#include "Player.h"
#include "Supervisor.h"
#include "Settings.h"

using namespace std;

class Games{
public:
    void populatePlayers(Player *players);
    int getAlivePlayers(Player *players);
    void printAlivePlayers(Player *players);
    int getMoney4WiningPlayer(Player *players);

    void populateSupervisors(Supervisor *supervisors);
    void getMoney4WiningSupervisors(Player *players,Supervisor *supervisors);
    void printDesendingSupervisors(Supervisor *supervisors);
    void printBestSupervisorTeam(Supervisor *supervisors);

    void redLightGreenLight(Player *players);
    void tugOfWar(Player *players);
    void marbles(Player *players);
    void genken(Player *players);

    void viewWiner();
};

#endif
