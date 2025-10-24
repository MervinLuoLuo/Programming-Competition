#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int MAXN = 1e8;
const int INF = 1e18;

int S;
vector<int> F(8,0);

bool check(int x){
    for(int i = 1; i < 8; i++){
        int sum = 0;
        for(int s = 1; s < 8; s++){
            if((s & i) > 0) sum += F[s];
        }
        if(x * popcount((unsigned)i) > sum) return 0;
    }
    return 1;
}

void solve(){
    cin >> S;
    for(int i = 1; i <= 7; i++) cin >> F[i];
    int l = 0, r = S;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }

    cout << l - 1 << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}