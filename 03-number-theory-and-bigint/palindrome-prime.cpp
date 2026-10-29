#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> linearSieve(int n)
{
    vector<int> primes;
    vector<bool> composite(n + 1, false);
    for (int i = 2; i <= n; i++)
    {
        if (composite[i] == false)
        {
            primes.push_back(i);
        }
        for (int j = 0; j <= primes.size(); j++)
        {
            int p = primes[j];
            if (i * p > n)
            {
                break;
            }
            composite[i * p] = true;
            if (i % p == 0)
            {
                break;
            }
        }
    }
    return primes;
}
bool palindrome(int n)
{
    string s = to_string(n);
    string t = s;
    reverse(t.begin(), t.end());
    if (s == t)
        return true;
    else
        return false;
}
int main()
{
    int a, b;
    cin >> a >> b;
    vector<int> primes = linearSieve(b);
    for (int i = 0; i < primes.size(); i++)
    {
        if (primes[i] >= a && palindrome(primes[i]) == true)
        {
            cout << primes[i] << endl;
        }
    }
    return 0;
}