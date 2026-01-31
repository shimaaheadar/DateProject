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


};

