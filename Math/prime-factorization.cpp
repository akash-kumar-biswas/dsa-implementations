#include<bits/stdc++.h>
using namespace std;

void primeFactorization(int n, vector<int>& primes){
    while(n%2 == 0){
        primes.push_back(2);
        n /= 2;
    }

    for(int i = 3; i*i <= n; i+=2){
        while(n%i == 0){
            primes.push_back(i);
            n /= i;
        }
    }
    
    if(n > 1)
        primes.push_back(n);
}

int main(){
    int n;
    cin >> n;

    vector<int> primes;
    primeFactorization(n, primes);

    for(auto prime: primes)
        cout << prime << " ";
    return 0;
}