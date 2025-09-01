#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);       // gcd(a, b) = gcd (b, a % b) , for a > b or a < b.Works for both
}

int lcm(int a, int b){
    return (a / gcd(a, b)) * b;   // LCM(a, b) * GCD(a, b) = a * b;
}

int main(){
    int a, b;
    cout << "Enter two numbers a and b: ";   // one number should be non-zero
    cin>> a >> b;  

    cout << "GCD of "<< a << " and " << b << " is: " << gcd(a, b);
    cout << "\nLCM of "<< a << " and " << b << " is: " << lcm(a, b);
    return 0;
}

// Time Complexity = O(log(min(a, b)));