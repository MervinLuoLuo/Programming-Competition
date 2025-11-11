#include <bits/stdc++.h>
using namespace std;

int dr[4] = {-1,1,0,0}, dc[4] = {0,0,-1,1};

int R = 9, C = 9;
int g[9][9];

bool inside(int r,int c){ return r>=0 && r<R && c>=0 && c<C; }

// 检查从 (r1,c1) 到 (r2,c2) 在同一行/列之间是否存在墙阻隔（不包括端点）
bool blocked_between(int r1,int c1,int r2,int c2){
    if(r1==r2){
        int cmin=min(c1,c2)+1, cmax=max(c1,c2)-1;
        for(int c=cmin;c<=cmax;c++){
            if(g[r1][c]==3) return true;
        }
        return false;
    } else if(c1==c2){
        int rmin=min(r1,r2)+1, rmax=max(r1,r2)-1;
        for(int r=rmin;r<=rmax;r++){
            if(g[r][c1]==3) return true;
        }
        return false;
    } else return true; // not same row/col => treat as blocked for line-of-sight
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 读 9x9 网格
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(!(cin >> g[i][j])){
                // 如果输入不足，退出
                return 0;
            }
        }
    }

    // 收集所有可放灯候选位置（原始为0）
    vector<pair<int,int>> cand;
    for(int i=0;i<R;i++) for(int j=0;j<C;j++) if(g[i][j]==0) cand.emplace_back(i,j);
    int m = (int)cand.size();

    vector<vector<pair<int,int>>> solutions;

    // 回溯枚举。我们按序决定每个候选位置是否放灯（递增索引，避免重复组合）
    vector<pair<int,int>> cur;

    // 为提高效率：预先计算每个候选位置是否与原始2相邻（若相邻则绝对不能放灯）
    vector<bool> adj2(m,false);
    for(int idx=0; idx<m; ++idx){
        int r=cand[idx].first, c=cand[idx].second;
        for(int d=0; d<4; ++d){
            int nr=r+dr[d], nc=c+dc[d];
            if(inside(nr,nc) && g[nr][nc]==2) adj2[idx]=true;
        }
    }

    function<void(int)> dfs = [&](int idx){
        if(idx==m){
            // 检查当前 cur 集合是否满足所有约束
            int L = (int)cur.size();
            // 1) 灯之间不能互相照到对方（即任意两个灯在同一行或列且中间无墙 -> 不允许）
            bool ok = true;
            for(int a=0;a<L && ok;a++){
                for(int b=a+1;b<L && ok;b++){
                    int r1=cur[a].first, c1=cur[a].second;
                    int r2=cur[b].first, c2=cur[b].second;
                    if(r1==r2 || c1==c2){
                        if(!blocked_between(r1,c1,r2,c2)){
                            ok = false;
                        }
                    }
                }
            }
            if(!ok) return;

            // 2) 模拟光照（灯及其四方向直到墙）
            vector<vector<bool>> lit(R, vector<bool>(C,false));
            for(auto &p: cur){
                int r=p.first, c=p.second;
                lit[r][c] = true;
                for(int d=0; d<4; ++d){
                    int nr=r+dr[d], nc=c+dc[d];
                    while(inside(nr,nc) && g[nr][nc]!=3){
                        lit[nr][nc] = true;
                        nr += dr[d];
                        nc += dc[d];
                    }
                }
            }

            // 3) 所有原始0格必须被光覆盖
            for(int i=0;i<R && ok;i++){
                for(int j=0;j<C && ok;j++){
                    if(g[i][j]==0){
                        if(!lit[i][j]) ok=false;
                    }
                }
            }
            if(!ok) return;

            // 4) 每个原始1格必须至少有一个相邻灯（上下左右）
            for(int i=0;i<R && ok;i++){
                for(int j=0;j<C && ok;j++){
                    if(g[i][j]==1){
                        bool hasAdjLamp=false;
                        for(int d=0; d<4; ++d){
                            int ni=i+dr[d], nj=j+dc[d];
                            if(inside(ni,nj)){
                                // check if (ni,nj) is in cur
                                for(auto &p: cur) if(p.first==ni && p.second==nj){ hasAdjLamp=true; break; }
                            }
                            if(hasAdjLamp) break;
                        }
                        if(!hasAdjLamp) ok=false;
                    }
                }
            }
            if(!ok) return;

            // 5) 另外还要确保没有灯放在与原始2相邻的位置（我们在回溯中已经避免，但再确认）
            for(auto &p: cur){
                int r=p.first, c=p.second;
                for(int d=0; d<4; ++d){
                    int nr=r+dr[d], nc=c+dc[d];
                    if(inside(nr,nc) && g[nr][nc]==2) ok=false;
                }
            }
            if(!ok) return;

            // 满足所有条件，记录解（按题目格式：输出横纵坐标）
            solutions.push_back(cur);
            return;
        }

        // 不放第 idx 个候选
        dfs(idx+1);

        // 尝试放第 idx 个候选：先做局部约束快速剪枝
        if(adj2[idx]) return; // 若与原始2相邻，则不能放
        // 还要保证该候选不会被已有灯的光照到（即不在已有灯的同行/同列且中间无墙）
        int rr = cand[idx].first, cc = cand[idx].second;
        for(auto &p: cur){
            int r2 = p.first, c2 = p.second;
            if(r2==rr || c2==cc){
                if(!blocked_between(r2,c2,rr,cc)){
                    return; // 已被其它灯光覆盖，不能放
                }
            }
        }
        // 通过剪枝，加入并继续
        cur.push_back(cand[idx]);
        dfs(idx+1);
        cur.pop_back();
    };

    dfs(0);

    // 输出所有解，格式：每个方案先输出 n，再输出 n 行 xi yi（0-based）
    // 按题意没有要求排序，这里按照发现顺序输出
    for(auto &sol : solutions){
        cout << sol.size() << '\n';
        for(auto &p : sol){
            cout << p.first + 1 << " " << p.second + 1 << '\n';
        }
    }

    // 如果没有解，可不输出或输出 0（这里选择不输出额外信息）
    return 0;
}
