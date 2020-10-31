#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll dirRow[] = {-1, 1, 0, 0, -1, 1, -1, 1};
ll dirCol[] = {0, 0, 1, -1, -1, 1, 1, -1};

void bfs(vector< vector<ll> > &dist, ll sizeOfRow, ll sizeOfColumn, ll startRow, ll startColumn)
{
    queue<ll> rowQ;
    queue<ll> columnQ;
    rowQ.push(startRow); columnQ.push(startColumn);
    dist[startRow][startColumn] = 0;

    while(!rowQ.empty())
    {
        ll r = rowQ.front(); ll c = columnQ.front();
        rowQ.pop(); columnQ.pop();
        for(int i=0; i<8; i++)
        {
            if(r + dirRow[i] >= sizeOfRow || c + dirCol[i] >= sizeOfColumn || r + dirRow[i] < 0 || c + dirCol[i] < 0) continue;
            if(dist[r + dirRow[i]][c + dirCol[i]] == -1)
            {
                dist[r + dirRow[i]][c + dirCol[i]] = dist[r][c] + 1;
                rowQ.push(r + dirRow[i]); columnQ.push(c + dirCol[i]);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
//    memset(dp, -1, sizeof(dp));
    ll sizeOfRow, sizeOfColumn, startRow, startColumn; cin >> sizeOfRow >> sizeOfColumn >> startRow >> startColumn;
    vector< vector<ll> > dist(sizeOfRow, vector<ll> (sizeOfColumn, -1));

    bfs(dist, sizeOfRow, sizeOfColumn, startRow, startColumn);

    for(ll i=0; i<sizeOfRow; i++)
    {
        for(ll j=0; j<sizeOfColumn; j++)
        {
            cout<<dist[i][j]<<" ";
        }
        cout<<"\n";
    }
}
