#include <bits/stdc++.h>

using namespace std;

struct square {
    long long x_max, y_max, x_min, y_min;

    square(){
        x_max = INT_MIN;
        x_min = INT_MAX;
        y_max = INT_MIN;
        y_min = INT_MAX;
    }
};

int  main() {
    square s[2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++ ){
            long long x, y; cin >> x >> y;
            s[i].x_max = max(x, s[i].x_max);
            s[i].x_min = min(x, s[i].x_min); 
            s[i].y_max = max(y, s[i].y_max); 
            s[i].y_min = min(y, s[i].y_min); 
        }
    }

    bool sobreposicao_x = max(s[0].x_min, s[1].x_min) <= min(s[0].x_max, s[1].x_max);
    bool sobreposicao_y = max(s[0].y_min, s[1].y_min) <= min(s[0].y_max, s[1].y_max);

    if (sobreposicao_x && sobreposicao_y) cout << "SIM" << endl;
    else cout << "NAO";

    
}



    else if (o1 == 0 && onSegment(p[0], p[2], p[1])) cout << "SIM" << endl; //colineares
    else if (o2 == 0 && onSegment(p[0], p[3], p[1])) cout << "SIM" << endl
    else if (o3 == 0 && onSegment(p[2], p[0], p[3])) cout << "SIM" << endl;
    else if (o4 == 0 && onSegment(p[2], p[1], p[3])) cout << "SIM" << endl;