#include<iostream>
#include<string>

#include "Games.h"

using namespace std;

void Games::populatePlayers(Player *players){
    int orderPlayers[NR_OF_PLAYERS];
    for(int i=0;i<NR_OF_PLAYERS;i++){
        orderPlayers[i]=i;
    }
    Random randomAdmin;
    randomAdmin.shuffleNumbers(orderPlayers,NR_OF_PLAYERS);

    for(int i=0;i<NR_OF_PLAYERS;i++){
        string str = to_string(i);
        players[i].setFirstName("Kim_"+str);
        players[i].setLastName("Jong_"+str);
        players[i].setCity("Seul");
        players[i].setDebt(-randomAdmin.randomNumber(MIN_DEBT,MAX_DEBT));
        players[i].setWeight(randomAdmin.randomNumber(MIN_WEIGHT,MAX_WEIGHT));
        players[i].setNumber(orderPlayers[i]+1);
        players[i].setAlive(true);
    }

    cout<<"\nPLAYERS("<<NR_OF_PLAYERS<<")\n";
    for(int i=0;i<NR_OF_PLAYERS;i++){
        players[i].print();
    }
};

int Games::getAlivePlayers(Player *players){
    int alive=0;
    for(int i=0;i<NR_OF_PLAYERS;i++)
        if(players[i].isAlive())
            alive++;

    return alive;
}

void Games::printAlivePlayers(Player *players){
    cout<<"\nALIVE PLAYERS("<<getAlivePlayers(players)<<")\n";
    for(int i=0;i<NR_OF_PLAYERS;i++)
        if(players[i].isAlive())
            players[i].print();
}

int Games::getMoney4WiningPlayer(Player *players){
    int sum=0;
    for(int i=0;i<NR_OF_PLAYERS;i++){
        if(!players[i].isAlive())
            sum=sum+(-players[i].getDebt());
    }

    return sum;
}

void Games::populateSupervisors(Supervisor *supervisors){
    Random randomAdmin;
    for(int i=0;i<NR_OF_SUPERVISORS;i++){
        string str = to_string(i);
        supervisors[i].setFirstName("Woong_"+str);
        supervisors[i].setLastName("Sook_"+str);
        supervisors[i].setCity("Seul");
        supervisors[i].setDebt(-randomAdmin.randomNumber(MIN_DEBT,MAX_DEBT));
    }

    int orderSupervisors[NR_OF_SUPERVISORS];
    for(int i=0;i<NR_OF_SUPERVISORS;i++){
        orderSupervisors[i]=i;
    }
    randomAdmin.shuffleNumbers(orderSupervisors,NR_OF_SUPERVISORS);

    for(int i=0;i<NR_OF_SUPERVISORS_TEAMS*NR_OF_SUPERVISORS_PER_TEAM;i++){
        if(orderSupervisors[i]<NR_OF_SUPERVISORS_PER_TEAM){
            supervisors[i].setMaskShape(rectangle);
        }else if(orderSupervisors[i]>=NR_OF_SUPERVISORS_PER_TEAM&&orderSupervisors[i]<2*NR_OF_SUPERVISORS_PER_TEAM){
            supervisors[i].setMaskShape(triangle);
        }else if(orderSupervisors[i]>=2*NR_OF_SUPERVISORS_PER_TEAM&&orderSupervisors[i]<3*NR_OF_SUPERVISORS_PER_TEAM){
            supervisors[i].setMaskShape(circle);
        }
    }

    cout<<"\nSUPERVISORS\n";
    for(int i=0;i<NR_OF_SUPERVISORS;i++){
        supervisors[i].print();
    }
};

void Games::getMoney4WiningSupervisors(Player *players,Supervisor *supervisors){
    int supervisorIndex=0;
    for(int i=0;i<NR_OF_PLAYERS;i++){
        supervisorIndex=i/NR_OF_PLAYERS_PER_SUPERVISOR;
        if(!players[i].isAlive()){
            supervisors[supervisorIndex].setDebt(supervisors[supervisorIndex].getDebt()+(-players[i].getDebt()));
        }else
            supervisors[supervisorIndex].setDebt(supervisors[supervisorIndex].getDebt()+(-10*players[i].getDebt()));
    }
};

void Games::printDesendingSupervisors(Supervisor *supervisors){
    cout<<"\nSUPERVISORS\n";

    int supervisorsPositions[2][NR_OF_SUPERVISORS];

    for(int i=0;i<NR_OF_SUPERVISORS;++i){
        supervisorsPositions[0][i]=i;
        supervisorsPositions[1][i]=supervisors[i].getDebt();
    }

    int desc=0;
    for(int i=0;i<NR_OF_SUPERVISORS;++i){
        for (int j=i+1;j <NR_OF_SUPERVISORS;++j){
            if (supervisorsPositions[1][i]<supervisorsPositions[1][j]){
                desc=supervisorsPositions[1][i];
                supervisorsPositions[1][i]=supervisorsPositions[1][j];
                supervisorsPositions[1][j]=desc;

                desc=supervisorsPositions[0][i];
                supervisorsPositions[0][i]=supervisorsPositions[0][j];
                supervisorsPositions[0][j]=desc;
            }
        }
    }

    for(int i=0;i<NR_OF_SUPERVISORS;i++){
        supervisors[supervisorsPositions[0][i]].print();
    }
}

