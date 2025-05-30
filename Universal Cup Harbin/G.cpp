#include<bits/stdc++.h>
#define int long long
#define end '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

int n, m , k;
struct men{
    bool free = 1;
    bool invited = 0;
    vector<int> know;
    vector<int> invite;
};
vector<men> man;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m >>k;
    man.resize(n + 5);
    for(int i = 1; i <= k; i++){
        int x;cin >> x;
        man[x].free = 0;
    }
    for(int i = 1; i <= m; i++){
        int a, b;cin >> a >> b;
        man[a].know.push_back(b);
        man[b].know.push_back(a);
    }
    int sponser = -1;
    for(int i = 1; i <= n; i++){
        if(man[i].free){sponser = i;man[i].invited = 1;;break;}
    }//找第一个闲人
    if(sponser == -1){no; return 0;}
    queue<int> q;
    q.push(sponser);//记的是编号
    vector<int> order;
    int cnt = 1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        bool flag = 0;
        if(!man[now].free) continue;
        for(int i = 0; i < man[now].know.size(); i++){
            int idx = man[now].know[i];
            if(!man[idx].invited){
                man[idx].invited = 1;
                man[now].invite.push_back(idx);
                q.push(idx);
                cnt++;flag = 1;
            }
        }
        if(flag) order.push_back(now);
    }
    if (cnt != n) no;
    else{
        yes;
        cout << order.size() << endl;
        for(int i = 0; i < order.size(); i++){
            int idx = order[i];
            cout << idx << ' ' << man[idx].invite.size() << ' ';
            for(auto p : man[idx].invite){
                cout << p << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
/*
n 个人
只要认识就一定相互认识
m 组关系
有 k 个人不能创建会议 也不能拉人
创建会议:
1. 找一个闲人创建会议 把他的好友拉进来
2. 在组内的人可以拉认识且不在组内的人进入会议 
    直到 n 个人都在会议内
问是否能找到一个方案使得所有人都在会议内
Input: 
n m k
a[i] 在忙的人
m 对相互认识的人
Output: 
如果找不到方案就 NO
找得到方案先 YES
然后输出 t 表示拉人次数 不要求最小
接下来 t 行 j-th
    每行两个整数 
    x[j] 表示拉人的人(j = 1时就是创建会议的人)
    y[j] 被拉的人的人数
    z[l] 被拉的人
    每个人只能拉一次人 
*/