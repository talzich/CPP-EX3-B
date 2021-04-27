//
// AUTHOR: Tal Zichlinsky
// This file will be used to build the Vertex class. This class will be implementing the Observer design pattern
// such that every vertex will be notified when one of its children (neighbors on outgoing edges) has a new outgoing edge.
// Thus, for each dimension in the units.txt file we would have a complete sub-graph in the entire graph representing the units file

#include <map>
#include <string>

#include "Vertex.hpp"

using namespace std;

namespace zich{

    class Vertex{

        // Maps to keep track of neighbors on ingoing or outgoing edges. The ins map will double as an observers(subscribers) list
        map<string, double> outs;
        map<string, double> ins;

        string key;

        public:
            
    };
}