#include <bits/stdc++.h>

using namespace std;

int main(){
    set <int> hartal;

    int t;
    cin>>t;

    while(t--){
        int n; cin>>n;
        int p; cin>>p;
        hartal.clear();

        while(p--){
            int h; cin>>h;
            for(int i=h; i<=n; i+=h)
                hartal.insert(i-1);
        }

        int total = 0;
        for(int i=0; i<=n; i++){
            if(i%7 >= 5) continue;
            if(hartal.find(i)!=hartal.end())total++;
        }

        cout<<total<<"\n";

    }

    return 0;
}
/*
1
100
4
12
15
25
40

1
14
3
3
4
8
*/
