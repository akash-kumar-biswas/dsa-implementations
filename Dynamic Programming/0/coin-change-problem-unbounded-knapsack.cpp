#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

vector<vector<int>> dp;

int solve(vector<int> &coins, int amount, int i){
    if(amount == 0)
        return 0;
    
    if(i >= coins.size())
        return INF;

    if(dp[i][amount] != -1)
        return dp[i][amount]; 

    if(coins[i] > amount)
        return dp[i][amount] = solve(coins, amount, i+1);
    
    int take = 1 + solve(coins, amount - coins[i], i);
    int skip = solve(coins, amount, i+1);

    return dp[i][amount] = min(take, skip);
}

int main(){
    vector<int> coins = {3, 4, 8, 1};
    int amount = 8;

   dp.assign(coins.size(), vector<int>(amount + 1, -1));

    cout << "Min number of coins: " << solve(coins, amount, 0) << endl;
    return 0;
}
