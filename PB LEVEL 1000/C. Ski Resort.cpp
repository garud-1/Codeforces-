#include <bits/stdc++.h>
using namespace std;

// ----------------- Data types and other shortnames ------------------
#define ll long long
#define ld long double
#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define all(a) (a).begin(), (a).end()
#define print(a)     \
    for (auto i : a) \
        std::cout << i << " ";
#define py cout << "YES" << endl;
#define pn cout << "NO" << endl;

#define debug(x)            \
    std::cerr << #x << " "; \
    _print(x);              \
    std::cerr << std::endl;
void _print(ll t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }

template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p)
{
    cerr << "{ ";
    _print(p.ff);
    cerr << ", ";
    _print(p.ss);
    cerr << "}";
}
template <class T>
void _print(vector<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << ", ";
    }
    cerr << "]";
}
template <class T>
void _print(set<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << ", ";
    }
    cerr << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cerr << "[ ";
    for (T i : v)
    {
        _print(i);
        cerr << ", ";
    }
    cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cerr << "[ ";
    for (auto i : v)
    {
        _print(i);
        cerr << ", ";
    }
    cerr << "]";
}
// ----------------- Loop -----------------------------------------------
#define loop(s, e) for (ll ii = s; ii <= e; ii++)
#define rloop(s, e) for (ll ii = s; ii >= e; ii--)
#define input(arr, n)              \
    for (ll ii = 0; ii <= n; ii++) \
        cin >> arr[ii];

// ----------------- Constant -------------------------------------------
const ll MOD = 1e9 + 7;
const double PI = 3.14;

// ----------------- storing (x,y) coordinate of point ------------------
template <typename T>
struct Point
{
    T x, y;
    Point() : x(0), y(0) {}
    Point(T x, T y) : x(x), y(y) {}
};

// ------------------ Number theory ----------------------------------------
ll fastpower(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1 == 1)
            res *= a;
        a *= a;
        b = b >> 1;
    }
    return res;
}

ll sqrt(ld a)
{
    return sqrtl(a);
}

ll gcd(ll a, ll b)
{
    return __gcd(a, b);
}

vector<ll> seive(ll N)
{
    vector<ll> primes(N + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= N; ++i)
    {
        if (primes[i] == 1)
        {
            for (int j = i * i; j <= N; j += i)
                primes[j] = 0;
        }
    }
    vector<ll> res;
    for (int i = 2; i <= N; ++i)
    {
        if (primes[i])
            res.push_back(i);
    }
    return res;
}

vector<vector<ll>> findDivisors(ll N)
{
    vector<vector<ll>> divisors(N);
    for (int i = 1; i <= N; ++i)
    {
        for (int j = i; j <= N; j += i)
        {
            divisors[j].push_back(i);
        }
    }
    return divisors;
}

vector<ll> findPrimeDivisors(ll N)
{
    vector<ll> res;
    vector<ll> primes(N + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= N; ++i)
    {
        if (primes[i] == 1)
        {
            for (int j = i * i; j <= N; j += i)
                primes[j] = 0;
        }
    }
    for (int i = 2; i <= N; ++i)
    {
        if (primes[i] && N % i == 0)
        {
            res.push_back(i);
            while (N % i == 0)
                N /= i;
        }
        if (N == 1)
            break;
    }
    if (N != 1)
        res.push_back(N);
    return res;
}

// ------------------ Bit Manupation -----------------------------------
bool check_bit(ll a, ll i)
{
    if ((a & (1 << i)) != 0)
        return true;
    return false;
}

ll set_bit(ll a, ll i)
{
    return (a | (1 << i));
}

ll unset_bit(ll a, ll i)
{
    return (a & (~(1 << i)));
}

ll toggle_bit(ll a, ll i)
{
    return (a ^ (1 << i));
}

ll least_set_bit(ll a)
{
    return (a & (-a));
}

ll get_bit(ll a, ll i)
{
    return ((a >> i) & 1);
}

ll count_setBits(ll a)
{
    ll ans = 0;
    while (a)
    {
        a = a & (a - 1);
        ans++;
    }
    return ans;
}

void solve()
{
    ll n, q, k;
    cin >> n >> q >> k;
    vector<ll> a;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        a.push_back(x);
    }

    ll ans = 0;
    ll cnt = 0;

    for (ll i = 0; i < n; i++)
    {
        if (a[i] <= k)
        {
            while (i < n and a[i] <= k)
            {
                cnt++;
                i++;
            }
            // cout<<cnt<<" ";
            if (cnt >= q)
            {
            // {   cout<<cnt<<" ";
                ll r = cnt - q + 1ll;
                ans += (r * (r + 1ll)) / 2ll;
            }
        }
        cnt =0;
    }
    // cout << ans << endl;
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
/*

Dima Vatrushin is a math teacher at school. He was sent on vacation for n
 days for his good work. Dima has long dreamed of going to a ski resort, so he wants to allocate several consecutive days and go skiing. Since the vacation requires careful preparation, he will only go for at least k
 days.

You are given an array a
 containing the weather forecast at the resort. That is, on the i
-th day, the temperature will be ai
 degrees.

Dima was born in Siberia, so he can go on vacation only if the temperature does not rise above q
 degrees throughout the vacation.

Unfortunately, Dima was so absorbed in abstract algebra that he forgot how to count. He asks you to help him and count the number of ways to choose vacation dates at the resort.

Input
The first line of the input contains an integer t
 (1≤t≤104
) — the number of test cases.

Then follow the descriptions of the test cases.

The first line of each test case contains three integers n
, k
, q
 (1≤n≤2⋅105
, 1≤k≤n
, −109≤q≤109
) — the length of the array a
, the minimum number of days at the resort, and the maximum comfortable temperature for Dima.

The second line of each test case contains n
 integers a1,a2,a3,…,an
 (−109≤ai≤109
) — the temperature at the ski resort.

The sum of all n
 values over all test cases does not exceed 2⋅105
.

Output
Output t
 integers, each of which is the answer to the corresponding test case — the number of ways for Dima to choose vacation dates at the resort.


*/


/*
 to solve this problem :
    1. we will iterate over the array and check if the temperature is less than or equal to k
    2. if it is then we will iterate over the array until the temperature is less than or equal to k
    3. we will keep a count of the number of days the temperature is less than or equal to k
    4. if the count is greater than or equal to q then we will calculate the number of ways to choose the vacation dates
    5. the number of ways to choose the vacation dates will be (r*(r+1))/2 where r is the number of days the temperature is less than or equal to k minus q plus 1
    6. we will add the number of ways to the answer
    7. finally we will print the answer

*/