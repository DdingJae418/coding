#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;

vector<set<int>> graph;
vector<bool> visited;
vector<int> visitSeq;

void dfs(int node, int& seq)
{
    visited[node] = true;
    seq+=1;
    visitSeq[node] = seq;

    for (int n : graph[node])
        if (!visited[n])
            dfs(n, seq);
}

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

    int seq = 0;
    dfs(startNode, seq);

    copy(visitSeq.begin()+1, visitSeq.end(), ostream_iterator<int>(cout, "\n"));

    return 0;
}