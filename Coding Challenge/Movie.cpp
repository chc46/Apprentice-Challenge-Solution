#include "Movie.h"



        /*****************************************************************************
         *          class Movie private member function implementation code          *
         *****************************************************************************/

string Movie::readUntilComma( istream& in ) const
{
    // Reads a string until a comma appears and returns that sequence before the comma
    
    string characterSequence;
    
    getline(in, characterSequence, COMMA);
    
    return characterSequence;
}


        /*****************************************************************************
         *          class Movie public member function implementation code           *
         *****************************************************************************/

Movie::Movie() : runTime()
{
    this->name = DEFAULT_NAME;
    this->year = DEFAULT_YEAR;
    this->rating = DEFAULT_RATING;
    
} // END default constructor for Movie class



string Movie::getName() const
{
    return name;
}



int Movie::getYear() const
{
    return year;
}



string Movie::getRating() const
{
    return rating;
}



Time *Movie::getRunTime()
{
    // A function that points to the address of the runTime of a movie object.
    // It returns the value at the address of runTime
    
    return &runTime;
}



void Movie::setMovie( int yr, string r) throw ( invalid_argument )
{
    string iaMsg = ERR_SET_MOVIE;
    
    try
    {
        bool yrOK = true;
        bool ratingOK = true;
        
        // Test that the movie was made after 1890, which is when the first movies were created,
        // and that the movie has one of the valid MPAA ratings.
        // If one or both of the conditions is not met, throw an invalid argument
        
        if ( yr < DEFAULT_YEAR )
        {
            yrOK = false;
            iaMsg += ERR_YEAR_INVALID;
        }
        
        if ( r != DEFAULT_RATING && r != RATING_OPTION_2 && r != RATING_OPTION_3
            && r != RATING_OPTION_4 && r != RATING_OPTION_5 )
        {
            ratingOK = false;
            iaMsg += ERR_RATING_INVALID;
        }
        
        if ( !yrOK || !ratingOK )
        {
            invalid_argument iaMovie( iaMsg );
            throw iaMovie;
        }
        
        this->year = yr;
        this->rating = r;
        
    } // END try block
    
    catch ( invalid_argument &ia )
    {
        throw;
    }
    
    catch ( ... )
    {
        throw;
    }
    
} // END function Movie::setMovie in Movie class



            /*****************************************************************************
             *            class Movie friend function implementation code                *
             *****************************************************************************/

ostream& operator<<( ostream& out, const Movie& m )
{
    // Displays the movie as it would appear in the final output.
    
    out << m.name << OUTPUT_MESSAGE << m.rating << COMMA << SPACE << m.runTime;
    out << endl;
    
    return out;
    
} // END overloaded stream insertion operator for Event class



istream& operator>>( istream& in, Movie& m ) throw ( invalid_argument )
{
    int yr = 0;
    
    char ch = '?'; // An extraneous character in the input stream
    
    string rting = "";
    string warning_message = "WARNING: executing operator>> of the Movie class\n";
    
    try
    {
        // If the stream is in a failed state, throw an invalid argument.
        
        if ( !in )
        {
            throw invalid_argument( ERR_STREAM_EXTRACTION );
        }
        
        // Read the value for the name, using the private function readUntilComma
        
        m.name = m.readUntilComma( in );
        
        // Read for the year then read the comma
        
        in >> yr;
        
        in >> ch;
        
        in.ignore();        // Ignore white space then read for the rating using readUntilComma
        
        rting = m.readUntilComma( in );
        
        // Test that stream is not in a failed state again.  If it is, throw a non-fatal exception
        
        if ( !in )
        {
            throw string( warning_message );
        }
        
        // Input the value for the movie runTime and then call the setMovie function
        
        in >> m.runTime;
        
        m.setMovie( yr, rting );
    
    } // END try block
    
    catch (string s )
    {
        cout << s << endl;
    }
        
    catch ( invalid_argument &ia1 )
    {
        throw;
    }
        
    catch ( ... )
    {
        cout << ERR_OVER_OP << endl;
    }
    
    return in;
        
} // END overloaded stream extraction operator for Movie class
