#include<bits/stdc++.h>
using namespace std;

void max_heapify(vector<int> &arr, int i){
    int left = 2*i + 1; // 0-based index
    int right = 2*i + 2;

    int largest = i;
    if(left < arr.size() && arr[left] > arr[largest])
        largest = left;

    if(right < arr.size() && arr[right] > arr[largest])
        largest = right;
    
    if(largest != i){
        swap(arr[largest], arr[i]);
        max_heapify(arr, largest);
    }
}

void build_max_heap(vector<int> &arr){
    int n = arr.size();

    for(int i = n/2 - 1; i >= 0; i--){
        max_heapify(arr, i);
    }
}

int main(){
    vector<int> arr = {3, 6, 5, 0, 8, 2, 1, 9}; 

    cout << "current array elements: ";
    for(auto it: arr){
        cout << it << " ";
    }

    build_max_heap(arr);
    cout << "\nAfter building max heap: ";
    for(auto it: arr){
        cout << it << " ";
    }
    return 0;
}