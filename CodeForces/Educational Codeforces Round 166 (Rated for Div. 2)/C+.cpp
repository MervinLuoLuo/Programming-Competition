#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n,m;cin >> n >> m;
        int nn = n + m + 1;
        vector<int> a(n + m + 1),b(n+ m + 1);
        for(int i = 0; i < nn; i++){
            cin >>a[i];
        }
        for(int i = 0; i < nn; i++){
            cin >> b[i];
        }
        
    }
    return 0;
}
