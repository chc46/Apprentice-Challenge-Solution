#include "Time.h"



            /****************************************************************************
             *          class Time public member function implementation code           *
             ****************************************************************************/

Time::Time()
{
    this->h = MIN_H;
    this->m = MIN_M;
    
} // END default constructor for Time class



Time::Time( int hour, int min ) throw( invalid_argument )
{
    try
    {
        // Call setTime function for any values input by parameters
        
        this->setTime( hour, min );
    }
    
    catch ( invalid_argument &ia )
    {
        throw;
    }
    
    catch ( ... )
    {
        throw;
    }
    
} // END constructor with parameters for Time class



void Time::setTime( int hour, int min ) throw( invalid_argument )
{
    string ia1 = ERR_SET_TIME;
    
    try
    {
        bool hOK = true;
        bool mOK = true;
        
        // Validate that the hour and minute entered does not exceed the limits for time.
        // If an error is caught, however, display an invalid argument.
        
        if ( hour < MIN_H || hour > MAX_H )
        {
            hOK = false;
            ia1 += ERR_H_INVALID;
        }
        
        if ( min < MIN_M || min > MAX_M )
        {
            mOK = false;
            ia1 += ERR_M_INVALID;
        }
        
        if ( !hOK || !mOK )
        {
            invalid_argument iaObject( ia1 );
            throw iaObject;
        }
        
        // If no error is caught, assign the inputed values to the private data members
        
        this->h = hour;
        this->m = min;
        
    }
    
    catch ( invalid_argument &ia )
    {
        throw;
    }
    
    catch ( ... )
    {
        throw;
    }
    
} // END setTime function for Time class



bool Time::operator<( const Time &t1 )
{
    bool isLessThan = true;
    
    // Tests that ensure that this time is less than another Time object
    
    if (this->h > t1.h)
    {
        isLessThan = false;
    }
    else if (this->h == t1.h)
    {
        if (this->m > t1.m)
        {
            isLessThan = false;
        }
    }
    
    return isLessThan;
    
} // END overloaded operator< function for Time class



Time Time::operator+( const Time &t1 )
{
    Time timeSum;
    
    timeSum.h = this->h + t1.h;
    timeSum.m = this->m + t1.m;
    
    // Test to ensure that the number of minutes does not exceed 59 for the sum.
    // If it does, subtract 60 from the minutes and add another hour
    
    if ( timeSum.m > MAX_M )
    {
        timeSum.m -= MINUTES_PER_HOUR;
        timeSum.h += ONE;
    }
    
    return timeSum;
    
    
} // END overloaded operator+ function for Time class



Time Time::operator-( const Time &t1 )
{
    Time timeDifference;
    
    timeDifference.h = this->h - t1.h;
    timeDifference.m = this->m - t1.m;
    
    // Test to ensure that the number of minutes is not less than 0 for the difference.
    // If it is, add 60 to the minutes and subtract an hour
    
    if ( timeDifference.m < MIN_M)
    {
        timeDifference.m += MINUTES_PER_HOUR;
        timeDifference.h -= ONE;
    }
    
    return timeDifference;
    
} // END overloaded operator- function for Time class



Time Time::operator--( int )
{
    Time temp = *this;
    
    this->m = --m;
    
    // Test to ensure that the number of minutes is not less than 0 for the difference.
    // If it is, make the number of minutes 59 minutes and subtract an hour
    
    if ( m < MIN_M )
    {
        this->h = --h;
        
        this->m = MAX_M;
        
        if ( h < MIN_H )
        {
            this->h = MAX_H;
        }
    }
    
    return temp;
    
} // END overloaded decrement operator for Time class



string Time::to_string( const Time& t1 )
{
    // Returns a Time object as a string (to be used in DailySchedule class)
    
    ostringstream s1;
    
    s1 << t1;
    
    return s1.str();
    
} // END to_string function for Time class



        /****************************************************************************
         *                class Time friend function implementation code            *
         ****************************************************************************/

ostream& operator<<( ostream& out, const Time& t1 )
{
    out << t1.h << COLON << setfill(ZERO)
        << setw(ROW_SIZE) << t1.m << setfill(SPACE);
    
    return out;
    
} // END overloaded stream insertion operator for Time class



istream& operator>> ( istream& in, Time& t1 ) throw( invalid_argument )
{
    try
    {
        // if the stream is in a failed state, throw an exception
        if ( !in )
        {
            throw invalid_argument(ERR_STREAM_EXTRACTION);
        }
        
        int hour = 0,
            minute = 0;
        
        char ch = '?';
        
        // Read in the values for time, including the discarded ":" character
        
        in >> hour >> ch >> minute;
        
        // Call the setDate and setTime functions and pass the values inputted by reference
        
        t1.setTime( hour, minute );
        
    }
    
    // Catches an invalid argument, if stream is in a failed state
    
    catch ( invalid_argument &ia )
    {
        throw;
    }
    
    // Catches an unknown exception
    
    catch ( ... )
    {
        throw;
    }
    
    return in;
    
} // END overloaded stream extraction operator for Time class








