// #include <iostream>
// #include <utility> // for std::pair
// #include <vector>
#include<bits/stdc++.h>

using namespace std;

int main() {
    // Creating a pair
    pair<int, string> person;
    
    // Assigning values to the pair
    person.first = 25;      // First element
    person.second = "Ram"; // Second element

    // Printing the pair
    cout << "Age: " << person.first << ", Name: " << person.second << endl;

    // Creating and initializing a pair using make_pair
    pair<int, string> another_person = make_pair(30, "Raghu");
    
    // Printing the second pair
    cout << "Age: " << another_person.first << ", Name: " << another_person.second << endl;

    // Using pairs in a vector
    vector<pair<int, string>> people;
    people.push_back(make_pair(22, "Rayaji"));
    people.push_back(make_pair(28, "Ranchordas"));
    
    // Printing the vector of pairs
    for (const auto& p : people) {
        cout << "Age: " << p.first << ", Name: " << p.second << endl;
    }

    pair<int, pair<int,int>> var={1,{2,3}};
    cout<<var.first;
    cout<<var.second.first;
    cout<<var.second.second;
    cout<<endl;

    //array of pairs
    pair<int,int> arr[]={{1,2},{2,3},{4,5}};
    cout<<arr[0].first;
    cout<<arr[0].second;
    cout<<arr[1].first;
    cout<<arr[1].second;
    cout<<arr[2].first;
    cout<<arr[2].second;


    return 0;
}
