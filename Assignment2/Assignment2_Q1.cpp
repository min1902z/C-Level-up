#include <iostream>
#include <cstring>

using namespace std;

int* get_even_num(int* arr, int* even_sz){
	int* p = NULL;
	int count=0;
	for(size_t i = 1; i < arr[0]; i++){
		if(arr[i] % 2 == 0){
			(*even_sz)++;
		}		
	}
	p = new int[*even_sz];
	for(size_t i = 1; i <= arr[0]; i++ ){
		if(arr[i] % 2 == 0){
			p[count] = arr[i];
			count++;
		}	
	}		
	return p;
}
int main(int argc, char** argv) {
	int *arr = NULL;
	int *p = NULL;
	int sz;
	int e_sz = 1;
	
	cout << "Input size of array: ";
	cin >> sz;
	
	arr = new int[sz+1];
	if(arr){
	memset(arr, 0x00, sz*sizeof(int));
	arr[0] = sz;
	for(size_t i = 1; i < sz+1; i++){
		cout << "arr[" << i << "] = ";
		cin >> arr[i];
	}
	p = get_even_num(arr, &e_sz);
	cout << "Address of Even Array: " << p << endl;
		
	delete[] arr;
	}
	return 0;
}
