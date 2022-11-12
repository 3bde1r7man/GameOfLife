#include "GameOfLife.h"

Universe::Universe()
{
	v = vector<vector<int>>(SIZE, vector<int>(SIZE, 0));
	
}

Universe::~Universe() {
	cout << "\n\n Please go check board.txt to see the board clearly\n";
}

void  Universe::initialize()
{
	int point, x{}, y{}; 
	cout << "PLease enter how many points you want to choose: ";
	cin >> point;
	for (int i = 0; i < point; i++)
	{
		int p = 0;
		while (!p)
		{
			cout << "please enter the point x and y from (0 , 19): ";
			cin >> x >> y;
			if (x < 20 && x >= 0 && y < 20 && y >= 0) {
				v[x][y] = 1;
				p = 1;
			}
			else
			{
				cout << "invalid input try again!!\n";
			}
		}
	}
}

void  Universe::display()
{
	fstream boardFile;
	boardFile.open("board.txt", ios::app);
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			cout << v[i][j] << ' ';
			boardFile << v[i][j] << ' ';
		}
		cout << '\n';
		boardFile << '\n';
	}
	boardFile << "---------------------------------------------------------------------------\n";
	cout << "---------------------------------------------------------------------------\n";
	boardFile.close();
}

void  Universe::reset()
{
	v = vector<vector<int>>(SIZE, vector<int>(SIZE, 0));
}

void  Universe::count_neighbors()
{
	int count = 0;
	vector<vector<int>> vec2(SIZE, vector<int>(SIZE, 0));
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			count = 0;
			if (i != 0 && j != 0) { //to avoid the 1st row && 1st col error
				if (v[i - 1][j] == 1) {
					count++;
				}
				if (v[i - 1][j - 1] == 1) {
					count++;
				}
				if (v[i][j - 1] == 1) {
					count++;
				}
			}
			if (i != SIZE - 1 && j != SIZE - 1) { //to avoid last row && last col error
				if (v[i + 1][j] == 1) {
					count++;
				}
				if (v[i + 1][j + 1] == 1) {
					count++;
				}
				if (v[i][j + 1] == 1) {
					count++;
				}
			}
			if (i != 0 && j != SIZE - 1) { //to avoid common row or column palces
				if (v[i - 1][j + 1] == 1) {
					count++;
				}
			}
			if (j != 0 && i != SIZE - 1) { //to avoid common row or column palces
				if (v[i + 1][j - 1] == 1) {
					count++;
				}
			}
			if (v[i][j] == 1) {
				if (count > 3) {
					vec2[i][j] = 0;
				}
				else if (count == 2 || count == 3) {
					vec2[i][j] = 1;
				}
			}
			else
			{
				if (count == 3) {
					vec2[i][j] = 1;
				}
			}
		}
	}
	v = vec2;
}

void  Universe::next_generation(int gen )
{
	display();
	initialize();
	for (int i = 0; i < gen; i++)
	{
		count_neighbors();
		display();
	}
}

void Universe::run()
{
	int gen;
	cout << "How many generation you want to diplay: ";
	cin >> gen;
	next_generation(gen);
}

ostream& operator<<(ostream& out, vector<int> vec)
{
	out << vec;
	return out;
}
