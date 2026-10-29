#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n,a[1001];
    bool b[1001]={false};
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++){
        int x=abs(a[i]-a[i+1]);
        if(x>=1 && x<=n-1){
            b[x]=true;
        }
    }
    for(int i=1;i<=n-1;i++){
        if(b[i]==false){
            cout<<"Not jolly"<<endl;
            exit(0);
        }
    }
    cout<<"Jolly"<<endl;
    return 0;
}