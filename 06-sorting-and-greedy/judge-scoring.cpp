#include<iostream>
#include<iomanip>
using namespace std;
int n,m,a[101][21];
float score(int x){
    int maxn=-1,minn=11;
    float ans,add=0;
    for(int i=0;i<m;i++){
        add+=a[x][i];
        if(a[x][i]>maxn){
            maxn=a[x][i];
        }
        if(a[x][i]<minn){
            minn=a[x][i];
        }
    }
    ans=(add-minn-maxn)/(m-2);
    return ans;
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    float mm=-1;
    for(int i=0;i<n;i++){
        if(score(i)>mm) mm=score(i);
    }
    cout<<fixed<<setprecision(2)<<mm<<endl;
    return 0;
}