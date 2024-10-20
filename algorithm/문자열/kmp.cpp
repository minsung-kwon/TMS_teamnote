#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;

vector<int> failure(string & s) {
    vector<int> f(s.size());
    int j = 0;
    for(int i = 1; i < s.size(); i++) {
        while(j>0 && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = ++j;
    } return f;
}
ll kmp(string s, string p) {
    vector<int> f = failure(p);
    ll cnt = 0;
    int j = 0;
    for(int i = 0; i < s.size(); i++) {
        while(j>0 && s[i] != p[j]) j = f[j-1];
        if(s[i] == p[j]) j++;
        if(j == p.size()) {
            cnt++;
            //w.emplace_back(i-j + 2); 몇번째인덱스인지카운트
        }
    } return cnt;
}