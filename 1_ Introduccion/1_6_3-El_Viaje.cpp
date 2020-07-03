#include <bits/stdc++.h>

#define MAX 1005

using namespace std;

int est[MAX]; //cuanto dinero gasto cada estudiante
int d[MAX]; //el dinero que gasto cada estudiante en enteros
int total;
int dar, mayor,menor;
double p;


int n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //cout<< setprecision(2)<<fixed;
    for(cin>>n; n; cin>>n){
        total = 0;
        dar = 0;
        mayor=menor=0;
        for(int i=0; i<n; i++){
            cin>>p;
            p*=100;
            est[i] = p;
            total += est[i];
            //cout<<p<<" "<<est[i]<<"\n";
        }
        //cout<<total<<"\n";
        if(total%n){
            double a = total%n;
            total-= total%n;

            if(a/n>=0.5)
                total+=n;
        }
        total/=n;

        for(int i=0; i<n; i++){
            if(est[i]>total){
                mayor+=est[i]-total;
            }
            else {
                menor+=total-est[i];
            }
        }
        if(mayor<menor)dar=mayor;
        else dar=menor;

        cout<<"$"<<(double)dar/100<<"\n";
    }

    return 0;
}


/*
3
10.00
20.00
30.00
4
15.00
15.01
3.00
3.01
0

6
12.00
11.99
11.95
5.55
5.54
5.53
6
12.00
11.99
11.96
5.55
5.54
5.53
6
12.00
11.99
11.97
5.55
5.54
5.53
6
12.00
11.99
11.98
5.55
5.54
5.53
6
12.00
11.99
11.99
5.55
5.54
5.53
6
12.00
11.99
11.99
5.56
5.54
5.53
2
12.00
12.00
1
99.99
0
*/
