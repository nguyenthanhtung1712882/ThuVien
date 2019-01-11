#include "MyDate.h"



MyDate::MyDate()
{
}


bool isLeap(int year)
{
	if (year % 4 != 0)
		return false;
	else if (year % 400 == 0)
		return true;
	else if (year % 100 == 0)
		return false;
	else
		return true;
}

MyDate::MyDate(const char temp[])
{
	string str = temp;
	MyDate md;
	md.stringToDate(str);
	*this = md;
}

int MyDate::dateOfMonth(int month, int year)
{
	switch (month)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 2:
		if (isLeap(year) == true)return 29;
		else return 28;
	case 4: case 6: case 9: case 11:
		return 30;
	default:
		break;
	}
}


bool MyDate::isValid()
{
	if (this->year<0 || this->year>INT_MAX)
		return false;
	if (this->month < 1 || this->month>12)
		return false;
	if (this->date < 1 || this->date>this->dateOfMonth(this->month, this->year))
		return false;
	return true;
}

string MyDate::toString()
{
	string stringDate;
	if (this->date < 10)stringDate.append("0");
	stringDate.append(to_string(this->date));
	stringDate.append("/");
	if (this->month < 10)stringDate.append("0");
	stringDate.append(to_string(this->month));
	stringDate.append("/");
	stringDate.append(to_string(this->year));
	return stringDate;
}



int MyDate::countDate()
{
	int date = 0;
	if (this->year >= MIN_YEAR)
	{
		for (int i = MIN_YEAR; i < this->year; i++)
		{
			if (isLeap(i) == true)
				date += 366;
			else date += 365;
		}
		for (int i = 1; i < this->month; i++)
		{
			date += dateOfMonth(i, this->year);
		}
		date += this->date;
	}
	return date;
}

MyDate MyDate::dateAfter(int date)
{
	MyDate md;
	md.year = MIN_YEAR;
	md.month = 1;
	date += this->countDate();
	while (date > 365)
	{
		if (isLeap(md.year) == true)date -= 366;
		else date -= 365;
		md.year++;
	}
	while (date > dateOfMonth(md.month, md.year))
	{
		date -= dateOfMonth(md.month,md.year);
		md.month++;
	}
	md.date = date;
	return MyDate(md);
}

MyDate MyDate::dateBefore(int date)
{
	MyDate md;
	md.year = MIN_YEAR;
	md.month = 1;
	date = this->countDate() - date;
	while (date > 365)
	{
		if (isLeap(md.year) == true)date -= 366;
		else date -= 365;
		md.year++;
	}
	while (date > dateOfMonth(md.month, md.year))
	{
		date -= dateOfMonth(md.month, md.year);
		md.month++;
	}
	md.date = date;
	return MyDate(md);
}

string MyDate::dayOfWeek()
{
	// 01/01/1900 Monday => 31/12/1899 Sunday
	int day = this->countDate() % 7 - 1;
	string DAY[7] = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
	return DAY[day];
}



MyDate & MyDate::operator=(const MyDate & md)
{
	this->date = md.date;
	this->month = md.month;
	this->year = md.year;
	return *this;
	// TODO: insert return statement here
}

MyDate & MyDate::operator=(const string temp)
{
	MyDate md;
	md.stringToDate(temp);
	*this = md;
	return *this;
	// TODO: insert return statement here
}

MyDate & MyDate::operator=(const char s[])
{
	string temp = s;
	MyDate md;
	md.stringToDate(temp);
	*this = md;
	return *this;
	// TODO: insert return statement here
}

MyDate & MyDate::operator+(int date)
{
	MyDate md;
	md = this->dateAfter(date);
	return md;
	// TODO: insert return statement here
}

MyDate & MyDate::stringToDate(string temp)
{
	int pos = 0, pos1;
	pos1 = temp.find_first_of("/-.", pos);
	this->date = stoi(temp.substr(pos, pos1 - pos));
	pos = pos1 + 1;
	pos1 = temp.find_first_of("/-.", pos);
	this->month = stoi(temp.substr(pos , pos1 - pos));
	pos = pos1 + 1;
	pos1 = temp.find_first_of("/-.", pos );
	this->year = stoi(temp.substr(pos, pos1 - pos));
	return *this;
	// TODO: insert return statement here
}


MyDate::~MyDate()
{
}

int operator-(MyDate md1, MyDate md2)
{
	return md1.countDate()-md2.countDate();
}

ostream & operator<<(ostream & outDev, MyDate md)
{
	if (md.date < 10)outDev << "0";
	outDev << md.date << "/";
	if (md.month < 10)outDev << "0";
	outDev << md.month << "/";
	outDev << md.year;
	return outDev;
	// TODO: insert return statement here
}

istream & operator>>(istream & inDev, MyDate & md)
{
	do {
		cout << "Input (dd/mm/yyyy) : ";
		char ch;
		inDev >> md.date >> ch >> md.month >> ch >> md.year;
		if (md.isValid() == true)break;
		else cout << "Time error. Input again" << endl;
	} while (1);
	return inDev;
	// TODO: insert return statement here
}
