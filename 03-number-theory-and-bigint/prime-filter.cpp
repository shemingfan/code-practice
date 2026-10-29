#include<iostream>
#include<vector>
using namespace std;
vector<int> prime(int n){
    vector<int> primes;
    vector<bool> composite(n + 1,false);
    for (int i = 2; i <= n;i++){
        if(composite[i]==false){
            primes.push_back(i);
        }
        for (size_t j = 0; j < primes.size();j++){
            int p = primes[j];
            if(p*i>n){
                break;
            }
            composite[p * i] = true;
            if(i%p==0){
                break;
            }
        }
    }
    return primes;
}
int main(){
    int n,a[101];
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    vector<int> primes = prime(100000);
    for (int i = 0; i < n;i++){
        for (size_t j = 0;j < primes.size();j++){
            if(a[i]==primes[j]){
                if(i==n-1){
                    cout << a[i] << endl;
                    break;
                }
                else{
                    cout << a[i] << ' ';
                    break;
                }
            }
        }
    }
        return 0;
}