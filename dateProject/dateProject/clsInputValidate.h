#pragma once
#include <iostream>
#include <ctime>
#include<vector>
#include <sstream>
#include <cstdlib> 
#include "Date.h";
using namespace std;


class clsInputValidate
{
public:
	static bool IsNumberBetween(int num, int from, int to) {
		if (num >= from && num <= to)
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(float Number, float From, float To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		if (Number >= From && Number <= To)
			return true;
		else
			return false;
	}


	static bool IsDateBetween(Date date, Date From, Date To)
	{
		//Date>=From && Date<=To
		if ((Date::isDate1AfterDate2(date, From) || Date::isDate1EqualDate2(date, From))
			&&
			(Date::isDate1BeforDate2(date, To) || Date::isDate1EqualDate2(date, To))
			)
		{
			return true;
		}
		if ((Date::isDate1AfterDate2(date, To) || Date::isDate1EqualDate2(date, To))
			&&
			(Date::isDate1BeforDate2(date, From) || Date::isDate1EqualDate2(date, From))
			)
		{
			return true;
		}

		return false;
	};


	static int readIntNumber(string errorMessage = "Invalid Number, Enter again\n") {
		int num;
		while (!(cin >> num)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << errorMessage << endl;



		}
		return num;
	};

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		int Number = readIntNumber();

		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = readIntNumber();
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
	{
		double Number = ReadDblNumber();

		while (!IsNumberBetween(Number, From, To)) {
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}
		return Number;
	}

	static bool IsValideDate(Date Date)
	{
		return	Date::isValidDate(Date);
	}

};

