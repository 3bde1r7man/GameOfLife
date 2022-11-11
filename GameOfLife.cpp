#include "GameOfLife.h"

GameOfLife::GameOfLife()
{
	v = vector<vector<int>>(SIZE1, vector<int>(SIZE1, 0));
	
}

void GameOfLife::initialize()
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

void GameOfLife::display()
{
	Sleep(2000);
	system("cls");
	for (int i = 0; i < SIZE1; i++)
	{
		for (int j = 0; j < SIZE1; j++)
		{
			cout << v[i][j] << ' ';
		}
		cout << '\n';
	}
}

void GameOfLife::reset()
{
	v = vector<vector<int>>(SIZE1, vector<int>(SIZE1, 0));
}

void GameOfLife::count_neighbors()
{
	int count = 0;
	vector<vector<int>> vec2(SIZE1, vector<int>(SIZE1, 0));
	for (int i = 0; i < SIZE1; i++)
	{
		for (int j = 0; j < SIZE1; j++)
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
			if (i != SIZE1 - 1 && j != SIZE1 - 1) { //to avoid last row && last col error
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
			if (i != 0 && j != SIZE1 - 1) { //to avoid common row or column palces
				if (v[i - 1][j + 1] == 1) {
					count++;
				}
			}
			if (j != 0 && i != SIZE1 - 1) { //to avoid common row or column palces
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

void GameOfLife::next_generation(int gen )
{
	display();
	initialize();
	for (int i = 0; i < gen; i++)
	{
		count_neighbors();
		display();
	}
}

void GameOfLife::run()
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
