#include<iostream>
using namespace std;
void swap(int &a,int &b,int &c){
    int x;
    x=a;
    a=b;
    b=c;
    c=x;
}
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    swap(a,b,c);
    cout<<a<<' '<<b<<' '<<c<<endl;
}