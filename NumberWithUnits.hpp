//
// AUTHOR: Tal Zichlinsky
// Header file for class NumberWithUnits

#include <string>


namespace ariel{

    class NumberWithUnits{

        double number;
        std::string unit;

        public:
            NumberWithUnits(double num, std::string unit);

            std::string get_unit();
            double get_number();

            static void read_units(std::ifstream &u_fle);

            //-----------------------------
            // Arithmetic Operators
            //-----------------------------

            NumberWithUnits operator-();
            NumberWithUnits operator-(NumberWithUnits num);
            NumberWithUnits operator-=(NumberWithUnits num);

            NumberWithUnits operator+();
            NumberWithUnits operator+(NumberWithUnits num);
            NumberWithUnits operator+=(NumberWithUnits num);

            //-----------------------------
            // Friend Comparison Operators
            //-----------------------------

            friend bool operator!=(NumberWithUnits num1, NumberWithUnits num2);
            friend bool operator==(NumberWithUnits num1, NumberWithUnits num2);

            friend bool operator<=(NumberWithUnits num1, NumberWithUnits num2);
            friend bool operator>=(NumberWithUnits num1, NumberWithUnits num2);

            friend bool operator<(NumberWithUnits num1, NumberWithUnits num2);
            friend bool operator>(NumberWithUnits num1, NumberWithUnits num2);

            //-----------------------------
            // Increment Decrement Operators
            //-----------------------------

            NumberWithUnits& operator--();
            NumberWithUnits operator--(int dummy);

            NumberWithUnits& operator++();
            NumberWithUnits operator++(int dummy);

            //-----------------------------
            // Friend Operators
            //-----------------------------

            friend NumberWithUnits operator*(double d, NumberWithUnits num);
            friend NumberWithUnits operator*(NumberWithUnits num, double d);
            
                //-----------------------------
                // I/O Operators
                //-----------------------------
            friend std::ostream& operator<<(std::ostream& out, NumberWithUnits num);
            friend std::istream& operator>>(std::istream& in, NumberWithUnits& num);
    };

}