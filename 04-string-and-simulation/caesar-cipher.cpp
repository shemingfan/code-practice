#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++){
        s[i]=(s[i]-'a'+n)%26+'a';
    }
    cout<<s<<endl;
    return 0;
}