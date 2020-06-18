#include <bits/stdc++.h>
using namespace std;

char tablero[8][8];

bool rook(int x, int y, char toKill){
    for(int i=y+1; i<8; i++)
        if(tablero[i][x]!='.'){
            if(tablero[i][x]==toKill)
                return true;
            break;
        }
    for(int i=y-1; i>=0; i--)
        if(tablero[i][x]!='.'){
            if(tablero[i][x]==toKill)
                return true;
            break;
        }
    for(int i=x+1; i<8; i++)
        if(tablero[y][i]!='.'){
            if(tablero[y][i]==toKill)
                return true;
            break;
        }
    for(int i=x-1; i>=0; i--)
        if(tablero[y][i]!='.'){
            if(tablero[y][i]==toKill)
                return true;
            break;
        }
    return false;
}

bool bishop(int x, int y, char toKill){
    for(int i=1; x+i<8 && y+i<8; i++)
        if(tablero[y+i][x+i]!='.'){
            if(tablero[y+i][x+i]==toKill)
                return true;
            break;
        }
    for(int i=1; x-i>=0 && y-i>=0; i++)
        if(tablero[y-i][x-i]!='.'){
            if(tablero[y-i][x-i]==toKill)
                return true;
            break;
        }
    for(int i=1; x+i<8 && y-i>=0; i++)
        if(tablero[y-i][x+i]!='.'){
            if(tablero[y-i][x+i]==toKill)
                return true;
            break;
        }
    for(int i=1; x-i>=0 && y+i<8; i++)
        if(tablero[y+i][x-i]!='.'){
            if(tablero[y+i][x-i]==toKill)
                return true;
            break;
        }
    return false;
}

bool knight(int x, int y, char toKill){

    if(x+2<8 && y+1<8)
        if(tablero[y+1][x+2]==toKill)
            return true;
    if(x+1<8 && y+2<8)
        if(tablero[y+2][x+1]==toKill)
            return true;

    if(x+2<8 && y-1>=0)
        if(tablero[y-1][x+2]==toKill)
            return true;
    if(x+1<8 && y-2>=0)
        if(tablero[y-2][x+1]==toKill)
            return true;
    if(x-2>=0 && y-1>=0)
        if(tablero[y-1][x-2]==toKill)
            return true;
    if(x-1>=0 && y-2>=0)
        if(tablero[y-2][x-1]==toKill)
            return true;

    if(x-2>=0 && y+1<8)
        if(tablero[y+1][x-2]==toKill)
            return true;
    if(x-1>=0 && y+2<8)
        if(tablero[y+2][x-1]==toKill)
            return true;

    return false;

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int g=1; true; g++){

        bool isEmpty=true;
        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++){
                cin>>tablero[i][j];
                if(tablero[i][j]!='.')
                    isEmpty=false;
            }
        if(isEmpty)
            return 0;

        bool wC=false, bC=false;
        for(int i=0; i<8; i++)
            for(int j=0; j<8; j++){
                 switch(tablero[i][j]){
                    case 'r':
                        if(rook(j,i, 'K'))
                            wC=true;
                    break;
                    case 'R':
                        if(rook(j, i, 'k'))
                            bC=true;
                    break;
                    case 'b':
                        if(bishop(j,i, 'K'))
                            wC=true;
                    break;
                    case 'B':
                        if(bishop(j, i, 'k'))
                            bC=true;
                    break;
                    case 'q':
                        if(bishop(j,i, 'K'))
                            wC=true;
                        if(rook(j,i, 'K'))
                            wC=true;
                    break;
                    case 'Q':
                        if(bishop(j, i, 'k'))
                            bC=true;
                        if(rook(j, i, 'k'))
                            bC=true;
                    break;
                    case 'n':
                        if(knight(j,i, 'K'))
                            wC=true;
                    break;
                    case 'N':
                        if(knight(j, i, 'k'))
                            bC=true;
                    break;
                    case 'P': //ataca hacia arriba
                        if(i>0){
                            if(j<7)
                                if(tablero[i-1][j+1]=='k')
                                    bC=true;
                            if(j>0)
                                if(tablero[i-1][j-1]=='k')
                                    bC=true;
                        }
                    break;
                    case 'p': //ataca hacia abajo
                        if(i<7){
                            if(j<7)
                                if(tablero[i+1][j+1]=='K')
                                    wC=true;
                            if(j>0)
                                if(tablero[i+1][j-1]=='K')
                                    wC=true;
                        }
                    break;

                 }
            }
            cout<<"Game #"<<g<<": ";
            if(bC){
                cout<<"black king is in check.\n";
            }
            else if(wC){
                cout<<"white king is in check.\n";
            }
            else {
                cout<<"no king is in check.\n";
            }

    }
    return 0;
}


/*
..k.....
ppp.pppp
........
.R...B..
........
........
PPPPPPPP
K.......

rnbqkbnr
pppppppp
........
........
........
........
PPPPPPPP
RNBQKBNR

rnbqk.nr
ppp..ppp
....p...
...p....
.bPP....
.....N..
PP..PPPP
RNBQKB.R

........
........
........
........
........
........
........
........


r......r
........
........
...k....
........
...n....
.....K..
........

k......K
........
pppppppp
pppppppp
pppppppp
pppppppp
pppppppp
pppppppp

........
........
........
........
........
........
........
........

*/
