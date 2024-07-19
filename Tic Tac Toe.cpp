#include <iostream>
#include <iomanip>
using namespace std;

char arr[3][3];
bool turn = true,endgame = false;
char chr;

void TicTacToe()
{
	cout << "-----------------------------\n";
	cout << "|         Tic Tac Toe       |\n";
	cout << "-----------------------------\n\n";
	cout << "Player1 : O\tPlayer2 : X\n\n";
}

void map()
{
	cout << " " << arr[0][0] << " | " << arr[0][1] << " | " << arr[0][2] << endl;
	cout << "-----------" << endl;
	cout << " " << arr[1][0] << " | " << arr[1][1] << " | " << arr[1][2] << endl;
	cout << "-----------" << endl;
	cout << " " << arr[2][0] << " | " << arr[2][1] << " | " << arr[2][2] << endl;
}

void clear()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			arr[i][j] = 32;
}

void player1()
{
	cout << "Player 1 turn : " << endl << endl;
	chr = 'O';
	turn = false;
}

void player2()
{
	cout << "Player 2 turn : " << endl << endl;
	chr = 'X';
	turn = true;
}

void Winner()
{
	system("cls");
	TicTacToe();
	map();
	if (chr == 'O')
		cout << "Player 1 is Winner.\n";
	else if (chr == 'X')
		cout << "Player 2 is Winner.\n";

	endgame = true;
}

void check()
{
	for(int i = 0; i < 3; i++)
	{
		if (arr[i][0] == chr && arr[i][1] == chr && arr[i][2] == chr)
		{
			Winner();
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (arr[0][i] == chr && arr[1][i] == chr && arr[2][i] == chr)
		{
			Winner();
		}
	}

	if (arr[0][0] == chr && arr[1][1] == chr && arr[2][2] == chr)
		Winner();
	else if (arr[0][2] == chr && arr[1][1] == chr && arr[2][0] == chr)
		Winner();
}

int main()
{
	clear();
	int row = 0, col = 0;

	for (int i = 0; i < 9; i++)
	{
		system("cls");
		TicTacToe();
		if (turn == true)
			player1();
		else
			player2();

		map();

		cout << "\nEnter the row : " ;
		cin >> row;
		cout << "Enter the colomn : " ;
		cin >> col;

		if (turn == false)
			arr[row - 1][col - 1] = 'O';
		else
			arr[row - 1][col - 1] = 'X';
		check();

		if (endgame == true)
			break;
	}

	if (endgame == false)
	{
		cout << "Game is Drawn.\n";
	}
	return 0;
}   