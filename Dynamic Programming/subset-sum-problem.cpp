#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

bool solve(vector<int> &num, int sum, int i){
    if(sum == 0)
        return true;
    
    if(i >= num.size())
        return false;

    if(dp[i][sum] != -1)
        return dp[i][sum]; 

    if(num[i] > sum)
        return dp[i][sum] = solve(num, sum, i+1);
    
    bool take = solve(num, sum - num[i], i+1);
    bool skip = solve(num, sum, i+1);

    return dp[i][sum] = take || skip;
}

int main(){
    vector<int> num = {3, 4, 1};
    int sum = 7;

   dp.assign(num.size(), vector<int>(sum + 1, -1));

    if(solve(num, sum, 0))
        cout << "Subset exists" << endl;
    else
        cout << "Subset doesn't exists" << endl;
    return 0;
}
