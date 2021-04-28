//
// AUTHOR: Tal Zichlinsky
// This file will be used to build the NumberWithUnits class, as described in this asignment's README file
// (https://github.com/talzich/CPP-EX3-A/blob/master/README.md)

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

#include "NumberWithUnits.hpp"
#include "Graph.hpp"

using namespace std;
using namespace zich;

const string UNIT_FILE_PATH = "units.txt";
const int START = 0;

namespace ariel{

    zich::Graph g{};

    NumberWithUnits::NumberWithUnits(double num, string unit){
        
    }

    void NumberWithUnits::read_units(ifstream &u_file){
        
        // Open file, if not already open
        if (!u_file.is_open()){
            // Opening file
            u_file.open(UNIT_FILE_PATH);
            if(!u_file){
                cerr << "Unable to open file " << UNIT_FILE_PATH <<endl;
                exit(1);
            }
        }

        string u1 = "", u2 = "", dummy = "=";
        double rate1, rate2;
        string str = "";
        while(getline(u_file, str)){
            istringstream s_str(str);
            s_str >> rate1 >> u1 >> dummy >> rate2 >> u2;
        }
        
        g.add_vertex(u1);
        g.add_vertex(u2);

        g.add_edge(u1, u2, rate2);
        g.add_edge(u2, u1, 1/rate2);

        u_file.close();

    }

    //-----------------------------
    // Arithmetic Operators
    //-----------------------------

    NumberWithUnits NumberWithUnits::operator-(){
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator-(NumberWithUnits num){
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator-=(NumberWithUnits num){
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator+(){
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator+(NumberWithUnits num){
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator+=(NumberWithUnits num){
        return *this;
    }

    //-----------------------------
    // Comparison Operators
    //-----------------------------

    bool operator!=(NumberWithUnits num1, NumberWithUnits num2){
        return false;
    }
    bool operator==(NumberWithUnits num1, NumberWithUnits num2){
        return false;
    }

    bool operator<=(NumberWithUnits num1, NumberWithUnits num2){
        return false;
    }
    bool operator>=(NumberWithUnits num1, NumberWithUnits num2){
        return false;
    }

    bool operator<(NumberWithUnits num1, NumberWithUnits num2){
        return false;
    }
    bool operator>(NumberWithUnits num1, NumberWithUnits num2){
        return false;
    }

    //-----------------------------
    // Increment Decrement Operators
    //-----------------------------

    NumberWithUnits NumberWithUnits::operator--(){
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator--(int dummy){
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator++(){
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator++(int dummy){
        return *this;
    }

    //-----------------------------
    // Friend Operators
    //-----------------------------

    NumberWithUnits operator*(double d, NumberWithUnits num){
        return num;
    }

    NumberWithUnits operator*(NumberWithUnits num, double d){
        return num;
    }

    //-----------------------------
    // I/O Operators
    //-----------------------------
    ostream& operator<<(ostream &out, NumberWithUnits num){
        return out;
    }
    istream& operator>>(istream &in, NumberWithUnits num){
        return in;
    }

}

// int main(void){
//     ariel::NumberWithUnits n{1, "km"};
//     ifstream u_file(UNIT_FILE_PATH);
//     n.read_units(u_file);
//     return 0;
// }