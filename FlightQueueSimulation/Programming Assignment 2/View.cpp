// Programming Assignment 2
// Queue Simulation for XYZ Airlines
// Jacob Kapusta
// 2/25/2013

#include "Simulator.cpp"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void loadTest(string data[6]);
int main()
{
	string data_holder[6];
	loadTest(data_holder);
	Simulator test(atoi(data_holder[0].c_str()), atoi(data_holder[1].c_str()), atoi(data_holder[2].c_str()), atoi(data_holder[3].c_str()), atoi(data_holder[4].c_str()), data_holder[5]);
	
	test.simulate();

	system("pause");
	return 0;
}
void loadTest(string data[6])
{
	string temp;
	int i = 0;

	ifstream file;
	file.open("Programming Assignment 2 Data.txt");
	while(!file.eof())
	{
		getline(file, temp);
		data[i] = temp;
		i++;
	}
	i=0;
}
