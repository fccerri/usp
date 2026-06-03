#include <bits/stdc++.h>

using namespace std;


int main() {
    string palavra, sub; cin >> palavra >> sub;
    int m = sub.length();
    int n = palavra.length();
    
    vector<int> lpps(m , 0); //Longest Proper Prefix wich is also a Sufix 
    int previousLenght = 0, i = 1;
    while (i < m) {
        if ( sub[previousLenght] == sub[i] ) {
            lpps[i] = ++previousLenght;
            i++;
        }
        
        //nao havia nenhuma construção de sufixo e prefixo de conjuntos, como len = 0, 
        else if (previousLenght == 0) {
            lpps[i] = 0; //os novos prefixos e sufixos de tamanho 1 tabem nao dao match pela verificacao anterior
            i++;
        }
        else{ //ja havia uma comparação anterior, aproveita-se matchs anteriores retrocedendo
            previousLenght = lpps[previousLenght - 1]; //i nao acresce!!
        }
    }

    int j = 0, res = 0; i = 0;
    while (i < n) {
        if (palavra[i] == sub[j]) { //deu match -> cresce i e j
            i++;
            j++;

            if (j == m) { //padrao inteiro deu macth
                res++;
                j = lpps[j - 1];
            }
            
        }
        else {
            if (j != 0) {
                j = lpps[j - 1];
            } else {
                i++;
            }
        }
        
    }    

    cout << res;

}