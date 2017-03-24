#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;
const int N = 20005;
long long f[N];

long long power(long long a , long long b){
    long long x = 1 , y = a;
    while(b > 0){
        if(b & 1){
            x = (x * y);
            if(x > MOD)
                x %= MOD;
        }

        y = y*y;
        if(y > MOD)
            y %= MOD;

        b >>= 1;
    }
    return x;
}


long long nCr(long long n , long long r){
    return (f[n] * power(f[r] * f[n-r] %MOD , MOD - 2))% MOD;
}


int main(){
    f[0] = 1;
    for(int i = 1 ; i < N ;i++)
        f[i] = (f[i-1] * i) % MOD;


    int t;
    cin >> t;
    while(t--){
        int n , m;
        cin >> n >> m;
        cout << nCr(n+m , n) << endl;
    }
}
