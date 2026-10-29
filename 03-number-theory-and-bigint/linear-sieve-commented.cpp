#include <iostream>
#include <vector>
using namespace std;

vector<int> linearSieve(int n)
{
    vector<int> primes;                     // 用来存所有质数
    vector<bool> isComposite(n + 1, false); // false 表示“还不是合数”

    for (int i = 2; i <= n; i++)
    {
        // 如果 i 没被标记成合数，那它就是质数
        if (isComposite[i] == false)
        {
            primes.push_back(i);
        }

        // 用当前的 i，去乘已经找到的质数
        for (int j = 0; j < primes.size(); j++)
        {
            int p = primes[j];

            // 如果 i * p 超过 n，就不用继续了
            if (i * p > n)
            {
                break;
            }

            // 标记 i * p 是合数
            isComposite[i * p] = true;

            // 关键一步：如果 i 能被 p 整除，就立刻停止
            if (i % p == 0)
            {
                break;
            }
        }
    }

    return primes;
}

int main()
{
    int n = 30;

    vector<int> primes = linearSieve(n);

    for (int i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << " ";
    }
    cout << endl;

    return 0;
}