#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
using ull = unsigned long long;
const int INF = 1e18;
const int maxn = 1e9;
const ull N = 20000003;

char buf[1<<23],*p1=buf,*p2=buf;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline unsigned long long rd() {
	unsigned long long x=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch)) x=x*10+(ch^48),ch=gc();
	return x;
}


struct HashTable{
    vector<ull> key,val;
    vector<int> vis;
    int timer = 0;
    HashTable() : key(N),val(N),vis(N,0){}

    void init(){++timer;}

    ull find(ull x){
        ull k = x % N;
        while(vis[k] == timer){
            if(key[k] == x) return val[k];
            if(++k == N) k = 0;
        }
        return 0;
    }

    void insert(ull x, ull y){
        ull k = x % N;
        while(vis[k] == timer){
            if(key[k] == x){
                val[k] = y;return;
            }
            if(++k == N) k = 0;
        }
        vis[k] = timer;
        key[k] = x;
        val[k] = y;
    }
};
void solve(){
    ull n;n = rd();
    HashTable ht;
    ht.init();
    ull ans = 0;
    for(int i = 1; i <= n; i++){
        ull x,y;x = rd();y = rd();
        ull res = ht.find(x);
        ans += res * (ull)i;
        ht.insert(x,y);
    }
    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}