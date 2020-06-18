#include <bits/stdc++.h>

#define MAX 1000005

long long l[MAX];
using namespace std;

long long calculaLongitud(long long i){
    if(i<MAX){
        if(l[i])
            return l[i];
        if(i%2)
            return l[i] = 1 + calculaLongitud(i*3 + 1);
        return l[i] = 1 + calculaLongitud(i/2);
    }
    else {
        if(i%2)
            return 1 + calculaLongitud(i*3 + 1);
        return 1 + calculaLongitud(i/2);
    }
}

int mayor(int a, int b){
    long long m = 0;
    long long p;
    for(int i=a; i<=b; i++)
        if( (p=calculaLongitud(i)) > m)
            m=p;
    return m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    l[1] = 1;
    int a, b;
    while(cin>>a>>b){
        if(b>a)
            cout<<a<<" "<<b<<" "<<mayor(a, b)<<"\n";
        else
            cout<<a<<" "<<b<<" "<<mayor(b, a)<<"\n";
    }
    return 0;
}
