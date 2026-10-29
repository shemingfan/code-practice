#include<iostream>
using namespace std;
int main(){
    string s;
    int a[200]={0};
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        for(int j='a';j<'z';j++){
            if(s[i]==j) a[j]++;
        }
    }
    int maxn=-1,minn=101;
    for(int i='a';i<='z';i++){
        if(a[i]==0) continue;
        if(a[i]>maxn) maxn=a[i];
        if(a[i]<minn) minn=a[i];
    }
    int t=maxn-minn;
    if(t<2){
        cout<<"No Answer"<<endl<<0<<endl;
        return 0;
    }
    for(int i=2;i<t;i++){
        if(t%i==0){
            cout<<"No Answer"<<endl<<0<<endl;
            return 0;
        }
    }
    cout<<"Lucky Word"<<endl<<t<<endl;
    return 0;
}