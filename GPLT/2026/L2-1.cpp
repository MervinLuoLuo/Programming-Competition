#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n,T;cin >> n >> T;
    if(n == 0) {cout << "";return;}
    vector<int> r;
    stack<PII> l,l1;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        int x;cin >> x;
        if(x > T){
            l.push({i,x});
            sum += x;
        }
        else r.push_back(i);
    }
    
    while(!l.empty() || !l1.empty()){
        if(!l.empty()) T = floor(sum / l.size());
        else if(!l1.empty()) T = floor(sum / l1.size());
        
        while(!l.empty()){
            auto [idx,x] = l.top();
            l.pop();
            if(x <= T){
                r.push_back(idx);
                sum -= x;
            }
            else l1.push({idx,x});
        }

        if(!l.empty()) T = floor(sum / l.size());
        else if(!l1.empty()) T = floor(sum / l1.size());
        
        while(!l1.empty()){
            auto [idx,x] = l1.top();
            l1.pop();
            if(x <= T){
                r.push_back(idx);
                sum -= x;
            }
            else l.push({idx,x});
        }
        
    }
    for(int i = 0; i < n; i++){
        cout << r[i];
        if(i != n - 1) cout << " ";
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