void Games::printBestSupervisorTeam(Supervisor *supervisors){
    int moneyPerTeam[2][NR_OF_SUPERVISORS_TEAMS];
    for(int i=0;i<NR_OF_SUPERVISORS;i++){
        switch(supervisors[i].getMaskShape()){
            case rectangle:
                moneyPerTeam[0][i]=0;
                moneyPerTeam[1][0]=moneyPerTeam[1][0]+supervisors[i].getDebt();
                break;
            case triangle:
                moneyPerTeam[0][i]=0;
                moneyPerTeam[1][1]=moneyPerTeam[1][1]+supervisors[i].getDebt();
                break;
            case circle:
                moneyPerTeam[0][i]=0;
                moneyPerTeam[1][2]=moneyPerTeam[1][2]+supervisors[i].getDebt();
                break;
        }
    }

    int cres=0;
    for(int i=0;i<NR_OF_SUPERVISORS_TEAMS;++i){
        for (int j=i+1;j<NR_OF_SUPERVISORS_TEAMS;++j){
            if (moneyPerTeam[1][i]>moneyPerTeam[1][j]){
                cres=moneyPerTeam[1][i];
                moneyPerTeam[1][i]=moneyPerTeam[1][j];
                moneyPerTeam[1][j]=cres;

                cres=moneyPerTeam[0][i];
                moneyPerTeam[0][i]=moneyPerTeam[0][j];
                moneyPerTeam[0][j]=cres;
            }
        }
    }

    cout<<"\nBest supervisor team is the ";
    switch(moneyPerTeam[0][0]){
        case 0:
            cout<<"rectangle ";
            break;
        case 1:
            cout<<"triangle ";
            break;
        case 2:
            cout<<"circle ";
            break;
        }
    cout<<"team that won the sum:\n"<<moneyPerTeam[1][0]<<"\n";
}

void Games::redLightGreenLight(Player *players){
    cout<<"\nRedLightGreenLight";

    for(int i=0;i<NR_OF_PLAYERS;i++){
        if(players[i].getNumber()%2==0){
            players[i].setAlive(false);
        }
    }
};

void Games::tugOfWar(Player *players){
    cout<<"\nTugOfWar";
    int orderPlayers[NR_OF_PLAYERS];
    for(int i=0;i<NR_OF_PLAYERS;i++){
        orderPlayers[i]=i;
    }
    Random randomAdmin;
    randomAdmin.shuffleNumbers(orderPlayers,NR_OF_PLAYERS);

    int number=0;
    int sum1=0,sum2=0,sum3=0,sum4=0;

    int numberOfLoops=(getAlivePlayers(players)/4)*4;

    int position[numberOfLoops];

    for(int i=0;number<numberOfLoops;i++){
        if(players[orderPlayers[i]].isAlive()){
            if(number<numberOfLoops/4){
                sum1=sum1+players[orderPlayers[i]].getDebt();
            }else if(number>=numberOfLoops/4&&number<numberOfLoops/2){
                sum2=sum2+players[orderPlayers[i]].getDebt();
            }else if(number>=numberOfLoops/2&&number<3*numberOfLoops/4){
                sum3=sum3+players[orderPlayers[i]].getDebt();
            }else if(number>=3*numberOfLoops/4&&number<numberOfLoops){
                sum4=sum4+players[orderPlayers[i]].getDebt();
            }

            position[number]=orderPlayers[i];
            number++;
        }
    }

    if(sum1>sum2)
        for(int i=numberOfLoops/4;i<numberOfLoops/2;i++)
            players[position[i]].setAlive(false);
    else if(sum1<sum2)
        for(int i=0;i<numberOfLoops/4;i++)
            players[position[i]].setAlive(false);

    if(sum3>sum4)
        for(int i=3*numberOfLoops/4;i<numberOfLoops;i++)
            players[position[i]].setAlive(false);
    else if(sum3<sum4)
        for(int i=numberOfLoops/2;i<3*numberOfLoops/4;i++)
            players[position[i]].setAlive(false);
};

