#include<iostream>
using namespace std;
int main(){
    int n,a[1005];
    scanf("%d",&n);
    int *p=a;//数组名a就是首元素a[0]的地址,所以取a[0]的地址为p的地址
    for(int i=0;i<n;i++){
        scanf("%d",p++);//指针向后移来存下每个数字
    }
    p=a;//让p的地址等于a的地址,将指针重置到数组开头
    int max_val=*p;//*p解引用,拿回p存的地址的值,即对应的a[0]
    for(int i=1;i<n;i++){
        p++;
        if(*p>max_val){
            max_val=*p;//如果更大,max_val存下更大值
        }
    }
    printf("%d",max_val);
    return 0;
}