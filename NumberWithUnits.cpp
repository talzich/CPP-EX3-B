//
// AUTHOR: Tal Zichlinsky
// This file will be used to build the NumberWithUnits class, as described in this asignment's README file
// (https://github.com/talzich/CPP-EX3-A/blob/master/README.md)

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
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

    NumberWithUnits convert(const NumberWithUnits& num, const string& dst_unit){
        
        // We need to check if units are connected on the graph
        if(!g.is_connected(num.get_unit(), dst_unit)){
            throw("Units not on the same dimension");
        }
        
        return NumberWithUnits{num.get_number()*g.get_weight(num.get_unit(), dst_unit), dst_unit};
    }

    NumberWithUnits::NumberWithUnits(double num, const string &unit){

        if(!g.has_vertex(unit)){
            throw("Unit provided not acceptable");
        }  

        this->number = num;
        this->unit = unit;
    }

    double NumberWithUnits::get_number()const{
        return this->number;
    }

    string NumberWithUnits::get_unit()const{
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

        string u1, u2, str, dummy = "=";
        double rate1 = 0, rate2 = 0;
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

        u_file.close();

    }

    //-----------------------------
    // Arithmetic Operators
    //-----------------------------

    NumberWithUnits NumberWithUnits::operator-() const{
        return NumberWithUnits{this->get_number()*(-1), this->get_unit()};
    }

    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &num){
        if(this->unit != num.unit){
            NumberWithUnits converted = convert(num, this->unit);
            return NumberWithUnits{this->get_number()-converted.get_number(), this->get_unit()};
        }
        return NumberWithUnits{this->get_number()-num.get_number(), this->get_unit()};
    }
    
    NumberWithUnits NumberWithUnits::operator-=(const NumberWithUnits &num){
        *this = *this - num;
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator+()const{
        return *this;
    }
    
    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &num){
        if(this->unit != num.unit){
            NumberWithUnits converted = convert(num, this->unit);
            return NumberWithUnits{this->get_number()+converted.get_number(), this->get_unit()};
        }
        return NumberWithUnits{num.get_number() + this->get_number(), this->get_unit()};
    }
    
    NumberWithUnits NumberWithUnits::operator+=(const NumberWithUnits &num){
        *this = *this + num;
        return *this;
    }

    NumberWithUnits NumberWithUnits::operator*(double d) const{
        return NumberWithUnits{this->get_number()*d, this->get_unit()};
    }
    
    //-----------------------------
    // Comparison Operators
    //-----------------------------

    bool NumberWithUnits::operator!=(const NumberWithUnits &other) const{
        return !(*this == other);
    }
    bool NumberWithUnits::operator==(const NumberWithUnits &other) const{
        if(this->get_unit() != other.get_unit()){
            NumberWithUnits converted = convert(other, this->get_unit());
            double diff = abs(converted.get_number() - this->get_number());
            return (diff < EPS);
        }

        double diff = abs(other.get_number() - this->get_number());
        return (diff < EPS);
    }

    bool NumberWithUnits::operator<=(const NumberWithUnits &other) const{
        return (*this < other || *this == other);
    }
    bool NumberWithUnits::operator>=(const NumberWithUnits &other) const{
         return (*this > other || *this == other);
    }

    bool NumberWithUnits::operator<(const NumberWithUnits &other) const{
        return (*this != other && !(*this > other));
    }
    bool NumberWithUnits::operator>(const NumberWithUnits &other) const{
        if(*this == other) {
            return false;
        }
        if(this->get_unit() != other.get_unit()){
            NumberWithUnits converted = convert(other, this->get_unit());
            double diff = converted.get_number() - this->get_number();
            return (diff < EPS);
        }

        double diff = other.get_number() - this->get_number();
        return (diff < EPS);
    }

    //-----------------------------
    // Increment Decrement Operators
    //-----------------------------


    NumberWithUnits &NumberWithUnits::operator--(){
        --(this->number);
        return *this;
    }
    
    // Postfix
    NumberWithUnits NumberWithUnits::operator--(int dummy){
        return NumberWithUnits((this->number)--, this->unit);
    }


    NumberWithUnits &NumberWithUnits::operator++(){
        ++(this->number);
        return *this;
    }

    // Postfix
    NumberWithUnits NumberWithUnits::operator++(int dummy){
        return NumberWithUnits((this->number)++, this->unit);
    }

    //-----------------------------
    // Friend Operators
    //-----------------------------

        //-----------------------------
        // Arithmetic Operators
        //-----------------------------
        NumberWithUnits operator*(double d,const NumberWithUnits &num){
            return NumberWithUnits{num.get_number()*d, num.get_unit()};
        }

        //-----------------------------
        // I/O Operators
        //-----------------------------
        ostream& operator<<(ostream &out, const NumberWithUnits num){
            out << num.get_number() << '[' << num.get_unit() << ']';
            return out;
        }

        istream& operator>>(istream& in, NumberWithUnits& num){
            
            string unit;
            char temp1 = 0, temp2 = 0;
            double number = 0;

            // Places each element in its proper place, although, further checks are neccesary
            in>>number>>temp1>>unit;

            // If char ] is in the string unit
            if(unit.find(']')!=string::npos){
                size_t index = unit.find(']');
                unit = unit.substr(0,index);
            }
            else{
                in>>temp2;
            } 

            // If we already know the unit
            if(g.has_vertex(unit)){
                num.number = number;
                num.unit = unit;
            }

            else{
                throw ("Unit specified is unacceptable");
            }

            return in;
        }
}