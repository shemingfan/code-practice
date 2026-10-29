#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
void Shemian(vector<vector<int>> &a,int t,int x,int y){
    if(t==1){
        return;
    }
    int half = t / 2;
    for (int i = 0; i < half; i++)
    {
        for(int j = 0;j < half; j++){
            a[x+i][y+j]=0;
        }
    }
    Shemian(a,half,x+half,y);
    Shemian(a,half,x,y+half);
    Shemian(a,half,x+half,y+half);
}
int main(){
    int n;
    cin>>n;
    int m=pow(2,n);
    vector<vector<int>> a(m,vector<int>(m,1));
    Shemian(a,m,0,0);
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}