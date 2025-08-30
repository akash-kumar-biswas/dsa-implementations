#include<bits/stdc++.h>
using namespace std;

void max_heapify(vector<int> &arr, int i, int n){
    int left = 2*i + 1; // 0-based index
    int right = 2*i + 2;

    int largest = i;
    if(left < n && arr[left] > arr[largest])
        largest = left;

    if(right < n && arr[right] > arr[largest])
        largest = right;
    
    if(largest != i){
        swap(arr[largest], arr[i]);
        max_heapify(arr, largest, n);
    }
}

void build_max_heap(vector<int> &arr){
    int n = arr.size();

    for(int i = n/2 - 1; i >= 0; i--){
        max_heapify(arr, i, n);
    }
}

void heap_sort(vector<int> &arr){
    int n = arr.size();

    for(int i = n - 1; i >= 1; i--){      //applying heapify on n-1 elements (not n elements).Bcz 1 element is always sorted.
        swap(arr[i], arr[0]);
        max_heapify(arr, 0, i);
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

    heap_sort(arr);
    cout << "\nAfter applying heap sort: ";
    for(auto it: arr){
        cout << it <<" ";
    }

    return 0;
}