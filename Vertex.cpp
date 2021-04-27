//
// AUTHOR: Tal Zichlinsky
// This file will be used to build the Vertex class. This class will be implementing the Observer design pattern
// such that every vertex will be notified when one of its children (neighbors on outgoing edges) has a new outgoing edge.
// Thus, for each dimension in the units.txt file we would have a complete sub-graph in the entire graph representing the units file

#include <map>
#include <string>
#include <vector>

#include "Vertex.hpp"

using namespace std;

namespace zich{

    class Vertex{

        // Maps to keep track of neighbors on ingoing or outgoing edges
        map<string, double> outs{};
        map<string, double> ins{};

        vector<Vertex> observers;
        string key;

        void update(Vertex nei, double weight){
            for(Vertex v : observers){
                v.add_nei(nei, weight);
            }
        }

        public:
            Vertex(string new_key){
                key = new_key;
            }

            ~Vertex(){
            }

            string get_key(){
                return key;
            }

            int add_nei(Vertex nei, double weight){
                outs[nei.get_key()] = weight;
                ins[nei.get_key()] = 1/weight;
                update(nei, weight);
                observers.push_back(nei);
            }
            
            
            // int add_nei_in();
            int remove_nei(string key);
    };
}