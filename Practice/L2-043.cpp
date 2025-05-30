#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

struct Node{//树节点
    int fath;
    int layer;
    vector<int> son;//子树
};
vector<Node> node;//树数组
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;cin >> n >> m;
    node.resize(n + 5);
    int root = -1;
    for(int i = 1; i <= n; ++i){
        cin >> node[i].fath;//输入父结点
        if(node[i].fath != -1) node[node[i].fath].son.push_back(i);//把当前结点的位置给到他的父节点的子节点数组中
        else root = i;
    }

    //层序遍历
    queue<int> q;q.push(root);
    while(!q.empty()){
        int now = q.front();q.pop();//队列求到最后一个
        if(now == root){node[now].layer = 0;}
        else {node[now].layer = node[node[now].fath].layer + 1;}//算layer 后面算最短要用
        for(int i = 0; i < node[now].son.size(); i++){
            q.push(node[now].son[i]);
        }
    }
    int ans = 0, maxl = 0;/*送完回家的话是每条路都得走两边 but题目送完不回家 要求路径最短的话就把回家最长的那条删掉 
                            即去掉layer最大那个放到最后走 然后减去他回去的路径*/
    vector<int> vis(n + 5, 0);//一个访问数组
    vis[root] = 1;
    while(m--){
        int x;cin >> x;
        int pos = x;
        maxl = max(maxl, node[x].layer);//维护最大layer
        while(vis[pos] == 0){//一直回溯到走过的父节点
            vis[pos] = 1;
            pos=node[pos].fath;
            ans += 2;//来回两次
        }
        cout <<  ans - maxl << endl;//每次加点都得输出
    }
    return 0;
}