#include<iostream>
using namespace std;
int main(){
    int n,m;
    char a[101][101];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int t=0;
            if (a[i][j] == '*'){
                cout << '*';
                continue;
            }
            if(j-1>=0 && a[i][j-1]=='*') t++;
            if(a[i][j+1]=='*') t++;
            if(i-1>=0 && a[i-1][j]=='*') t++;
            if(a[i+1][j]=='*') t++;
            if(i-1>=0 && j-1>=0 && a[i-1][j-1]=='*') t++;
            if(a[i+1][j+1]=='*') t++;
            if(j-1>=0 && a[i+1][j-1]=='*') t++;
            if(i-1>=0 && a[i-1][j+1]=='*') t++;
            cout<<t;
        }
        cout<<endl;
    }
    return 0;
}