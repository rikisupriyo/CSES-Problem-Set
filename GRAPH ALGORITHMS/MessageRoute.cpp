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

int n,m;
vi adj[MAX_N], dist, parent;

void pathShort() {
	vi v;

	while(n != 1) {
		v.pb(n);
		n = parent[n];
	}
	v.pb(1);
	reverse(v.begin(), v.end());

	rep(i,0,v.size()) cout<<v[i]<<" ";
}


void bfs(int s) {

	queue<int> q;
	dist.assign(n+1, -1);
	parent.assign(n+1, -1);
	q.push(s);
	dist[s] = 1;
	parent[s] = s;

	while(!q.empty()) {
		int u = q.front();
		q.pop();

		for(auto nbrs:adj[u]) {
			if(dist[nbrs] == -1) {
				q.push(nbrs);
				dist[nbrs] = dist[u] + 1;
				parent[nbrs] = u;
			}
		}
	}
	if(dist[n] != -1) {cout<<dist[n]<<endl; pathShort();}
	else cout<<"IMPOSSIBLE\n";
}

void solve(){
	cin>>n>>m;
	rep(i,0,m) {
		int u,v; cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	bfs(1);
}

int main(){
	
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif

	solve();
	
	return 0;
}