//
// AUTHOR: Tal Zichlinsky
// This file will be used to build the Vertex class.

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

        string key;

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
            }

            int remove_nei(string key){
                outs.erase(key);
                ins.erase(key);
            }
    };
}