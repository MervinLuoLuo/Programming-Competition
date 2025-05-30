/*https://codeforces.com/contests/2091/problem/A*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

void solve(){
    int n;cin >> n;
    int num_0 = 0, num_1 = 0, num_3 = 0, num_5 = 0, num_2 = 0;
    bool flag = 0;
    int i = 1;
    for(i = 1; i <= n; i++){
        int x;cin >> x;
        if(x == 0) num_0++;
        if(x == 1) num_1++;
        if(x == 3) num_3++;
        if(x == 2) num_2++;
        if(x == 5) num_5++;
        if(num_0 >= 3 and num_1 >= 1 and num_3 >= 1 and num_2 >= 2 and num_5 >= 1){
            flag = 1;
            break;
        }
    }
    if(flag) cout << i << endl;
    else cout << 0 << endl;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
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