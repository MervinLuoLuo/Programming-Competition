/*https://www.luogu.com.cn/problem/P1581*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e4;
bool nisp[MAXN + 2];
vector<int> p;

void sp(){
    for(int i = 2; i <= MAXN; i++){
        if(!nisp[i]) p.push_back(i);
        for(int j : p){
            if(i * j > MAXN) break;
            nisp[i * j] = 1;
            if(i % j == 0) break;
        }
    }
}


void solve(){
    string s;cin >> s;
    int len = s.find('+');
    string l = s.substr(0,len),r = s.substr(len + 1, INF);
    if(l.size() < r.size()) swap(l,r);
    // cout << l << endl << r << endl;
    
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sp();
    solve();
    return 0;
}