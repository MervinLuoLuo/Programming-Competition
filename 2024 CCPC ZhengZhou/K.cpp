#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

bool flag = 1;
struct Node{
    int m = 0;
    int fa = -1;
    int val;
    vector<int> son;
};
void black(int root, vector<Node> node){
    if(node[root].m) return;//被标记过
    if(node[root].fa == -1)return;//没固定爹过(为根节点或有多个爹)
    node[root].m = 1;//标记
    for(int i = 0; i < node[root].son.size(); i++){//该节点被标记 则起所有子节点都应该被标记
        int son = node[root].son[i];
        if(son == node[root].fa) continue;// 互为父子 往下
        if(node[son].fa != -1 and node[son].fa != root){flag = 0;return;}//认了两个爹
        node[son].fa = root;//正常情况到这步 确定父节点
        black(son, node);//递归dfs
    }
}

vector<Node> node; 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n;cin >> n;
        node.resize(n + 5);
        int ans = 0;
        for(int i = 1; i <= n; i++){
            cin >> node[i].val;//输入值
        }
        for(int i = 0; i < n- 1; i++){
            int u, v;cin >> u >> v;
            if(node[u].val * 2 < node[v].val ){
                if(node[u].fa != v)flag = 0;//多爹
                node[v].fa = u;}//正常给爹
            if(node[v].val * 2 < node[u].val){
                if(node[v].fa != u)flag = 0;
                node[u].fa = v;} 
            node[u].son.push_back(v);//经典双向图
            node[v].son.push_back(u);
        }
        for(int i = 1; i <= n; i++){
            black(i, node);//标记
        }
        for(int i = 1; i  <= n; i++){
            if(node[i].m == 0) ans++;//没标记就是可以 ans++
        }
        if(!flag) cout << 0 << endl;continue; //如果非树 就不存在完美节点 数量为 0
        cout << ans << endl;
    }
    return 0;
}
/*
子节点 >= 父节点 1 / 2 
*/