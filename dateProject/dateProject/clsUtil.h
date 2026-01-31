#pragma once
#include <iostream>
#include <ctime>
#include<vector>
#include <sstream>
#include <cstdlib> 
#include "Date.h";
using namespace std;



class clsUtil
{
public:
	enum enCharType {
		small = 1, capital = 2, special = 3, digit = 4, mix = 5
	};

	static void initRandom() {
		srand((unsigned)time(NULL));
	}

	static int randomNum(int from, int to) {
		int n = rand() % (to - from) + from;
		return n;
	}

	static char getRandomChar(enCharType type) {
		if (type == mix) {
			type = (enCharType)randomNum(1, 3);
		}

		switch (type)
		{
		case clsUtil::small:
			return char(randomNum(97, 122));
			break;
		case clsUtil::capital:
			return char(randomNum(65, 90));
			break;
		case clsUtil::special:
			return char(randomNum(33, 47));
			break;
		case clsUtil::digit:
			return char(randomNum(48, 57));
			break;
		default:
			return char(randomNum(65, 90));
			break;
		}

	}

	static string generateWord(enCharType type, int length) {
		string s = "";

		for (int i = 0; i < length; i++) {
			s += getRandomChar(type);
		}

		return s;

	}

	static string generateKey(enCharType type=capital) {
		string s = "";
		s += generateWord(type, 4) + "_";
		s += generateWord(type, 4) + "_";
		s += generateWord(type, 4) + "_";
		s += generateWord(type, 4) ;

		return s;
	}

	static void generateKeys(enCharType type, int num) {
		for (int i = 0; i < num; i++) {
			cout << " [ " << i + 1 << " ] : ";
			cout << generateKey(type);
		}
	}

	static void fillArrayWithRandomNumber(int arr[100], int len, int from, int to) {
		for (int i = 0; i < len; i++) {
			arr[i] = randomNum(from, to);
		}
	}
	static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = generateWord(CharType, Wordlength);

	}

	static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = generateKey(CharType);
	}

	static void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	static void swap(double& a, double& b) {
		double temp = a;
		a = b;
		b = temp;
	}
	static void swap(float& a, float& b) {
		float temp = a;
		a = b;
		b = temp;
	}

	static  void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static  void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;
	}

	static void shuffleArray(int arr[100], int length) {

		for (int i = 0; i < length; i++) {
			swap(arr[randomNum(1, length) - 1], arr[randomNum(1, length) - 1]);
		}

	}

	static  void ShuffleArray(string arr[100], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[randomNum(1, arrLength) - 1], arr[randomNum(1, arrLength) - 1]);
		}

	}


	static string tap(short numOfTaps) {
		string t = "";
		for (int i = 0; i < numOfTaps; i++) {
			t += "\t";
		}
		return t;
	}

	static string encryptText(string text, short encryptionKey) {
		for (int i = 0; i < text.length(); i++) {
			text[i] = char((int)text[i] + encryptionKey);
		}
		return text;
	}

	static string decryptText(string text, short encryptionKey) {
		for (int i = 0; i < text.length(); i++) {
			text[i] = char((int)text[i] - encryptionKey);
		}
		return text;
	}









};

