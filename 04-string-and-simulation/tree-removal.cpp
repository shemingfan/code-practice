#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int l, n, ans = 0;
    cin >> l >> n;
    vector<int> a(l + 1, 1);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        for (int j = x; j <= y; j++)
        {
            a[j] = 0;
        }
    }
    for (int i = 0; i <= l; i++)
    {
        if (a[i] == 1)
        {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}