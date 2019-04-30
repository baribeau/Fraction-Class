// Julia Baribeau
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
using namespace std;

class Fraction
{
    private:
        int num, denom;
    public:
        Fraction()
        {
            num = 1;
            denom = 2;
        }

        Fraction(int numerator, int denominator)
        {
            if(denominator < 0){
                denom = -denominator;
                num = -numerator;
            }
            else if (denominator == 0){
                cout << "Invalid denominator" << endl;
            }
            else{
                denom = denominator;
                num = numerator;
            }
        }

        int get_numerator() const
        {
            return num;
        }
        int get_denominator() const
        {
            return denom;
        }

        void set_num_denom(int numerator, int denominator)
        {
            if(numerator < denominator && denominator != 0)
            {
                num = numerator;
                denom = denominator;
            }
            else
                cout << "Invalid." << endl;
        }

        double approximate(int decimals)
        {
            return round(pow(10,decimals)*num/denom)
                    /pow(10,decimals);
        }

        bool isExactlySame(Fraction const & other)
        {
            if(num == other.num && denom == other.denom)
                return 1;
            else
                return 0;
        }

        void output(ostream &out) const
        {
            out << num << "/" << denom << endl;
        }

};

int main()
{
    Fraction f0 = Fraction();
    Fraction f1(1,3);
    Fraction f2(3,-7);
    Fraction f3(-3,-7);
    Fraction f4(3,7);

    f0.output(cout); // 1/2
    f1.output(cout); // 1/3
    f2.output(cout); // -3/7
    f3.output(cout); // 3/7
    f4.output(cout); // 3/7

    cout << endl;

    cout << f3.isExactlySame(f2) << endl; // 0
    cout << f3.isExactlySame(f4) << endl; // 1
    cout << f3.isExactlySame(f0) << endl; // 0

    cout << endl;

    f1.set_num_denom(5,10);
    f1.output(cout); // 5/10
    f1.set_num_denom(10,5); // Invalid.

    cout << endl;

    cout << f4.approximate(0) << endl; // 0
    cout << f4.approximate(2) << endl; // 0.43


    system("PAUSE");
    return EXIT_SUCCESS;
}

/* Output:

1/2
1/3
-3/7
3/7
3/7

0
1
0

5/10
Invalid.

0
0.43
Press any key to continue . . .

Process returned 0 (0x0)   execution time : 5.281 s
Press any key to continue.
*/
