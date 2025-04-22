#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <iterator>

using namespace std;

vector<set<int>> graph;
vector<bool> visited;
vector<int> visitSeq;


int main(void)
{
    int vertexNum, edgeNum, startNode;
    cin>>vertexNum>>edgeNum>>startNode;

    graph.resize(vertexNum + 1);
    visited.resize(vertexNum + 1);
    visitSeq.resize(vertexNum + 1);

    for (int i = 0; i < edgeNum; i++)
    {
        int v1, v2;
        cin>>v1>>v2;

        graph[v1].insert(v2);
        graph[v2].insert(v1);
    }

    queue<int> q;
    int seq = 1;
    visited[startNode] = true;
    visitSeq[startNode] = seq;
    q.push(startNode);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int n : graph[cur])
            if(!visited[n])
            {
                visited[n] = true;
                visitSeq[n] = ++seq;
                q.push(n);
            }
    }

    copy(visitSeq.begin()+1, visitSeq.end(), ostream_iterator<int>(cout, "\n"));

    return 0;
}