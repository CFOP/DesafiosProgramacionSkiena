#include <bits/stdc++.h>
#define MAX 505

using namespace std;

int calle[MAX];
int T;
int n;
int s;
int suma[MAX];

int main(){
    cin>>T;

    while(T--){
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>calle[i];
        sort(calle, calle+n);
        s=1;

        for(int i=1; i<n; i++)
           if(calle[s-1]!=calle[i]){
                calle[s++]=calle[i];
           }

        suma[0]=0;
        for(int i=1; i<s; i++){
            suma[i] = calle[i] - calle[i-1];
        }


    }
    return 0;
}
