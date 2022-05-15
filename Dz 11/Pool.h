#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Pool
{
private:
	int day, hour, people;
public:
	Pool();
	Pool(int _day, int _hour, int _people);
	int GetDay();
	int GetHour();
	int GetPeople();
	friend istream& operator>>(istream& in, Pool& p);
	friend ostream& operator<<(ostream& out, Pool& p);
};

