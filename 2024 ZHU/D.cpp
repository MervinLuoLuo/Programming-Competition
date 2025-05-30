#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    string str = "nc";
    for(int i = 0; i < n; i++){
        for(int j = 0;j < s[i].size();j++){
            if(s[i][j] == 'l' and s[i][j+1] == 'j' and s[i][j+2] == 'l'){
                s[i].insert(j - 1,str);
                s[i][j + 2] = 'r';
                j = j + 3;
            }
        }
    }
    for(auto p : s){
        cout << p << endl;
    }
    return 0;
}