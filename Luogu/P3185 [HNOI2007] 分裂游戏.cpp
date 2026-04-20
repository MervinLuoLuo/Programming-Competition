/*https://www.luogu.com.cn/problem/P3185*/
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
constexpr int N = 21;

vector<int> sg(N,0);

void SG(){
    for(int i = 1; i < N; i++){
        vector<int> vis(101,0);
        for(int j = i - 1; j >= 0; j--){
            for(int k = j; k >= 0; k--){
                vis[sg[j] ^ sg[k]] = 1;
            }
        }

        for(int s = 0; s < 101; s++){
            if(!vis[s]){
                sg[i] =s;
                break;
            }
        }
    }
}

void solve(){
    int n;cin >> n;
    vector<int> a(n);
    for(int i = n - 1; i >= 0; i--) cin >> a[i];

    int res = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] & 1) res ^= sg[i];
    }

    if(res == 0){
        cout << "-1 -1 -1" << endl;
        cout << 0 << endl;
        return;
    }

    int cnt = 0;
    int x = -1,y = -1, z = -1;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] > 0){
            for(int j = i - 1;j >= 0; j--){
                for(int k = j;k >= 0; k--){
                    int tmp = res ^ sg[i] ^ sg[j] ^ sg[k];
                    if(tmp == 0){
                        cnt++;
                        if(x == -1){
                            x = n - i - 1;
                            y = n - j - 1;
                            z = n - k - 1;
                        }
                    }
                }
            }
        }
    }

    cout << x << " " <<y << " " << z << endl;
    cout << cnt << endl;
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    SG();
    while(t--){
        solve();
    }
    return 0;
}