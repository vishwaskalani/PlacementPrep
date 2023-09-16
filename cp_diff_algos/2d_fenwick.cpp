#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pob pop_back
#define ff first
#define ss second
#define vi vector<int>
#define vll vector<long long>
#define mp make_pair
#define min3(a,b,c) min(min(a,b),c)
#define min4(a,b,c,d) min(min(a,b),min(c,d))
#define max3(a,b,c) max(max(a,b),c)
#define max4(a,b,c,d) max(max(a,b),max(c,d))
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
typedef vector<vi> vvi;
typedef vector<vll> vvl;
const ll MOD=1e9+7;
const ll INF=1e18;
const ll NINF=-1*1e18;
#define mapii map<int, int>
#define mapll map<long, long>
#define FOR(i, a, b) for (ll i = (a); i < (b); ++i)
#define rof(i, a, b) for (ll i = (b)-1; i >= (a); --i)
#define rep(a) for (ll i = 0; i < a; ++i)
#define vln(a, n)    \
    vector<ll> a(n); \
    rep(n) cin >> a[i];
#define str(s) \
    string s;  \
    cin >> s;
void display_ll(vector<ll> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}
void display_int(vector<int> &v){
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
}
#define fio                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define tc     \
    ll tc;     \
    cin >> tc; \
    while (tc--)

ll sum(vll &v){
    int n=v.size();
    ll sum=0;
    FOR(i,0,n){
        sum+=v[i];
    }
    return sum;
}
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
}
long long fast_power(long long x,long long p)
{
    long long re=1;
    while (p)
    {
        if (p&1)
           re=re*x%MOD;
        x=x*x%MOD;
        p>>=1;
    }
    return re;
}
// Function to calculate nCr
ll NcR(ll n, ll r)
{
    ll p= 1, k = 1;
    if (n - r < r)
        r = n - r;
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
            ll m = gcd(p, k);
            p /= m;
            k /= m;
            n--;
            r--;
        }
    }
    else{
        p = 1;
    }
    return p;
}


// Function to find all primes up to n using a bitset and sieve of Eratosthenes
vector<int> findPrimes(int n)
{
    bitset<10000010> sieve;
    sieve.set();
    sieve[0] = sieve[1] = 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= n; j += i)
                sieve[j] = 0;
        }
    }
    vector<int> primes;
    for (int i = 0; i <= n; i++)
    {
        if (sieve[i])
            primes.push_back(i);
    }
    return primes;
}

struct FenwickTree{
    vector<vector<int>> bit;
    vector<vector<int>> mp;
    int n;
    int m;
    FenwickTree(int n,int m){
        this->n = n;
        this->m = m;
        bit.assign(n,vector<int>(m,0));
        mp.assign(n,vector<int>(m,0));
    }

    FenwickTree(vector<vector<int>> arr) : FenwickTree(arr.size(),arr[0].size()){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                add(i,j,arr[i][j]);
                mp[i][j] = 1;
            }
        }
    }

    void add(int x,int y,int delta){
        if(!mp[x][y]){
            for(int i=x; i<n; i = i | (i+1)){
                for(int j=y; j<m; j = j|(j+1)){
                    bit[i][j] += delta;
                }
            }
            mp[x][y] = 1;
        }
    }

    int sum(int x,int y){
        int ret = 0;
        for(int i=x; i>=0; i = (i&(i+1))-1){
            for(int j=y; j>=0; j = (j&(j+1))-1){
                ret += bit[i][j];
            }
        }
        return ret;
    }
    
};


void solve() {
    int t;
    cin>>t;
    int count = 0;
    while(t--){
        count++;
        cout<<"Case "<<count<<":"<<endl;
        int q;
        cin>>q;
        FenwickTree ft(1000,1000);
        for(int i=0; i<q; i++){
            int qtype;
            cin>>qtype;
            if(qtype==0){
                int x,y;
                cin>>x>>y;
                ft.add(x,y,1);
            }
            else if (qtype==1){
                int x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                cout<<ft.sum(x2,y2)-ft.sum(x1-1,y2)-ft.sum(x2,y1-1)+ft.sum(x1-1,y1-1)<<endl;
            }
        }

    }

}


int main()
{   
    fio;
    solve();
    return 0;
}