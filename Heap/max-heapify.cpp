#include<bits/stdc++.h>
using namespace std;

void max_heapify(vector<int> &heap, int i){
    int left = 2*i + 1; // 0-based index
    int right = 2*i + 2;

    int largest = i;
    if(left < heap.size() && heap[left] > heap[largest])
        largest = left;

    if(right < heap.size() && heap[right] > heap[largest])
        largest = right;
    
    if(largest != i){
        swap(heap[largest], heap[i]);
        max_heapify(heap, largest);
    }
}

int main(){
    vector<int> heap = {1, 14, 10, 8, 7, 9, 3, 2, 4, 6}; // only 0th node is not maintain the heap property

    cout << "current heap (0th node not maintain heap property): ";
    for(auto it: heap){
        cout << it << " ";
    }

    max_heapify(heap, 0);
    cout << "\nAfter heapifying the 0th node: ";
    for(auto it: heap){
        cout << it << " ";
    }
    return 0;
}