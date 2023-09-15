// Description:
// In this TIC_TAC_TOE game i made the function for the whole processing of this game, I took x and y as the players.
// Also I add some basic functionality to start the game and color theme to the font of the game!!! 
// toss is way to shuffle the X and O between the players. Gameboard is shown after every turn. I show the Game Result then
// and lastly I ask them to play again!!!
// Used PF functionality
#include <iostream>
#include <ctime>
using namespace std;

// Function declarations
void gameMenu();
void drawBoard();
void playGame();
void showBoard(char[]);

int x, y;   // these are the players 

int main()
{
    system("color B");   // for color adding 
    gameMenu();

    cout<<"\n Want to play Again!! if yes enter 1: ";
    int pAgain;
    cin>> pAgain;
    if(pAgain==1)
    {
        gameMenu();
    }
    else 
    {
        cout<<"Game Ended!!";
        return 0;
    }
    
}

void gameMenu()
{
    char play;

    cout << "\n\t\t   _____________________________________________________________________________";
    cout << "\n\t\t ||                              GAME                                           ||";
    cout << "\n\t\t ||                   <----TIC----TAC----TOE---->                               ||";
    cout << "\n\t\t ||        Welcome to the Game develpoed By Muzammil Ashraf                     ||\n";
    cout << "\t\t || Head (0) has been Selected For Toss by Player 1 and Palyer 2 select Tail (1)||";
    cout << "\n\t\t ||                  Press A to start the game                                  ||";
    cout << "\n\t\t  ______________________________________________________________________________\n\t\t";

    int guess;
    
    srand(time(NULL));
    guess = rand() % 2;
    
    cin>> play;



    if (play == 'A'|| play=='a')
    {
        if (guess == 0)
        {
            cout << "\n\t\t Here we go For the Toss And It Heads";
            cout << "\n\t\t Player 1 got the First Turn";
            x = 1;
            y = 2;
        }
        else if (guess == 1)
        {
            cout << "\n\t\t Here we go For the Toss And it Tails";
            cout << "\n\t\t Player 2 got the First Turn";
            x = 2;
            y = 1;
        }

        cout << "\n\n\t\t\tplayer " << x << "(X)\n\n\t\t\tplayer " << y << "(O)";
        drawBoard();
        playGame();
    }

    else if(play != 'A' || play!='a')
    {
        cout << "\n\n\t\tInvalid key!Press a valid key";
        gameMenu();
    }
}

void drawBoard()
{
    cout << "\n\n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t  1     |  2    |  3     \n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t_________________________\n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t  4     |  5    |  6     \n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t_________________________\n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t  7     |  8    |  9     \n";
    cout << "\t\t\t        |       |       \n";
}

void playGame()
{
    int i;
    char choice[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};     

    for (i = 2; i < 11; i++)     //  turns would be shuffled between the players
    {
        int place = 0;
        if ((i % 2) == 0)   // player 1 turns
        {
            cout << "\n\n\t\t\tplayer " << x << " turn : ";
            cin >> place;

            while (place < 1 || place > 9)
            {
                cout << "\t\t Invalid\n\t\t ReEnter: ";
                cin >> place;
            }

            if (choice[place - 1] != 'X' && choice[place - 1] != 'O')
            {
                choice[place - 1] = 'X';
            }
            else
            {
                cout << "\n\t\t\tPls ReEnter on the place that will have not been already filled: ";
                cin >> place;
                choice[place - 1] = 'X';
            }
        }
        else                 // player 2 turn 
        {
            cout << "\n\n\t\t\tplayer " << y << " turn : ";
            cin >> place;

            while (place < 1 || place > 9)
            {
                cout << "\t\t Invalid\n\t\t ReEnter: ";
                cin >> place;
            }

            if (choice[place - 1] != 'X' && choice[place - 1] != 'O')
            {
                choice[place - 1] = 'O';
            }
            else
            {
                cout << "\n\t\t\tPls ReEnter on the place that will not have been already filled: ";
                cin >> place;
                choice[place - 1] = 'O';
            }
        }
        showBoard(choice);

        // condition chking after printing GameBoard with 
        if (choice[0] == choice[1] && choice[1] == choice[2] && choice[2] == 'X')
        {
            cout << "\n\t\t\tPLAYER " << x << " WON" << endl;
            cout << "\n\t\t\tYour Game has completed" << endl;
            cout << "\n\t\t\tThank You For Playing" << endl;
            break;
        }

        else if (choice[3] == choice[4] && choice[4] == choice[5] && choice[5] == 'X')
        {
            cout << "\n\t\t\tPLAYER " << x << " WON" << endl;
            cout << "\n\t\t\tYour Game has completed" << endl;
            cout << "\n\t\t\tThank You For Playing" << endl;
            break;
        }

        else if (choice[6] == choice[7] && choice[7] == choice[8] && choice[8] == 'X')
        {
            cout << "\n\t\t\tPLAYER " << x << " WON" << endl;
            cout << "\n\t\t\tYour Game has completed" << endl;
            cout << "\n\t\t\tThank You For Playing" << endl;
            break;
        }




        else if (choice[0] == choice[1] && choice[1] == choice[2] && choice[2] == 'O')
        {
            cout << "\n\t\t\tPLAYER " << x << " WON" << endl;
            cout << "\n\t\t\tYour Game has completed" << endl;
            cout << "\n\t\t\tThank You For Playing" << endl;
            break;
        }

        else if (choice[3] == choice[4] && choice[4] == choice[5] && choice[5] == 'O')
        {
            cout << "\n\t\t\tPLAYER " << x << " WON" << endl;
            cout << "\n\t\t\tYour Game has completed" << endl;
            cout << "\n\t\t\tThank You For Playing" << endl;
            break;
        }

        else if (choice[6] == choice[7] && choice[7] == choice[8] && choice[8] == 'O')
        {
            cout << "\n\t\t\tPLAYER " << x << " WON" << endl;
            cout << "\n\t\t\tYour Game has completed" << endl;
            cout << "\n\t\t\tThank You For Playing" << endl;
            break;
        }

       
        else if (i == 10)
        {
            cout<< "\n\t\t\tGAME ONGOING";
            cout<< "\n\t\t\tThank You For Playing";
            
        }
    }

}

void showBoard(char choice[])
{
    system("cls");

    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t  " << choice[0] << "     |  " << choice[1] << "    |  " << choice[2] << "     \n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t_________________________\n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t  " << choice[3] << "     |  " << choice[4] << "    |  " << choice[5] << "     \n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t_________________________\n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t  " << choice[6] << "     |  " << choice[7] << "    |  " << choice[8] << "     \n";
    cout << "\t\t\t        |       |       \n";
    cout << "\t\t\t        |       |       \n";
}

