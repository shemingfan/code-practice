#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    vector<int> a;
    long long x,ans=0;
    while(cin>>x){
        a.push_back(x);
    }
    for(int i=0;i<(int)a.size();i++){
        ans+=a[i];
    }
    long long result;
    result=ans*(1LL<<((int)a.size()-1));
    cout<<result<<endl;
    return 0;
}