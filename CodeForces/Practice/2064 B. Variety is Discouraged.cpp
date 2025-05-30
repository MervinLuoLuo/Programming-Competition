/*https://codeforces.com/problemset/problem/2064/B*/
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
    int n;cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> freq(n + 1);
    for (int x : a) freq[x]++;
    vector<int> len(n + 1);
    len[0] = freq[a[0]] == 1;
    for (int i = 1; i < n; i++)
        if (freq[a[i]] == 1) len[i] = len[i - 1] + 1;
    int mx = *max_element(len.begin(), len.end());
    if (mx == 0){cout << 0 << endl;return;}
    for (int i = 0; i < n; i++){
        if (len[i] == mx){
            cout << i - len[i] + 2 << " " << i + 1 << endl;
            return;
        }
    }
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