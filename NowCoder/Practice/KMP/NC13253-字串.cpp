/*https://ac.nowcoder.com/acm/problem/13253*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;


string trans(int x,int k){
    string res;
    while(x){
        int y = x % k;
        if(y >= 10) res += (y - 10) + 'A';
        else res += y + '0';
        x /= k;
    }
    reverse(res.begin(),res.end());
    return res;
}

vector<int> pre(const string &s){
    int len = s.size();
    vector<int> pi(len);
    for(int i = 1; i < len; i++){
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) j = pi[j - 1];
        if(s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

void solve(){
    int n;cin >> n;
    string t;cin >> t;
    int k = 2;
    for(char c : t) {
        int val;
        if('0' <= c && c <= '9') val = c - '0';
        else val = c - 'A' + 10;
        k = max(k, val + 1);
    }
    vector<int> pi = pre(t);
    for(;k <= 16; k++){
        int j = 0;
        for(int i = 1; i <= n; i++){
           string s = trans(i,k);
            for(char c : s){
                while(j > 0 && t[j] != c) j = pi[j - 1];
                if(t[j] == c) j++;
                if(j == t.size()){
                    cout << "yes" << endl;
                    return;
                }
            }
        }
    }
    cout << "no" << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}