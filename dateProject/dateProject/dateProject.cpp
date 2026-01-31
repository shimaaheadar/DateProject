#include <iostream>
#include <ctime>
#include<vector>
#include <sstream>
#include "Date.h";
using namespace std;


int main()
{
    Date d1;
    d1.print();

    Date d2(2025, 12, 15);

    cout<<d1.GetDifferenceInDays(d2)<<endl;
    
    Date myDate(2005, 8, 16);
    int age = Date::CalculateMyAgeInDays(myDate);
    cout << age<<endl;
   

    /*Date d2("5/1/2026");
    d2.print();

    Date d3(2030, 4, 22);
    d3.print();*/

    /*Date d4(125, 2024);
    d4.print();*/
    



}

