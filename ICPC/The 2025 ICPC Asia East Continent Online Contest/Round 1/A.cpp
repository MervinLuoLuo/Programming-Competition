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

//分开记录提交
struct Submission {
    string name;
    int q;
    int t;
    string state;
};

struct Team {
    string name;
    int lpass = 0; // 确定通过题数
    int ldirt = 0; // 确定罚时
    vector<int> solved;   // 题目状态
    vector<int> penalty;  // 该题累积罚时
    vector<Submission> unknown; // Unknown 提交
    void init() {
        solved.assign(26, 0);
        penalty.assign(26, 0);
    }
};

void solve() {
    int n; cin >> n;
    vector<Submission> subs(n);
    for (int i = 0; i < n; i++) {
        string name; char q; int t; string st;
        cin >> name >> q >> t >> st;
        subs[i] = {name, q - 'A', t, st};
    }

    // 按时间排序
    sort(subs.begin(), subs.end(), [](auto &a, auto &b) {
        return a.t < b.t;
    });

    map<string,int> mp;// 队名映射为编号
    vector<Team> team;
    int idx = 0;

    // 遍历提交
    for (auto &sub : subs) {
        if (!mp.count(sub.name)) {
            mp[sub.name] = ++idx;
            team.push_back({});
            team.back().name = sub.name;
            team.back().init();
        }
        int id = mp[sub.name] - 1;

        if (sub.state == "Unknown") {
            team[id].unknown.push_back(sub);
            continue;
        }

        if (sub.state == "Rejected") {
            if (!team[id].solved[sub.q]) {
                team[id].penalty[sub.q] += 20;
            }
        } else if (sub.state == "Accepted") {
            if (!team[id].solved[sub.q]) {
                team[id].solved[sub.q] = 1;
                team[id].lpass++;
                team[id].ldirt += team[id].penalty[sub.q] + sub.t;
            }
        }
    }

    // 找通过题数最多且罚时最少
    int maxpass = 0, mindirt = 1e18;
    for (auto &t : team) {
        if (t.lpass > maxpass) {
            maxpass = t.lpass;
            mindirt = t.ldirt;
        } else if (t.lpass == maxpass) {
            mindirt = min(mindirt, t.ldirt);
        }
    }

    // 模拟 Unknown
    set<string> ans;
    for (auto &t : team) {
        if (t.lpass == maxpass && t.ldirt == mindirt) {
            ans.insert(t.name);
            continue;
        }
        int pro = t.lpass;
        int pen = t.ldirt;
        auto solved = t.solved;
        auto penalty = t.penalty;

        for (auto &sub : t.unknown) {
            if (!solved[sub.q]) {
                solved[sub.q] = 1;
                pro++;
                pen += penalty[sub.q] + sub.t;
            }
        }

        if (pro > maxpass || (pro == maxpass && pen <= mindirt)) {
            ans.insert(t.name);
        }
    }

    for (auto &s : ans) cout << s << " ";
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--){
        solve();
    } 
    return 0;
}
