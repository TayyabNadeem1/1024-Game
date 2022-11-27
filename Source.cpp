#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;
double board[4][4] = { };
double chucky[4][4] = { };
int check;
void credit()
{
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "  PROGRAMMED BY" << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "    AAON RAZA " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "  TAYYAB NADEEM " << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "MUHAMMAD ABDULLAH " << endl;

}

void display()
{
	system("cls");
	cout << endl;
	cout << endl;
	cout << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << "  " << "  " << "  " << " WELCOME TO OUR PROJECT !!!" << endl << endl;
	cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << " " << " " << " " << " LET'S PLAY !!!" << endl << endl << endl;
	cout << endl << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "  " << "-----------------" << endl;
	for (int x = 0; x < 4; x++)
	{
		cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << " " << " | ";
		for (int y = 0; y < 4; y++)
		{
			cout << board[x][y] << " | ";
		}
		cout << endl << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "  " << "-----------------" << endl;
	}
	cout << endl;
	cout << endl;
	cout << '\t' << "  " << "  " << "Press W to go up";
	cout << '\t' << "  " << "  " << "Press A to go left";
	cout << '\t' << "  " << "  " << "Press S to go down";
	cout << '\t' << "  " << "  " << "Press D to go right" << endl;
	cout << endl;
	cout << endl;
	credit();
	cout << endl;
}
void firstrandom()//to generate the random tile(s) at the start
{
	int x, a = 0, b = 0, c = 0, d = 0, numb;
	for (x = 0; x < 2; x++)
	{
		srand(time(0));
		while ((a == b) || (c == d))
		{
			a = rand() % 4;
			b = rand() % 4;
			c = rand() % 4;
			d = rand() % 4;
		}
		numb = (rand() % 2) + 1;
		board[a][b] = numb;
		numb = (rand() % 2) + 1;
		board[c][d] = numb;
	}
}

void mainrandom()//to generate the random tiles after a valid move
{
	bool chuck = 0;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (chucky[x][y] != board[x][y])//checks if the board was changed in any way
			{
				chuck = 1;//if so,then it gives the greenlight to generate the random number
			}
		}
	}
	int i, j;
	srand(time(0));
	i = rand() % 4;
	j = rand() % 4;
	while ((board[i][j] != 0))//to make sure that the random is only generated in an empty space
	{
		i = rand() % 4;
		j = rand() % 4;
	}
	if (chuck == 1)
	{
		board[i][j] = (rand() % 2) + 1;
	}
	display();//to display the board after every turn
}

void endgame()//check=1 to keep playing
			  //check=2 to win
			  //check=0 to lose
{
	bool validation1 = 0, validation2 = 0;
	int x, y, count = 0, count2 = 0;
	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
		{
			if (board[x][y] == 0)//to check if there is any space left in the board
			{
				count++;
			}

		}
	}
	if (count == 0)
	{
		validation1 = 1; //one of the 2 conditions for losing is fulfilled
	}




	for (x = 0; x < 4; x++)// this is to check whether any matching tiles are next to each other
	{
		for (y = 0; y < 4; y++)
		{
			if ((x != 0) && (x != 3) && (y != 0) && (y != 3))
			{
				if ((board[x][y] == board[x + 1][y]) || (board[x][y] == board[x - 1][y]) || (board[x][y] == board[x][y + 1]) || (board[x][y] == board[x][y - 1]))
				{
					count2++;
				}
			}
			else if (x == 0 && y == 0)
			{
				if ((board[x][y] == board[x + 1][y]) || (board[x][y] == board[x][y + 1]))
				{
					count2++;
				}
			}
			else if (x == 0 && y == 3)
			{
				if ((board[x][y] == board[x][y - 1]) || (board[x][y] == board[x + 1][y]))
				{
					count2++;
				}
			}
			else if (x == 3 && y == 0)
			{
				if ((board[x][y] == board[x][y + 1]) || (board[x][y] == board[x - 1][y]))
				{
					count2++;
				}
			}
			else if (x == 3 && y == 3)
			{
				if ((board[x][y] == board[x - 1][y]) || (board[x][y] == board[x][y - 1]))
				{
					count2++;
				}
			}


		}

	}
	if (count2 == 0)
	{
		validation2 = 1;// second condition is fulfilled
	}
	if (validation1 == 1 && validation2 == 1)// checks if both conditions are fulfilled
	{
		check = 0;//if fulfilled then you loser
	}
	for (x = 0; x < 4; x++)
	{
		for (y = 0; y < 4; y++)
		{
			if (board[x][y] == 1024)//checks if any of the tiles contains 1024
			{
				check = 2;//if so, then you winner
			}
		}
	}

}

