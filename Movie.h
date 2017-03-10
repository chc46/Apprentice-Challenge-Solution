#ifndef EVENT_H
#define EVENT_H

#include "Time.h"

// Start of constant declarations

const int DEFAULT_YEAR = 1890;   // The default year is 1890 because movies were first created then

const char COMMA = ',';

const string DEFAULT_NAME = "";
const string DEFAULT_RATING = "G";
const string RATING_OPTION_2 = "PG";
const string RATING_OPTION_3 = "PG-13";
const string RATING_OPTION_4 = "R";
const string RATING_OPTION_5 = "NC-17";
const string OUTPUT_MESSAGE = " - Rated ";
const string ERR_SET_MOVIE = "ERROR: in function Movie::setStatus, one or "
                              "more date values are out of range\n";
const string ERR_RATING_INVALID = "Invalid rating entered (must be G, PG, PG-13, R or NC-17)";
const string ERR_YEAR_INVALID = "Invalid number entered for year";
const string ERR_OVER_OP = "ERROR: unknown exception caught in overloaded operator>> of Movie";


/**
 * A class for storing information about a particular movie.  A Movie
 * consists of a name, a release year, an MPAA rating and
 * a run time (which is composed from the Time class).
 * This class also includes methods for finding a movie name, release year, rating and run time.
 * There is also a private function that reads the movie title and rating until the comma appears
 * (which is how it appears in the input file).
 *
 * @author Christian Collier
 * 3/3/17
 */

class Movie
{
    friend ostream& operator<<( ostream& out, const Movie& m );
    friend istream& operator>>( istream& in, Movie& m ) throw ( invalid_argument );
    
  public:
    Movie();
    string getName() const;
    int getYear() const;
    string getRating() const;
    Time* getRunTime();
    void setMovie( int yr, string r) throw ( invalid_argument );
    
  private:
    /** the name of the Movie */
    string name;
    /** the year the Movie was released */
    int year;
    /** the rating of the Movie */
    string rating;
    /** the run time of a movie */
    Time runTime;
    
    string readUntilComma( istream& in ) const;
    
}; // Movie class

#endif

