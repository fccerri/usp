#include <bits/stdc++.h>
using namespace std;

int gcd(long long a, long long b) {
    if (b == 0)
        return a; 
    return gcd(b, a % b);
}

int main () {
    int n; cin >> n;
    while (n--) {
        long long a,b; cin >> a >> b;
        long long gcdNumber = gcd(a,b);

        cout << gcdNumber << " " << (a / gcdNumber) * b << endl;
    }
}