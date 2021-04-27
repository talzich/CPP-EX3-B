//
// AUTHOR: Tal Zichlinsky
// Header file for class Vertex

namespace zich{
    
    class Vertex{

        public:

            Vertex(std::string key);
            ~Vertex();

            std::string get_key();

            int add_nei(Vertex nei, double weight);
            // int add_nei_in();
            int remove_nei(std::string key);
    };
}