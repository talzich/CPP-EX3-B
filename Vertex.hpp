//
// AUTHOR: Tal Zichlinsky
// Header file for class Vertex. This class will be implementing the observer design pattern

#include <map>

namespace zich{
    
    class Vertex{
        
        string key;

        public:

            Vertex();
            Vertex(string key);
            ~Vertex();

            string get_key();

            int add_nei(string key, double weight);
            int remove_nei(string key);
    };
}