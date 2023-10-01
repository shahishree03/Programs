#include<iostream>

using namespace std;

class Queue{
private:
int capacity;
char *arr;
int front;
int rear;

public:
 Queue(int size)
 {
     this->capacity = size;
     this->arr= new char[size];
     this->front = rear-1;
 }
 
 ~Queue()
 {
     delete[] arr;
 }
 
 bool isFull()
 {
     return (rear+1)%capacity == front;
 }
 
 bool isEmpty()
 {
     return front == -1 ;
     
 }
 
 void push(char c)
 {
     if(isFull())
     {
         return;
     }
     if(isEmpty())
     {
         front = rear =0;
     }
     else
     {
         rear = (rear+1)%capacity;
     }
     arr[rear] =c; 
 }
 
 char pop()
    {
        if(isEmpty())
        {
            return '\0';
        }
        char poppedValue = arr[front]; 
        if(front == rear)
        {
            front = rear =-1;
        }
        else
        {
            front= (front+1)%capacity;
        }
        return poppedValue;
    }
};

int main()
{
    Queue qu(11);
    
    string seq= "EAS*Y*QUE***ST***IO*N***";
    for(char c:seq)
    {
        if(c>=65 && c<=90)
        {
            qu.push(c);
        }
        else if(c=='*')
        {
            char value = qu.pop();
            if(value!='\0'){
            cout<<"Popped value is "<<value<<endl;
        }
        }
    }
    
}