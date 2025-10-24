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

struct Team{
    vector<int> passed;
    void ini(){
        passed.assign(26,0);
    }
};

void solve(){
    int n;cin >> n;
    map<string,int> mp;
    vector<Team> team;
    team.push_back({});
    vector<int> pass(26,0);
    for(int i = 0; i < n; i++){
        string name;cin >> name;
        if(mp[name] == 0){
            team.push_back({});
            mp[name] = team.size() - 1;
            team[team.size() - 1].ini();
        }
        int id = mp[name];
        char c;cin >> c;
        string stat;cin >> stat;
        int p = c - 'A';
        if(team[id].passed[p] == 0 && stat == "accepted"){
            pass[p]++;team[id].passed[p] = 1;
        }
    }

    char ans;
    int maxx = -1;
    for(int i = 0; i < 26; i++){
        if(pass[i] > maxx){
            ans = 'A' + i;
            maxx = pass[i];
        }
    }

    cout << ans << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}