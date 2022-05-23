#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class CFraction
{
	private: 
		int num;
		int den;
		
	public:
		void importFra(CFraction &fra);
		void showFra(CFraction fra);
		friend CFraction reduceFra(CFraction fra);		
		friend CFraction operator+ (const CFraction&, const CFraction&);
		friend CFraction operator- (const CFraction&, const CFraction&);
		friend CFraction operator* (const CFraction&, const CFraction&);
		friend CFraction operator/ (const CFraction&, const CFraction&);
};

int main(int argc, char** argv) {
	CFraction fra1,fra2;
	CFraction Sum,Sub,Mul,Div;
	
	cout << "\nEnter Fraction 1: ";
	fra1.importFra(fra1);
	cout << "\nEnter Fraction 2: ";
	fra1.importFra(fra2);
	
	cout << "\nSum = ";
	Sum = fra1+fra2;
	Sum = reduceFra(Sum);
	Sum.showFra(Sum);
	
	cout << "\nSub = ";
	Sub = fra1-fra2;
	Sub = reduceFra(Sub);
	Sub.showFra(Sub);
	
	cout << "\nMul = ";
	Mul = fra1*fra2;
	Mul = reduceFra(Mul);
	Mul.showFra(Mul);
	
	cout << "\nDiv = ";
	Div = fra1/fra2;
	Div = reduceFra(Div);
	Div.showFra(Div);
	return 0;
}

/******************************
* Function name: importFra()
* Description: import fraction
* Parameter: 
	fra (I) : fraction
* Return value: void
*******************************/
void CFraction::importFra(CFraction &fra)
{
	cout << "\nEnter numberator: "; 
	cin >> fra.num;
	do
	{
		cout << "\nEnter denominator: "; 
		cin >> fra.den;
		if(fra.den == 0)
			cout << "Error: Re-Enter denominator ";
	}while(fra.den == 0);
}

/******************************
* Function name: showFra()
* Description: show fraction
* Parameter: 
	fra (I) : fraction
* Return value: void
*******************************/
void CFraction::showFra(CFraction fra)
{
	cout << fra.num << "/" << fra.den;
}

/******************************
* Function name: operator+
* Description: fraction 1 + fraction 2
* Parameter: 
	const fra1 (I) : fraction 1
	const fra2 (I) : fraction 2
* Return value: result
*******************************/
CFraction operator+(const CFraction&fra1, const CFraction&fra2)
{
	CFraction result;
	result.num = fra1.num*fra2.den + fra1.den*fra2.num;
	result.den = fra1.den*fra2.den;
	return result;
}

/******************************
* Function name: operator-
* Description: fraction 1 - fraction 2
* Parameter: 
	const fra1 (I) : fraction 1
	const fra2 (I) : fraction 2
* Return value: result
*******************************/
CFraction operator-(const CFraction&fra1, const CFraction&fra2)
{
	CFraction result;
	result.num = fra1.num*fra2.den - fra1.den*fra2.num;
	result.den = fra1.den*fra2.den;
	return result;
}

/******************************
* Function name: operator*
* Description: fraction 1 * fraction 2
* Parameter: 
	const fra1 (I) : fraction 1
	const fra2 (I) : fraction 2
* Return value: result
*******************************/
CFraction operator*(const CFraction&fra1, const CFraction&fra2)
{
	CFraction result;
	result.num = fra1.num*fra2.num;
	result.den = fra1.den*fra2.den;
	return result;
}

/******************************
* Function name: operator/
* Description: fraction 1 / fraction 2
* Parameter: 
	const fra1 (I) : fraction 1
	const fra2 (I) : fraction 2
* Return value: result
*******************************/
CFraction operator/(const CFraction&fra1, const CFraction&fra2)
{
	CFraction result;
	result.num = fra1.num*fra2.den;
	result.den = fra1.den*fra2.num;
	return result;
}

/******************************
* Function name: ucln
* Description: greatest common divisor of a & b
* Parameter: 
	int a (I) : number 1
	int b (I) : number 2
* Return value: a
*******************************/
int ucln(int a, int b)
{
    while (b != 0)    {
        const int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

/******************************
* Function name: reduceFra
* Description: reduce fraction
* Parameter: 
	CFraction fra (I) : fraction
* Return value: result
*******************************/
CFraction reduceFra(CFraction fra)
{
	CFraction result;
    int divisor = ucln(fra.num, fra.den);
    result.num /= divisor;  
    result.den  /= divisor;
    return result;
}
