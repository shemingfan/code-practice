#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    char s[100];
    char op;
    for(int i=0;i<n;i++){
        scanf("%s",s);
        int num1,num2,ans;
        char op_char;
        if(s[0]=='a'|| s[0]=='b' || s[0]=='c'){
            op=s[0];
            scanf("%d %d",&num1,&num2);
        }
        else{
            sscanf(s,"%d",&num1);
            scanf("%d",&num2);
        }
        if(op=='a'){
            op_char='+';
            ans=num1+num2;
        }else if(op=='b'){
            op_char='-';
            ans=num1-num2;
        }else{
            op_char='*';
            ans=num1*num2;
        }
        char result[100];
        sprintf(result,"%d%c%d=%d",num1,op_char,num2,ans);
        printf("%s\n",result);
        printf("%d\n",strlen(result));
    }
    return 0;
}