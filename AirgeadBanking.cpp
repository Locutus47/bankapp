#include "AirgeadBanking.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

//Converts our floating points currency format, 2 places after the decimal
//this gives us the ability without using additional libraries
string to_string1(double a_value)
{
	ostringstream out;
	out << fixed << setprecision(2) << a_value;
	return out.str();
}

void AirgeadBanking::setInitAmount()
	{
		
         cout << "How much do you plan to initially invest? ";
		 cin >> m_initAmount;
		 

	}

void AirgeadBanking::setMonthContrib()
{
	cout << "How much do you plan to contribute each month? ";
	cin >> m_monthlyContrib;
}

void AirgeadBanking::setNumYears()
{
	cout << "How many years do you plan to invest? ";
	cin >> m_numYears;
	m_numMonths = m_numYears * 12;
}
void AirgeadBanking::setInterestRate()
{
	cout << "What is the desired interst rate? ";
	cin >> m_interestRate;
}
void AirgeadBanking::calculateInvestments()
{
	/*
		We are using a monthly calculation rather than a yearly one.
		This allows for future portability such as generating a monthly
		statement.
	*/
	unsigned int i;
	double interest;
	double openingBal;
	double closingBal;
	double totalInterest=0;
	//the first opening balance needs to be calculated outside the loop
	openingBal = m_initAmount + m_monthlyContrib;
	for (i = 0; i < m_numMonths; ++i) {
		//put the opening balance into the vector
		m_monthOpen.push_back(openingBal);
		//monthly  interest rate calcuation
		interest = ((openingBal) * ((m_interestRate / 100)/12));
		//interest each month
		totalInterest += interest;
		m_totalInterest.push_back(totalInterest);
		m_monthinterest.push_back(interest);
		//the balance at the end of the month
		closingBal = (openingBal + interest);
		//	closingBal = (openingBal + interest + m_monthlyContrib);
			m_monthClose.push_back(closingBal);
		//	cout << monthClose.at(i) << endl;
			//The next month's opening balance is the same as this one's close
			openingBal = closingBal + m_monthlyContrib;
			closingBal = 0; //reset closeBal to prevent errors

	}

}


void AirgeadBanking::displayYearlyInt()
{
	
	unsigned int i;
	cout << "--------------------------------------------------------------" << endl;;
	cout << "Year\tYear End Balance\tTotal Interest Earned:" << endl;
	for (i = 1; i <= m_numYears; i++) {
		
			

		

		cout << fixed << setprecision(2)<< i << "\t" << m_monthClose.at((i * 12) - 1)<< "\t\t\t" << 
			m_totalInterest.at((i * 12) - 1) << endl;
	}
	


}void AirgeadBanking::displayReports()
{
	displayYearlyInt();
	//clear vectors
	m_monthClose.clear();
	m_totalInterest.clear();
	m_monthinterest.clear();
	m_monthOpen.clear();
	//reset contribution to 0
	m_monthlyContrib = 0;
	//rerun the calcuations
	calculateInvestments();
	displayYearlyNoInt();
}  


void AirgeadBanking::displayYearlyNoInt()
{

	unsigned int i;
	cout << "--------------------------------------------------------------" << endl;;
	cout << "Year\tYear End Balance\tTotal Interest Earned:" << endl;
	for (i = 1; i <= m_numYears; i++) {





		cout << fixed << setprecision(2) << i << "\t" << m_monthClose.at((i * 12) - 1) << "\t\t\t" <<
			m_totalInterest.at((i * 12) - 1) << endl;
	}
}