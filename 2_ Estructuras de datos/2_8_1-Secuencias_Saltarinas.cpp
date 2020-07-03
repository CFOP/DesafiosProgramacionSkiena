#include <bits/stdc++.h>
#define MAX 3005

using namespace std;

bool dif[MAX];
int s;
int a, b;
int n;

void isJolly(){
    s=0;
    cin>>a;
    for(int i=1; i<n; i++){
        cin>>b;
        //cout<<b-a;
        if(abs(b-a) < n){
            if(!dif[abs(b-a)]){
                dif[abs(b-a)]=true;
            }
            else {
                cout<<"Not jolly\n";
                for(i++; i<n; i++)
                    cin>>b;
                return;
            }
        }
        else {
            cout<<"Not jolly\n";
            for(i++; i<n; i++)
                    cin>>b;
            return;
        }
        a=b;
    }
    cout<<"Jolly\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n){
        for(int i=0; i<MAX; i++)
            dif[i]=false;
        isJolly();
    }
    return 0;
}

