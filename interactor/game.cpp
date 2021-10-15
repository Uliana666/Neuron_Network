#pragma GCC optimize("Ofast,unroll-all-loops")
#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC target("popcnt")
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

template<typename A, typename B>
string to_string(pair<A, B> p);

template<typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template<typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string &s) {
    return '"' + s + '"';
}

string to_string(const char *s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template<size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template<typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template<typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " +
           to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template<typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " +
           to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", \
                   debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

#define sz(a) (ll)((a).size())
#define all(v) (v).begin(), (v).end()
#define rall(v) v.rbegin(), v.rend()
#define pikachu push_back
#define mp make_pair
#define st first
#define nd second
#define i128 __int128
#define pt(s) (s)[sz((s)) - 2]
#define pll pair<ll, ll>

//mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

inline ll bpow(ll a, ll b, ll mod) {
    a %= mod, b %= mod;
    ll res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = (1ll * res * a) % mod;
        }
        a = (1ll * a * a) % mod;
    }
    return res;
}

const ll INF = (is_same<int, ll>::value ? 1e9 + 666 : 1e18l + 666);
void run();
int main(int argc, char *argv[]) {
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << setprecision(20) << fixed;
    run();
}
const ll S = 6, K = 6;
struct Game {
    int pers[2];
    int stone[2][S];
    Game() {
        pers[0] = pers[1] = 0;
        fill(stone[0], stone[0] + S, K);
        fill(stone[1], stone[1] + S, K);
    }
};
bool check(Game &g) {
    bool fl = 1;
    for (ll i = 0; i < S; ++i)
        if (g.stone[0][i]) fl = 0;
    if (fl) return true;
    fl = 1;
    for (ll i = 0; i < S; ++i)
        if (g.stone[1][i]) fl = 0;
    return fl;
}
void print(Game g) {
    cerr << "GAME: \n";
    cerr << g.pers[0] << ' ' << g.pers[1] << endl;
    for (ll i = S - 1; i >= 0; --i) cerr << g.stone[0][i] << ' ';
    cerr << endl;
    for (ll i = 0; i < S; ++i) cerr << g.stone[1][i] << ' ';
    cerr << endl;
}
pair<Game, bool> xod(Game g, bool type, ll num) {
    ll ct = g.stone[type][num];
    g.stone[type][num] = 0;
    bool pers = type;
    int start = num + 1;
    while (ct) {
        for (ll i = start; i < S && ct; ++i) {
            --ct;
            ++g.stone[pers][i];
            if (ct == 0 && pers == type && g.stone[pers][i] == 1 && g.stone[type ^ 1][S - i - 1]) {
                g.pers[type] += 1 + g.stone[type ^ 1][S - i - 1];
                g.stone[type][i] = g.stone[type ^ 1][S - i - 1] = 0;
                return {g, type ^ 1};
            }
        }
        if (pers == type && ct) {
            --ct, ++g.pers[type];
            if (ct == 0) return {g, type};
        }
        pers ^= 1;
        start = 0;
    }
    return {g, type ^ 1};
}
const ll deep = 11; //13 -- max
ll last, we;
const ll M = 1000;
ll answer(Game &g) {
    if (check(g)) {
        ll ans = 0;
        ans += M * g.pers[0];
        ans -= M * g.pers[1];
        for (ll i = 0; i < S; ++i)
            ans += M * g.stone[0][i];
        for (ll i = 0; i < S; ++i)
            ans -= M * g.stone[1][i];
        return ans;
    }
    ll ans = 0;
    ll mx1 = 0, mx2 = 0;
    for (ll i = 0; i < S; ++i) {
        ans += M * g.stone[0][i];
        cmax(mx1, g.stone[0][i]);
    }
    for (ll i = 0; i < S; ++i) {
        ans -= M * g.stone[1][i];
        cmax(mx2, g.stone[1][i]);
    }
    mx1 *= M, mx2 *= M;
    ans /= 4;
    ans += mx1 / 3 - mx2 / 3;
    ans += M * g.pers[0];
    ans -= M * g.pers[1];
    if (!g.stone[0][0] && we == 1) ans += -4 * M;
    //if (!g.stone[1][0]) ans -= -3 * M;
    return ans;
}
ll caalc(Game &g, bool type, ll a, ll b, ll d) {
    if (check(g) || d > deep) return answer(g);
    ll ans = type ? INF : -INF, xd = -1;
    for (ll i = 0; i < S; ++i) {
        if (g.stone[type][i] == 0) continue;
        auto [newg, p] = xod(g, type, i);
        auto t = caalc(newg, p, a, b, d + 1);
        if (!type) {
            if (cmax(ans, t)) xd = i;
            cmax(a, t);
            if (a >= b) {
                last = xd;
                return ans;
            }

        } else {
            cmin(ans, t);
            cmin(b, t);
            if (b <= a) {
                //last = xd;
                return ans;
            }
        }
    }
    last = xd;
    return ans;
}
void calc(Game &g, bool type) {
    caalc(g, type, -INF, INF, 0);
}
Game my_xod(Game g) {
    if (check(g)) exit(0);
    calc(g, 0);
    cout << last + 1 << endl;
    auto [newg, p] = xod(g, 0, last);
    if (check(newg)) exit(0);
    while (p == 0) {
        calc(newg, 0);
        cout << last + 1 << endl;
        auto [newg2, p2] = xod(newg, 0, last);
        newg = newg2;
        p = p2;
        if (check(newg)) exit(0);
    }
    return newg;
}
Game you_xod(Game g) {
    if (check(g)) exit(0);
    ll xd;
    cin >> xd;
    --xd;
    auto [newg, p] = xod(g, 1, xd);
    if (check(newg)) exit(0);
    while (p) {
        cin >> xd;
        --xd;
        auto [newg2, p2] = xod(newg, 1, xd);
        newg = newg2;
        p = p2;
        if (check(newg)) exit(0);
    }
    return newg;
}
void run() {
    Game G;
    ll kek, xd;
    cin >> kek >> we;
    if (we == 1) G = my_xod(G);
    while (true) {
        G = you_xod(G);
        G = my_xod(G);
        if (check(G)) exit(0);
    }
}