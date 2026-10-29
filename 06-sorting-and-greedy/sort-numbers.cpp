#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int m;
    vector<int> a;
    cin>>m;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<(int)a.size();i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    return 0;
}