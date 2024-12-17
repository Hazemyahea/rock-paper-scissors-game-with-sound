#include <iostream>
#include <string>
#include <cmath> 
#include <vector>
#include <windows.h>

using namespace std; // This allows you to use standard library names without the `std::` prefix.


int RadnomNumber(int number, int from, int to) {
    int Rendom = number % (to - from + 1) + from;
    return Rendom;
}


// Game Code .. 
enum enOptions
{
    stone = 1,
    paper = 2,
    scissor = 3
};

enum enScoore
{
    ComputerWin = 1,
    PlayerWin = 2,
    draw = 3
};
int HowManyRound() {
    int rounds = 0;
    cout << "How Many Rounds You want play?" << endl;
    cin >> rounds;
    return rounds;
}

bool countanio() {
    int coun = 0;
    cout << "Do You Want Play Again ?! [0] Yes , [1] No" << endl;
    cin >> coun;
    if (coun == 0)
    {
        return true;
    }
    else {
        return false;
    }
}

enOptions WhatThayChoose(int choose) {
    enOptions enChoose;
    if (choose == 1)
    {
        enChoose = enOptions::stone;
        cout << " Choose is Stone " << endl;
    }
    else if (choose == 2) {
        enChoose = enOptions::paper;
        cout << " Choose is Paper " << endl;
    }
    else if (choose = 3)
    {
        enChoose = enOptions::scissor;
        cout << " Choose is scissor" << endl;
    }

    return enChoose;
}

enScoore playerWinRound(enOptions PlayerChoose, enOptions ComputerChoose) {
    if (PlayerChoose == ComputerChoose) {
        cout << "It's a tie!\t" << endl;
        return enScoore::draw;
    }
    else if (PlayerChoose == enOptions::stone && ComputerChoose == enOptions::scissor) {
        cout << "The Player wins!" << endl;
        return enScoore::PlayerWin;
    }
    else if (ComputerChoose == enOptions::stone && PlayerChoose == enOptions::scissor) {
        cout << "The Computer wins!" << endl;
        return enScoore::ComputerWin;
    }
    else if (PlayerChoose == enOptions::scissor && ComputerChoose == enOptions::paper) {
        cout << "The Player wins!" << endl;
        return enScoore::PlayerWin;
    }
    else if (ComputerChoose == enOptions::scissor && PlayerChoose == enOptions::paper) {
        cout << "The Computer wins!" << endl;
        return enScoore::ComputerWin;
    }
    else if (PlayerChoose == enOptions::paper && ComputerChoose == enOptions::stone) {
        cout << "The Player wins!" << endl;
        return enScoore::PlayerWin;
    }
    else if (ComputerChoose == enOptions::paper && PlayerChoose == enOptions::stone) {
        cout << "The Computer wins!" << endl;
        return enScoore::ComputerWin;
    }

    return enScoore::draw;
}
void FinalResult(int PlayerScoore, int ComputerScoore, int drawScoore) {
    cout << "\t\t\t --------- FinalResult --------- \t\t\t" << endl;
    cout << "\t\t\tPlayer win \t: " << PlayerScoore << endl;
    cout << "\t\t\tcomputer win \t: " << ComputerScoore << endl;
    cout << "\t\t\tdraw \t: " << drawScoore << endl;
    cout << "\t\t\t------------------------------\t\t\t" << endl;
}
void startGame() {
    int Rounds = HowManyRound();
    int i = 0;
    int RealGamerChoose = 0;
    int CoumputerChoose = 0;
    enOptions enGamerChoose;
    enOptions enComputerChoose;
    int PlayerScoore = 0;
    int ComputerScoore = 0;
    int drawScoore = 0;
    do
    {
        do
        {
            cout << "Choose From Stone[1] - Paper[2] - Scissor[3]" << endl;
            cin >> RealGamerChoose;

            enGamerChoose = WhatThayChoose(RealGamerChoose);
            cout << "Computer Turn" << endl;
            CoumputerChoose = RadnomNumber(rand(), 1, 3);
            enComputerChoose = WhatThayChoose(CoumputerChoose);

            switch (playerWinRound(enGamerChoose, enComputerChoose))
            {
            case(enScoore::ComputerWin):
                ComputerScoore++;
                system("color 4F");
                Beep(1000, 500);

                break;
            case(enScoore::PlayerWin):
                PlayerScoore++;
                system("color 2F");
                break;
            case(enScoore::draw):
                system("color 6F");
                drawScoore++;
            }


            i++;
            cout << "----------------------" << endl;
        } while (i != Rounds);
        FinalResult(PlayerScoore, ComputerScoore, drawScoore);

        i = 0;
        PlayerScoore = 0;
        ComputerScoore = 0;
        drawScoore = 0;

    } while (countanio());


}



int main()
{
    srand((unsigned)time(NULL));


    startGame();
    return 0; // It's good practice to explicitly return 0 to indicate success.
}