#include <iostream>
using namespace std;
int main(){
    int n,a[1001][8],b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0;
    cin>>n;
    for(int i=0;i<=n;i++){
        for(int j=0;j<7;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        int t=0;
        for(int j=0;j<7;j++){
            for(int k=0;k<7;k++){
                if(a[i][j]==a[0][k]) t++;
            }
        }
        if(t==1) b7++;
        if(t==2) b6++;
        if(t==3) b5++;
        if(t==4) b4++;
        if(t==5) b3++;
        if(t==6) b2++;
        if(t==7) b1++;
    }
    cout<<b1<<' '<<b2<<' '<<b3<<' '<<b4<<' '<<b5<<' '<<b6<<' '<<b7<<endl;
}