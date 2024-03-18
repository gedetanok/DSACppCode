#include <iostream>
using namespace std;

class Stack {
public:
    int size = 0;
    int top = -1;
    char *items;

    Stack(int stackSize) {
        size = stackSize;
        items = new char[size];
    }

    void push(char item) {
        if (top == size - 1) {
            cout << "Stack overflow!" << endl;
        } 
        else {
            top++;
            items[top] = item;
        }
    }

    char pop() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return '\0'; // ngereturn karakter \0 ketika stack full
        } 
        else {
            char item = items[top];
            top--;
            return item;
        }
    }

    ~Stack() {
        delete[] items;
    }
};

int main() {
    Stack kantong1(5);

    kantong1.push('A');
    kantong1.push('B');

    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;
    cout << kantong1.pop() << endl;

    return 0;
}
