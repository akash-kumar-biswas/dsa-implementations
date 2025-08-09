#include<bits/stdc++.h>
using namespace std;

void sieve(int n, vector<int>& isPrime, vector<int> &primes){
    
    isPrime[0] = isPrime[1] = false;

    for(int i = 2; i*i <= n; i++){
        if(isPrime[2]){
            for(int j = i*i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    for(int i = 2; i <= n; i++){
        if(isPrime[i])
            primes.push_back(i);
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> isPrime(n + 1, true);
    vector<int> primes;

    sieve(n, isPrime, primes);   // generate all prime numbers up to a given number n in O(nloglogn) time

    for(auto prime: primes)
        cout << prime << " ";      // prime number from 1 to n
    return 0;
}