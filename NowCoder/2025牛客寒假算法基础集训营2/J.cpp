#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;
/*YYYY-MM-DD
HH-MM-SS*/
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,h ,m;cin >> n >> h >> m;
    string Date = to_string(h) + '-';
    if(m < 10){
        Date += '0' + to_string(m);
    }
    else{
        Date += to_string(m);
    }
    set<string> a, b ,c;
    for(int i = 0; i < n; i++){
        string user,date,time;
        cin >> user >> date >> time;
        if(date.substr(0,7) != Date) continue;
        string H = time.substr(0,2);
        if(H == "07" or H == "08" or time == "09:00:00" or H == "18" or H == "19" or time == "20:00:00") a.insert(user);
        if(H == "11" or H == "12" or time == "13:00:00") b.insert(user);
        if(H == "22" or H == "23" or H == "00" or time == "01:00:00") c.insert(user);
    }
    cout << a.size() << ' ' << b.size() <<  ' ' << c.size();
    return 0;
}