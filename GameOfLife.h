#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;



const int SIZE = 20;

class  Universe
{
protected:
	vector<vector<int>> v;
	
public:
	Universe();
	~Universe();
	void initialize();
	void display();
	void reset();
	void count_neighbors();
	void next_generation(int gen);
	void run();
	friend ostream& operator<<(ostream& out, vector<int> vec);
};




