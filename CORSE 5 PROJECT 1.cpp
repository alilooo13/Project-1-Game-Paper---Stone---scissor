// CORSE 5 PROJECT 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>

using namespace std; 


struct gameresults
{
    int totalrounds; 
    string winner; 
    int playerWONtimes;
    int computeWONtimes; 
    int drawTIMES; 

}; 

int readnumberofrounds()
{
    int number;
    cout << "Please enter how many rounds you want to play: "; cin >> number; 
    return number;
} 

int randomnumber(int from, int to)
{
    int random = rand() % (to - from + 1) + from; 
    return random;
} 

void gameround(  int roundnumber , gameresults &results )
{  
   


    int OPTIONS;
    cout << "----------------------------- ROUND [" << roundnumber << "] ------------------------------ \n" << endl; 

    cout << "please choose an option [1] : paper - [2] : stone - [3] : scissor "; cin >> OPTIONS;   

    int computeroption = randomnumber(1, 3);

    if (computeroption == OPTIONS)
    {    
        results.drawTIMES ++;

        system("color 6f");

        cout << "DRAW !!!!!" << endl;
        cout << "computer option was: " << computeroption << " and yours was: " << OPTIONS << endl;
        cout << "\n";
    }

    else if (computeroption == 1 && OPTIONS == 2)
    {  
        results.computeWONtimes ++;

        system("color 4f");
        cout << "\a ";

        cout << "Computer won !!! " << endl;  
        cout << "computer option was: " << computeroption << " and yours was: " << OPTIONS << endl;
        cout << "\n";

    }

    else if (computeroption == 2 && OPTIONS == 3)
    {   
        results.computeWONtimes ++;

        system("color 4f");
        cout << "\a ";
        cout << "computer won !!!! " << endl;
        cout << "computer option was: " << computeroption << " and yours was: " << OPTIONS << endl;
        cout << "\n";

    }
    else if (computeroption == 3 && OPTIONS == 1)
    {   
        results.computeWONtimes ++;

        system("color 4f");
        cout << "\a ";

        cout << "computer won !!!! " << endl;
        cout << "computer option was: " << computeroption << " and yours was: " << OPTIONS << endl;

        cout << "\n";


    }

    else {
        results.playerWONtimes++;
        system("color 2f");
        cout << "Player won !!! computer option was: " << computeroption << " and yours was: " << OPTIONS << endl; 

        cout << "\n";

    }


}

void gameover(gameresults results)
{
    cout << "\n------------- GAME OVER ---------------\n" << endl;

    cout << "computer won times: " << results.computeWONtimes << endl;
    cout << "Player won times: " << results.playerWONtimes << endl;
    cout << "Draw times: " << results.drawTIMES << endl;

    if (results.computeWONtimes > results.playerWONtimes)
    {
        cout << "THE winner is the computer !!! " << endl;
    }
    else if (results.computeWONtimes < results.playerWONtimes)
    {
        cout << "CONGRATULATIONS ! you won !!! " << endl;
    }
    else cout << "DRAW ! no one has won ! \n" << endl;

    cout << "-------------------------------------------------- " << endl;
}

void game( gameresults results)
{
    int numberOFrounds = readnumberofrounds(); 

    cout << endl;
    results.computeWONtimes = 0;
    results.playerWONtimes = 0;
    results.drawTIMES = 0;


    for (int i = 0; i < numberOFrounds; i++)
    {
        gameround(i + 1 , results );
        
    }

    gameover(results); 
    int yesno;

    do
    {

        cout << "\n do you want to play more rounds ? [1] FOR YES [0] FOR NO " << endl;
        cin >> yesno; 
        if (yesno == 1)
        {    
            system("cls"); // this means clear screen ( all the above info would be cleared ) 
            system("color 0F"); // this would set the screen color to BLACK
            game(results);
        }

        else return;

    } while (yesno == 1);

 
   

}





int main()
{  
    srand((unsigned)time(NULL));
    gameresults results;
    game(results);




}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
