#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> linearSieve(int n){
    vector<int> primes;
    vector<bool> composite(n + 1, false);
    for (int i = 2; i <= n; i++){
        if(composite[i]==false){
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size(); j++){
            int p = primes[j];
            if(i*p>n){
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
int main()
{
    int n,ans=0;
    long long ans1 = 0;
    cin >> n;
    vector<int> primes = linearSieve(n);
    for (int i = 0; i < primes.size();i++){
        if(ans1+primes[i]>n){
            break;
        }
        cout << primes[i] << endl;
        ans1 += primes[i];
        ans++;
    }
    cout << ans;
    return 0;
}