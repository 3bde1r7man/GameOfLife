#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <Windows.h>

using namespace std;



const int SIZE1 = 20;

class GameOfLife
{
protected:
	vector<vector<int>> v;
	
public:
	GameOfLife();
	void initialize();
	void display();
	void reset();
	void count_neighbors();
	void next_generation(int gen);
	void run();
	friend ostream& operator<<(ostream& out, vector<int> vec);
};




