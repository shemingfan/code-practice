#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    vector<int> a;
    cin>>n;
    int ans=n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<(int)a.size();i++){
        if(a[i]==0) continue;
        int j=1;
        while((i+j)<n && a[i]==a[i+j]){
            ans--;
            a[i+j]=0;
            j++;
        }
    }
    cout<<ans<<endl;
    for(int i=0;i<(int)a.size();i++){
        if(a[i]==0) continue;
        cout<<a[i]<<' ';
    }
    return 0;
}