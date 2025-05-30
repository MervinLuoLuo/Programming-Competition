/*https://codeforces.com/contest/2098/problem/A*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    string s;cin >> s;
    int n = s.size();
    map<int,int> freq;
    for(int i = 0; i < n; i++){
        freq[s[i] - '0']++;
    }
    for(int i = 9; i >= 0; i--){
        int pos = i;
        while(!freq[pos]) pos++;
        cout << pos;
        freq[pos]--;
    }
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}