/*Airgead Banking App.cpp : This file contains the 'main' function. Program execution begins and ends there.
Programmer: Ryan Sanders
*/

#include <iostream>
#include "AirgeadBanking.h"
using namespace std;

int main()
{
    
    AirgeadBanking bank;
   

    bank.setInitAmount();
    bank.setNumYears();
    bank.setMonthContrib();
    bank.setInterestRate();
    bank.calculateInvestments();
    bank.displayReports();
}

