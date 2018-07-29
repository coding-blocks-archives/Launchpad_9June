#include <bits/stdc++.h>
using namespace std;

class UnionSet {
    vector<int> parent;
    vector<int> sze;

    int root(int curIdx) {
        while (curIdx != parent[curIdx]) {
            curIdx = parent[curIdx];
        }
        return curIdx;
    }

public:
    UnionSet(int numElements) {
        parent.resize(numElements + 1);
        sze.resize(numElements + 1);

        for (int i = 0; i <= numElements; ++i) {
            parent[i] = i;
        }
        fill(sze.begin(), sze.end(), 1);
    }

    void makeSet(int element1, int element2) {
        int root1 = root(element1);
        int root2 = root(element2);

        if (sze[root1] > sze[root2]) {
            parent[root2] = root1;
            sze[root1] += sze[root2];
        }
        else {
            parent[root1] = root2;
            sze[root2] += sze[root1];
        }
    }

    bool isSameSet(int element1, int element2) {
        return root(element1) == root(element2);
    }
};


class WeightedGraph {
    map<int, vector<pair<int, int> > > adjList;
    int numVertices;

public:
    WeightedGraph(int n) {
        numVertices = n;
        for (int i = 1; i <= n; ++i) {
            adjList[i];
        }
    }

    void addEdge(int src, int dest, int wt) {
        adjList[src].push_back(make_pair(dest, wt));
        adjList[dest].push_back(make_pair(src, wt));
    }

    void printGraph() {
        typedef map<int, vector<pair<int, int> > >::iterator mapIterator;

        cout << "--------Graph Begins-----\n";
        for (mapIterator it = adjList.begin(); it != adjList.end(); ++it) {
            int curVtx = it->first;
            const vector<pair<int, int> > &nbrList = it->second;

            cout << curVtx << "\t: ";

            for (int i = 0; i < nbrList.size(); ++i) {
                cout << nbrList[i].first << "(" << nbrList[i].second << ")" << " ";
            }
            cout << endl;
        }
        cout << "-----------Graph ENDS------\n";
    }

    class compareClass {
    public:
        bool operator()(const tuple<int, int, int>& edge1,
                        const tuple<int, int, int>& edge2)
        {
            if (get<2>(edge1) < get<2>(edge2)) {
                return true;
            }
            return false;
        }
    };

    int kruskal() {
        typedef tuple<int, int, int> Edge;
        vector<Edge> edgeList;

        for (int iVtx = 0; iVtx <= numVertices; ++iVtx) {
            int curVtx = iVtx;
            auto& nbrList = adjList[curVtx];
            for (int iNbr = 0; iNbr < nbrList.size(); ++iNbr) {
                pair<int, int> curNbrWt = nbrList[iNbr];
                Edge EdgeVtxNbr = Edge(curVtx, curNbrWt.first, curNbrWt.second);
                edgeList.push_back(EdgeVtxNbr);
            }
        }

        compareClass compClassObj;
        sort(edgeList.begin(), edgeList.end(), compClassObj);

        UnionSet edgeSet(numVertices + 1);
        int minCost = 0;

        for (int i = 0; i < edgeList.size(); ++i) {
            Edge curEdge = edgeList[i];
            int src = get<0>(curEdge);
            int dest = get<1>(curEdge);
            if (edgeSet.isSameSet(src, dest)) {
                continue;
            }
            else {
                minCost += get<2>(curEdge);
                edgeSet.makeSet(src, dest);
            }
        }
        return minCost;
    }
};


int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;
    WeightedGraph g(numVertices);

    for (int iEdge = 0; iEdge < numEdges; ++iEdge) {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        g.addEdge(src, dest, wt);
    }

    g.printGraph();
    int ans = g.kruskal();
    cout << ans;
}