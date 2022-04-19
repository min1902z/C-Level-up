#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int findPalindrome(int num){
	int temp = 0, n;
	temp=num;
	while(num != 0){
		temp = num % 10;
		n = (n * 10) + temp;
		num = num / 10;
	}
	return n;
}
int main(int argc, char** argv) {
	int num;
	cout << "Enter number: ";
	cin >> num;
	if(num == findPalindrome(num))
		cout << "Palindrome" << endl;
	else
		cout << "not Palindrome" << endl;	
	return 0;
}
