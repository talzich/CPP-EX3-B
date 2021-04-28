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
        return 1;
    }

    bool Graph::has_vertex(string key){
        return (adj.count(key) == 1);
    }
    
    void Graph::notify(string key1, string key2){
        double tmp;
        for(auto &nei : adj[key2]){
            tmp = adj[key1][key2] * nei.second;
            adj[key1][nei.first] = tmp;
            adj[nei.first][key1] = 1/tmp;
        }
    }

    bool Graph::is_connected(string key1, string key2){
        return (adj.at(key1).count(key2) == 1);
    }

    double Graph::get_weight(string key1, string key2){
        if(!is_connected(key1, key2)){
            throw("Units not on the same dimension");
        }

        return(adj.at(key1).at(key2));
    }
}