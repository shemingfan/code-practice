#include<iostream>
using namespace std;
void move(char from,char to){
    cout<<from<<"-->"<<to<<endl;
}
void hanoi(int n,char from,char aux,char to){
    if(n==1) move(from,to);
    else{
        hanoi(n-1,from,to,aux);
        move(from,to);
        hanoi(n-1,aux,from,to);
    }
}
int main(){
    int m;
    cin>>m;
    hanoi(m,'A','B','C');
    return 0;
}