#include <iostream>
#include <cstring>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int findsubstr(const char* str, char* sub);
int main(int argc, char** argv) {
	char str[] = "Chuoi Vu khong buon ngu a?" ;
	char sub1[] = "Chuoi";
	char sub2[] = "?";
	char sub3[] = "xXx";
	cout << "\nResult: " << findsubstr(str, sub2);
	return 0;
}
/******************************
* Function name: findsubstr()
* Description: find sub char 
* Parameter: 
	const char* str : parent char
	char* sub : sub char
* Return value: int
*******************************/
int findsubstr(const char* str, char* sub)
{
	int i, j;
	for(i=0; i < strlen(str); i++)
	{
		for(j=0; j < strlen(sub); j++)
		{
			if(str[i] == sub[j])
			{
				return i;
			}
		}
	}
	return -1;
}
