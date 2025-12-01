// find common element in two arrays using hash set

#include <iostream>
using namespace std;

int main(){
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    int arr1[n1];
    cout << "Enter elements of first array: ";
    for(int i = 0; i < n1; i++){
        cin >> arr1[i];
    }

    cout << "Enter size of second array: ";
    cin >> n2;
    int arr2[n2];
    cout << "Enter elements of second array: ";
    for(int i = 0; i < n2; i++){
        cin >> arr2[i];
    }

    const int MAX = 1000;
    bool hashSet[MAX] = {false};

    for(int i = 0; i < n1; i++){
        hashSet[arr1[i]] = true;
    }

    cout << "Common elements are: ";
    for(int i = 0; i < n2; i++){
        if(hashSet[arr2[i]]){
            cout << arr2[i] << " ";
            hashSet[arr2[i]] = false;
        }
    }
    cout << endl;

    return 0;
}