#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

bool check(int k,int b,int cnto,int cnte){
    int c = k - 1 - b;
    int remo = cnto - 1,reme = cnte - b;
    int L = max(0LL,k - 1- cnte), R = min(remo,c);

    if(L > R) return 0;
    if(L % 2 == 0) return 1;
    return (L + 1 <= R);
}

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<int> odd,even;
    sort(a.begin(),a.end(),greater<int>());
    for(int x : a){
        if(x % 2 == 1) odd.push_back(x);
        else even.push_back(x);
    }

    int cnto = odd.size(),cnte = even.size();
    if(cnto == 0){
        for(int i = 1; i <= n; i++) cout << 0 << " ";
        cout << endl;
        return;
    }


    int maxo = odd[0];
    vector<int> pree(cnte + 1, 0);
    for(int i = 0; i < cnte; i++){
        pree[i + 1] = even[i] + pree[i];
    }

    for(int k = 1; k <= n;k ++){
        if(k == 1) {
            cout << maxo << " ";
            continue;
        }

        int par = (k - 1) % 2;
        int br = min(cnte, k - 1);
        if(br % 2 != par) br--;
        
        int bl = par;
        if(br < bl){cout << 0 << " ";continue;}

        int m = (br - bl) / 2;
        int l = 0,r = m;
        int best = -1;

        while(l <= r){
            int mid = (r + l) / 2;
            int b = bl + 2 * mid;
            if(check(k,b,cnto,cnte)){
                best = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        if(best == -1) cout << 0 << " ";
        else{
            int bo = bl + 2 * best;
            int ans = maxo + pree[bo];
            cout << ans << " ";
        }
    }
    cout << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}