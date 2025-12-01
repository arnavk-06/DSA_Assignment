// find first non repeating element in an array using hash map

#include <iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int freq[100] = {0}; // assuming elements are in range 0-99

    for(int i=0;i<n;i++){
        freq[arr[i]]++;
    }

    for(int i=0;i<n;i++){
        if(freq[arr[i]] == 1){
            cout<<"First non-repeating element is: "<<arr[i]<<endl;
            return 0;
        }
    }

    cout<<"No non-repeating element found"<<endl;
    return 0;
}