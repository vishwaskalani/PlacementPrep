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


// Function to find all primes up to n using a bitset and sieve of Eratosthenes
// time complexity of sieve is n(log(log n))
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

//function to find the minimum primes of numbers till n
int MAX_N = 1000000;
vector<ll> least_prime(MAX_N+1, 0);
void leastPrimeFactor()
{
    least_prime[1] = 1;
    for (ll i = 2; i <= MAX_N; i++)
    {
        if (least_prime[i] == 0)
        {
            least_prime[i] = i;
            for (ll j = i*i; j <= MAX_N; j += i){
				if (least_prime[j] == 0){
					least_prime[j] = i;
				}
			}
        }
    }
}

//function to find the number of factors of a number using prime factorization
// this function is sqrt(n) in worst case and O(log n) in best case
// works well
ll factors(ll x){
	ll facts = 1;
	ll count = 0;
	while(x%2==0){
		count++;
		x = x/2;
	}
	facts*=(count+1);
	for(ll i=3; i*i<=x; i+=2){
		ll count =0;
		while(x%i==0){
			count+=1;
			x = x/i;
		}
		facts*=(count+1);
		
	}
	if(x>2){
		facts*=2;
	}
	return facts;
}

// this function finds the largest prime factor of a number using the similar above approach
int largestPrime(int n){
	int answer = 2;
	while(n%2==0){
		n = n/2;
	}
	for(int i=3; i<=sqrt(n); i++){
		bool flag = false;
		while(n%i==0){
			n/=i;
			flag = true;
		}
		if(flag){
			answer = i;
		}
	}
	if(n>2){
		answer = n;
	}
	return answer;
}


// even the above method might time out some times
// we can use the sive for prime factorization in O(log n) time and O(n) space
// The main idea is to precompute the Smallest Prime Factor (SPF) for each number from 1 to MAXN 
// using the sieve function. SPF is the smallest prime number that divides a given number without 
// leaving a remainder. Then, the getFactorization function uses the precomputed SPF array 
// to find the prime factorization of the given number by repeatedly dividing the number 
// by its SPF until it becomes 1.
// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
vector<ll> getFactorization(ll x)
{
    vector<ll> ret;
    while (x != 1) {
        ret.push_back(least_prime[x]);
        x = x / least_prime[x];
    }
    return ret;
}


void solve() {
	cout<<factors(6)<<endl;
	leastPrimeFactor();
	cout<<least_prime[15]<<endl;
	vector<ll> factors = getFactorization(36);
	display_ll(factors);
}


int main()
{   
	solve();
	return 0;
}