#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll binary_gcd(ll a,ll b) { //큰 수에 대해서 사용.
    if(a==0||b==0) return a+b;
    int shift = __builtin_ctzll(a|b);
    a >>= __builtin_ctzll(a);
    while(b != 0) {
        b >>= __builtin_ctzll(b);
        if(a>b) swap(a,b); b-=a;
    }
    return a << shift;
}

struct egcdResult {
    ll gcd,x,y;
};
egcdResult egcd(ll a,ll b) {
    if(b==0) {
        return {a,1,0};
    }
    egcdResult res = egcd(b,a%b);
    ll x = res.y;
    ll y = res.x - (a/b) * res.y;
    return {res.gcd,x,y};
}

ll mod(ll a,ll m) {return (a % m + m) % m;}
// x인 해와 그 mod
pair<ll,ll> crt(ll a1, ll m1,ll a2, ll m2) {
    ll g = gcd(m1,m2) , m = m1 / g * m2;
    if((a2 - a1) % g) return {-1,-1};//crt의 해가 존재X
    ll md = m2/g, s = mod((a2-a1)/g,m2/g);
    ll t = mod(egcd(m1/g%md,m2/g).x ,md);
    return {a1 + s * t % md * m1,m};
}

pair<ll,ll> crtmany(const vector<ll> &a,const vector<ll> &m) {
    ll ra = a[0], rm = m[0];
    for(int i = 1; i < m.size(); i++) {
        auto [aa,mm] = crt(ra,rm,a[i],m[i]);
        if(mm == -1) return {-1,-1}; else tie(ra,rm) = tie(aa,mm);
    }return {ra,rm};
}