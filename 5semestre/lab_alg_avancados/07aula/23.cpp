#include <bits/stdc++.h>
using namespace std;

                //current solution, current line
bool verifyPosition (vector<int> board, int line, int col) {
    for (int i = 0; i < board.size(); i++) {//linha do tabuleiro 
        if (board[i] == col || i == line ) //verifica rainhas na mesma linha ou coluna
            return false;

        if (abs(line - i) == abs(col - board[i])) { //verifica rainhas na mesma diagonal
            return false;
        }
    }
    return true;
} 

// retorna vetor de soluções;
vector<vector<int>> solve(int n) {
    vector<vector<int>> solutions;
    vector<int> board;
    int i = 0, j = 0;
    while (i < n) { //linha

        if (j == n) { //backtrack
            if (--i < 0) break; //todas solucoes encontradas
            j = board[i] + 1; //volta na ultima posicao alocada uma rainha
            board.pop_back();
        }

        while (j < n)  {//coluna
            if (verifyPosition (board, i, j)) {
                board.push_back(j); //add rainha
                if (i + 1 == n) { //se solucao encontrada
                    solutions.push_back(board);
                    board.pop_back();
                    j++; //continua na ultima linha
                }
                else {//solucao nao encontrada -> primeira linha da proxima coluna
                    j = 0;
                    i++;
                }
            }
            else { //nao eh valido, continuamos na proxima posiscao da linha
                j++; 
            }
        }

    }
    return solutions;
}

int main () {
    int n; cin >> n;
    while (n!= 0) {
        if (n == 2 || n == 3) {
            printf("[%d,%d]\n",n, 0);
            cout << "sem solucao" << endl;
            cin >> n;
            continue;
        }
        vector<vector<int>> solucao = solve(n);
        printf("[%d,%lu]\n",n, solucao.size());
        for (auto s : solucao[0]) {
            cout << s + 1 << " ";
        }
        cout << endl;
        cin >> n;
    } 
}