#include<bits/stdc++.h>
using namespace std;

int find_target(vector<int> &arr, int target){
    int low = 0, high = arr.size() - 1;

    int mid;
    while(low <= high){
        mid = low + (high - low)/2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main(){
    vector<int> arr = {1,2,5,8}; // find target element in a non-decreasing sorted array with all unique elements
    
    int idx = find_target(arr, 6);

    if(idx == -1){
        cout << "Target deosn't exist" << endl;
    }
    else{
        cout << "Target exists at index: " << idx << endl;
    }
    return 0;
}