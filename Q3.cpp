#include <iostream>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
bool leapYear(int nYear);
int numberOfMonth(int nMonth, int nYear);
bool checkDay(int nDay, int nMonth, int nYear);
void previousDay(int& nDay, int& nMonth, int& nYear);
void nextDay(int& nDay, int& nMonth, int& nYear);
int main(int argc, char** argv) {
	int nDay, nMonth, nYear;
	cout << "CALENDAR\n\n";
	do
	{
	cout << "Day: ";
	cin >> nDay;

	cout << "Month: ";
	cin >> nMonth;

	cout << "Year: ";
	cin >> nYear;
	}while(!checkDay(nDay, nMonth, nYear));
	
	while(true){
	cout << "\n================MENU================\n";
	cout << "1. Find the number of month\n";
	cout << "2. Show next day (dd/mm/yyyy)\n";
	cout << "3. Show previous next day (dd/mm/yyyy)\n";	
	cout << "4. Quit\n";
	int n;
	cout << "Select your choice: ";
	cin >> n;
	int tmpDay = nDay;
	int tmpMonth = nMonth;
	int tmpYear = nYear;
	switch (n)
	{
	case 1:
		cout << "The number of month: " << numberOfMonth(tmpMonth, tmpYear);
		break;
	case 2:
		nextDay(tmpDay, tmpMonth, tmpYear);
		cout << "Tomorrow: " << tmpDay << " / " << tmpMonth << " / " << tmpYear << endl;
		break;
	case 3:
		previousDay(tmpDay, tmpMonth, tmpYear);
		cout << "Yesterday: " << tmpDay << " / " << tmpMonth << " / " << tmpYear << endl;
		break;
	case 4:
		exit(1);
		break;
	default:
		cout << "Your choice is not valid!";
	}
	}
	return 0;
}
bool leapYear(int nYear)
{
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		return true;
	}
	return false;
}
int numberOfMonth(int nMonth, int nYear)
{
	int nNumOfDays;

	switch (nMonth)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12: 
		nNumOfDays = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11: 
		nNumOfDays = 30;
		break;
	case 2:
		if (leapYear(nYear))
		{
			nNumOfDays = 29;
		}
		else
		{
			nNumOfDays = 28;
		}
		break;
	}

	return nNumOfDays;
}
bool checkDay(int nDay, int nMonth, int nYear)
{
	bool bResult = true; 

	if (!(nYear > 0 && nMonth))
	{
		bResult = false; 
	}

	if (!(nMonth >= 1 && nMonth <= 12))
	{
		bResult = false; 
	}

	if (!(nDay >= 1 && nDay <= numberOfMonth(nMonth, nYear)))
	{
		bResult = false; 
	}

	return bResult; 
}
void previousDay(int& nDay, int& nMonth, int& nYear)
{
	nDay--;
	if (nDay == 0)
	{
		nMonth--;
		if (nMonth == 0)
		{
			nMonth = 12;
			nYear--;
		}

		nDay = numberOfMonth(nMonth, nYear);
	}
}
void nextDay(int& nDay, int& nMonth, int& nYear)
{
	nDay++;
	if (nDay > numberOfMonth(nMonth, nYear))
	{
		nDay = 1;
		nMonth++;
		if (nMonth > 12)
		{
			nMonth = 1;
			nYear++;
		}
	}
}

