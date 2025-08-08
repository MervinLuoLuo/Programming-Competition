#include <bits/stdc++.h>
#define endl '\n'
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define int long long
#define pii pair<int,int>
#define vii vector<vector<int>>
using namespace std;
const int INF = 1e18;
const int maxn = 2e5 + 9;
const int BLEN = 24, BMSK = (1 << BLEN) - 1, EMSK = BMSK / 3;

struct Com {
    vector<int> a, b;

    pii parO(int n, const char* s) {
        int res[2] = {}, o = 0;
        for (int i = 0; i < n; ++i, o = !o)
            res[o] = -res[o] << 1 | (s[i] == '1');
        return {res[!o], res[o]};
    }

    void parse() {
        a.clear(); b.clear();
        static char s[maxn];
        scanf("%s", s);
        int n = strlen(s), fir = n % (BLEN << 1), u, v;
        if (fir > 0) {
            tie(u, v) = parO(fir, s);
            a.push_back(u);
            b.push_back(v);
        }
        for (int i = fir; i < n; i += (BLEN << 1)) {
            tie(u, v) = parO(BLEN << 1, s + i);
            a.push_back(u);
            b.push_back(v);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        stf();
    }

    void stf() {
        while (!a.empty() && !a.back()) a.pop_back();
        while (!b.empty() && !b.back()) b.pop_back();
    }

    int size() const {
        return max(a.size(), b.size());
    }

    int reduO(int& v) const {
        int r = v & BMSK;
        v = (v - r) >> BLEN;
        if (r > EMSK) {
            ++v;
            r -= 1 << BLEN;
        }
        return r;
    }

    Com operator * (const Com& t) const {
        int sz = size(), tsz = t.size(), len = sz + tsz - 1;
        int va = 0, vb = 0;
        Com res;
        res.a.reserve(len + 2); res.b.reserve(len + 2);
        for (int i = 0; i < len; ++i) {
            for (int j = max(i - tsz + 1, 0LL), k = i - j; k >= 0; ++j, --k) {
                int aL = j < (int)a.size() ? a[j] : 0, bL = j < (int)b.size() ? b[j] : 0;
                int aR = k < (int)t.a.size() ? t.a[k] : 0, bR = k < (int)t.b.size() ? t.b[k] : 0;
                va += aL * aR - 2LL * bL * bR;
                vb += aL * bR + (int)aR * bL;
            }
            res.a.push_back(reduO(va));
            res.b.push_back(reduO(vb));
        }
        while (va || vb) {
            res.a.push_back(reduO(va));
            res.b.push_back(reduO(vb));
        }
        res.stf();
        return res;
    }

    void print() const {
        int sz = size(), len = 0;
        static char buf[maxn];
        for (int i = 0, o, val[2]; i < sz; ++i) {
            val[0] = i < (int)a.size() ? a[i] : 0;
            val[1] = i < (int)b.size() ? b[i] : 0;
            for (o = 0; val[0] || val[1]; o = !o) {
                buf[len++] = "01"[val[o] & 1];
                val[o] = -((val[o] - (val[o] & 1)) >> 1);
            }
            if (i + 1 < sz)
                for (o = (i + 1) * (BLEN << 1); len < o; buf[len++] = '0');
        }
        reverse(buf, buf + len);
        if (!len) buf[len++] = '0';
        buf[len] = '\0';
        puts(buf);
    }

} A, B, C;

void solve() {
    A.parse();
    B.parse();
    C = A * B;
    C.print();
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    scanf("%lld", &t);
    while (t--) {
        solve();
    }
    return 0;
}
