#include <bits/stdc++.h>
typedef long long ll;

ll POW(ll a, ll b, ll MMM) { ll ret = 1; for (; b; b >>= 1, a = (a * a) % MMM)if (b & 1)ret = (ret * a) % MMM; return ret; }