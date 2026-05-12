#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >> n;
    int Xor = 0;
    for(int i = 1; i < n; i++) Xor ^= i;
    if(Xor == 0){
        cout << "impossible" << endl;
        return;
    }

    int pre = 1;
    vector<int> ans = {1,0};
    for(int i = 2; i < n; i++){
        if((pre ^ i) == 0){
            if(i == n - 1){
                cout << "impossible" << endl;
                return;
            }
            else{
                ans.push_back(i + 1);ans.push_back(i);
                pre = pre ^ i ^ (i + 1);
                i++;
            }
        }
        else{
            ans.push_back(i);
            pre ^= i;
        }
    }

    for(int x : ans) cout << x << " ";
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