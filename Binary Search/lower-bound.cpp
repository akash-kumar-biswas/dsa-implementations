#include<bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &arr, int target){
    int low = 0, high = arr.size() - 1;

    int mid;
    while(low <= high){
        mid = low + (high - low)/2;

        if(arr[mid] >= target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

int main(){
    vector<int> arr = {1,1,1,2,2,5,8}; // find the first index where arr[i] >= target
    
    int target = 2;
    int idx = lower_bound(arr, target);

    cout << "The lower bound of " << target << " is: " << idx << endl;
    
    return 0;
}