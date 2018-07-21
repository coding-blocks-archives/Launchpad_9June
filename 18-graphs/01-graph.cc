// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

template<typename T>
class BiDirectionalGraph {
    map<T, vector<T> > adjList;
    int numVertices;

    void dfs(T src, set<T> &visited) {
        visited.insert(src);
        cout << src << " ";

        const vector<T> &nbrList = adjList[src];
        for (int i = 0; i < nbrList.size(); ++i) {
            T curNbr = nbrList[i];
            if (visited.find(curNbr) == visited.end()) {
                // this applies that curNbr is not in the sack...it means it has not been
                // visited so far
                dfs(curNbr, visited);
            }
        }
    }

public:
    BiDirectionalGraph(int n) {
        numVertices = n;
    }

    void addEdge(T src, T dest) {
        // adjList["Pakistan"] // if (adjList.find("Pakistan") == adjList.end())
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void printGraph() {
        typedef typename map<T, vector<T> >::iterator mapIterator;

        cout << "--------Graph Begins-----\n";
        for (mapIterator it = adjList.begin(); it != adjList.end(); ++it) {
            T curVtx = it->first;
            const vector<T> &nbrList = it->second;

            cout << curVtx << "\t: ";

            for (int i = 0; i < nbrList.size(); ++i) {
                cout << nbrList[i] << " ";
            }
            cout << endl;
        }
        cout << "-----------Graph ENDS------\n";
    }

    void dfs(T src) {
        set<T> visited;
        dfs(src, visited);
    }

    void bfs(T src) {
        queue<T> curVtxToVisit;
        set<T> visited;
        curVtxToVisit.push(src);
        visited.insert(src);    // Mark src as visited

        while (curVtxToVisit.empty() == false) {
            T curVtx = curVtxToVisit.front(); curVtxToVisit.pop();
            cout << curVtx << " ";

            vector<T> &nbrList = adjList[curVtx];
            for (int i = 0; i < nbrList.size(); ++i) {
                T curNbr = nbrList[i];
                if (visited.find(curNbr) == visited.end()) {
                    curVtxToVisit.push(curNbr);
                    visited.insert(curNbr);
                }
            }
        }
    }

    // enum Elephant {AFRICAN , INDIAN}; Elephant e;

    bool isBipartite() {
        T src = adjList.begin()->first;
        enum state { RED, BLACK, UNCOLORED };

        map<T, state> color;
        typedef typename map<T, vector<T> >::iterator mapIterator;
        for (mapIterator it = adjList.begin(); it != adjList.end(); ++it) {
            T curVtx = it->first;
            color[curVtx] = UNCOLORED;
        }

        queue<T> vtxToProcess;

        for (mapIterator it = adjList.begin(); it != adjList.end(); ++it) {
            T src = it->first;
            if (color[src] == UNCOLORED) {
                vtxToProcess.push(src);
                color[src] = RED;

                while (vtxToProcess.empty() == false) {
                    T curVtx = vtxToProcess.front(); vtxToProcess.pop();

                    vector<T> &nbrList = adjList[curVtx];
                    for (int i = 0; i < nbrList.size(); ++i) {
                        T curNbr = nbrList[i];
                        if (color[curNbr] == UNCOLORED) {
                            color[curNbr] = color[curVtx] == RED ? BLACK : RED;
                            vtxToProcess.push(curNbr);
                        }
                        else if (color[curNbr] == color[curVtx]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    int numVertices, numEdges;
    cin >> numVertices >> numEdges;

    BiDirectionalGraph<string> g(numVertices);

    for (int i = 0; i < numEdges; ++i) {
        string src, dest;
        cin >> src >> dest;
        g.addEdge(src, dest);
    }
    g.printGraph();

    // g.dfs("Delhi");
    // g.bfs("Delhi");
    bool ans = g.isBipartite();
    cout << ans;
}