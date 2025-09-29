    /*https://www.luogu.com.cn/problem/P1896*/
    #include <bits/stdc++.h>
    #define endl '\n'
    #define yes cout << "YES" << endl
    #define no cout << "NO" << endl
    #define int long long
    #define pii pair<int,int>
    #define vii vector<vector<int>>
    using namespace std;
    const int INF = 1e18;
    const int maxn = 1e9;
    int dp[10][100][2000];
    int cnt[2000],ok[2000];
    int n,k,num;

    void solve(){
        cin >> n >> k;
        //Initial
        for(int s = 0; s < (1 << n); s++){
            int total = 0, sl = s;
            while(sl){
                if(sl & 1) total++;
                sl >>= 1;
            }
            cnt[s] = total;
            if((((s<<1)|(s>>1)) & s) == 0) ok[++num] = s;
        }

        dp[0][0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int l = 1; l <= num; l++){
                int sl = ok[l];
                for(int r = 1 ; r <= num; r++){
                    int sr = ok[r];
                    if(((sr|(sr<<1)|(sr>>1)) & sl) == 0){
                        for(int j = 0; j <= k; j++){
                            if(j - cnt[sl] >= 0) dp[i][j][sl] += dp[i - 1][j - cnt[sl]][sr];
                        }
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= num; i++) ans += dp[n][k][ok[i]];

        cout << ans << endl;
    }
    signed main(){
        ios::sync_with_stdio(0);cin.tie(0);
        solve();
        return 0;
    }