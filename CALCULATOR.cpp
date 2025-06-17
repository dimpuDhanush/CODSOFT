#include <iostream>
using namespace std;
int main() {
    int a, b;
    char operation;
    cout<<"enter first number : ";
    cin>>a;
    cout<<"enter second number : ";
    cin>>b;
    cout<<"enter the operation to be performed (+,-,*,/) : ";
    cin>>operation;
    switch(operation){
case '+':
    cout<<"sum of two numbers is "<<a+b<<endl;
    break;
case '-':
    cout<<"difference between two numbers is "<<a-b<<endl;
    break;
case '*':
    cout<<"product of two numbers is "<<a*b<<endl;
    break;
case '/':
    if(b==0){
        cout<<"division cannot be performed with denominator 0";
    }
    else{
        cout<<"division of two numbers is "<<(float)a/b<<endl;
    }
    break;
default:
    cout<<"operation is invalid";


    }

    return 0;
}
