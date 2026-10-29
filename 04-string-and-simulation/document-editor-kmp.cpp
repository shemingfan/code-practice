#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
void num4(const vector<char> &s, const string &t){
    int n = (int)s.size();
    int m = (int)t.size();
    if (m == 0 || m > n){
        cout << -1 << endl;
        return;
    }
    vector<int> nxt(m, 0);
    for (int i = 1; i < m; i++){
        int j = nxt[i - 1];
        while (j > 0 && t[i] != t[j]) j = nxt[j - 1];
        if (t[i] == t[j]) j++;
        nxt[i] = j;
    }
    int j = 0;
    for (int i = 0; i < n; i++){
        while (j > 0 && s[i] != t[j]) j = nxt[j - 1];
        if (s[i] == t[j]) j++;
        if (j == m){
            cout << (i - m + 1) << endl;
            return;
        }
    }
    cout << -1 << endl;
}

void printDoc(const vector<char> &s){
    for (int j = 0; j < (int)s.size(); j++) cout << s[j];
    cout << endl;
}

int main(){
    int q;
    cin >> q;
    cin.ignore();

    string str;
    cin >> str;  
    cin.ignore();

    vector<char> s(str.begin(), str.end());

    for (int k = 0; k < q; k++){
        string line;
        getline(cin, line);
        if (line.empty()) { k--; continue; }

        istringstream iss(line);
        int op;
        iss >> op;

        if (op == 1){
            string t;
            iss >> t;
            s.insert(s.end(), t.begin(), t.end());
            printDoc(s);
        }
        else if (op == 2){
            int a, b;
            iss >> a >> b;
            vector<char> s2;
            for (int j = a; j < a + b && j < (int)s.size(); j++){
                s2.push_back(s[j]);
            }
            s.swap(s2);
            printDoc(s);
        }
        else if (op == 3){
            int a;
            string t;
            iss >> a >> t;
            if (a > (int)s.size()) a = (int)s.size();
            s.insert(s.begin() + a, t.begin(), t.end());
            printDoc(s);
        }
        else if (op == 4){
            string t;
            iss >> t;
            num4(s, t);
        }
    }
    return 0;
}
