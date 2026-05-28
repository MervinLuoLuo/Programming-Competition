#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
// #ifdef debug(x)
#define debug(x) debug << #x << " : " << x << endl;
using namespace std;
using i128 = __int128;
constexpr int INF = 1e9;

void solve(){
    int n; cin >> n;
    priority_queue<PII> pq;
    vector<int> w;
    for(int i = 1; i <= n; ++i){
        char op; cin >> op;
        if(op == 'F'){
            int val; cin >> val;
            pq.push({val*(n-i+1),i});
        } else {
            w.push_back(i);
        }
    }
    auto get = [&](int input,int i){
        return input/(n-i+1);
    };
    int res = 0;
    for(auto i:w){
        if(i<pq.top().second){
            res += pq.top().first;
            pq.pop();
        }else{
            res += (n-i+1)*get(pq.top().first,pq.top().second);
            pq.pop();
        }
    }
    cout<<res<<endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int tt = 1;
    cin >> tt;
    while(tt--) solve();
    return 0;
}