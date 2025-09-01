#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a % b);       // gcd(a, b) = gcd (b, a % b) , for a > b or a < b.Works for both
}

int main(){
    int a, b;
    cout << "Enter two numbers a and b: ";   // one number should be non-zero
    cin>> a >> b;  

    cout << "GCD of "<< a << " and " << b << " is: " << gcd(a, b);
    return 0;
}