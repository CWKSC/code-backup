#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>

using namespace std;

int main()
{
    std::map<std::string, int> choose{ {"Rock", 0}, {"Paper", 1}, {"Scissor", 2} };
    std::string numToChoose[]{ "Rock" , "Paper", "Scissor" };
    std::string input;
    srand(time(NULL));

    cout << "Let play Rock Paper Scissors! Choose one below\nRock\tPaper\tScissors" << endl;

    while (true)
    {
        while ((cin >> input) && choose.find(input) == choose.end()) {
            cout << "invaild" << endl;
        }

        int npcChoose = rand() % 3;
        int playerChoose = choose[input];
        cout << "CPU: " << numToChoose[npcChoose] << "\n";

        if (npcChoose == playerChoose) 
            cout << "draw" << endl;
        else if ((3 + playerChoose - npcChoose) % 3 == 1)
            cout << "you win" << endl;
        else
            cout << "you lose" << endl;
    }

    return 0;
}
