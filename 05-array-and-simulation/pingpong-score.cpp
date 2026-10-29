#include<iostream>
using namespace std;
char a[100000],C;
int x=0;
void el(){
    int sc1=0,sc2=0;
    for(int i=0;i<x;i++){
        if(a[i]=='W') sc1++;
        if(a[i]=='L') sc2++;
        if((sc1>=11 || sc2>=11) && (sc1-sc2<=-2 || sc1-sc2>=2)){
            cout<<sc1<<':'<<sc2<<endl;
            sc1=0;
            sc2=0;
        }
    }
    cout<<sc1<<':'<<sc2<<endl;
}
void tw(){
    int sc1=0,sc2=0;
    for(int i=0;i<x;i++){
        if(a[i]=='W') sc1++;
        if(a[i]=='L') sc2++;
        if((sc1>=21 || sc2>=21) && (sc1-sc2<=-2 || sc1-sc2>=2)){
            cout<<sc1<<':'<<sc2<<endl;
            sc1=0;
            sc2=0;
        }
    }
    cout<<sc1<<':'<<sc2<<endl;
}
int main(){
    while(cin>>C){
        if(C=='E'){
            break;
        }
        a[x]=C;
        x++;
    }
    el();
    cout<<endl;
    tw();
    return 0;
}