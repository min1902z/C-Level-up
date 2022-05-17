#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float Plus(float a,float b);
float Minus(float a,float b);
float Multiply(float a,float b);
float Divide(float a, float b);
void operation(float a,float b, float (*p2Func)(float,float));
int main(int argc, char** argv) {
	float num1, num2;
	
	cout << "Enter number 1: ";
	cin >> num1;
	
	cout << "Enter number 2: ";
	cin >> num2;
	
	cout << "\nResult: " << endl;
	cout << "\nPlus= ";
	operation(num1, num2, Plus);
	cout << "\nMinus= ";
	operation(num1, num2, Minus);
	cout << "\nMultiply= ";
	operation(num1, num2, Multiply);
	cout << "\nDivide= ";
	operation(num1, num2, Divide);
	return 0;
}
/******************************
* Function name: Plus()
* Description: number 1 + number 2
* Parameter: 
	float a(I) : number 1
	float b(I) : number 2
* Return value: float
*******************************/
float Plus(float a,float b)
{
	return a+b;
}
/******************************
* Function name: Minus()
* Description: number 1 - number 2
* Parameter: 
	float a(I) : number 1
	float b(I) : number 2
* Return value: float
*******************************/
float Minus(float a,float b)
{
	return a-b;
}
/******************************
* Function name: Multiply()
* Description: number 1 x number 2
* Parameter: 
	float a(I) : number 1
	float b(I) : number 2
* Return value: float
*******************************/
float Multiply(float a,float b)
{
	return a*b;
}
/******************************
* Function name: Divide()
* Description: number 1 / number 2
* Parameter: 
	float a(I) : number 1
	float b(I) : number 2
* Return value: float
*******************************/
float Divide(float a, float b)
{
	return a/b;
}
/******************************
* Function name: Plus()
* Description: number 1 + number 2
* Parameter: 
	float a(I) : number 1
	float b(I) : number 2
	float *p2Func: pointer of operation
* Return value: void, result of operation
*******************************/
void operation(float a,float b, float (*p2Func)(float,float))
{
	float result = p2Func(a,b);
	cout << result << endl;
}
