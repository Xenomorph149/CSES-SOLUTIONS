#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <chrono>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <iomanip>
using namespace std;
#define int long long
#define double long double
#define mod 1000000007
#define pi 3.1415926535897932384626433832795
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
int modAdd(int a, int b, int m) {
    return ((a % m) + (b % m)) % m;
}

int modSub(int a, int b, int m) {
    return ((a % m) - (b % m) + m) % m;
}

int modMul(int a, int b, int m) {
    return ((a % m) * (b % m)) % m;
}

int power(int x, unsigned int y, int p) {
    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int modInverse(int a, int m) {
    return power(a, m - 2, m);
}

int modDiv(int a, int b, int m) {
    a = a % m;
    int inv = modInverse(b, m);
    return (inv * a) % m;
}
vector < int > read_arr(int n) {
    vector < int > arr(n);
    for (int & x: arr) cin >> x;
    return arr;
}
void print_arr(const vector < int > & arr) {
    for (int x: arr) cout << x << " ";
    cout << endl;
}
vector < int > SieveOfEratosthenes(int n) {
    vector < bool > prime(n + 1, true);
    vector < int > primes;
    for (int p = 2; p * p <= n; ++p)
        if (prime[p])
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
    for (int p = 2; p <= n; ++p)
        if (prime[p]) primes.push_back(p);
    return primes;
}
signed main() {
    setIO();
    int t=1;
    while (t--) {
        string s;
        cin>>s;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        string a,ans;
        int oc=0;
        char och='*';
        for(auto i : mp){
            int cnt=i.second;
            if(cnt%2){
                oc++;
                och=i.first;
            }
            string x(cnt/2,i.first);
            a+=x;
        }
        ans+=a;
        reverse(a.begin(),a.end());
        if(oc==1){ans+=och;}
        ans+=a;
        ans=(oc>1)?"NO SOLUTION":ans;
        cout<<ans<<endl;
    }
    return 0;
}