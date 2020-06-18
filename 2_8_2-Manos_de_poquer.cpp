#include <bits/stdc++.h>

using namespace std;

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

int main(){
    char value;
    char suit;
    while(cin>>value){
        cin>>suit;
        black.push_back(make_pair<char, char>(value, suit));
        for(int i=1; i<5; i++){
                cin>>value>>suit;
                black.push_back(make_pair<char, char>(value, suit));
        }
        for(int i=0; i<5; i++){
                cin>>value>>suit;
                white.push_back(make_pair<char, char>(value, suit));
        }

        sort(white.begin(), white.end(), comp);

        //ya me dio flojera seguirle

        white.clear();
        black.clear();
    }
    return 0;
}
