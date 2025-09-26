#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    vector<int> posa,posb;
    for(int i = 0; i < n; i++){
        if(s[i] == 'a') posa.push_back(i);
        else posb.push_back(i);
    }

    auto calc= [&](vector<int> pos){
        int k = pos.size();
        if(k == 0) return INF;
        vector<int> diff(k);
        for(int i = 0; i < k; i++) diff[i] = pos[i] - i;
        
        nth_element(diff.begin(),diff.begin() + k / 2,diff.end());
        int med = diff[k / 2];
        int res = 0;
        for(int i = 0; i < k; i++) res += abs(diff[i] - med);
        return res;
    };

    cout << min(calc(posa),calc(posb)) << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}