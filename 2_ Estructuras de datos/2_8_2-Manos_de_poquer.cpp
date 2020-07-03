#include <bits/stdc++.h>

using namespace std;

#define WHITE -1
#define BLACK 1
#define TIE 0
#define NOT -2

vector < pair <char, char> > black;
vector < pair <char, char> > white;

char valueOrder[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};

int getValueOrder(pair <char, char> a){
    for(int i=0; i<13; i++){
        if(valueOrder[i] == a.first){
            return i;
        }
    }
    return 13;
}

bool comp(pair<char, char> a, pair<char, char> b){
    if(getValueOrder(a) > getValueOrder(b))
        return false;
    if(getValueOrder(a) < getValueOrder(b))
        return true;
    if(a.second > b.second)
        return false;
    return true;
}

int getValue(pair <char, char> a){
    return getValueOrder(a);
}

int masAlta(){
    for(int i=4; i>=0; i--){
        if(getValue(white[i])>getValue(black[i]))
            return WHITE;
        if(getValue(white[i])<getValue(black[i]))
            return BLACK;
    }
    return TIE;
}

int encontrarPareja(vector <pair <char, char>> juego, int n=4){
    for(int i=n; i>0; i--){
        if(juego[i].first == juego[i-1].first)
            return getValue(juego[i]);
    }
    return NOT;
}
int pareja(){
    int pb, pw;
    if((pb=encontrarPareja(black))==NOT && (pw=encontrarPareja(white)==NOT))
       return NOT;
    if(pb>pw)
        return BLACK;
    if(pb<pw) return WHITE;
    return masAlta();
}

int encontrarPareja2(vector <pair <char, char>> juego){
    int p=0;
    for(int i=4; i>0; i--){
        if(juego[i].first == juego[i-1].first){
            if(++p==2)
                return getValue(juego[i]);
            i = i-1;
        }
    }
    return NOT;
}
int doblePareja(){
    if(encontrarPareja2(white)==NOT && encontrarPareja2(black)==NOT) return NOT;
    //cout<<"v";
    if(encontrarPareja2(white)==NOT) return BLACK;
    if(encontrarPareja2(black)==NOT) return WHITE;

    int pb, pw;
    pb=encontrarPareja(black);
    pw=encontrarPareja(white);
    if( pw == NOT && pb == NOT)
       return NOT;
    //cout<<pb<<pw;
    if(pb>pw)
        return BLACK;
    if(pb<pw) return WHITE;
    //cout<<encontrarPareja(black);
    if((pb=encontrarPareja2(black))==NOT && (pw=encontrarPareja2(white)==NOT))
       return NOT;
    if(pb>pw)
        return BLACK;
    if(pb<pw) return WHITE;
    return masAlta();
}

int encontrarTrio(vector <pair <char, char>> juego){
    for(int i=4; i>1; i--){
        if(juego[i].first == juego[i-1].first && juego[i].first == juego[i-2].first)
            return getValue(juego[i]);
    }
    return NOT;
}

int trio(){
    int pb, pw;
    if((pb=encontrarTrio(black))==NOT && (pw=encontrarTrio(white)==NOT))
       return NOT;
    if(pb>pw)
        return BLACK;
    if(pb<pw) return WHITE;
    return masAlta();
}

bool checarEscalera(vector <pair <char, char>> juego){
    for(int i=1; i<5; i++)
        if(getValue(juego[i])!=getValue(juego[i-1])+1)
            return false;
    return true;
}

int escalera(){
    if(!checarEscalera(white) && !checarEscalera(black))
        return NOT;
    if(!checarEscalera(white))
        return BLACK;
    if(!checarEscalera(black))
        return WHITE;
    return masAlta();
}

bool checarColor(vector <pair <char, char>> juego){
    return juego[4].second==juego[3].second
        && juego[4].second==juego[2].second
        && juego[4].second==juego[1].second
        && juego[4].second==juego[0].second;
}

int color(){
    if(!checarColor(white) && !checarColor(black))
        return NOT;
    if(!checarColor(white))
        return BLACK;
    if(!checarColor(black))
        return WHITE;
    return masAlta();
}

int checarFull(vector <pair <char, char>> juego){
    if(encontrarTrio(juego)==NOT)
        return NOT;
    if(getValue(juego[4])==encontrarTrio(juego)){
        if(juego[1].first==juego[1].first)
            return encontrarTrio(juego);
        else return NOT;
    }
    else {
        if(juego[4].first==juego[3].first)
             return encontrarTrio(juego);
        else return NOT;
    }
}

int full(){
    if(checarFull(white)==NOT && checarFull(black)==NOT)
        return NOT;
    if(checarFull(white)==NOT)
        return BLACK;
    if(checarFull(black)==NOT)
        return WHITE;
    if(checarFull(white)>checarFull(black))
        return WHITE;
    if(checarFull(white)<checarFull(black))
        return BLACK;
    return TIE;
}

int checarPoquer(vector <pair <char, char>> juego){
    if(juego[4].first == juego[3].first && juego[2].first == juego[1].first && juego[2].first == juego[3].first)
        return getValue(juego[4]);
    if(juego[0].first == juego[3].first && juego[2].first == juego[1].first && juego[2].first == juego[3].first)
        return getValue(juego[0]);
    return NOT;
}

int poquer(){
    if(checarPoquer(white)==NOT && checarPoquer(black)==NOT)
        return NOT;
    if(checarPoquer(white)==NOT)
        return BLACK;
    if(checarPoquer(black)==NOT)
        return WHITE;
    if(checarPoquer(white)>checarPoquer(black))
        return WHITE;
    return BLACK;
}

int escaleraColor(){
    if(!(checarEscalera(white) && checarColor(white)) && !(checarEscalera(black) && checarColor(black)))
        return NOT;
    if(!(checarEscalera(white) && checarColor(white)))
        return BLACK;
    if(!(checarEscalera(black) && checarColor(black)))
        return WHITE;
    return masAlta();
}

int main(){
    char value;
    char suit;
    while(cin>>value){
        cin>>suit;
        black.push_back(make_pair(value, suit));
        for(int i=1; i<5; i++){
                cin>>value>>suit;
                black.push_back(make_pair(value, suit));
        }
        for(int i=0; i<5; i++){
                cin>>value>>suit;
                white.push_back(make_pair(value, suit));
        }

        sort(white.begin(), white.end(), comp);
        sort(black.begin(), black.end(), comp);

        int resultado = NOT;
        resultado = escaleraColor();
        if(resultado==NOT)
            resultado = poquer();
        if(resultado==NOT)
            resultado = full();
        if(resultado==NOT)
            resultado = color();
        if(resultado==NOT)
            resultado = escalera();
        if(resultado==NOT)
            resultado = trio();
        if(resultado==NOT)
            resultado = doblePareja();
        if(resultado==NOT)
            resultado = pareja();
        if(resultado==NOT)
            resultado = masAlta();
        if(resultado==TIE)
            cout<<"Tie.\n";
        else if(resultado==BLACK)
            cout<<"Black wins.\n";
        else cout<<"White wins.\n";

        white.clear();
        black.clear();
    }
    return 0;
}

/*
2H 3D 5S 9C KD 2C 3H 4S 8C AH
2H 4S 4C 2D 4H 2S 8S AS QS 3S
2H 3D 5S 9C KD 2C 3H 4S 8C KH
2H 3D 5S 9C KD 2D 3H 5C 9S KH

3H 3D 6C 3S 3C 2H 2C AC AD 2D

TD TC 2D 2H AC TS TH 3S 3D 2S
*/
