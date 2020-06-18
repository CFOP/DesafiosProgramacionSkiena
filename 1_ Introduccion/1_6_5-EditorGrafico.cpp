#include <bits/stdc++.h>
#define MAX 255
using namespace std;

char picture[MAX][MAX];
int M, N;

void clearPicture(){
    for(int i=0; i<=N; i++)
        for(int j=0; j<=M; j++)
            picture[i][j]='O';
}

void print(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++)
            cout<<picture[i][j];
        cout<<"\n";
    }
}

void fill(int x, int y, char toPrint, char c){ //los toPrint lo voy a pintar de c
    if(x<1 || x>M) return;
    if(y<1 || y>N) return;
    if(picture[y][x]!=toPrint)return;

    picture[y][x] = c;
    fill(x-1, y, toPrint, c);
    fill(x+1, y, toPrint, c);
    fill(x, y-1, toPrint, c);
    fill(x, y+1, toPrint, c);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    char C;
    int x, y;
    int y1, y2, x1, x2;
    string a;
    string name;
    char c;
    for(cin>>C; C!='X'; cin>>C){
        switch(C){
            case 'I':
                cin>>M>>N;
                clearPicture();
            break;
            case 'C':
                clearPicture();
            break;
            case 'L':
                cin>>x>>y>>c;
                picture[y][x]=c;
            break;
            case 'V':
                cin>>x>>y1>>y2>>c;
                if(y1>y2)
                    swap(y1, y2);
                for(int i=y1; i<=y2; i++)
                picture[i][x]=c;
            break;
            case 'H':
                cin>>x1>>x2>>y>>c;
                if(x1>x2)
                    swap(x1, x2);
                for(int i=x1; i<=x2; i++)
                    picture[y][i]=c;
            break;
            case 'K':
                cin>>x1>>y1>>x2>>y2>>c;

                if(x1>x2)
                    swap(x1, x2);
                if(y1>y2)
                    swap(y1, y2);

                for(int i=y1; i<=y2; i++)
                    for(int j=x1; j<=x2; j++)
                        picture[i][j]=c;
            break;
            case 'F':
                cin>>x>>y>>c;
                if(picture[y][x]==c)break;
                fill(x, y, picture[y][x],c);
            break;
            case 'S':
                cin>>name;
                cout<<name<<"\n";
                print();
            break;
            default:
                getline(cin, a);
            break;
        }
    }
    return 0;
}
/*
I 5 6
L 2 3 A
S one.bmp
G 2 3 J
F 3 3 J
V 2 3 4 W
H 3 4 2 Z
S two.bmp
X

I 7 20
H 1 7 18 G
K 2 1 4 20 Z
F 5 11 R
L 7 16 U
F 7 2 H
S 20.jpeg
X


L 2 7 Q
*/
