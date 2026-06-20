#include <bits/stdc++.h>
using namespace std;
#define ll long long


ll inverso_modular(ll a, ll b, ll &x, ll &y) {
    ll bb = b;//salva o modulo orignal
    ll x0 = 1, y0 = 0;
    ll x1 = 0, y1 = 1;
    
    while (b != 0) {
        ll quociente = a / b;
        ll resto = a % b;
           
        a = b; //att a e b
        b = resto;
        
        ll tmpx = x1; //att x
        x1 = x0 - quociente * x1;
        x0 = tmpx;
        
        ll tmpy = y1; //att y
        y1 = y0 - quociente * y1;
        y0 = tmpy;
    }
    
    x = x0;
    y = y0;
    
    if (a != 1) //modulo nao existe
        return -1;
    return (x % bb + bb) % bb;
}

int main () {
    ll n; cin >> n; 
    while (n--) {
        ll a, b, x, y; cin >> a >> b;
        cout << inverso_modular(a, b, x, y) << endl;
    }
}