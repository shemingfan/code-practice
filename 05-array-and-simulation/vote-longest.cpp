#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct person{
    int id;
    string vote;
};
int main(){
    int n;
    cin>>n;
    vector<person> resident; 
    for(int i=0;i<n;i++){
        person p;
        p.id=i+1;
        string s;
        cin>>s;
        p.vote=s;
        resident.push_back(p);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(resident[i].vote.size()>ans){
            ans=resident[i].vote.size();
        }
    }
    string ss[21];
    int add=0;
    for(int i=0;i<n;i++){
        if(resident[i].vote.size()!=ans){
            continue;
        }else{
            ss[add]=resident[i].vote;
            add++;
        }
    }
    string result=ss[0];
    for(int i=0;i<add;i++){
        if(result<ss[i]){
            result=ss[i];
        }
    }
    for(int i=0;i<n;i++){
        if(resident[i].vote==result){
            cout<<resident[i].id<<endl;
            cout<<resident[i].vote<<endl;
            break;
        }
    }
    return 0;
}