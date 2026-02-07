#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;

void solve(){
    int n;cin >>n;
    string s;cin >> s;
    int cnt0 = 0,cnt1 = 0;
    bool flag0 = 0,flag1 = 0;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == s[i + 1]){
            if(s[i] == '0'){
                if(!flag0){
                    cnt0++;
                    flag0 = 1;
                }
                flag1 = 0;
            }
            else{
                if(!flag1){
                    cnt1++;
                    flag1 = 1;
                }
                flag0 = 0;
            }
        }
        else{
            flag0 = flag1 = 0;
        }
    }

    cout << max(cnt0,cnt1) << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}