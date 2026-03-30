#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

int tran(char c){
    if(c == 'M') return 1;
    if(c == 'K') return 2;
    if(c == 'G') return 3;
    if(c == 'F') return 4;
    if(c == 'A') return 5;
    if(c == 'B') return 6;
    if(c == 'O') return 7;
}

void solve(){
    string s1,s2;cin >> s1 >> s2;
    int a = tran(s1[0]),b = tran(s2[0]);
    if(a > b) cout << "hotter" << endl;
    else if(a < b) cout << "cooler" << endl;
    else{
        if(s1[1] > s2[1]) cout << "cooler" << endl;
        else if(s1[1] < s2[1]) cout << "hotter" << endl;
        else cout << "same" << endl;
    }
       
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}