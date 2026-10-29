#include <iostream>
using namespace std;
int main(){
    int w,x,h,q,ans=0;
    cin>>w>>x>>h>>q;
    int a[101][101][101]={0};
    for(int i=0;i<q;i++){
        int x1,x2,y1,y2,z1,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        for(int j1=x1;j1<=x2;j1++){
            for(int j2=y1;j2<=y2;j2++){
                for(int j3=z1;j3<=z2;j3++){
                    a[j1][j2][j3]=1;
                }
            }
        }
    }
    for(int j1=1;j1<=w;j1++){
        for(int j2=1;j2<=x;j2++){
            for(int j3=1;j3<=h;j3++){
                if(a[j1][j2][j3]==0) ans++;
            }
        }
    }
    cout<<ans<<endl;
}

