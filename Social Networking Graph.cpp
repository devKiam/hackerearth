#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll bfs(vector<ll> adjList[], vector<ll> &dist, ll start, ll distance, ll counting)
{
    queue<ll> q;
    q.push(start);
    dist[start] = 0;
    while(!q.empty())
    {
        ll frontNode = q.front();
        q.pop();
        for(ll i=0; i<adjList[frontNode].size(); i++)
        {
            if(dist[adjList[frontNode][i]] == -1)
            {
                q.push(adjList[frontNode][i]);
                dist[adjList[frontNode][i]] = dist[frontNode] + 1;
                if(dist[adjList[frontNode][i]] == distance) counting++;
            }
        }
    }
    return counting;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    memset(dp, -1, sizeof(dp));
    ll nodes, edges; cin>>nodes>>edges;

    vector<ll> adjList[nodes+1];

    for(ll i=1; i<=edges; i++)
    {
        ll x, y; cin>>x>>y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    ll nQueries; cin>>nQueries;

    for(ll i=0; i<nQueries; i++)
    {
        vector<ll> dist(nodes+1, -1);

        ll start, distance; cin>>start>>distance;

        cout<<bfs(adjList, dist, start, distance, 0)<<endl;
    }
}
