#include <bits/stdc++.h>

#define MAX 105

int mapa[MAX][MAX];
char mapaReal[MAX][MAX];
int n, m;

using namespace std;

void borrar(){
    for(int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
            mapa[i][j]=0;
}

void sumar(int i, int j){
    mapa[i+1][j]++;//arriba
    mapa[i-1][j]++;//abajo
    mapa[i][j-1]++;//izquierda
    mapa[i][j+1]++;//derecha
    mapa[i+1][j-1]++;//arriba izq
    mapa[i+1][j+1]++;//arriba der
    mapa[i-1][j-1]++;//abajo izq
    mapa[i-1][j+1]++;//abajo der
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int field=1; n || m;field++){
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++){
                cin>>mapaReal[i][j];
                if(mapaReal[i][j]=='*')
                    sumar(i, j);
            }
        cout<<"Field #"<<field<<":\n";
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(mapaReal[i][j]=='*')
                    cout<<'*';
                else cout<<mapa[i][j];
            }
            cout<<"\n";
        }
        cin>>n>>m;
        if(n || m) borrar(), cout<<"\n";
    }
    return 0;
}
/*
4 4
*...
....
.*..
....
3 5
**...
.....
.*...
0 0
*/
