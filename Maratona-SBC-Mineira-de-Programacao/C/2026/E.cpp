// Link => https://codeforces.com/group/YgJmumGtHD/contest/106552/problem/E
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define f first
#define s second

using namespace std; 

int const MAXN = 5e2 + 1;

ll grid[MAXN][MAXN];
pii pos_g[MAXN*MAXN], pos_a[MAXN*MAXN];

int N, M, T;

vector<pii> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool val(int x, int y, int i, int k) {
    if (x < 0 || x == N || y < 0 || y == M) return false;

    if (x == i) return abs(y - k) > 1;
    if (y == k) return abs(x - i) > 1;

    return true;
}

ll play(pii pos_p, pii pos_ad) {
    ll ans = 0;
    pos_p.f--;
    pos_p.s--;
    int i = --pos_ad.f;
    int k = --pos_ad.s;

    //cout << "My pos => " << pos_p.f << " " << pos_p.s << endl;
    //cout << "Ad pos => " << i << " " << k << endl;
    if(val(pos_p.f, pos_p.s, i, k)) {
        //cout << " - catch here " << grid[pos_p.f][pos_p.s] << endl;
        ans += grid[pos_p.f][pos_p.s];
        grid[pos_p.f][pos_p.s] = 0;
    }
    for(auto [x, y] : dirs) {
        x += pos_p.f;
        y += pos_p.s;
        //cout << "trying to " << x << " " << y;
        if(val(x, y, i, k)) {
            //cout << " YES, catch " << grid[x][y] << endl;
            ans += grid[x][y];
            grid[x][y] = 0;
        } else {
            //cout << " NO" << endl;
        }
    }

    return ans;
}

int main() {
   cin >> N >> M >> T;

   for(int i = 0; i < N; i++)
       for(int j = 0; j < M; j++) cin >> grid[i][j];

   for(int i = 0; i < T; i++) {
       cin >> pos_g[i].f >> pos_g[i].s;
   }
   for(int i = 0; i < T; i++) {
       cin >> pos_a[i].f >> pos_a[i].s;
   }
    
    int ans_g, ans_a;
    ans_g = ans_a = 0;

    for(int i = 0; i < T; i++) {
        //cout << "G playing:" << endl;
        ans_g += play(pos_g[i], pos_a[i]);
        //cout << "A playing:" << endl;
        ans_a += play(pos_a[i], pos_g[i]);
    }

    cout << ans_g << " " << ans_a << endl;

}
