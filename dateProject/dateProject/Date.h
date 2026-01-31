#pragma once
#pragma warning(disable : 4996) 
#include <iostream>
#include <ctime>
#include<vector>
#include <sstream>
using namespace std;


class Date
{
private:
	int year, month, day;

	vector<string> split(string s, string delim = " ") {
		vector<string> v;
		int pos = 0;
		string sword;
		while ((pos = s.find(delim)) != std::string::npos) {
			sword = s.substr(0, pos);
			if (sword != "") {
				v.push_back(sword);
			}
			s.erase(0, pos + delim.length());
		}
		if (s != "") {
			v.push_back(s);
		}
		return v;
	}

public:
	static Date GetSystemDate() {
		Date d;
		time_t t = time(0);
		tm* now = localtime(&t);
		d.year = now->tm_year + 1900;
		d.month = now->tm_mon + 1;
		d.day = now->tm_mday;

		return d;
	}
	Date () {
		time_t t = time(0);
		tm* now = localtime(&t);
		year = now->tm_year+1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;
	}
	Date(int y, int m, int d) {
		year = y;
		month = m;
		day = d;
	}
	Date(string d) {
		vector <string> v = split(d,"/");
		day = stoi(v[0]);
		month = stoi(v[1]);
		year = stoi(v[2]);
	}

