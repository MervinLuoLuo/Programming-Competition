/*https://codeforces.com/contest/2071/problem/B*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "-1" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    vector<int> ans;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += i;
        ans.push_back(i);
        int tmp = sqrt(sum);
        if(tmp * tmp == sum){
            ans.pop_back();
            ans.push_back(i + 1);
            sum += i + 1;
            ans.push_back(i);
            i++;
        }
    }
    //for(auto it : ans) cout << it << ' ';
    if(ans.size() != n) no;
    else {
        for(auto it : ans) cout << it << ' ';
        cout  << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while(t--){
       solve();
    }
    return 0;
}