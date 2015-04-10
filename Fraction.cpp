#include <iostream>
#include "frac.h"

using namespace std;

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
   Fraction r;        // declare a Fraction to hold the result

   // load result Fraction with sum of adjusted numerators
   r.numerator = (f1.numerator*f2.denominator)
                  + (f2.numerator*f1.denominator);

   // load result with the common denominator
   r.denominator = f1.denominator * f2.denominator;

   return r;         // return the result Fraction
}

ostream& operator<< (ostream& s, const Fraction& f)
{
  s << f.numerator << '/' << f.denominator;
  return s;
}

Fraction::Fraction()
// Default constructor.  Initializes fraction to 0/1
{
   numerator = 0;
   denominator = 1;
}

Fraction::Fraction(int n, int d)
// initializes fraction to n/d (defaults to 0/1 if invalid data)
{
   if (SetValue(n, d) == false)
        SetValue(0, 1);
}

//postincrement
Fraction Fraction::operator++(int ignoreme)
{
 Fraction f1;
 Fraction f2(1,1);
 Fraction f3;
 f3 = f1 + f2;
 return f1;
}
//preincrement
Fraction Fraction::operator++()
{
 Fraction f1;
 Fraction f2(1,1);
 Fraction f3;
 f3 = f1 + f2;
 return f3;
}

//+= operator
Fraction Fraction::operator+=(const Fraction& RHS)
{
Fraction f1;
f1 += RHS;
return *this;
}


}
void Fraction::Input()
// Get a fraction from standard input, in the form
"numerator/denominator."
// what kind of error checking should be added?
{
   char divSign;        // used to consume the '/' character during
input
   do
   {
      cin >> numerator >> divSign >> denominator;
      if (denominator <= 0)
        cout << "*** Denominator must be positive.  Try again: ";

   } while (denominator <= 0);
}

void Fraction::Show() const
// Display a fraction, in the form "numerator/denominator."
{
   cout << numerator << '/' << denominator;
}

int Fraction::GetNumerator() const
{
   return numerator;
}
int Fraction::GetDenominator() const
{
   return denominator;
}

bool Fraction::SetValue(int n, int d)
// sets fraction to n/d and returns true for success (good data)
// returns false and leaves fraction alone if bad data
{
   if (d <= 0)
        return false;

   numerator = n;
   denominator = d;
   return true;
}
double Fraction::Evaluate() const
// Calculates and returns the decimal value of a fraction
{
   return static_cast<double>(numerator) / denominator;
}

