#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void mul(vector<int> &a, int b)
{
    int carry = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int t = a[i] * b + carry;
        a[i] = t % 10;
        carry = t / 10;
    }
    while (carry != 0)
    {
        a.push_back(carry % 10);
        carry /= 10;
    }
}
void add(vector<int> &sum, vector<int> &fact)
{
    int carry = 0;
    int n = max(sum.size(), fact.size());
    if (sum.size() < n)
        sum.resize(n);
    for (int i = 0; i < n || carry != 0; i++)
    {
        if (i == sum.size())
            sum.push_back(0);
        int t = sum[i] + carry;
        if (i < fact.size())
            t += fact[i];
        sum[i] = t % 10;
        carry = t / 10;
    }
}
void print(vector<int> &a)
{
    for (int i = a.size() - 1; i >= 0; --i)
    {
        cout << a[i];
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    vector<int> fact(1, 1);
    vector<int> sum(1, 0);
    for (int i = 1; i <= n; i++)
    {
        mul(fact, i);
        add(sum, fact);
    }
    print(sum);
    return 0;
}