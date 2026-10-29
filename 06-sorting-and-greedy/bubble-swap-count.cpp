#include<iostream>
#include<vector>
using namespace std;
void swap(int &x,int &y){
    int temp=x;
    x=y;
    y=temp;
}
int main(){
    int n;
    cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    int add=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(j==n-1) break;
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                add++;
            }
        }
    }
    cout<<add<<endl;
    return 0;
}