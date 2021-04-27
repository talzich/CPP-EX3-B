//
// AUTHOR: Tal Zichlinsky
// Header file for class Vertex

namespace zich{
    
    class Vertex{

        public:

            Vertex(std::string key);
            ~Vertex();

            std::string get_key();

            int add_nei(std::string key, double weight);
            int remove_nei(std::string key);
    };
}