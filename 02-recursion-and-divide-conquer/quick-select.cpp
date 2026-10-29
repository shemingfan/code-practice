#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long n, k;
long long a[5000005];
void search(long long l,long long r){
    if(l>=r){
        return;
    }
    long long num = a[l];
    vector<long long> minn, maxn;
    for (long long i = l + 1 ; i < r;i++){
        if(a[i]<num){
            minn.push_back(a[i]);
        }else{
            maxn.push_back(a[i]);
        }
    }
    long long pos = l + (int)minn.size();
    for (long long i = l; i < pos;i++){
        a[i] = minn[i-l];
    }
    a[pos] = num;
    for (long long i = pos+1; i < r; i++){
        a[i] = maxn[i-pos-1];
    }
    if(k < pos){
        search(l, pos);
    }else if(k == pos){
        printf("%lld", num);
        exit(0);
    }else{
        search(pos+1, r);
    }
}
int main(){
    scanf("%lld%lld", &n, &k);
    for (long long i = 0; i < n;i++){
        scanf("%lld", &a[i]);
    }
    search(0, n);
    return 0;
}