void right()
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			chucky[x][y] = board[x][y];//at the start of the move, we'll save the array,so we can compare it later 
		}
	}
	int sum;
	//for sum
	for (int x = 0; x < 4; x++)
	{
		int i = x;
		for (int y = 3; y > -1; y--)
		{
			if ((board[x][y] == board[x][y - 1]) && (y != 0))
			{

				sum = board[x][y] + board[x][y - 1];
				board[x][y] = sum;
				board[x][y - 1] = 0;
			}
			else if ((board[x][y] == board[x][y - 2]) && (board[x][y - 1] == 0) && (y > 1) && (x == i))
			{
				sum = board[x][y] + board[x][y - 2];
				board[x][y] = sum;
				board[x][y - 2] = 0;
				break;
			}
			else if ((board[x][y] == board[x][y - 3]) && (board[x][y - 1] == 0) && (board[x][y - 2] == 0) && (y == 3) && (x == i))
			{
				sum = board[x][y] + board[x][y - 3];
				board[x][y] = sum;
				board[x][y - 3] = 0;
				break;
			}
		}
	}
	//for swiping
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			for (int z = 3; z > 0; z--)
			{
				if (board[x][z] == 0 && board[x][z - 1] != 0)
				{
					board[x][z] = board[x][z - 1];

					board[x][z - 1] = 0;
				}
			}
		}
	}
	mainrandom();
	endgame();
}

void left()
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			chucky[x][y] = board[x][y];//at the start of the move, we'll save the array,so we can compare it later
		}
	}
	int sum;
	//for sum
	for (int x = 0; x < 4; x++)
	{

		for (int y = 0; y < 4; y++)
		{
			if ((board[x][y] == board[x][y + 1]) && (y < 3))
			{
				sum = board[x][y] + board[x][y + 1];
				board[x][y] = sum;
				board[x][y + 1] = 0;

			}
			else if ((board[x][y] == board[x][y + 2]) && (board[x][y + 1] == 0) && (y < 2))
			{
				sum = board[x][y] + board[x][y + 2];
				board[x][y] = sum;
				board[x][y + 2] = 0;
				break;
			}
			else if ((board[x][y] == board[x][y + 3]) && (board[x][y + 1] == 0) && (board[x][y + 2] == 0) && (y < 1))
			{
				sum = board[x][y] + board[x][y + 3];
				board[x][y] = sum;
				board[x][y + 3] = 0;
				break;
			}
		}
	}
	//for swiping
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{

			for (int z = 0; z < 3; z++)
			{
				if (board[x][z] == 0 && board[x][z + 1] != 0)
				{
					board[x][z] = board[x][z + 1];
					board[x][z + 1] = 0;
				}
			}
		}
	}
	mainrandom();
	endgame();
}


