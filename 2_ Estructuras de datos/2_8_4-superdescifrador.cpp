#include <bits/stdc++.h>

#define MAX 1005

using namespace std;

int n;
vector <string> dic[MAX];
vector <string> cif;

int c[30];

bool probar(string posible, string desifrar){
    for(int i=0; i<posible.size(); i++){
        if(c[desifrar[i]-'a']){//ya esta asignada la letra
            if(c[desifrar[i]-'a'])
        }
    }
}

bool buscar(int i=0){
    string desifrar = cif[i];

    for(string posible : dic[desifrar.size()]){
        if(probar(posible, desifrar))
            if(buscar(i+1))
                return true;
    }

    return false;
}

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        string a; cin>>a;
        dic[a.size()].push_back(a);
    }

    while(!cin.eof()){
        string a; getline(cin, a);
        string ward = a;
        cif.clear();
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

        memset(c, 0, sizeof(c));
        if(!buscar())
            for(char i : ward)
                if(i==' ')cout<<" ";
                else cout<<'*';
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
*/
