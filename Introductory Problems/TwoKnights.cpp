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
        cin >>n;
        for(int i=1;i<=n;i++){
            int x=((i*i)*((i*i)-1))/2;
            int y=4*(i-1)*(i-2);
            cout<<(x-y)<<endl;
        }
    }
    return 0;
}