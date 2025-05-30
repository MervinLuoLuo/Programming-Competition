#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
typedef long long ll;

void solve(){
    string s;cin >> s;
    vector<int> posa,posb,posc;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'A') posa.push_back(i);
        if(s[i] == 'B') posb.push_back(i);
        if(s[i] == 'C') posc.push_back(i);
    }
    int ans = 0;
    for(int j = 0; j < posb.size(); j++){
        int b = posb[j];
        for(int i = 0; i < posa.size(); i++){
            int a = posa[i];
            for(int k = posc.size() -1; k >= 0; k--){
                int c = posc[k];
                if(c < b) break;
                if((b - a) ==(c - b)) ans++;
            }
            if(a > b) break;
        }
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}