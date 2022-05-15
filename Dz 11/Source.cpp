#include <iostream>
#include<set>
#include<map>
#include <string>
#include<fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct Time {
	string day;
	double hour;
	Time() {
		day = " ";
		hour = 0.0;
	}
	Time(string _day, double _hour) {
		day = _day;
		hour = _hour;
	}

};
ostream& operator<<(ostream& out, Time a)
{
	out << a.hour << ":00";
	return out;
}

map <string, double>m;

bool compare(pair<string, Time> a, pair<string, Time> b) {
	return m[a.first] <m[b.first];
}


int main() {
	ifstream fin("data.txt");
	int n;
	fin >> n;
	string day;
	double hour;
	int people;
	m["monday"] = 0;
	m["tuesday"] = 1;
	m["wednesday"] = 2;
	m["thursday"] = 3;
	m["friday"] = 4;
	m["saturday"] = 5;
	m["sunday"] = 6;
	map<string, int>Pool1;
	map<string, vector<pair<Time, double>>>Pool2;
	for (int i = 0; i < n; i++) {
		fin >> day >> hour >> people;
		Pool1[day] += people;
		Pool2[day].push_back(make_pair(Time(day, hour), people));
	}
	vector<pair<string, Time>>days;
	for (auto it : Pool2) {
		Time res = it.second[0].first;
		if (!it.second.empty()) {
			days.push_back(make_pair(it.first, res));
		}
	}
	sort(days.begin(), days.end(), compare);
	ofstream fout("file1.txt");
	cout << "Data sorted by days of week:" << endl;
	for (int i = 0; i < days.size(); i++)
	{
		cout << days[i].first << ' ' << days[i].second << endl;
		fout << days[i].first << ' ' << days[i].second << endl;
	}
	for (int i = 0; i < Pool2.size(); i++)
	{
		cout << days[i].first << ' ' << days[i].second << endl;
		fout << days[i].first << ' ' << days[i].second << endl;
	}
	string result = " ";
	int max = 0;
	for (auto it : Pool1) {
		if (it.second > max) {
			max = it.second;
			result = it.first;
		}
	}
	ofstream out("file2.txt");
	out << result << endl;
	cout << "Day with the biggest amount of visitors:" << endl;
	cout << result << endl;
	return 0;
}