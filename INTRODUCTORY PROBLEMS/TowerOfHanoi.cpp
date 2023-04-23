#include <bits/stdc++.h>
using namespace std;

/* functions */

#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define SQ(a) (a)*(a)
#define rep(i,a,b) for (int i=a; i<b; i++)
#define crep(i,a,b) for (int i=a; i<=b; i++)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()

/* types */

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define mii map<int, int>
#define si set<int>
#define sc set<char>

/* utils */

void yes() {cout<<"YES\n";}
void no() {cout<<"NO\n";}

/* constants */

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int c=0;
vector<pair<int,int>> v;

void towerOfHanoi(int n, int s, int h, int d) {
    if (n==0) return;
    towerOfHanoi(n-1, s, d, h);
    v.pb({s, d}); c++;
    towerOfHanoi(n-1, h, s, d);
}

void solve(){
	int n;
	cin>>n;
	towerOfHanoi(n, 1, 2, 3);
	cout<<c<<"\n";
	rep(i,0,v.size()) 
		cout<<v[i].f<<" "<<v[i].s<<"\n";
}

int main(){
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	solve();
	
	return 0;
}