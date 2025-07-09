/*https://ac.nowcoder.com/acm/contest/20960/1001*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
typedef long long ll;

void solve(){
    int a,b,c;cin >> a >> b >> c;
    string s;cin >> s;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '-'){
            if( !((isalpha(s[i-1]) && isalpha(s[i+1])) || (isdigit(s[i-1]) && isdigit(s[i+1]))))continue;

            if(i == 0 or i == s.size() - 1) continue;
            if(s[i - 1] + 1 == s[i + 1]){s.erase(i,1);continue;}
            if(s[i - 1] >= s[i + 1]) continue;
            if(isalpha(s[i +1]) and isdigit(s[i -1])) continue;
            string add;
            if(a == 3){
                int dis = s[i  + 1] - s[i - 1] - 1;
                //cout << dis << endl;
                dis *= b;
                for(int j = 0; j < dis; j++){
                    add += '*';
                }
                s.erase(i,1);
                s.insert(i,add);
                i += dis;
                continue;
            }
            if(c == 1){
                for(char x = s[i - 1] + 1; x < s[i + 1]; x++){
                    for(int y = 1; y <= b;y++){
                        add += x;
                    }
                }
            }
            else{
                for(char x = s[i + 1] - 1; x > s[i - 1]; x--){
                    for(int y = 0; y < b; y++){
                        add+=x;
                    }
                }
            }
            if(a == 2) transform(add.begin(),add.end(),add.begin(),::toupper);
            s.erase(i,1);
            s.insert(i,add);
            i += add.size();
        }
    }
    cout << s << endl;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while(t--){
       solve();
    }
    return 0;
}
