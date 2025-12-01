// check for duplicate elements in an array using hash set

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    const int MAX = 100000; 
    bool hashSet[MAX] = {false};

    for (int i = 0; i < n; i++) {
        if (hashSet[arr[i]]) {
            cout << "Duplicate element found: " << arr[i] << endl;
            return 0;
        }
        hashSet[arr[i]] = true;
    }

    cout << "No duplicate elements found." << endl;
    return 0;
}