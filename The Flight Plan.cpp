#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

void bfs(vector<ll> adjList[], vector<ll> &cost, vector<ll> &parent, ll start, ll destination, ll nodes, ll edges, ll t, ll c)
{
    queue<ll> q; q.push(start); cost[start] = 0;
    while(!q.empty())
    {
        ull frontNode = q.front(); q.pop();
        sort(adjList[frontNode].begin(), adjList[frontNode].end());
        for(ull i=0; i<adjList[frontNode].size(); i++)
        {
            if(cost[adjList[frontNode][i]] == -1)
            {
                q.push(adjList[frontNode][i]);
                parent[adjList[frontNode][i]] = frontNode;
                cost[adjList[frontNode][i]] = cost[frontNode] + c;
                if(adjList[frontNode][i] == destination) return;
//                if((cost[adjList[frontNode][i]] / t) % 2 == 1)
//                {
//                    cost[adjList[frontNode][i]] += t - (cost[adjList[frontNode][i]] % t);
//                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    memset(dp, -1, sizeof(dp));
    ll nodes, edges, t, c; cin>>nodes>>edges>>t>>c;
    vector<ll> adjList[nodes+1];
    vector<ll> cost(nodes+1, -1);
    vector<ll> parent(nodes+1, -1);
    for(ll i=0; i<edges; i++)
    {
        ll u,v; cin>>u>>v;
        adjList[u].push_back(v); adjList[v].push_back(u);
    }
    ll start, destination; cin>>start>>destination;

    bfs(adjList, cost, parent, start, destination, nodes, edges, t, c);

    ll i = destination;
    vector<ll> v;
    while(parent[i] > -1)
    {
        v.push_back(parent[i]);
        i = parent[i];
    }
    reverse(v.begin(), v.end());
    cout<<v.size()+1<<endl;

    for(ll i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<destination<<endl;
}
