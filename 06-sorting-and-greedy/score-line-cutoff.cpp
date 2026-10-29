#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct competitor{
    int k;
    int s;
};
bool cmp(const competitor &u,const competitor &v){
    if(u.s!=v.s){
        return u.s>v.s;
    }else{
        return u.k<v.k;
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<competitor> comp;
    for(int i=0;i<n;i++){
        competitor temp;
        cin>>temp.k>>temp.s;
        comp.push_back(temp);
    }
    sort(comp.begin(),comp.end(),cmp);
    int line=m*15/10,ans=0;
    int scoreline=comp[line-1].s;
    for(int i=0;i<n;i++){
        if(comp[i].s>=scoreline) ans++;
    }
    cout<<scoreline<<' '<<ans<<endl;
    for(int i=0;i<ans;i++){
        cout<<comp[i].k<<' '<<comp[i].s<<endl;
    }
    return 0;
}