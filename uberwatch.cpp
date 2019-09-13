#include <iostream>

using namespace std;

int n; //Duracion del juego
int m; //Tiempo para cargar ulti
int x[4]; //Jugadores en ese momento
int s[4]; //Soluciones

int mejor_caso_desde(int t, int carga) {
    if(s[t] != -1) return s[t];

    if(t == n-1) { //Ultima posicion
        if(carga >= m) {
            s[t] = x[t];
        }
        else {
            s[t] = 0;
        }
    }
    else {
        if(carga >= m) {
            s[t] = max(x[t] + mejor_caso_desde(t+1, 1), mejor_caso_desde(t+1, m+1));
        }
        else {
            s[t] = mejor_caso_desde(t+1, carga+1);
        }
    }

    return s[t];
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    int i;

    for(i = 0; i < n; i++) {
        cin >> x[i];
        s[i] = -1;
    }

    cout << mejor_caso_desde(0, 0) << '\n';

    return 0;
}
