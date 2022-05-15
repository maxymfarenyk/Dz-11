#include "Pool.h"

Pool::Pool()
{
	day = 0;
	hour = 0;
	people = 0;
}

Pool::Pool(int _day, int _hour, int _people)
{
	day = _day;
	hour = _hour;
	people = _people;
}

int Pool::GetDay()
{
	return day;
}

int Pool::GetHour()
{
	return hour;
}

int Pool::GetPeople()
{
	return people;
}

istream& operator>>(istream& in, Pool& p)
{
	in >> p.day >> p.hour >> p.people;
	return in;
}

ostream& operator<<(ostream& out, Pool& p)
{
	out << p.day << ", " << p.hour << ", " << p.people << endl;
	return out;
}
