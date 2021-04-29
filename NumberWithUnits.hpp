//
// AUTHOR: Tal Zichlinsky
// Header file for class NumberWithUnits

#include <string>


namespace ariel{

    class NumberWithUnits{

        double number;
        std::string unit;

        public:
            NumberWithUnits(double num, const std::string &unit);

            std::string get_unit() const;
            double get_number()const;

            static void read_units(std::ifstream &u_file);

            //-----------------------------
            // Arithmetic Operators
            //-----------------------------

            NumberWithUnits operator-() const;
            NumberWithUnits operator-(const NumberWithUnits &num);
            NumberWithUnits operator-=(const NumberWithUnits&num);

            NumberWithUnits operator+() const;
            NumberWithUnits operator+(const NumberWithUnits &num);
            NumberWithUnits operator+=(const NumberWithUnits &num);

            NumberWithUnits operator*(double d) const;

            //-----------------------------
            // Comparison Operators
            //-----------------------------

            bool operator!=(const NumberWithUnits &other) const;

            bool operator==(const NumberWithUnits &other) const;

            bool operator<=(const NumberWithUnits &other) const;
            bool operator>=(const NumberWithUnits &other) const;

            bool operator<(const NumberWithUnits &other) const;
            bool operator>(const NumberWithUnits &other) const;


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

            friend NumberWithUnits operator*(double d,const NumberWithUnits &num);
            
                //-----------------------------
                // I/O Operators
                //-----------------------------
            friend std::ostream& operator<<(std::ostream &out, NumberWithUnits num);
            friend std::istream& operator>>(std::istream &in, NumberWithUnits &num);
    };

}