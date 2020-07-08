#include <bits/stdc++.h>

#define MAX 1005

//#define PRUEBA 1

//using namespace std;
using std::string;
using std::vector;
using std::unordered_map;
using std::cin;
#ifndef PRUEBA
using std::cout;
#endif // PRUEVA

vector <string> dic[MAX];
vector <string> cif;
unordered_map <string, string> hmap;

char c[200];
bool ocupado[200];

bool probar(int n){
    if(n==0)
        return true;
    for(int i=0; i<200; i++)
        ocupado[i]=c[i]=0;
    for(int i=0; i<n; i++){
        //cout<<cif[i]<<" "<<hmap[cif[i]]<<"\n";
        for(int j=0; j<cif[i].size(); j++){
            if(c[cif[i][j]]){
                if(hmap[cif[i]][j] != c[cif[i][j]]){
                    //cout<<cif[i][j]<<" "<<hmap[cif[i]][j]<<" "<<c[cif[i][j]]<<"\n\n\n";
                    return false;
                }
            }
            else{
                if(ocupado[hmap[cif[i]][j]]) return false;
                ocupado[hmap[cif[i]][j]]=true;
                c[cif[i][j]] = hmap[cif[i]][j];
            }
        }
    }
    //cout<<"\n\n";
    return true;
}

bool buscar(int i=0){
    if(i==cif.size())
        return probar(i);
    //cout<<i;
    if(!probar(i))
        return false;
    string desifrar = cif[i];
    if(hmap.find(desifrar)!=hmap.end())
        return buscar(i+1);
    //cout<<". ";
    for(string posible : dic[desifrar.size()]){
            hmap[desifrar] = posible;
            if(buscar(i+1))
                return true;
            hmap.erase(desifrar);
    }

    return false;
}

int main(){
    #ifdef PRUEBA
    std::ofstream cout;
    cout.open("ans.txt");
    #endif // PRUEBA
    #ifndef PRUEBA
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    #endif
    int n; cin>>n;
    string a;
    getline(cin, a);
    for(int i=0; i<n; i++){
        getline(cin, a);
        dic[a.size()].push_back(a);
    }
    while(!cin.eof()){
        getline(cin, a);
        #ifdef PRUEBA
        if(a=="kk"){
            cout.close();
            return 0;
        }
        #endif // PRUEBA
        string ward = a;
        cif.clear();
        hmap.clear();
        while(a.size()){
            if(a[0]==' '){
                a = a.substr(1, a.size());
                continue;
            }
            int p;
            for(p=0; p<a.size() && a[p]!=' '; p++);
            cif.push_back(a.substr(0, p));
            a = a.substr(p);
        }

        //memset(c, 0, sizeof(c));
        if(!buscar()){
            for(char i : ward)
                if(i==' ')cout<<" ";
                else cout<<'*';
        }
        else {
            for(char i : ward)
                if(i==' ')cout<<" ";
                else cout<<c[i];
        }
        cout<<"\n";
    }

    return 0;
}

/*
6
and
dick
jane
puff
spot
yertle
bjvg xsb hxsn xsb qymm xsb rqat xsb pnetfn
xxxx yyy zzzz www yyyy aaa bbbb ccc dddddd

29
baseball
football
basketball
tennis
ball
is
a
sport
which
uses
not
one
two
player
players
too
i
like
also
these
are
sports
soccer
no
chess
btw
by
the
way
lrsglrww as r sexvh
dffbqtoo sk t kjfcb bff
knnwqndd hg j gmnbw wnn
u wuqe bdaebdww
c pu iuo hcsw owiict
xhwkw fiw kldixk xwzzak yddxmfjj mfkqwxmfjj mfkwmfjj
micvc tbc vwfbmv mff mchhev pffmdtoo dtvacmdtoo dtvcdtoo jicvv
mysrs bus rehumr mhh msggar ohhmjbxx jbrksmjbxx jbrsjbxx rkaagq
miana pfa ndcfmn mcc mallbn sccmqpjj qpnoamqpjj qpnaqpjj nceeaf
a ybhd baic hdttcu oks
w rvez vwum ezkkmg dj psm trj
b fkry kbew ryggwa qu liw tfurbvw


29
baseball
football
basketball
tennis
ball
is
a
sport
which
uses
not
one
two
player
players
too
i
like
also
these
are
sports
soccer
no
chess
btw
by
the
way
u wuqe bdaebdww


6
baseball
a
k
i
like
also
u wuqe bdaebdww
*/
