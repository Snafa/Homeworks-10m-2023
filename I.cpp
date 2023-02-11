//#pragma GCC optimize("O3")
//#pragma GCC optimize("Ofast")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <unordered_map>
#include <unordered_set>
#include <immintrin.h>
#include <algorithm>
#include <iostream>
#include <thread>
#include <bitset>
#include <random>
#include <vector>
#include <queue>
#include <deque>
#include <cmath>
#include <mutex>
#include <set>
#include <map>

#define int int64_t
#define int128_t __int128
#define uint128_t unsigned __int128
#define double long double

using namespace std;
using namespace __gnu_pbds;

template<typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T> using umset = unordered_multiset<T>;
template<typename T> using mset = multiset<T>;
template<typename T> using uset = unordered_set<T>;
template<typename A, typename B> using ummap = unordered_multimap<A, B>;
template<typename A, typename B> using mmap = multimap<A, B>;
template<typename A, typename B> using umap = unordered_map<A, B>;

template<typename T>
T sign(T a) {
    return (0 <= a) - (a < 0);
}

template<typename T>
T bin_pow(T a, T e, int h) {
    if (!h)
        return e;
    T x = bin_pow(a, e, h >> 1);
    if (h & 1)
        return x * x * a;
    return x * x;
}

template<typename T>
T bin_mod_pow(T a, T e, int h, int m) {
    if (!h)
        return e;
    T x = bin_mod_pow(a, e, h >> 1, m);
    if (h & 1)
        return (((x * x) % m) * a) % m;
    return (x * x) % m;
}

const int64_t INF = 1e18, mod = 998244353, inf = 2e9, MOD = 1e18 + 9, sz = 30, SIZE = (1ll << sz);




int sum = 0;
mutex mt;

void in() {
    mt.lock();
    for (int a; cin >> a;) {
        this_thread::sleep_for(chrono::milliseconds(20));
        sum += a;
        mt.unlock();
        this_thread::sleep_for(chrono::milliseconds(20));
        mt.lock();
    }
}

void out() {
    this_thread::sleep_for(chrono::milliseconds(20));
    while (true) {
        mt.lock();
        cout << sum << '\n';
        cout.flush();
        mt.unlock();
        this_thread::sleep_for(chrono::milliseconds(30));
    }
}

void solve() {
    thread In(in);
    thread Out(out);
    In.join();
    Out.join();
}

int32_t main() {
#ifdef BIBIKOV
    clock_t tStart = clock();
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);


    int tt = 1;
//    cin >> tt;
    while (tt--) {
        solve();
        cout << '\n';
    }

#ifdef BIBIKOV
    fprintf(stderr, ">> Runtime: %.10fs\n", (double_t) (clock() - tStart) / CLOCKS_PER_SEC);
#endif

    return 0;
}