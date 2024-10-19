#include <bits/stdc++.h>
typedef long long ll;

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