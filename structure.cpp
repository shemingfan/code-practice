#include<iostream>
using namespace std;
struct student{
    int num;
    int score1,score2;
    int scoreall;
    double finalscore;
};
bool isgood(student *stu)
{
    stu->scoreall = stu->score1 + stu->score2;
    if(stu->scoreall>140 && stu->finalscore>=800){
        return true;
    }
    else
        return false;
}
int main(){
    int n;
    cin>>n;
    student s;
    for(int i=0;i<n;i++){
        cin>>s.num>>s.score1>>s.score2;
        s.finalscore = s.score1*7 + s.score2*3;
        if (isgood(&s))
        {
            cout << "Excellent" << endl;
        }
        else
            cout << "Not excellent" << endl;
    }
    return 0;
}