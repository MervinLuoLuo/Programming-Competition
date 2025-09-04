#include<bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int MAXN = 1e8;
const int INF = 1e18;
// using i128 =  __int128_t;
using ull = unsigned long long;
const ull MOD = (1 << 26);

char buf[1<<23],*p1=buf,*p2=buf;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
inline unsigned long long rd() {//读入一个 64 位无符号整数
	unsigned long long x=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch)) x=x*10+(ch^48),ch=gc();
	return x;
}

const ull N = 1e7 + 19;
struct Hash_table{
    const int null = 0x3f3f3f3f;
    ull h[N],kk[N],ex[N];
    void init() {
        memset(h,0,sizeof(h));
        memset(kk,0,sizeof(kk));
        memset(ex,0,sizeof(ex));
    }

    ull find(int x){
        int k = (x % N + N) % N;
        while(ex[k]){
            if(kk[k] == x) return h[k];
            k++;
            if(k == N) k = 0;
        }
        return 0;
    }

    void insert(int x,int y){
        int k = (x % N + N) % N;
        while(ex[k]){
            if(kk[k] == x) break;
            k++;
            if(k == N) k = 0;
        }
        kk[k] = x;h[k] = y;ex[k] = 1;
    }
};

void solve(){
    ull n; n = rd();
    Hash_table ht;
    ht.init();
    int ans = 0;
    for(int i = 0; i < n; i++){
        ull x,y;x = rd();y = rd();
        ull fx = (ht.find(x) * i) % MOD;
        ans = (ans + fx) % MOD;
        ht.insert(x,y);
    }
    cout << ans << endl;
}
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}