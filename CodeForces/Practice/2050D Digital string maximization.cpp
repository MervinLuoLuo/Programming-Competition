/*https://codeforces.com/problemset/problem/2050/D*/
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
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        a[i] = s[i] - '0';
    }
    
    for(int i = 0; i < n; i++){
        int best = a[i],pos = i;
        for(int j = i; j < min(i + 10,n); j++){
            if(a[j] - (j - i) > best){
                best = a[j] - j + i;
                pos = j;
            }
        }
        while(pos > i){
            swap(a[pos],a[pos - 1]);
            pos--;
        }
        a[i] = best;
    }
    for(int x : a) cout << x;
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}