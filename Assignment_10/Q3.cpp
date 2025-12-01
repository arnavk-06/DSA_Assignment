// count frequency of each element in an array using hash map

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
    int hashMap[MAX] = {0};
    for (int i = 0; i < n; i++) {
        hashMap[arr[i]]++;
    }
    cout << "Element frequencies:" << endl;
    for (int i = 0; i < n; i++) {
        if (hashMap[arr[i]] != 0) {
            cout << arr[i] << ": " << hashMap[arr[i]] << endl;
            hashMap[arr[i]] = 0; // to avoid printing duplicates
        }
    }
    
    return 0;
}