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
    string name;
    int hpent = 0;
    int lpent = 0;
    int pass = 0;
    vector<vector<pii>> que;
    void ini(){
        que.resize(26);
    }
};

bool cmp(Team a,Team b){
    if(a.hpass == b.hpass){
        return a.hpent < b.hpent;
    }
    return a.pass < b.pass;
}

void solve(){
    int n;cin >> n;
    map<string,int> mp;
    vector<Team> team;
    team.push_back({});
    int size = 1;
    for(int i = 1; i <= n; i++){
        string name;cin >> name;
        if(mp[name] == 0) {
            mp[name] = size;
            team.push_back({});
            team.back().name = name;
            team[size].ini();
            size ++;
        }
        int cur = mp[name];
        char q;cin >> q;
        int time;cin >> time;
        string s;cin >> s;
        int stat = 0;
        if(s == "Accepted") stat = 1;
        else if(s == "Rejected") stat = 0;
        else if(s == "Unknown") stat = 2;
        int qu = q - 'A';

        //输入不是按时间递增,全部都得存
        team[cur].que[qu].push_back({stat,time});
    }
    
    //排序找出第一个 AC / Unknown
    for(int i = 1; i <= size; i++){
        for(int j = 0; j < 26; j++){
            sort(team[i].que[j].begin(),team[i].que[j].end());
        }
    }

    // vector<int> hscore(size + 1, 0),lscore(size + 1, maxn);

    //遍历每个队的每个题目情况,计算最高 dirt 和 最低 dirt
    for(int i = 1; i <= size; i++){
        Team cur = team[i];
        for(int j = 0,tpent = 0; j < 26; j++){
            //没交过或者最后只有 WA 就跳过
            if(cur.que[j].empty()) continue;
            if(cur.que[j].back().first == 0) continue;
            //算罚时
            int k = 0;
            while(cur.que[j][k].first == 0){
                tpent += cur.que[j][k].second + 20;
                k++;
            }
            team[i].hpent += tpent, team[i].lpent += tpent;
            //第一个是 AC 就直接算两个
            if(cur.que[j][k].first == 1){
                team[i].hpent += cur.que[j][k].second;
                team[i].lpent += cur.que[j][k].second;
                team[i].pass ++;
                team[i].pass ++;
            }
            //第一个是 Un 就只算 hpent
            else if(cur.que[j][k].first == 2){
                team[i].hpent += cur.que[j][k].second;
                team[i].pass ++;
            }
        }
    }

    sort(team.begin(),team.end(),cmp);
    
    vector<string> ans;
    int basep = team.back().pass;
    int base = team.back().hpent;

    //冠军条件:过题数最大 && lpent少于最高的hpent
    int i = size;
    for(; i >= 1; i--){
        if(team[i].pass < basep) break;

    }

    

    for(auto it : ans) cout << it << " ";
    cout << endl;

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