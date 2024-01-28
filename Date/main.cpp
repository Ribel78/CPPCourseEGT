// Date class test program.
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "Date.h" // Date class definition

int main()
{
   Date d1; // defaults to January 1, 1900
   Date d2( 12, 27, 1992 ); // December 27, 1992
   Date d3( 0, 99, 8045 ); // invalid date

   cout << "d1 is " << d1 << "\nd2 is " << d2 << "\nd3 is " << d3;
   cout << "\n\nd2 += 7 is " << ( d2 += 7 );

   d3.setDate( 2, 28, 1992 );
   cout << "\n\n  d3 is " << d3;
   cout << "\n++d3 is " << ++d3 << " (leap year allows 29th)";

   Date d4( 7, 13, 2002 );

   cout << "\n\nTesting the prefix increment operator:\n"
      << "  d4 is " << d4 << endl;
   cout << "++d4 is " << ++d4 << endl;
   cout << "  d4 is " << d4;

   cout << "\n\nTesting the postfix increment operator:\n"
      << "  d4 is " << d4 << endl;
   cout << "d4++ is " << d4++ << endl;
   cout << "  d4 is " << d4 << endl;

   cout << "\n\nTesting the prefix decrement operator:\n";
   cout << "d4-- is " << d4-- << endl;
   cout << "  d4 is " << d4 << endl;
   cout << "\n\nTesting the postfix decrement operator:\n";
   cout << "--d4 is " << --d4 << endl;
   cout << "  d4 is " << d4 << endl;

   cout << "\n\nTesting spcial cases with overloaded decrementing operators:\n";
   cout << "\n\nNon-leap year:\n";
   Date d5( 3, 1, 2023 );
   cout << "  d5 is " << d5 << endl;
   cout << "--d5 is " << --d5 << endl;

   cout << "\n\nLeap year:\n";
   Date d6( 3, 1, 2024 );
   cout << "  d6 is " << d6 << endl;
   cout << "--d6 is " << --d6 << endl;
   cout << "d6-- is " << d6-- << endl;
   cout << "d6 is " << d6 << endl;
   cout << "++d6 is " << ++d6 << endl;
   cout << "++d6 is " << ++d6 << endl;

   cout << "\n\nBeginning of the year:\n";
   Date d7( 1, 1, 1998 );
   cout << "  d7 is " << d7 << endl;
   cout << "--d7 is " << --d7 << endl;
   cout << "d7++ is " << d7++ << endl;
   cout << "d7 is " << d7 << endl;

   cout << "\n\nTesting the overloaded stream extract operator:\n";
   Date d8;
   cin >> d8;
   cout << "d8 is " << d8 << endl;
   return 0;
} // end main


