#include<iostream>
#include<algorithm>
using namespace std;
int n;
struct stu{
    int id;
    int ch;
    int score;
}a[305];
bool cmp(const stu &u,const stu &v){
    if(u.score!=v.score){
        return u.score>v.score;
    }else if(u.ch!=v.ch){
        return u.ch>v.ch;
    }
    else return u.id<v.id;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        a[i].id=i;
        a[i].ch=x;
        a[i].score=x+y+z;
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=5;i++){
        cout<<a[i].id<<' '<< a[i].score<<endl;
    }
    return 0;
}