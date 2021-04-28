//
// AUTHOR: Tal Zichlinsky
// Header file for class Graph

#include <map>

namespace zich{
    
    class Graph{

        std::map<std::string, std::map<std::string, double> > adj{};

        public:
            // Constructors
            Graph();
            ~Graph();

            int add_vertex(std::string v);
            
            int add_edge(std::string src, std::string dst, double weight);

            int remove_vertex(std::string v);

            int remove_edge(std::string src, std::string dst);

            int get_size();
    };
}