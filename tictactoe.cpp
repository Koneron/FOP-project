/*This 2 player program is made by BY AFFAN, UMER AND AREEB. There will be multiple comment 
along the program that explain what each user defined function is supposed to do
*/

#include <iostream>
#include <limits>
#include <climits>
#include <ctime>
#include <cstdlib>
using namespace std;
//Array/Layout for the board
char board[3][3] = {'1','2','3','4','5','6','7','8','9'};
int choice;
int row,column;
char turn = 'X';
bool draw = false;

//Function to show the current status of the gaming board

void display_board(){

    cout<<"PLAYER - 1 is [X]\t PLAYER - 2 is [O]\n\n";
    cout<< "Note: Do not use Aplhabets as input and any number outside 1-9 range. \nwe are not responsible for any errors if you disregard input rules\n\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[0][0]<<"  | "<<board[0][1]<<"   |  "<<board[0][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[1][0]<<"  | "<<board[1][1]<<"   |  "<<board[1][2]<<" \n";
    cout<<"\t\t_____|_____|_____\n";
    cout<<"\t\t     |     |     \n";
    cout<<"\t\t  "<<board[2][0]<<"  | "<<board[2][1]<<"   |  "<<board[2][2]<<" \n";
    cout<<"\t\t     |     |     \n";
}

//Function to tell who'se turn it is, get the player input and update the board. this function is still slightly unstable

void player_turn()
{
    if(turn == 'X'){
        cout<<"\n\tPlayer - 1's [X] turn : ";
    }
    else if(turn == 'O'){
        cout<<"\n\tPlayer - 2's [O] turn : ";
    }
    //Taking input from user
    //updating the board according to choice and reassigning the turn for other player
    cin>> choice;
    // check for alphabetic input and number outside 1-9 range and make user reenter values if input is invalid
     while (cin.fail() || choice < 1 || choice > 9) 
	 {
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number from 1 to 9: ";
        cin >> choice;
    }

    /*switch case to get which row and column will be updated. this code was updated for computer function in which
    we made the code only 2-4 lines long instead of a very long switch statement. credit to Affan Suhail for compressing the code*/

    switch(choice){
        case 1: 
		row=0; column=0;
		 break;
        case 2: 
		row=0; column=1;
		 break;
        case 3:
		 row=0; column=2;
		  break;
        case 4:
		 row=1; column=0;
		  break;
        case 5:
		 row=1; column=1;
		  break;
        case 6:
		 row=1; column=2;
		  break;
        case 7: 
		row=2; column=0;
		 break;
        case 8:
		 row=2; column=1;
		  break;
        case 9: 
		{
		row=2; column=2;
		 break;	}
        default:
          {
		  cout<<"Invalid Move, please select from 1-9 and no alphabets.";
	player_turn();}
    }
// check if slot is already occupied. if not, assign the player symbol and if yes return function back to the beginning
    if(turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
	{	
        board[row][column] = 'X';
        turn = 'O';
    }
	else if(turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
	{
        board[row][column] = 'O';
        turn = 'X';
    }
	else {
        cout<<"Box already filled!\n Please choose another!\n\n";
        player_turn();
    }
}
void player_turn2() {
    if (turn == 'X') {
        cout << "\n\tPlayer - 1's [X] turn : ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 9 || board[(choice - 1) / 3][(choice - 1) % 3] == 'X' || board[(choice - 1) / 3][(choice - 1) % 3] == 'O') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //removes all values from the input buffer
            cout << "Invalid input or position already taken. Please enter a valid number from 1 to 9: ";
            cin >> choice;
        }
		// this code replaces the lengthy switch statement in the 2 player function. credit to Affan Suhail for compressing.
        row = (choice - 1) / 3;
        column = (choice - 1) % 3;
        board[row][column] = 'X';
        turn = 'O';
    } else {
        cout << "\n\tPlayer - 2's [O] (Computer) turn : ";

        // Computer's turn: Generate a random move
        srand(time(nullptr)); // Seed for random number generation.in simple words srand is for fetching a random number and the argument is the seed for the starting value
        choice = rand() % 9 + 1; // Generate a random number between 1 and 9

        while (board[(choice - 1) / 3][(choice - 1) % 3] == 'X' || board[(choice - 1) / 3][(choice - 1) % 3] == 'O') {
            choice = rand() % 9 + 1;
        }

        row = (choice - 1) / 3;
        column = (choice - 1) % 3;
        board[row][column] = 'O';
        turn = 'X';
    }
}

bool gameover(){
    //checking the win for Sraight Rows and Straight Column
    for(int i=0; i<3; i++)
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
    return false;

    //checking the win for both diagonal

    if(board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    return false;

    //Checking the game is in continue mode or not
    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(board[i][j] != 'X' && board[i][j] != 'O')
    return true;

    draw = true;
    return false;
}

//Program Main Body

int main()
{
	int game;
    cout<<"\t\t\tT I C K -- T A C -- T O E -- G A M E\t\t\t";
    cout<<"\n\t\t\t\tFOR 2 PLAYERS\n\t\t\t";
     cout<<"\n\t\t\t\tBY AFFAN, UMER AND AREEB\n\t\t\t";
     cout<<"Press 1 to play against computer\npress 2 for 2 player game.";
     cin>>game;
     if(game==1)
     {
	 display_board();
    while(gameover())
	{
        player_turn2();
        display_board();
        gameover();
    }
}
	else if (game==2)
	{
		display_board();
    while(gameover())
	{
        player_turn();
        display_board();
        gameover();
    }
    else
    {cout<<"invalid input";
    
	}
    if(turn == 'O' && draw == false){
        cout<<"\n\nCongratulations!Player 1 has won the game";
    }
    else if(turn == 'X' && draw == false){
        cout<<"\n\nCongratulations!Player 2 has won the game";
    }
    else
    cout<<"\n\nGAME DRAW!!!\n\n";
    return 0;
} 
