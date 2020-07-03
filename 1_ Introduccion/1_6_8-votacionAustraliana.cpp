#include <bits/stdc++.h>
using namespace std;

#define MAX 25

string name[MAX];
vector <int*> vote;
vector <int> actualVote;
int votes[MAX];
bool alive[MAX];
int n;

int main(){
    int casos;
    cin>>casos;
    char c;
    string trash;
    while(casos--){
        ///init
        vote.clear();
        for(int i=0; i<MAX; i++){
            votes[i]=0;
            alive[i]=true;
        }
        ///lectura
        cin>>n;
        for(int i=0; i<n; i++)
            getline(cin, name[i]);
        getline(cin, trash);
        {
            int j=0;
            for(c=cin.get(); c!='\n' && !cin.eof(); c=cin.get(), j++){
                cin.putback(c);
                vote.push_back(new int[n]);
                actualVote.push_back(0);
                for(int i=0; i<n; i++){
                    cin>>vote[j][i];
                }
                getline(cin, trash);
            }
        }

        ///procesamiento
        bool winner=false;
        while(!winner){
            //contar votos (si se encuentra uno ganador, terminar el ciclo)
            //buscar menores
            //eliminar menores
            //si no hay menores salir
        }

    }
    return 0;
}
/*
1
3
John Doe
Jane Smith
Sirhan Sirhan
1 2 3
2 1 3
2 3 1
1 2 3
3 1 2
*/
