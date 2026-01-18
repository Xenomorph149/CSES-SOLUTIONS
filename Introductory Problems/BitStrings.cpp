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
    int t=1,n;
    while (t--) {
        cin >> n;
        cout<<power(2,n,1000000007)<<endl;
    }
    return 0;
}