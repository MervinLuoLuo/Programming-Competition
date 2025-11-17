#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
constexpr int INF = 1e18;
constexpr int maxn = 1e9;

map<string,int> rf;
map<int,string> f;
void ini(){
    int cur = 0;
    int now = 1923;
    while(now <= 2024){
        bitset<8> hc(cur);
        string s = "";
        for(int i = 0; i < 8; i++){
            s += hc[i] ? '1' : '0';
        }

        string rs = s;
        reverse(rs.begin(),rs.end());
        if(!rf.count(s) && !rf.count(rs)){
            f[now] = s;
            rf[s] = now;
            rf[rs] = now;
            now++;
        }
        cur++;
    }
}

void solve(){
    string op;cin >> op;

    if(op == "write"){
        int n;cin >> n;
        cout << f[n] << endl;
    }
    else{
        string s;cin >> s;
        cout << rf[s] << endl;
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ini();
    solve();
    return 0;
}