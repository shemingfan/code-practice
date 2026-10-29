#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct student{
    string name;
    int yu;
    int shu;
    int ying;
    int ans;
};
int main(){
    int n,maxn=-1,t;
    cin>>n;
    vector<student> stu(n);
    for(int i=0;i<n;i++){
        cin>>stu[i].name>>stu[i].yu>>stu[i].shu>>stu[i].ying;
        stu[i].ans=stu[i].yu+stu[i].shu+stu[i].ying;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(abs(stu[i].ans-stu[j].ans)<=10 && abs(stu[i].yu-stu[j].yu)<=5 && abs(stu[i].shu-stu[j].shu)<=5 && abs(stu[i].ying-stu[j].ying)<=5){
                cout<<stu[i].name<<' '<<stu[j].name<<endl;
            }
        }
    }
    return 0;
}