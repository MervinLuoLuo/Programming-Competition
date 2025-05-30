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
    string ans;
    
    cout << "mul " << 999999999 << endl;
    cout.flush();
    cin >> ans;
    if(ans != "1") return;

    cout << "digit" << endl;
    cout.flush();
    cin >> ans;
    if(ans != "1") return;

    if(n == 81){
        cout << "!" << endl;
        cout .flush();
        cin >> ans;
        if(ans != "1") return;
    }

    else{
        cout << "add " << (n - 81) << endl;
        cout.flush();
        cin >> ans;
        if(ans != "1") return;

        cout << "!" << endl;
        cout .flush();
        cin >> ans;
        if(ans != "1") return;        
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    //t = 1;
    while(t--){
       solve();
    }
    return 0;
}