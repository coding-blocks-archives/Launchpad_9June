#include <bits/stdc++.h>
using namespace std;

class WeightedGraph{
    map<int, vector<pair<int, int> > > adjList;
    int numVertices;

public:
    WeightedGraph(int n){
        numVertices = n;
        for(int i = 1; i <= n; ++i){
            adjList[i];
        }
    }

    void addEdge(int src, int dest, int wt){
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

    class compareClass{
    public:
        bool operator()(const tuple<int, int, int>& edge1, 
                        const tuple<int, int, int>& edge2)
        {
               if (get<2>(edge1) < get<2>(edge2)){
                return false;
               }
               return true;
        }
    };

    int primsAlgo(){
        int src = 0;
        typedef tuple<int, int, int> Edge;
        priority_queue<Edge, vector<Edge>, compareClass > minEdge;
        vector<bool> visited(numVertices + 1);

        minEdge.push(tuple<int, int, int>(src, src, 0));
        int minCost = 0;

        while(minEdge.empty() == false){
            Edge curEdge = minEdge.top(); minEdge.pop();
            int curSrc = get<0>(curEdge);
            int curNbr = get<1>(curEdge);
            int curCost = get<2>(curEdge);
            if (visited[curNbr] == true){
                continue;
            }

            visited[curNbr] = true;
            minCost += curCost;
            const auto& curList = adjList[curNbr];
            for(int iNbr = 0; iNbr < curList.size(); ++iNbr){
                auto& curPair = curList[iNbr];  // auto is pair<int, int>
                int curNbrNbr = curPair.first;
                int curNbrCost = curPair.second;
                if (visited[curNbrNbr] == false){
                    minEdge.push(Edge(curNbr, curNbrNbr, curNbrCost));
                }
            }
        }
        return minCost;
    }
};


int main(){
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;
    WeightedGraph g(numVertices);

    for(int iEdge = 0; iEdge < numEdges; ++iEdge){
        int src, dest, wt;
        cin >> src >> dest >> wt;
        g.addEdge(src, dest, wt);
    }

    g.printGraph();
    int ans = g.primsAlgo();
    cout << ans;
}