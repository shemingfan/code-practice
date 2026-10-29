#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,b;
    cin>>n>>b;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int ans=0,k=(int)a.size()-1;
    int add=0;
    while(ans<b){
        ans+=a[k];
        k--;
        add++;
    }
    cout<<add<<endl;
    return 0;
}