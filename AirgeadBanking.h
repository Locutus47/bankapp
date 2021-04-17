
#ifndef AIRGEAD_BANKING_H
#define AIRGEAD_BANKING_H

#endif 

#include <vector>
#include<string>
using namespace std;
class AirgeadBanking
{
public:
	//basic mutator functions
	void setInterestRate();
	void setNumYears();
	void setInitAmount();
	void setMonthContrib();
	void displayInputs();
	//report generator, calls add't private functions
	void displayReports();
	//do all our math stuff
	void calculateInvestments();

protected:
	double m_interestRate;
	double m_initAmount;
	double m_monthlyContrib;
	double m_yearCloseBal;
	double m_yearCloseIntrst;

	unsigned int m_numYears;
	unsigned int m_numMonths;
	//vectors for our data, this may use more memory
	//but it gives the best chance of portability
	//and expandability
	vector<double> m_monthOpen = vector<double>();
	vector<double> m_monthClose = vector<double>();
	vector<double> m_monthinterest = vector<double>();
	vector<double> m_totalInterest = vector<double>();

private:
	void displayYearlyNoInt();
	void displayYearlyInt();


	

};

