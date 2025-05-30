/*https://ac.nowcoder.com/acm/problem/14326*/
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
 
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin >> n;
    while(n){
        int flag = n;
        while(flag){
            vector<int> a(flag + 5);
            for(int i = 1; i <= flag; i++){
                cin >> a[i];
                if(a[i] == 0){
                    flag = 0;
                    cout << endl;break;
                }
            }
            if(!flag)break;
            stack<int> s;
            for(int i = 1, j = 1;i <= flag; i++){
                s.push(i);
                while(!s.empty() and s.top() == a[j]){
                    s.pop();
                    j++;
                }
            }
            if(s.empty()) yes;
            else no;
        }
        cin >> flag;
        n = flag;
    }    
    return 0;
}
/*

*/