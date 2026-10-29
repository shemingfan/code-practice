#include<iostream>
#include<vector>
using namespace std;
void year(int x,int y){
    int ans=0;
    vector<int> a;
    for (int i = x; i <= y;i++){
        if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0){
            ans++;
            a.push_back(i);
        }
    }
    cout << ans << endl;
    if(a.empty()){
        return;
    }
    for (size_t i = 0; i < a.size()-1;i++){
        cout << a[i] << ' ';
    }
    cout << a[a.size() - 1] << endl;
}
int main(){
    int x, y;
    cin >> x >> y;
    year(x, y);
    return 0;
}