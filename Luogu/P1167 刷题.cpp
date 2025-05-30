/*https://www.luogu.com.cn/problem/P1167*/
#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define int long long
#define pii pair<int,int>
using namespace std;
const int INF = 1e18;
const int maxn = 1e9;

const int m[12]={31,28,31,30,31,30,31,31,30,31,30,31};

bool check(int x){
    if(x%100==0){if(x%400==0)return 1;}
    else{if(x%4==0)return 1;}
    return 0;
}

void solve(){
    int n;cin>>n;
    int a[5010]={0};
    int year2,month2,day2,hour2,minute2;
    int year,month,day,hour,minute;
    int year1,month1,day1,hour1,minute1;
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a,a+n);
    scanf("%d-%d-%d-%d:%d",&year,&month,&day,&hour,&minute);
    scanf("%d-%d-%d-%d:%d",&year1,&month1,&day1,&hour1,&minute1);
    year2=year1-year;
    month2=month1-month;
    day2=day1-day;
    hour2=hour1-hour;
    minute2=minute1-minute;
    
    if(year2>0){
        month2+=year2*12;
    }
    if(month2>0){
        int i=month,j=year;
        for(int o=0;o<month2;o++){
            if(i>12){
                i-=12;
                j++;
            }
            if(i==1&& check(j)){
                day2+=m[i-1]+1;
                i++;
                continue;
            }
            day2+=m[i-1];
            i++;
        }
        
    }
    if(day2>0){
        hour2+=day2*24;
    }
    if(hour2>0){
        minute2+=hour2*60;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        if(a[i]<=minute2){
            minute2-=a[i];
            sum++;
        }
    }
    cout<<sum;
}
signed main(){
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t--){
       solve();
    }
    return 0;
}