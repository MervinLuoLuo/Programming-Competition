/*https://www.luogu.com.cn/problem/P3375*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<int,int>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

vector<int> pre(string s){
    int len = s.size();
    vector<int> pi(len);
    for(int i = 1; i < len; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j =pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }

    return pi;
}

void solve(){
    string s,t;cin >> s >> t;
    string S = t + "#" + s;
    vector<int> pi = pre(S);
    // for(int x : pi) cerr << x << " ";

    vector<int> ans;
    for(int i = t.size() + 1; i < S.size();i++){
        if(pi[i] == t.size()){
            int pos = i - 2 * (int)t.size() + 1;
            ans.push_back(pos);
            // cerr << i << endl;
        }
    }
    // cout << ans.size() << endl;
    for(int x : ans )cout << x << endl;
    vector<int> res = pre(t);
    for(int x: res) cout << x << " ";
    cout << endl;

}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}