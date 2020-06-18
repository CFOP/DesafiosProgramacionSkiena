#include <bits/stdc++.h>
using namespace std;

vector<short> number;
string word;
int s;

void print1(int n){
    cout<<" ";
    for(int i=0; i<s; i++){
        if(n==4 || n==1) cout<<" ";
        else cout<<"-";
    }
    cout<<" ";
}
void print2(int n){
    if(n==4 || n==5 || n==6 || n==8 || n==9 || n==0)
        cout<<"|";
    else
        cout<<" ";
    for(int i=0; i<s; i++)
        cout<<" ";
    if(n==2 || n==3 || n==4 || n==7 || n==8 || n==9 || n==0 || n==1)
        cout<<"|";
    else
        cout<<" ";
}
void print3(int n){
    cout<<" ";
    for(int i=0; i<s; i++){
        if(n==7 || n==1 || n==0) cout<<" ";
        else cout<<"-";
    }
    cout<<" ";
}
void print4(int n){
    if(n==2 || n==6 || n==8 || n==0)
        cout<<"|";
    else
        cout<<" ";
    for(int i=0; i<s; i++)
        cout<<" ";
    if(n==1 || n==3 || n==4 || n==5 || n==8 || n==9 || n==0 || n==6 || n==7)
        cout<<"|";
    else
        cout<<" ";
}
void print5(int n){
    cout<<" ";
    for(int i=0; i<s; i++){
        if(n==4 || n==1 || n==7) cout<<" ";
        else cout<<"-";
    }
    cout<<" ";
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(cin>>s>>word;s || word!="0";cin>>s>>word){

     ///crear arreglo de numeros
      number.clear();
      for(int i=0; i<word.size(); i++){
        number.push_back(word[i]-'0');
      }


      ///print

      for(int i=0; i<number.size(); i++){ //1
        print1(number[i]);
        if(i<number.size()-1)cout<<" ";
      } cout<<"\n";

      for(int j=0; j<s; j++){
          for(int i=0; i<number.size(); i++){ //2
            print2(number[i]);
            if(i<number.size()-1)cout<<" ";
          } cout<<"\n";
      }

      for(int i=0; i<number.size(); i++){ //3
        print3(number[i]);
        if(i<number.size()-1)cout<<" ";
      } cout<<"\n";

      for(int j=0; j<s; j++){
          for(int i=0; i<number.size(); i++){ //4
            print4(number[i]);
            if(i<number.size()-1)cout<<" ";
          } cout<<"\n";
      }

      for(int i=0; i<number.size(); i++){ //5
        print5(number[i]);
        if(i<number.size()-1)cout<<" ";
      } cout<<"\n";
      cout<<"\n";
    }
    return 0;
}

/*
2 12345
3 67890
0 0

6 35138132
5 6584131
10 543
1 99999999
9 135
2 351381
4 6846354
10 0
5 1094
4 11111
3 18818818
1 0
2 0
3 0
8 31415
2 007
0 0

*/
