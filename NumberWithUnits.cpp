//
// AUTHOR: Tal Zichlinsky
// This file will be used to build the NumberWithUnits class, as described in this asignment's README file
// (https://github.com/talzich/CPP-EX3-A/blob/master/README.md)

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cmath>

#include "NumberWithUnits.hpp"
#include "Graph.cpp"

using namespace std;
using namespace zich;

const string UNIT_FILE_PATH = "units.txt";
const int START = 0;
const double EPS = 0.00001;

namespace ariel{

    zich::Graph g{};
    bool read_flag = false;

    NumberWithUnits convert(NumberWithUnits num, string dst_unit){
        
        // We need to check if units are connected on the graph
        if(!g.is_connected(num.get_unit(), dst_unit)){
            throw("Units not on the same dimension");
        }
        
        NumberWithUnits *converted;
        converted = new NumberWithUnits(num.get_number()*g.get_weight(num.get_unit(), dst_unit), dst_unit);
        return *converted;
    }

    NumberWithUnits::NumberWithUnits(double num, string unit){

        if(!read_flag) throw("Units file not read yet");
        if(!g.has_vertex(unit))  throw("Unit provided not acceptable");

        this->number = num;
        this->unit = unit;
    }

    double NumberWithUnits::get_number(){
        return this->number;
    }

    string NumberWithUnits::get_unit(){
        return this->unit;
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

            g.add_vertex(u1);
            g.add_vertex(u2);

            g.add_edge(u1, u2, rate2);
            g.add_edge(u2, u1, 1/rate2);

            g.notify(u1, u2);
            g.notify(u2, u1);

        }

        read_flag = true;
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
        if(this->unit != num.unit){
            NumberWithUnits converted = convert(num, this->unit);
            return NumberWithUnits{this->get_number()+converted.get_number(), this->get_unit()};
        }
        return NumberWithUnits{num.get_number() + this->get_number(), this->get_unit()};
        
    }
    NumberWithUnits NumberWithUnits::operator+=(NumberWithUnits num){
        return *this;
    }

    //-----------------------------
    // Comparison Operators
    //-----------------------------

    bool operator!=(NumberWithUnits num1, NumberWithUnits num2){
        return !(num1 == num2);
    }
    bool operator==(NumberWithUnits num1, NumberWithUnits num2){
        if(num1.get_unit() != num2.get_unit()){
            NumberWithUnits converted = convert(num2, num1.get_unit());
            double diff = abs(converted.get_number() - num1.get_number());
            return (diff < EPS);
        }

        double diff = abs(num2.get_number() - num1.get_number());
        return (diff < EPS);
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
        out << num.get_number() << '[' << num.get_unit() << ']';
        return out;
    }
    istream& operator>>(istream &in, NumberWithUnits num){
        return in;
    }

}

// int main(){
//     //ariel::NumberWithUnits n{1, "km"};
//     ifstream u_file(UNIT_FILE_PATH);
//     ariel::NumberWithUnits::read_units(u_file);
//     return 0;
// }