//
// AUTHOR: Tal Zichlinsky
// This file will be used to build the Graph class.
// The vertices on this are implementign the Observer design pattern, such that,
// whenever a vertex connects to a new one, it updates all the other vertices in the currently known connected component.
//
// Each connected component in this graph represents a dimension in which exchanges (conversions) are allowed.

#include<map>
#include<string>

#include "Graph.hpp"

using namespace std;

namespace zich{

    Graph::Graph(){}

    Graph::~Graph(){}

    int Graph::add_vertex(string v){
        if(!adj.count(v)){
            adj[v] = map<string, double>{};
        }
        return 1;
    }

    int Graph::add_edge(string src, string dst, double exc_rate){
        adj[src][dst] = exc_rate;
        
        double tmp;
        for(auto &nei : adj[src]){
            tmp = adj[src][dst] * nei.second;
            adj[src][nei.first] = tmp;
            adj[nei.first][src] = 1/tmp;
        }

        return 1;
    }
    
}