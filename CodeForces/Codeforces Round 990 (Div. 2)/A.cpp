#include<bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
const int INF = 1e19;
const int maxn = 1e9;

signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a(n + 5);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int cnt = 1, fi = 1,happy = 1;//cnt 记录放的块数 fi记录完成的层数
        for(int i = 1; i < n; i++){//由于第一天一定只放一块 直接略过第一天 从第二天开数起 若放的块数为(2*layer-1)^ 2 则layer层填满
            int layer = fi + 1;
            cnt += a[i];
            if (cnt == pow((2 * layer - 1), 2)) {fi++;happy++;}
            else if(cnt > pow(2*layer - 1, 2)){
                while(cnt > pow(2*layer - 1, 2)){
                    layer++;
                    fi = layer -1;
                }
                 if (cnt == pow((2 * layer - 1), 2)) {fi++;happy++;}
            }
        
         //cout << fi << ' ' << cnt << ' '<< happy << endl;
        }
        cout << happy << endl;
    }
    return 0;
}
/*
假设一个不正常的方形 
n 次操作: 
    第一次 他先把主块放到桌子中间
    第[i]次 他以顺时针顺序围绕中心块放置a[i]数字块
    保证下一层开始前 这一层已经拼满
求 n 次后 他完成的层数
得那天正好拼完才开心
Input: 
t cases
n
a[i] Alyona在 i-th 天要拼的块数
Output: 
他完成的层数

1. 1 * 1
2. 3 * 3
3. 5 * 5
4. 7 * 7
...
n. (2n-1) ^ 2
 */