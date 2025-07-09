/*https://ac.nowcoder.com/acm/contest/109081*/
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
    vector<char> a(n);
    vector<string> cnt(n);
    for(char &x : a) cin >> x;
    for(string &s : cnt) cin >> s;
    int maxc = 0;
    char ans = '0';
    for(int i = 0; i < n; i++){
        string cur = cnt[i];
        string num;
        for(int j = 0; cur[j] != '/'; j++){
            num += cur[j];
        }
        int count = stoi(num);
        if(count > maxc){maxc = count;ans = a[i];}
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t--){
       solve();
    }
    return 0;
}