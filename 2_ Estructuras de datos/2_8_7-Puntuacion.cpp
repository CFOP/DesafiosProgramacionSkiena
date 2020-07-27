#include <bits/stdc++.h>
using namespace std;

#define MAX 105

pair<int, int> total[MAX]; //puntos, penalizacion
bool mostrar[MAX];

               //tiempo, correcto?
priority_queue <pair<int, bool>, vector<pair<int, bool>>, less<pair<int, bool>>> envios[MAX][11];

struct classcomp{
    bool operator() (const int &a, const int &b) const{
        if(total[a].first!=total[b].first) return total[a].first<total[b].first;
        if(total[a].second!=total[b].second)
            return total[a].second > total[b].second;
        return a>b;
    }
};

priority_queue<int, vector<int>, classcomp> concursante; //id

void limpiar(){
    for(pair<int, int> &p : total)
        p.first = p.second = 0;

    for(int i=0; i<MAX; i++)
        for(int j=0; j<11; j++)
            while(envios[i][j].size())envios[i][j].pop();

    for(bool &a:mostrar)
        a=false;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    stringstream line;
    string a;
    line.clear();
    getline(cin, a);
    line<<a;
    line>>t;

    getline(cin, a);
    //cout<<"v";

    while(t--){
        //cout<<t<<"\n";
        limpiar();
        line.clear();

        int q=0;
        getline(cin, a);
        while(a!=""){
            line<<a<<"\n";
            //cout<<a<<"\n";
            getline(cin, a);
            q++;
        }
        //cout<<q<<"\n";
        //cout<<"v";

        for(int i=0; i<q; i++){
                int concursante, problema, tiempo;
                char L;
                line>>concursante>>problema>>tiempo>>L;
                //cout<<concursante<<" ";
                if(L=='C' || L=='I')
                    envios[concursante][problema].push(make_pair(tiempo, L!='C'));
                mostrar[concursante] = true;
        }
        //cout<<"c";

        for(int i=0; i<MAX; i++){
            if(mostrar[i]){
                //cout<<i<<":\n";
                int puntos = 0, penalty = 0;

                for(int j=0; j<11; j++){
                    //cout<<"\t"<<j<<": ";
                    //cout<<envios[i][j].size() << " | ";
                    while(envios[i][j].size() && envios[i][j].top().second) {
                            //cout<<envios[i][j].top().first<<" ";
                            envios[i][j].pop();
                    }
                    if(envios[i][j].size()){
                            //cout<<envios[i][j].top().second;
                            int p;
                            while(envios[i][j].size() && !envios[i][j].top().second){
                                p = envios[i][j].top().first;
                                envios[i][j].pop();
                            }
                            puntos++;
                            penalty += p;
                            //envios[i][j].pop();
                    }

                    penalty += envios[i][j].size()*20;
                    //cout<<"\n";

                }

                total[i].first = puntos;
                total[i].second = penalty;
                concursante.push(i);
            }
        }

        while(concursante.size()){
            int i = concursante.top(); concursante.pop();
            cout<<i<<" "<<total[i].first<<" "<<total[i].second<<"\n";
        }cout<<"\n";

    }

    return 0;
}

/*
2

1 2 10 I
3 1 11 C
1 2 19 R
1 2 21 C
1 1 25 C

1 2 10 I
3 1 11 C
1 2 19 R
1 2 21 C
1 1 25 C



*/
