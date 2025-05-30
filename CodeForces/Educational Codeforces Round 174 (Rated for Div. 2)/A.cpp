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
    vector<int> b(n-2);
    for(int i = 0; i < n - 2; i++){
        cin >> b[i];
    }
    bool flag = 1;
    for(int i = 1; i < n - 3; i++){
        if(b[i - 1] == 1 and b[i] == 0 and b[i + 1] == 1){flag = 0;break;}
    }
    if(flag) yes;
    else no;
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