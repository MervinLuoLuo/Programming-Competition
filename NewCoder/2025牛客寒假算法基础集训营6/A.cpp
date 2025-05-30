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
    int n;cin >> n;
    vector<int >b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    vector<int> a;
    for(int i = 0; i < n; i++){
        if(b[i] == b[i - 1]) continue;
        a.push_back(b[i]);
    }
    cout << a.size() << endl;
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