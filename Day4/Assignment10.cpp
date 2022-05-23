#include <iostream>
#include<string>
#include <cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class String
{
	public:
		char* str;
	public:
		friend String operator + (const String&, const String&);
		friend ostream& operator << (ostream&, String&);
		friend istream& operator >> (istream&, String&);
};
int main(int argc, char** argv) {
	String s1,s2,s3;
	cout << "\nEnter String 1: ";
	cin >> s1;
	cout << "\nEnter String 2: ";
	cin >> s2;
	
	cout << "\nResult: ";
	s3 = s1+s2;
	cout << s3;
	
	return 0;
}

/******************************
* Function name: operator +()
* Description: String 1 + String 2
* Parameter: 
	const String &s1 (O): String 1
	const String &s2 (I): String 2
* Return value: s1
*******************************/
String operator + (const String &s1, const String &s2)
{
	int i,j,n1,n2;
	n1 = strlen(s1.str);
	n2 = strlen(s2.str);
	j=0;
	for(i = n1; i < n1+n2; i++){
		s1.str[i] = s2.str[j];
		j++;
	}	 
	s1.str[i] = '\0';
	
	return s1;
}

/******************************
* Function name: operator <<()
* Description: print out string
* Parameter: 
	ostream& os (O) : output string
	String& obj (I) : input string
* Return value: os
*******************************/
ostream& operator << (ostream& os,String& obj)
{
    os << obj.str;
    return os;
}

/******************************
* Function name: operator >>()
* Description: input string
* Parameter: 
	istream& is (O) : output string inputed
	String& obj (I) : input string
* Return value: is
*******************************/
istream& operator >> (istream& is, String& obj)
{
	obj.str = new char[100];
	is >> obj.str;
	return is;
}