void up()
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			chucky[x][y] = board[x][y];//at the start of the move, we'll save the array,so we can compare it later
		}
	}
	int sum;
	//for sum
	for (int x = 0; x < 4; x++)
	{

		for (int y = 0; y < 4; y++)
		{
			if ((board[x][y] == board[x + 1][y]) && (x < 3))
			{
				sum = board[x][y] + board[x + 1][y];
				board[x][y] = sum;
				board[x + 1][y] = 0;

			}
			else if ((board[x][y] == board[x + 2][y]) && (board[x + 1][y] == 0) && (x < 2))
			{
				sum = board[x][y] + board[x + 2][y];
				board[x][y] = sum;
				board[x + 2][y] = 0;
				break;
			}
			else if ((board[x][y] == board[x + 3][y]) && (board[x + 1][y] == 0) && (board[x + 2][y] == 0) && (x < 1))
			{
				sum = board[x][y] + board[x + 3][y];
				board[x][y] = sum;
				board[x + 3][y] = 0;
				break;
			}
		}
	}
	//for swiping
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			for (int z = 0; z < 3; z++)
			{
				if (board[z][y] == 0 && board[z + 1][y] != 0)
				{

					board[z][y] = board[z + 1][y];

					board[z + 1][y] = 0;
				}
			}
		}
	}
	mainrandom();
	endgame();
}

void down()
{
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			chucky[x][y] = board[x][y];//at the start of the move, we'll save the array,so we can compare it later
		}
	}
	int sum;
	//for sum
	for (int x = 3; x > -1; x--)
	{
		for (int y = 0; y < 4; y++)
		{
			if ((board[x][y] == board[x - 1][y]) && (x > 0))
			{

				sum = board[x][y] + board[x - 1][y];
				board[x][y] = sum;
				board[x - 1][y] = 0;

			}
			else if ((board[x][y] == board[x - 2][y]) && (board[x - 1][y] == 0) && (x > 1))
			{
				sum = board[x][y] + board[x - 2][y];
				board[x][y] = sum;
				board[x - 2][y] = 0;
			}
			else if ((board[x][y] == board[x - 3][y]) && (board[x - 1][y] == 0) && (board[x - 2][y] == 0) && (x == 3))
			{
				sum = board[x][y] + board[x - 3][y];
				board[x][y] = sum;
				board[x - 3][y] = 0;
			}
		}
	}
	//for swiping
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			for (int z = 3; z > 0; z--)
			{
				if (board[z][y] == 0 && board[z - 1][y] != 0)
				{
					board[z][y] = board[z - 1][y];
					board[z - 1][y] = 0;
				}
			}
		}
	}
	mainrandom();
	endgame();
}


int main()
{
	check = 1;
	char choice;
	firstrandom();
	display();
	while (check == 1)
	{
		cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "Enter a direction" << '\t';
		cin >> choice;
		while (choice != 'w' && choice != 'W' && choice != 'A' && choice != 'a' && choice != 's' && choice != 'S' && choice != 'D' && choice != 'd')//to make sure that user doesn't enter invalid key
		{
			cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "Invalid Direction Entered!!!" << endl;
			cout << '\t' << '\t' << '\t' << '\t' << '\t' << '\t' << "Enter again" << '\t';
			cin >> choice;
		}
		if ((choice == 'w') || (choice == 'W'))// to make sure that the directions work both for upper and lower case
		{
			up();
		}
		else if ((choice == 'a') || (choice == 'A'))// to make sure that the directions work both for upper and lower case
		{
			left();
		}
		else if ((choice == 's') || (choice == 'S'))// to make sure that the directions work both for upper and lower case
		{
			down();
		}
		else if ((choice == 'd') || (choice == 'D'))// to make sure that the directions work both for upper and lower case
		{
			right();
		}
	}
	if (check == 0)
	{
		cout << '\t' << '\t' << '\t' << '\t' << '\t' << "  " << "  " << "  " << "YOU LOSE HEHE" << endl;
	}
	else if (check == 2)
	{
		cout << '\t' << '\t' << '\t' << '\t' << '\t' << "  " << "  " << "  " << "YOU HAVE SUCCESSFULLY WASTED TIME";
	}
	system("pause");
	return 0;
}