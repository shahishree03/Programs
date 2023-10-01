#include<iostream>
using namespace std;
int main()
{
int first , second, *p, *q;
cout<<"Enter your   number to add\n";
cin>>first>>second;

p =&first;
q=&second;

first= *p+*q;
cout<<first;


}