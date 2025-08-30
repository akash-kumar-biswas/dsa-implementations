#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(vector<int> &nums, int i, int prev){
    if(i >= nums.size())
        return 0;
    
    if(dp[i][prev + 1] != -1)
        return dp[i][prev + 1];

    int take = 0;
    if(prev == -1 || nums[prev] < nums[i])
        take = 1 + solve(nums, i+1, i);

    int skip = solve(nums, i+1, prev);

    return dp[i][prev + 1] = max(take, skip);
}

int main(){
    vector<int> nums = {0, 1, 0, 3, 2, 3};
    int n = nums.size();
    dp.assign(n, vector<int>(n+1, -1));
    cout << "Lenght of the LIS: " << solve(nums, 0, -1);
    return 0;
}
