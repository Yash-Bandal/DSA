//top = index that is incre / decre to track pos -1 0 1 2 3 ....
#include <bits/stdc++.h>

using namespace std;
class Stack
{
    int size;
    int *arr;
    int top;

public:
    Stack()
    {
        top = -1;
        size = 1000;  //the disadvantage of array implementation (needs to assign extra space static)
        arr = new int[size];
    }
    void push(int x)
    {
        top++;
        arr[top] = x;
    }
    int pop()
    {
        int x = arr[top];
        top--;
        return x;
    }
    int Top()
    {
        return arr[top];
    }
    int Size()
    {
        return top + 1;
    }
};
int main()
{

    Stack s;
    s.push(6); // 6
    s.push(3); // 6 3
    s.push(7); // 6 3 7
    cout << "Top of stack is before deleting any element " << s.Top() << endl;
    cout << "Size of stack before deleting any element " << s.Size() << endl;
    cout << "The element deleted is " << s.pop() << endl;  //7 op..deleted
    cout << "Size of stack after deleting an element " << s.Size() << endl;
    cout << "Top of stack after deleting an element " << s.Top() << endl;
    return 0;
}
/*
basics :
    int arr1[5] = {1, 2, 3, 4, 5};    // Fixed array
    int *arr2 = new int[5];           // Dynamic array

    arr2[0] = 10;                     // Assigning values to dynamically allocated array

    cout << "arr1[0]: " << arr1[0] << endl;    //1
    cout << "arr2[0]: " << arr2[0] << endl;    //10  

    delete[] arr2; // Free heap memory
*/

/*
OP 
Top of stack is before deleting any element 7
Size of stack before deleting any element 3  
The element deleted is 7
Size of stack after deleting an element 2    
Top of stack after deleting an element 3  
*/

//Complete
#include <bits/stdc++.h>

using namespace std;

class Stack {
    int size;
    int* arr;
    int top;

public:
    Stack(int s = 1000) { // Default size is 1000, but can be customized
        top = -1;
        size = s;
        arr = new int[size];
    }

    ~Stack() { // Destructor to free memory
        delete[] arr;
    }

    void push(int x) {
        if (top == size - 1) {
            cout << "Stack Overflow! Cannot push " << x << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow! No elements to pop.\n";
            return -1;
        }
        int x = arr[top];
        top--;
        return x;
    }

    int Top() {
        if (top == -1) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return arr[top];
    }

    int Size() {
        return top + 1;
    }
};

int main() {
    Stack s(5); // Example stack with custom size 5

    s.push(6);
    s.push(3);
    s.push(7);
    cout << "Top of stack before deleting any element: " << s.Top() << endl;
    cout << "Size of stack before deleting any element: " << s.Size() << endl;
    cout << "The element deleted is: " << s.pop() << endl;
    cout << "Size of stack after deleting an element: " << s.Size() << endl;
    cout << "Top of stack after deleting an element: " << s.Top() << endl;

    // Testing underflow condition
    s.pop();
    s.pop();
    s.pop(); // Should print stack underflow error

    return 0;
}
