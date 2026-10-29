#include<iostream>
using namespace std;
int main(){
    string s;
    int add=0;
    getline(cin,s);
    for(int i=0;i<s.size();i++){
        if(s[i]==' ') continue;
        add++;
    }
    cout<<add<<endl;
    return 0;
}