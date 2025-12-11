#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    string s,t;cin >> t >> s;
    int n = s.size(),m = t.size();
    vector<int> freqs(26,0),freqt(26,0);
    for(char c : s) freqs[c - 'a']++;
    for(char c : t) freqt[c - 'a']++;

    // for(int i = 0; i < 26; i++) cerr << freqt[i] << " ";
    for(int i = 0; i < 26; i++){
        if(freqs[i] < freqt[i]){
            cout << "Impossible" << endl;
            return;
        }
        freqs[i] -= freqt[i];
    }

    string ans = "";
    queue<int> q;
    for(int i = 0; i < 26; i++){
        while(freqs[i] > 0){
            q.push(i);
            freqs[i]--;
        }
    }
    int p = 0;
    while(!q.empty()){
        char u = 'a' + q.front();
        q.pop();
        while(p < m && t[p] <= u){
            ans += t[p];
            p++;
        }
        ans += u;
    }

    while(p < m){
        ans += t[p];
        p++;
    }

    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}