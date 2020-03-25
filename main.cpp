#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int caut(char c, char v[]){
    for(int i=0; i<=strlen(v); ++i)
        if(v[i] == c)
            return i;
    return -1;
}

bool evaluate(int a[][51], char alfabet[], int n, int stariFinale[], int k, int q0, char cuvant[]){
    int i, lungime = strlen(cuvant), stare = q0;
    for(i=0; i<lungime; ++i){
        stare = a[stare][caut(cuvant[i], alfabet)];
        if(stare == n+1)
            return false;
    }
    for(i=0; i<k; ++i)
        if(stariFinale[i] == stare)
            return true;
    return false;
}

int main() {
    ifstream fin("automata.in");
    int n, m, q0, k, l, i, stare1, stare2, poz, j, a[1001][51], stariFinale[1001];
    char alfabet[51], tranzitie, cuvant[51];
    fin >> n >> m;
    for(i=0; i<n; ++i)      //initializare matrice
        for(j=0; j<m; ++j)
            a[i][j] = n+1;
    for(i=0; i<m; ++i)
        fin >> alfabet[i];
    fin >> q0 >> k;
    for(i=0; i<k; ++i)
        fin >> stariFinale[i];
    fin >> l;
    for(i=1; i<=l; ++i) {       //construire matrice
        fin >> stare1 >> tranzitie >> stare2;
        poz = caut(tranzitie, alfabet);
        a[stare1][poz] = stare2;
    }
    cout << "Introduceti cuvantul: ";
    cin >> cuvant;
    bool value = evaluate(a, alfabet, n, stariFinale, k, q0, cuvant);
    if(value == 1) cout << "TRUE";
    else cout << "FALSE";
    return 0;
}
