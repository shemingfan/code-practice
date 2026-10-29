#include<iostream>
using namespace std;
int jiecheng(int n){
    if(n==0){
        return 1;
    }
    return jiecheng(n-1)*n;
}
int main(){
    int n;
    cin>>n;
    cout<<jiecheng(n)<<endl;
    return 0;
}