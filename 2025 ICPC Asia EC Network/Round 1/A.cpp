#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int,int>
#define vii vector<vector<int>>
const int INF = 1e18;
const int MAXN = 1e8;

struct Tag{
    
};

void solve(){
    int n;cin >> n;
    map<string,int> t;
    int id = 1;
    vii ID;
    for(int i = 0; i < n; i++){
        string name;cin >> name;
        if(t[name] == 0) {
            t[name] = id++;
        }
        string id;cin >> id;
         
    }

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