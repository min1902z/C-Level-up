#include <iostream>
using namespace std;
 
template<class T>
class Stack {
private:
    int Size;
    int Top;
    T *Data;
public:
    Stack(int = 10);
    ~Stack();
    bool Push(const T&);
    bool Pop(T&);
    bool isEmpty() const;
    bool isFull() const;
};
 
template<class T>
Stack<T> ::Stack(int n) {
    if (n > 0 && n < 1000)
        Size = n;
    else
        Size = 10;
    Top = -1;
    Data = new T[Size];
}
 
template<class T>
Stack<T> ::~Stack() {
    delete[] Data;
}
/******************************
* Function name: Push()
* Description:  push item to stack
* Parameter: Item	
* Return value: boolean
*******************************/ 
template<class T>
bool Stack<T> ::Push(const T& Item) {
    if (!isFull()) {
        Top++ ;
        Data[Top] = Item;
        
        return true;
    }
    return false;
}
/******************************
* Function name: Pop()
* Description: print out stack item
* Parameter: Item	
* Return value: boolean
*******************************/
template<class T>
bool Stack<T> ::Pop(T& Item) {
    if (!isEmpty()) {
        Item = Data[Top];
        Top--;
        return true;
    }
    return false;
}
/******************************
* Function name: isEmpty()
* Description: check empty Stack
* Parameter: 	
* Return value: boolean
*******************************/ 
template<class T>
bool Stack<T>::isEmpty() const{
    if (Top == -1)
        return true;
    return false;
}
/******************************
* Function name: isFull()
* Description: check full Stack
* Parameter: 	
* Return value: boolean
*******************************/
template<class T>
bool Stack<T>::isFull() const {
    if (Top == Size)
        return true;
    return false;
}
 
int main() {
    Stack<int> st(100);
    
    st.Push(1);
    st.Push(2);
    st.Push(3);
    st.Push(4);
    st.Push(5);
    st.Push(6);
    st.Push(7);
    int data;
    
    while (st.Pop(data) ){
        cout << data << endl;
    }
}
