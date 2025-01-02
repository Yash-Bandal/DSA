/*Almost all same logic for recursion...especially stack..*/


//Brute
void SortedStack ::sort() {
    vector<int> arr;

    while (!s.empty()) {
        arr.push_back(s.top());
        s.pop();
    }
    std::sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size(); ++i) {
        s.push(arr[i]);
    }
}


//recursion
//use reference ..else error
void insertSorted(stack<int>&s,int element) { //note we cant use s stack directly ..as no '::'' used..thus pass from below
    // Base case: If stack is empty or element is greater than or equal to the top of the stack, push it
    if (s.empty() || s.top() <= element) {
        s.push(element);
        return;
    }

    // Otherwise, pop the top element..i
    int top = s.top();
    s.pop();

    // Recursively insert the element
    insertSorted(s,element);  //dont push top by mistake

    // After insertion, push the popped element back onto the stack
    s.push(top);
}

void SortedStack ::sort() {
    // Base case: if stack is empty, return
    if (s.empty()) {
        return;
    }

    // Step 1: Pop the top element
    int top = s.top();
    s.pop();

    // Step 2: Recursively sort the remaining stack
    sort();

    // Step 3: Insert the popped element back in the correct position
    insertSorted(s,top);
}
