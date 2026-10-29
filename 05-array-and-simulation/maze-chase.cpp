#include<iostream>
using namespace std;
int main(){
    char a[11][11];
    int x1,y1,x2,y2;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin>>a[i][j];
            if(a[i][j]=='C') {
                x1=i;
                y1=j;;
            }
            if(a[i][j]=='F'){
                x2=i;
                y2=j;
            }
        }
    }
    int tx1=-1,ty1=0,tx2=-1,ty2=0,time=0;
    while(x1!=x2 || y1!=y2){
        if((x1+tx1>=0 && y1+ty1>=0 && x1+tx1<=9 && y1+ty1<=9) && a[x1+tx1][y1+ty1]!='*'){
            x1+=tx1;
            y1+=ty1;
        }else{
            if(tx1==0 && ty1==-1){
                tx1=-1;
                ty1=0;
            }
            else if(tx1==1 && ty1==0){
                tx1=0;
                ty1=-1;
            }
            else if(tx1==0 && ty1==1){
                tx1=1;
                ty1=0;
            }
            else if(tx1==-1 && ty1==0){
                tx1=0;
                ty1=1;
            }
        }
        if((x2+tx2>=0 && y2+ty2>=0 && x2+tx2<=9 && y2+ty2<=9) && a[x2+tx2][y2+ty2]!='*'){
            x2+=tx2;
            y2+=ty2;
        }else{
            if(tx2==0 && ty2==-1){
                tx2=-1;
                ty2=0;
            }
            else if(tx2==1 && ty2==0){
                tx2=0;
                ty2=-1;
            }
            else if(tx2==0 && ty2==1){
                tx2=1;
                ty2=0;
            }
            else if(tx2==-1 && ty2==0){
                tx2=0;
                ty2=1;
            }
        }
        time++;
        if(time>160000) break;
    }

    if(time<=160000) cout<<time<<endl;
    else cout<<0<<endl;
    return 0;
}