	static bool isLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}

	//return the date from the number of day from the bigging of the year

	static Date getDateFromDayOrderInTheYear(int d, int y) {
		int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int m = 1;
		for (int i : NumberOfDays) {
			if (i == 2&&isLeapYear(y)) {
				d -= i + 1;
			}
			else if (d > i) {
				d -= i;
				m++;
			}
			else
				break;
		}
		Date dd(y, m, d);

		return dd;
		
	}

	Date(int d, int y) {
		*this = getDateFromDayOrderInTheYear(d, y);
	}

	void print() {
		cout << day << "/" << month << "/" << year << endl;
	}
   static void print(Date d) {
		cout << d.day << "/" << d.month << "/" << d.year << endl;
	}

	static int numOfDaysInMonth(int m,int y) {
		int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		return (m==2)?  (isLeapYear(y)? 29:28)  : NumberOfDays[m - 1];
	}

	static bool isValidDate(Date d) {
		if (d.month > 12 || d.month < 1)
			return false;
		if (d.day > numOfDaysInMonth(d.month, d.year) || d.day < 1)
			return false;
		return true;

	}

	bool isValid()
	{
		return isValidDate(*this);
	}



	int numOfDaysInMonth() {
		return numOfDaysInMonth(month,year);
	}

	static string DateToString(Date Date)
	{
		return  to_string(Date.day) + "/" + to_string(Date.month) + "/" + to_string(Date.year);
	}

	string DateToString()
	{
		return  DateToString(*this);
	}

	static short NumberOfDaysInAYear(short Year)
	{
		return  isLeapYear(Year) ? 366 : 365;
	}

	short NumberOfDaysInAYear()
	{
		return  NumberOfDaysInAYear(year);
	}

	static short NumberOfHoursInAYear(short Year)
	{
		return  NumberOfDaysInAYear(Year) * 24;
	}

	short NumberOfHoursInAYear()
	{
		return  NumberOfHoursInAYear(year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return  NumberOfHoursInAYear(Year) * 60;
	}

	int NumberOfMinutesInAYear()
	{
		return  NumberOfMinutesInAYear(year);
	}

	static int NumberOfSecondsInAYear(short Year)
	{
		return  NumberOfMinutesInAYear(Year) * 60;
	}

	int NumberOfSecondsInAYear()
	{
		return  NumberOfSecondsInAYear();
	}


	static string MonthShortName(short MonthNumber)
	{
		string Months[12] =
		{
		 "Jan", "Feb", "Mar",
		 "Apr", "May", "Jun",
		 "Jul", "Aug", "Sep",
		 "Oct", "Nov", "Dec"
		};
		return (Months[MonthNumber - 1]);
	}

	string MonthShortName() {
		return MonthShortName(month);
	}

	
	static short indexNameOfTheDay(short Day, short Month, short Year)
	{
		short a, y, m;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		// Gregorian: 
		//0:sun, 1:Mon, 2:Tue...etc.  
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}

	short indexNameOfTheDay() {
		return indexNameOfTheDay(day, month, year);
	}

	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

		return arrDayNames[DayOfWeekOrder];
	}

	

	static void printMonthCalender(int y,int m) {
		int current = indexNameOfTheDay(1, m, y);
		int numOfDays = numOfDaysInMonth(m,y);

		printf("________________________________%s_______________________\n\n", MonthShortName(m).c_str());

		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int i ;
		for (i = 0; i < current; i++) {
			printf("     ");
		}
		for (int j = 1; j <= numOfDays; j++) {
			printf("%5d", j);
			if (++i == 7) {
				i = 0;
				cout << "\n";
			}
		}
		cout << "\n______________________________________________________________\n";

	}

	void printMonthCalender() {
		printMonthCalender(year, month);
	}

	static void printYearCalender(int y) {
		printf("\n_____________________________________\n\n");
		printf("                  calender %d\n",y);
		printf("\n_____________________________________\n\n");

		for (int i = 1; i < 13; i++) {
			printMonthCalender(y, i);
		}
	}

	void printYearCalender() {
		printYearCalender(year);
	}

	static short DaysFromTheBeginingOfTheYear(short d, short m, short y) {

		int days = 0;
		for (int i = 1; i < m; i++) {
			days += numOfDaysInMonth(i,y);
		}

		days += d;

		return days;

	}

	short DaysFromTheBeginingOfTheYear() {
		return DaysFromTheBeginingOfTheYear(day, month, year);
	}

	static void addDays(int d,int &dd,int &mm,int &y) {
		int days = d + DaysFromTheBeginingOfTheYear(dd, mm, y);
		y += days / 365;
		days = days % 365;

		int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		int m = 1;
		for (int i : NumberOfDays) {
			if (days > i) {
				days -= i;
				m++;
			}
			else
				break;
		}
		dd = days;
		mm = m;
		
	}

	void addDays(int d) {
		addDays(d, day, month, year);
	}

	static bool isDate1BeforDate2(Date d1, Date d2) {
		return (d1.year < d2.year) ? true :
			(d1.year == d2.year) ? ((d1.month < d2.month) ? true :
				(d1.month == d2.month) ? ((d1.day < d2.day) ? true :
					false) : false) : false;
	}

	bool isDate1BeforDate2(Date d2) {
		
		return isDate1BeforDate2(*this, d2);
	}
	static bool isDate1EqualDate2(Date d1, Date d2) {

		return (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day);

	}

	bool isDate1EqualDate2(Date d2) {
		return isDate1EqualDate2(*this, d2);
	}

	static bool isDate1AfterDate2(Date d1, Date d2) {
		return !(isDate1BeforDate2(d1, d2) && isDate1EqualDate2(d1, d2));
	}

	bool isDate1AfterDate2( Date d2) {
		return isDate1AfterDate2(*this, d2);
	}


	static bool IsLastDayInMonth(Date Date)
	{

		return (Date.day == numOfDaysInMonth(Date.month,Date.year));

	}

	bool IsLastDayInMonth()
	{

		return IsLastDayInMonth(*this);

	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}

	static void  SwapDates(Date& Date1, Date& Date2)
	{

		Date TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}

	static Date AddOneDay(Date Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date.month))
			{
				Date.month = 1;
				Date.day = 1;
				Date.year++;
			}
			else
			{
				Date.day = 1;
				Date.month++;
			}
		}
		else
		{
			Date.day++;
		}

		return Date;
	}



	void AddOneDay()

	{
		*this = AddOneDay(*this);
	}

	static int GetDifferenceInDays(Date d1, Date d2, bool IncludeEndDay = false) {

		int days = 0;
		short swapFlagValue = 1;

		if (!(isDate1BeforDate2(d1, d2))) {
			SwapDates(d1, d2);
			swapFlagValue = -1;
		}

		while (isDate1BeforDate2(d1, d2)) {
			days++;
			d1 = AddOneDay(d1);

		}

		return (IncludeEndDay) ? ++days * swapFlagValue : days * swapFlagValue;

	}

	int GetDifferenceInDays(Date d1) {
		return GetDifferenceInDays(d1, *this);
	}

	static short CalculateMyAgeInDays(Date DateOfBirth)
	{
		
		return GetDifferenceInDays(DateOfBirth,Date::GetSystemDate());
	}


	static short IsEndOfWeek(Date Date)
	{
		return  indexNameOfTheDay(Date.day, Date.month, Date.year) == 6;
	}

	short IsEndOfWeek()
	{
		return IsEndOfWeek(*this);
	}

	static bool IsWeekEnd(Date Date)
	{
		//Weekends are Fri and Sat
		short DayIndex = indexNameOfTheDay(Date.day, Date.month, Date.year);
		return  (DayIndex == 5 || DayIndex == 6);
	}

	bool IsWeekEnd()
	{
		return  IsWeekEnd(*this);
	}

	static bool IsBusinessDay(Date Date)
	{
		//Weekends are Sun,Mon,Tue,Wed and Thur

	   /*
		short DayIndex = DayOfWeekOrder(Date.Day, Date.Month, Date.Year);
		return  (DayIndex >= 5 && DayIndex <= 4);
	   */

	   //shorter method is to invert the IsWeekEnd: this will save updating code.
		return !IsWeekEnd(Date);

	}

	bool IsBusinessDay()
	{
		return  IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(Date Date)
	{
		return 6 - indexNameOfTheDay(Date.day, Date.month, Date.year);
	}

	short DaysUntilTheEndOfWeek()
	{
		return  DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(Date Date1)
	{

		Date EndOfMontDate;
		EndOfMontDate.day = numOfDaysInMonth(Date1.month, Date1.year);
		EndOfMontDate.month = Date1.month;
		EndOfMontDate.year = Date1.year;

		return GetDifferenceInDays(Date1, EndOfMontDate, true);

	}

	short DaysUntilTheEndOfMonth()
	{
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(Date Date1)
	{

		Date EndOfYearDate;
		EndOfYearDate.day = 31;
		EndOfYearDate.month = 12;
		EndOfYearDate.year = Date1.year;

		return GetDifferenceInDays(Date1, EndOfYearDate, true);

	}

	short DaysUntilTheEndOfYear()
	{
		return  DaysUntilTheEndOfYear(*this);
	}





	

};

