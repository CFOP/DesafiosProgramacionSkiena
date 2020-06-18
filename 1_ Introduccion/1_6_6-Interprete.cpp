#include <bits/stdc++.h>

using namespace std;

#define MAX 1005

string RAM[MAX];
int R[10];
int n;

int rAM(int i){
    int n=0;
    n+=(RAM[i][0]-'0')*100;
    n+=(RAM[i][1]-'0')*10;
    n+=(RAM[i][2]-'0');
    return n;
}

string r(int i){
    string n="";
    n+=R[i]/100+'0';
    n+=(R[i]%100)/10+'0';
    n+=R[i]%10+'0';
    return n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;

    string a;
    getline(cin, a);
    getline(cin, a);
    while(n--){

        for(int i=0; i<MAX; i++)RAM[i]="000";
        for(int i=0; i<10; i++)R[i]=0;

        {
            int i=0;
            for(getline(cin, a); a!="" && !cin.eof(); getline(cin, a))
                RAM[i++]=a;
        }


        int k=0;
        for(int i=0; true; i++){
            //cout<<i<<"\n";
            //getchar();
            k++;
            //k%=1000;
            if(RAM[i]=="100")
                break;

            switch(RAM[i][0]){
                case '2':
                    R[RAM[i][1]-'0']=RAM[i][2]-'0';
                break;
                case '3':
                    R[RAM[i][1]-'0']+=RAM[i][2]-'0';
                    R[RAM[i][1]-'0']%=1000;
                break;
                case '4':
                    R[RAM[i][1]-'0']*=RAM[i][2]-'0';
                    R[RAM[i][1]-'0']%=1000;
                break;
                case '5':
                    R[RAM[i][1]-'0']=R[RAM[i][2]-'0'];
                break;
                case '6':
                    R[RAM[i][1]-'0']+=R[RAM[i][2]-'0'];
                    R[RAM[i][1]-'0']%=1000;
                break;
                case '7':
                    R[RAM[i][1]-'0']*=R[RAM[i][2]-'0'];
                    R[RAM[i][1]-'0']%=1000;
                break;
                case '8':
                    {
                       int a = RAM[i][2]-'0';
                       int d = RAM[i][1]-'0';
                       R[d]=rAM(R[a]);
                    }
                break;
                case '9':
                    {
                       int s = RAM[i][1]-'0';
                       int a = RAM[i][2]-'0';
                       RAM[R[a]] = r(s);
                    }
                break;
                case '0':
                    {
                       int d = RAM[i][1]-'0';
                       int s = RAM[i][2]-'0';
                       if(R[s])
                        i=R[d]-1;
                    }
                break;
            }

        }
        cout<<k<<"\n";
        if(n)cout<<"\n";
    }
    return 0;
}

/*
1

299
492
495
399
492
495
399
283
279
689
078
100
000
000
000

1

297
287
273
689
078
100

0
0
0
0
0
0
0
3
14
7


5

299
492
495
399
492
495
399
283
279
689
078
100
000
000
000

221
422
425
000
311
712
712
913
031

299
233
255
990
803
301
050
100

212
415
521
721
532
439
543
631
339
923
029
873
674
027
023

299
492
495
399
492
495
399
589
279
689
279
078
100
000
000
000

1

212
415
521
721
532
439
543
631
339
923
029
873
674
027
023
*/
