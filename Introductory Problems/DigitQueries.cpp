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
    int t;
    cin>>t;
    vector<int> arr;
    int x=1;
    for(int i=1;i<=17;i++){
        int a=9*i*x;
        arr.push_back(a);
        x*=10;
    }
    while(t--){
        int n;
        cin>>n;
        int cur=0,x=1,dl=1;
        if(n<10){
            cout<<n<<endl;
            continue;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]<n){
                n-=arr[i];
                x*=10;
                dl++;
            }
            else{
                break;
            }
        }
        if(x>1){cur=x;}
        int num=cur+(n/dl);
        if(n%dl==0){
            num--;
            cout<<(num%10)<<endl;
        }
        else{
            int n_del=dl-(n%dl);
            while(n_del){
                num/=10;
                n_del--;
            }
            cout<<(num%10)<<endl;
        }
    }
    return 0;
}
