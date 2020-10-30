#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

void bfs(vector<ll> v[], vector<ll> &dist, ll start)
{
    queue<ll> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty())
    {
        ll frontNode = q.front();
        q.pop();
        for(ll i = 0; i < v[frontNode].size(); i++)
        {
            if(dist[v[frontNode][i]] == -1)
            {
                q.push(v[frontNode][i]);
                dist[v[frontNode][i]] = dist[frontNode] + 1;
            }

        }

    }

}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    memset(dp, -1, sizeof(dp));
    ll testCases; cin>>testCases;
    while(testCases--)
    {
        ll nodes, edges; cin>>nodes>>edges;
        vector<ll> v[nodes+1];
        vector<ll> dist(nodes+1, -1);
        for(ll i=1; i<=edges; i++)
        {
            ll x, y; cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        bfs(v, dist, 1);
        cout<<dist[nodes]<<endl;
    }
}
