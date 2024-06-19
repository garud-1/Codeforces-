/*
  BY AKSHAY SURESH WALE 
  Linkedin : https://www.linkedin.com/in/akshay-wale-28b20a257/
*/


#include <bits/stdc++.h>
using namespace std;

#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);              \
    cout.precision(numeric_limits<double>::max_digits10);
#define int long long
#define ll long long
#define ld long double
#define memset(arr, val) memset(arr, val, sizeof(arr))
#define INF INT64_MAX
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define umap unordered_map
#define mii map<int, int>
#define pii pair<int, int>
#define vi vector<int>
#define vc vector<char>
#define vb vector<bool>
#define vvi vector<vi>
#define vpii vector<pii>
#define ff first
#define ss second
#define rep(i, x, y) for (int i = x; i < y; i++)
#define rrep(i, x, y) for (int i = x; i >= y; i--)
#define setbits(n) __builtin_popcountll(n)
#define bitsize(n) (63 - __builtin_clzll(n))
#define lcm(a, b) (a / __gcd(a, b) * b)
#define yn(f) f ? cout << "YES\n" : cout << "NO\n"
#define syn(f) f ? cout << "Yes\n" : cout << "No\n"

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

void Akshay()
{
    int n;cin>>n;
    char c ;cin>>c;
    string s;cin>>s;

    int index = n-1,index2 =0;
    rrep(i,n-1,0)if(s[i] == c) {index =i;break;}
    rep(i,n,0) if(s[i] == c) {index2 = i;break;}
    // now we have to find the nearest green index from this index 
    if(c == 'g') {cout<<0<<endl;return;}
    int i = index,cnt=0;
    while(s[i%n] != 'g'){
         ++cnt;i++;
    }

    int j = index2,cnt2=0;
    while(s[j%n] != 'g'){
         cnt2++;j++;
    }
    cout<<max(cnt,cnt2)<<endl;
}

int32_t main()
{
    fastIO;
#ifndef ONLINE_JUDGE
// freopen("input.txt", "r" , stdin);
// freopen("output.txt", "w", stdout);
#endif

    ll t = 1;
    cin >> t;

    while (t--)
    {   
        Akshay();
    }

    return 0;
}


/*
 key note 
 what were we finding : maximum distance of the greeen light from the nearest light er have given 
 whats the fault : 
 in the test where n = 3 c = y
 our ans will be 1 by the first count by the next ount our ans will be 2 
 
*/