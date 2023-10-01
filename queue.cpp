#include <iostream>
using namespace std;

class Queue {
private:
    char* arr;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size) {
        capacity = size;
        arr = new char[size];
        front = rear = -1;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    void push(char value) {
        if (isFull()) {
            cout << "Queue is full. Cannot push " << value << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
        cout << "PUSH: " << value << endl;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot pop." << endl;
            return '\0';
        }

        char value = arr[front];

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % capacity;
        }

        cout << "POP: " << value << endl;
        return value;
    }
};

int main() {
    const char* sequence = "EAS*Y*QUE***ST***IO***N***";
    int queueSize = 10; // Set an appropriate size for your queue

    Queue q(queueSize);

    for (int i = 0; sequence[i] != '\0'; i++) {
        if (sequence[i] == 'E') {
            q.push('E');
        } else if (sequence[i] == '*') {
            char poppedValue = q.pop();
            // You can use poppedValue as needed (in this example, it's not used)
        }
    }

    return 0;
}
