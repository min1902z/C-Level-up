#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n,i,j,s;
	cout << "Enter n: ";
	cin >> n;
	for(i = 1; i <= n; i++){
		for(j = i; j < n; j++)
		cout << " ";
		for(s = 1; s <= (2*i -1); s++)
		cout << "*";
		cout << "\n";
	}
	for(i = n - 1; i >= 1; i--){
		for(j = i; j < n; j++)
		cout << " ";
		for(s = 1; s <= (2*i -1); s++)
		cout << "*";
		cout << "\n";
	}
	return 0;
}
