#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;  vector<int> pilhas(n);
    for (int i = 0; i < n; i++) {
        cin >> pilhas[i];
    }

    int nimSum = 0;
    for (auto p : pilhas) {
        nimSum ^= p;
        // cout << nimSum;
    }


    if (nimSum) cout << "Primeiro\n";
    else cout << "Segundo\n";
}