#ifndef DailySchedule_h
#define DailySchedule_h

#include "Movie.h"
#include "Stack.h"

const char DATE_SLASH = '/';

const int DEFAULT_OPENING_HOUR = 8;
const int DEFAULT_OPENING_MINUTE = 0;
const int DEFAULT_CLOSING_HOUR = 23;
const int DEFAULT_CLOSING_MINUTE = 0;
const int OPENING_HOUR_2 = 10;
const int OPENING_MINUTE_2 = 30;
const int CLOSING_HOUR_2 = 23;
const int CLOSING_MINUTE_2 = 30;
const int SET_UP_HOUR = 1;
const int SET_UP_MINUTES = 0;
const int CLEAN_UP_HOURS = 0;
const int CLEAN_UP_MINUTES = 35;
const int MIN_MM = 1;
const int MIN_DD = 1;
const int MAX_MM = 12;
const int MAX_DD = 31;
const int EMPTY_VEC_SIZE = 0;
const int FIVE = 5;
const int SHOW_TIME_ROW_LENGTH = 15;

const string DEFAULT_DAY_OF_WEEK = "Monday";
const string DAY_OF_WEEK_2 = "Tuesday";
const string DAY_OF_WEEK_3 = "Wednesday";
const string DAY_OF_WEEK_4 = "Thursday";
const string DAY_OF_WEEK_5 = "Friday";
const string DAY_OF_WEEK_6 = "Saturday";
const string DAY_OF_WEEK_7 = "Sunday";
const string SHOW_TIME = " - ";
const string ERR_SET_DATE = "ERROR: in function DailySchedule::setDate, one or"
                            " more date values are out of range\n";
const string ERR_DD_INVALID = "The day value is outside of acceptable range "
                              "( 1 <= day <= 31 )\n";
const string ERR_MM_INVALID = "The month value is outside of acceptable range "
                              "( 1 <= month <= 12 )\n";
const string ERR_YY_INVALID = "The year value is outside of acceptable range "
                              "( 1890 <= year )\n";
const string ERR_DAY_OF_WEEK_INVALID = "The day of the week entered is not an acceptable value\n";
const string EMPTY_VECTORS = "Nothing to schedule.  There are no movies to display.";
const string ERR_READ_MOVIES = "ERROR: unknown exception caught in DailySchedule::readMovies()";
const string ERR_FILE_OPENING = "ERROR: file failed to open in DailySchedule::readMovies()";
const string ERR_INV_ARG_READ = "ERROR: invalid argument in function DailySchedule::readMovies()";
const string MOVIES_PROCESSED = " movies processed.";
const string ERR_FILE = "ERROR: cannot find file.";

/**
 * A class for storing the daily schedule of a theater and the movie
 * times playing that day.  Methods exist to read movies
 * from files and to read the day of the week and the date from keyboard input.
 * A size method displays the number of movies shown in one day.
 * The main method in this class is the private function schedule, which organizes the show times
 * of a movie on a given day starting with the last screening and moving backwards. 
 * This function then displays the show times to the screen chronologically using a stack
 *
 * @author Christian Collier
 * 3/7/17
 */

class DailySchedule
{
  public:
    DailySchedule();
    void setDate( string dOfWk, int mm, int dd, int yy ) throw ( invalid_argument );
    unsigned size() const;
    void printSchedule( DailySchedule schedule1 );
    void readMovies( string filename ) throw ( logic_error, invalid_argument );
    void readDate( istream& in, DailySchedule& schedule1 ) throw ( invalid_argument );

  private:
    string dayOfWeek;
    int month;
    int day;
    int year;
    vector<Movie> movies;
    Time openingTime;
    Time closingTime;
    
    void schedule( Movie movie1 );
    
}; // DailySchedule class

#endif
