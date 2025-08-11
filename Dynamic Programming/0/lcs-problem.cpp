#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int solve(string s1, string s2, int i1, int i2){
    if(i1 >= s1.size() || i2 >= s2.size())
        return 0;
    
    if(dp[i1][i2] != -1)
        return dp[i1][i2];

    if(s1[i1] == s2[i2])
        return dp[i1][i2] = 1 + solve(s1, s2, i1 + 1, i2 + 1);

    int skip_i2 = solve(s1, s2, i1, i2 + 1);
    int skip_i1 = solve(s1, s2, i1 + 1, i2);

    return dp[i1][i2] = max(skip_i2, skip_i1);
}

int main(){
    string s1 = "abcde", s2 = "ace";
    int m = s1.size(), n = s2.size();

    dp.assign(m, vector<int>(n, -1));
    cout << "Lenght of the LCS: " << solve(s1, s2, 0, 0);
    return 0;
}
