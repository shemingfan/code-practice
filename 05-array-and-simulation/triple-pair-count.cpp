#include <iostream>
using namespace std;
int main(){
    int n,a[1001][4],ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            if(a[i][0]-a[j][0]<=5 && a[i][0]-a[j][0]>=-5 && a[i][1]-a[j][1]<=5 && a[i][1]-a[j][1]>=-5 && a[i][2]-a[j][2]<=5 && a[i][2]-a[j][2]>=-5){
                int add1=a[i][0]+a[i][1]+a[i][2];
                int add2=a[j][0]+a[j][1]+a[j][2];
                if(add1-add2>=-10 && add1-add2<=10){
                    ans++;
                }
            }
        }
    }
    cout<<ans/2<<endl;
}

