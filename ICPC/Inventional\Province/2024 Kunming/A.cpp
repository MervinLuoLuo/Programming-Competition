#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define VII vector<vector<int>>
using namespace std;
using i128 = __int128;
constexpr int INF = 1e18;
constexpr int MAXN = 1e9;
struct Team{
    int id;
    int s;
    vector<int> p;
    int sum = 0;
    int cnt = 0;
};

void solve(){
    int n,m,k;cin >> n >> m >> k;
    vector<Team> team(n + 1);
    for(int i = 1; i <= n; i++){
        team[i].id = i;
        cin >> team[i].s;
        int sum = 0,cnt = 0;
        for(int j = 1; j <= m; j++){
            int x;cin >> x;
            team[i].p.push_back(x);
            if(x == -1) cnt++;
            else sum += x;
        }
        team[i].sum = sum;team[i].cnt = cnt;
    }

    
    sort(team.begin() + 1,team.end(),[](const Team x,const Team y){
        if(x.s == y.s){
            if(x.sum == y.sum) return x.cnt < y.cnt;
            return x.sum < y.sum;
        }
        return x.s < y.s;
    });
    
    // 等级最小的全部都置 0
    for(int &x : team[1].p){
        if(x == -1) x = 0;
    }
    for(auto &[id,s,p,sum,cnt] : team){
        cerr << s << ": " << sum << " " <<  cnt << endl;
        for(int &x : p) cerr << x << " ";
        cerr << "\n-----------------" << endl;
    }
    
    for(int i = 1; i < n; i++){
        auto &[id1,s1,p1,sum1,cnt1] = team[i];
        auto &[id2,s2,p2,sum2,cnt2] = team[i + 1];

        // 同级操作 只需要让他满足 sum1 <= sum2 即可
        if(s1 == s2){
            if(sum1 <= sum2){
                for(int &x : p2){
                    if(x == -1) x = 0;
                }
            }
            else{
                int d = sum1 - sum2;
                for(int &x : p2){
                    if(x == -1){
                        if(d >= k) x = k,d -= k;
                        else x = d,d = 0;
                    }
                }

                if(d != 0){
                    cout << "No" << endl;
                    return;
                } 
                sum2 = sum1;
            }
        }

        // 不同级要求 sum2 > sum1
        else{
            if(sum1 < sum2){
                for(int &x : p2){
                    if(x == -1) x = 0;
                }
            }
            else{
                int d = sum1 - sum2 + 1;
                for(int &x : p2){
                    if(x == -1){
                        if(d >= k) x = k,d -= k;
                        else x = d,d = 0;
                    }
                }
                if(d != 0){
                    cout << "No" << endl;
                    return;
                }
                sum2 = sum1 + 1;
            }
        }
    }

    // 按照 id 排序还原原顺序
    sort(team.begin() + 1,team.end(),[](const Team x,const Team y){
        return x.id < y.id;
    });

    cout << "Yes" << endl;
    for(int i = 1; i <= n; i++){
        for(int x : team[i].p) cout << x << " ";
        cout << endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        solve();
    }
    return 0;
}