#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) REP(i,0,n)
typedef pair<double,double> P;
#define N 1001
double d[1<<15][15][15];
vector<int> G[N],rG[N],g;
bool u[N];
int n,cmp[N];
  
void add_edge(int x,int y){G[x].push_back(y);rG[y].push_back(x);}
void dfs(int x){u[x]=1;rep(i,G[x].size())if(!u[G[x][i]])dfs(G[x][i]);g.push_back(x);} 
void rdfs(int x,int k){u[x]=1;cmp[x]=k;rep(i,rG[x].size())if(!u[rG[x][i]])rdfs(rG[x][i],k);}
int scc() {
  memset(u,0,sizeof(u));g.clear();rep(i,n)if(!u[i])dfs(i);memset(u,0,sizeof(u));
  int k=0;rrep(i,g.size())if(!u[g[i]])rdfs(g[i],k++);return k;
}
void init() {
  rep(i,n) G[i].clear(),rG[i].clear();
  g.clear();
}
int rev(int x) {return (x+n/2)%n;}
int two_sat(vector<P> v) {
  init();
  rep(i,v.size()) {
    add_edge(v[i].F,rev(v[i].S));
    add_edge(v[i].S,rev(v[i].F));
  }
  scc();
  rep(i,n/2) {
    if(cmp[i]==cmp[i+n/2]) return 0;
  }
  return 1;
}
double D(P a,P b) {
  return sqrt((a.F-b.F)*(a.F-b.F)+(a.S-b.S)*(a.S-b.S));
}

int main() {
  int m;
  cin >> n >> m;
  P a[n][2],b[m];
  rep(i,n)rep(j,2) cin >> a[i][j].F >> a[i][j].S;
  rep(i,m) cin >> b[i].F >> b[i].S;
  rep(t,1<<m)rep(i,m)rep(j,m) d[t][i][j]=1<<30;
  rep(k,m) {
    d[1<<k][k][k]=0;
    rep(t,1<<m) {
      rep(i,m) {
        if(!(t&(1<<i))) continue;
        rep(j,m) {
          if(!(t&(1<<j))) d[t|(1<<j)][k][j]=min(d[t|(1<<j)][k][j],d[t][k][i]+D(b[i],b[j]));
        }
      }
    }
  }
  double c[n][n][4];
  n*=2;
  rep(i,n/2) {
    REP(j,i+1,n/2) {
      rep(k,4) c[i][j][k]=1<<30;
      rep(k,m)rep(l,m)rep(s,2)rep(t,2)c[i][j][s+t*2]=min(c[i][j][s+t*2],D(a[i][s],b[k])+d[(1<<m)-1][k][l]+D(b[l],a[j][t]));
    }
  }
  double l=0,r=10000;
  rep(t,50) {
    double mid=(l+r)/2;
    vector<P> v;
    rep(i,n/2) {
      REP(j,i+1,n/2) {
        if(c[i][j][0]>mid) v.push_back(P(i,j));
        if(c[i][j][1]>mid) v.push_back(P(rev(i),j));
        if(c[i][j][2]>mid) v.push_back(P(i,rev(j)));
        if(c[i][j][3]>mid) v.push_back(P(rev(i),rev(j)));
      }
    }
    if(two_sat(v)) r=mid;
    else l=mid;
  }
  printf("%.10f\n",l);
  return 0;
}
