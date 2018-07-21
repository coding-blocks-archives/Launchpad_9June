// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <map>
#include <queue>
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
        typedef pair<int, int> weightedEdge;
        bool operator()(weightedEdge w1, weightedEdge w2){
            if (w1.second < w2.second){ return false; }
            return true;
        }
    };

    vector<int> dijkstra(int src){
        typedef pair<int, int> weightedEdge;
        priority_queue<weightedEdge, vector<weightedEdge>, compareClass> pq;

        const int inf = 1e6;
        vector<int> distFrmSrc(numVertices + 1, inf);
        vector<bool> visited(numVertices + 1, false);

        distFrmSrc[src] = 0;
        pq.push(make_pair(src, 0));

        while(pq.empty() == false){
            weightedEdge curEdge = pq.top(); pq.pop();

            if (visited[curEdge.first] == true){
                continue;
            }

            visited[curEdge.first] = true;
            distFrmSrc[curEdge.first] = curEdge.second;

            vector<weightedEdge> &nbrList = adjList[curEdge.first];
            for(int i = 0; i < nbrList.size(); ++i){
                weightedEdge curNbr = nbrList[i];
                if (visited[curNbr.first] == false){
                    int distCurNbrFrmSrc = distFrmSrc[curEdge.first] + curNbr.second;
                    pq.push(make_pair(curNbr.first, distCurNbrFrmSrc));
                }
            }
        }
        return distFrmSrc;
    }

};

int main(){
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;
    WeightedGraph g(numVertices);
    for (int i = 0; i < numEdges; ++i) {
        int src, dest, wt;
        cin >> src >> dest >> wt;
        g.addEdge(src, dest, wt);
    }
    g.printGraph();   

    int src; cin >> src;
    vector<int> ans = g.dijkstra(src);
    for(int i = 1; i <= numVertices; ++i){
        cout << ans[i] << " ";
    }
}