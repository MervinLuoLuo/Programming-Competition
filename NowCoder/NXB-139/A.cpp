#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    int a = 0,b = 0;
    for(char c : s){
        if(c == '0') a++;
        else b++;
    }
    cin >> s;
    for(char c : s){
        if(c == '0') a++;
        else b++;
    }
    cout << a << " " << b;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}