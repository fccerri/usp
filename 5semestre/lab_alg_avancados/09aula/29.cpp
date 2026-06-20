#include <bits/stdc++.h>

using namespace std;

struct ponto{
    long long x, y;
};

int orientacao(ponto a, ponto b, ponto c) {
    long long val = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    
    if (val == 0) return 0; //colinear
    return (val < 0) ? 1 : 2;
};

bool contido(ponto p, ponto a, ponto b) { //verifica se p esta em ab
    if (p.x <= max(a.x, b.x) && p.x >= min(a.x, b.x) &&
        p.y <= max(a.y, b.y) && p.y >= min(a.y, b.y)) {
        return true;
    }
    return false;
}

int main (){
    ponto p[4];
    for (int i = 0; i<4; i++) cin >> p[i].x >> p[i].y;

    int o1 = orientacao(p[0], p[1], p[2]); // r1 com r2 inicioi
    int o2 = orientacao(p[0], p[1], p[3]); // r1 com r2 fim
    int o3 = orientacao(p[2], p[3], p[0]); // r2 com r1 inicioi
    int o4 = orientacao(p[2], p[3], p[1]); // r2 com r1 fim
 
    //extrai sinal   multiplica
    if ((o1 != o2) && o3 != o4) cout << "SIM" << endl; //cruza
    else if (o1 == 0 && contido(p[2], p[0], p[1])) cout << "SIM" << endl; //colineares
    else if (o2 == 0 && contido(p[3], p[0], p[1])) cout << "SIM" << endl;
    else if (o3 == 0 && contido(p[0], p[2], p[3])) cout << "SIM" << endl;
    else if (o4 == 0 && contido(p[1], p[2], p[3])) cout << "SIM" << endl;

    else cout << "NAO" << endl;
}