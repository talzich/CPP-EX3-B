//
// AUTHOR: Tal Zichlinsky
// This file will be used to build the NumberWithUnits class, as described in this asignment's README file
// (https://github.com/talzich/CPP-EX3-A/blob/master/README.md)

#include <iostream>
#include <fstream>

#include "NumberWithUnits.hpp"

using namespace std;

namespace ariel{

    const string UNIT_FILE_PATH = "units.txt";

    NumberWithUnits::NumberWithUnits(double num, string unit){
        
    }

    void NumberWithUnits::read_units(std::ifstream &u_file){
        
        // Opening file
        u_file.open(UNIT_FILE_PATH);
        if(!u_file){
            cerr << "Unable to open file " << UNIT_FILE_PATH <<endl;
            exit(1);
        }

        char c = ' ';
        while(u_file >> c){
            cout << c << endl;
        }

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

int main(void){
    ariel::NumberWithUnits n{1, "km"};
    ifstream u_file;
    n.read_units(u_file);
    return 0;
}