void Games::marbles(Player *players){
    cout<<"\nMarbles";
    int number=0;
    int numberOfLoops=(getAlivePlayers(players)/2)*2;
    int numberGenerated1,numberGenerated2;
    Random randomAdmin;

    for(int i=0;number<numberOfLoops-1;i++){
        if(players[i].isAlive()){
            numberGenerated1=randomAdmin.randomNumber(0,10);
            for(int j=i+1;number<numberOfLoops;j++){
                if(players[j].isAlive()){
                    numberGenerated2=randomAdmin.randomNumber(0,10);
                    if(numberGenerated1>numberGenerated2){
                        players[i].setAlive(false);
                    }else if(numberGenerated1<numberGenerated2){
                        players[j].setAlive(false);
                    }
                    i=j+1;
                    number++;
                }
            }
            number++;
        }
    }
};

void Games::genken(Player *players){
    cout<<"\nGenken";

    int nrOfPlayersAlive=getAlivePlayers(players);
    int playersPositions[2][nrOfPlayersAlive];
    int countPlayersAlive=0;

    for(int i=0;countPlayersAlive<nrOfPlayersAlive;i++){
        if(players[i].isAlive()){
            playersPositions[0][countPlayersAlive]=i;
            playersPositions[1][countPlayersAlive]=players[i].getNumber();
            countPlayersAlive++;
        }
    }
    if(VERBOSE){
        cout<<"\nARRAY:\n";
        for(int i=0;i<nrOfPlayersAlive;i++)
            players[playersPositions[0][i]].print();
        cout<<"\n";
    }

    int desc=0;
    for(int i=0;i<nrOfPlayersAlive;++i){
        for (int j=i+1;j<nrOfPlayersAlive;++j){
            if (playersPositions[1][i]<playersPositions[1][j]){
                desc=playersPositions[1][i];
                playersPositions[1][i]=playersPositions[1][j];
                playersPositions[1][j]=desc;

                desc=playersPositions[0][i];
                playersPositions[0][i]=playersPositions[0][j];
                playersPositions[0][j]=desc;
            }
        }
    }

    if(VERBOSE){
        cout<<"\nARRAY DESC:\n";
        for(int i=0;i<nrOfPlayersAlive;i++)
            players[playersPositions[0][i]].print();
        cout<<"\n";
    }

    Random randomAdmin;
    int firstPlayerChoice=0;
    int secondPlayerChoice=0;

    for(int firstPlayer=0;firstPlayer<nrOfPlayersAlive-1;firstPlayer++){
        for(int secondPlayer=firstPlayer+1;secondPlayer<nrOfPlayersAlive;secondPlayer++){
            do{
                firstPlayerChoice=randomAdmin.randomNumber(1,3);
                secondPlayerChoice=randomAdmin.randomNumber(1,3);
            }while(firstPlayerChoice==secondPlayerChoice);

            if(VERBOSE){
                cout<<"FirstPlayer: "<<firstPlayerChoice<<"\n";
                players[playersPositions[0][firstPlayer]].print();

                cout<<"SecondPlayer: "<<secondPlayerChoice<<"\n";
                players[playersPositions[0][secondPlayer]].print();
            }

            if(firstPlayerChoice==rock&&secondPlayerChoice==scissors){
                players[playersPositions[0][secondPlayer]].setAlive(false);
            }else if(firstPlayerChoice==scissors&&secondPlayerChoice==rock){
                players[playersPositions[0][firstPlayer]].setAlive(false);
            }else if(firstPlayerChoice==rock&&secondPlayerChoice==paper){
                players[playersPositions[0][firstPlayer]].setAlive(false);
            }else if(firstPlayerChoice==paper&&secondPlayerChoice==rock){
                players[playersPositions[0][secondPlayer]].setAlive(false);
            }else if(firstPlayerChoice==paper&&secondPlayerChoice==scissors){
                players[playersPositions[0][firstPlayer]].setAlive(false);
            }else if(firstPlayerChoice==scissors&&secondPlayerChoice==paper){
                players[playersPositions[0][secondPlayer]].setAlive(false);
            }

            if(!players[playersPositions[0][firstPlayer]].isAlive()){
                firstPlayer=secondPlayer-1;
                break;
            }
        }
    }
};

void Games::viewWiner(){
    Supervisor supervisors[NR_OF_SUPERVISORS];
    populateSupervisors(supervisors);

    Player players[NR_OF_PLAYERS];
    populatePlayers(players);

    redLightGreenLight(players);
    printAlivePlayers(players);

    tugOfWar(players);
    printAlivePlayers(players);

    marbles(players);
    printAlivePlayers(players);

    genken(players);

    try{
        if(getAlivePlayers(players)==1){
            printAlivePlayers(players);

            int prizeMoney=getMoney4WiningPlayer(players);
            cout<<"Won the sum:\n"<<prizeMoney<<"\n";

            getMoney4WiningSupervisors(players,supervisors);
            printDesendingSupervisors(supervisors);

            printBestSupervisorTeam(supervisors);
        }else{
            throw 10;
        }
    }
    catch(int n){
        cout<<"\nCompilation error!!\n";
    }
};
