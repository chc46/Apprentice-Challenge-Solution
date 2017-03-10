#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>
#include <exception>

using namespace std;

// Start of constant declarations

const int ROW_SIZE = 2;
const int MIN_H = 0;
const int MIN_M = 0;
const int MAX_H = 23;
const int MAX_M = 59;
const int MINUTES_PER_HOUR = 60;
const int ONE = 1;

const char ZERO = '0';
const char SPACE = ' ';

const string COLON = ":";
const string ERR_STREAM_EXTRACTION = "ERROR: in operator>> stream argument is in failed state\n";
const string ERR_SET_TIME = "ERROR: in function Time::setTime, "
                            "one or more time values are out of range\n";
const string ERR_H_INVALID = "The hour value is outside of acceptable range "
                             "( 1 <= hour <= 24 )\n";
const string ERR_M_INVALID = "The minute value is outside of acceptable range "
                             "( 0 <= minute <= 59 )";

/**
 * A class for storing times.  Times are in the 24-hour format Hours:Minutes (from 0:00-23:59).
 * This class includes methods to get and set data members, and overloaded operators to be used in
 * later parts of the program.  Additionally, the to_string function is used to display movie
 * start times and end times in subsequent classes.
 *
 * @author Christian Collier
 * 3/3/17
 */

class Time
{
    friend ostream& operator<<( ostream& out, const Time& t1 );
    friend istream& operator>>( istream& in, Time& t1 ) throw ( invalid_argument );
    
  public:
    Time();
    Time( int hour, int min ) throw ( invalid_argument );
    void setTime( int hour, int min ) throw ( invalid_argument );
    int getMinutes() const { return m; };
    int getHours() const { return h; };
    bool operator<( const Time& t1 );
    Time operator-( const Time& t1 );
    Time operator+( const Time& t1 );
    Time operator--( int );
    string to_string( const Time& t1 );
    
  private:
    /** the hour of the day */
    int h;
    /** the minute of the hour */
    int m;
    
}; // DateTime

#endif
