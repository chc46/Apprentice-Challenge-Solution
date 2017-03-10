#include "DailySchedule.h"



        /**********************************************************************************
         *       class DailySchedule private member function implementation code          *
         **********************************************************************************/

void DailySchedule::schedule( Movie movie1 )
{
    string displayShowTime = "";
    
    Time showStartTime, showEndTime;                     // The start and end times of a given show
    
    Time setUpTime( SET_UP_HOUR, SET_UP_MINUTES );       // The time required to set up the theater
                                                         // at the start of the day
    
    Time cleanUpTime( CLEAN_UP_HOURS, CLEAN_UP_MINUTES ); // The time required for previews,
                                                          // cleanup and work change between movies
                                                          // (this also occurs at the start of
                                                          // the day for the first movie).
    
    Stack<string> showTimes;             // A stack used to display the show times chronologically
    
    // Get the last show start time assuming the movie ends exactly when the theater closes
    
    showStartTime = closingTime - *movie1.getRunTime();
    
    showEndTime = closingTime;
    
    // Use a while loop to test that a movie's starting time does not occur before
    // the theater is ready to display movies.
     
    while ( !(showStartTime < ( openingTime + setUpTime + cleanUpTime )) )
    {
        // Decrement the show's end time and start time until the show starts on a minute
        // that is a factor of 5 (i.e. 0, 5, 10, 15, 20, ..., 55)
        
        while ( showStartTime.getMinutes() % FIVE != 0 )
        {
            showStartTime--;
            showEndTime--;
        }
        
        // Use the to_string function to display a string showing the start and end times for
        // a particular movie
        
        displayShowTime = showStartTime.to_string( showStartTime ) + SHOW_TIME
        + showEndTime.to_string( showEndTime );
        
        // Push that string on to the stack
        
        showTimes.push( displayShowTime );
        
        // Then reinitialize the string for the previous movie show times and
        // make the prior showing's end time equal to the last show's start time
        // minus the time required to clean the theater between shows.
        
        displayShowTime = "";
        
        showEndTime = showStartTime - cleanUpTime;
        
        showStartTime = showEndTime - *movie1.getRunTime();
        
    } // END while loop
    
    // Display the show times entered in the stack, starting with the last string entered,
    // which should be the first show time of that day.  Then remove that value from the stack.
    // Repeat until the stack is empty
    
    while ( !showTimes.empty() )
    {
        cout << setw(SHOW_TIME_ROW_LENGTH) << showTimes.top() << endl;
        showTimes.pop();
    }
    
    
} // END schedule function for DailySchedule class



        /**********************************************************************************
         *        class DailySchedule public member function implementation code          *
         **********************************************************************************/

DailySchedule::DailySchedule() : openingTime( DEFAULT_OPENING_HOUR, DEFAULT_OPENING_MINUTE ),
    closingTime( DEFAULT_CLOSING_HOUR, DEFAULT_CLOSING_MINUTE )
{
    dayOfWeek = DEFAULT_DAY_OF_WEEK;
    
    month = MIN_MM;
    day = MIN_DD;
    year = DEFAULT_YEAR;
    
} // END default constructor for DailySchedule class



void DailySchedule::setDate( string dOfWk, int mm, int dd, int yy) throw( invalid_argument )
{
    try
    {
        string iaMsg = ERR_SET_DATE;
        
        // Booleans that ensure that the day of week, month, day and year entered are valid
        
        bool dOfWkOK = true;
        bool mmOK = true;
        bool ddOK = true;
        bool yyOK = true;
        
        // Test that each of the values entered are not out of the valid range for each.
        // If one is, set the boolean variable for that variable equal to false
        
        if (dOfWk != DEFAULT_DAY_OF_WEEK && dOfWk != DAY_OF_WEEK_2 && dOfWk != DAY_OF_WEEK_3
            && dOfWk != DAY_OF_WEEK_4 && dOfWk != DAY_OF_WEEK_5 && dOfWk != DAY_OF_WEEK_6
            && dOfWk != DAY_OF_WEEK_7)
        {
            iaMsg += ERR_DAY_OF_WEEK_INVALID;
            dOfWkOK = false;
        }
        
        if (dd < MIN_DD || dd > MAX_DD)
        {
            iaMsg += ERR_DD_INVALID;
            ddOK = false;
        }
        
        if ( mm < MIN_MM || mm > MAX_MM )
        {
            iaMsg += ERR_MM_INVALID;
            mmOK = false;
        }
        
        if ( yy < DEFAULT_YEAR )
        {
            iaMsg += ERR_YY_INVALID;
            yyOK = false;
        }
        
        // If one of the bool variables is false, throw an invalid argument object
        
        if ( !dOfWkOK || !ddOK || !mmOK || !yyOK )
        {
            invalid_argument iaObj( iaMsg );
            throw iaObj;
        }
        
        // Otherwise, set the month, day and year equal to the values entered
        
        this->dayOfWeek = dOfWk;
        this->month = mm;
        this->day = dd;
        this->year = yy;
        
        if (dOfWk == DEFAULT_DAY_OF_WEEK || dOfWk == DAY_OF_WEEK_2 || dOfWk == DAY_OF_WEEK_3
            || dOfWk == DAY_OF_WEEK_4)
        {
            openingTime.setTime( DEFAULT_OPENING_HOUR, DEFAULT_OPENING_MINUTE );
            closingTime.setTime( DEFAULT_CLOSING_HOUR, DEFAULT_CLOSING_MINUTE );
        }
        else
        {
            openingTime.setTime( OPENING_HOUR_2, OPENING_MINUTE_2 );
            closingTime.setTime( CLOSING_HOUR_2, CLOSING_MINUTE_2 );
        }
        
    } // END try block
    
    // Catches an invalid argument
    
    catch ( invalid_argument &ia )
    {
        throw;
    }
    
    // Catches an unknown exception
    
    catch ( ... )
    {
        throw;
    }
    
} // END function setDate in Daily Schedule class



unsigned DailySchedule::size() const
{
    // Return the size of the events vector for a DailySchedule object
    
    return (static_cast<unsigned int>(movies.size()));
    
} // END size function for DailySchedule class



void DailySchedule::printSchedule( DailySchedule schedule1 )
{
    // Test that the size of the movies vector is empty. If it is, no further work is necessary.
    // Otherwise, call the private member function schedule and print the schedule for that date
    
    if (schedule1.size() == EMPTY_VEC_SIZE)
    {
        cout << EMPTY_VECTORS << endl;
    }
    else
    {
        cout << "Now displaying the theater schedule for the given date..." << endl;
        
        cout << "\n" << schedule1.dayOfWeek << " " << schedule1.month
             << DATE_SLASH << schedule1.day << DATE_SLASH << schedule1.year << endl
             << endl;
        
        // Loop through each movie in the vector of movies outputting data about a given movie
        // followed by the show times on a particular day.
        
        for (unsigned long int i = 0; i < movies.size(); i++)
        {
            // Display a particular movie and get that movie's schedule by calling the private
            // schedule member function
            
            cout << movies.at(i);
            
            schedule( schedule1.movies.at(i) );
        }
        
    } // END else loop
    
} // END function printSchedule for DailySchedule class



void DailySchedule::readDate( istream& in, DailySchedule& schedule1 ) throw ( invalid_argument )
{
    invalid_argument ia1( ERR_STREAM_EXTRACTION );
    
    int mm = 0;
    int dd = 0;
    int yy = 0;
    
    string day = "";
    
    char ch = '?';
    
    try
    {
        // If the stream is in a failed state, throw a fatal exception
        
        if ( !in )
        {
            throw ia1;
        }
        
        // Ask for the input for a day of week and date then test that the values entered
        // are valid by calling the setDate function
        
        cout << "Enter a particular day of the week and date (in the format MM/DD/YYYY):\n";
        
        in >> day;
        
        in >> mm >> ch >> dd >> ch >> yy;
        
        schedule1.setDate( day, mm, dd, yy);
    }
    
    catch ( invalid_argument &ia1 )
    {
        throw;
    }
    
    catch ( ... )
    {
        throw;
    }
    
} // END readDate function for DailySchedule class



void DailySchedule::readMovies( string filename ) throw ( logic_error, invalid_argument )
{
    ifstream inFile;
    
    int rowNumber = 0;
    
    logic_error logError1( ERR_FILE_OPENING );
    invalid_argument invArg1( ERR_INV_ARG_READ );
    
    Movie movie1;
    
    string firstLine = "";
    
    try
    {
        // Open the filename and convert to C-string
        
        inFile.open(filename.c_str());
        
        // If ifstream is in failed state, throw logic error
        
        if ( !inFile )
        {
            throw logError1;
        }
        
        // Read the first line of input, which does not contain any data
        
        getline(inFile, firstLine);
        
        // Add an event to the events vector as long as inFile keeps processing data
        
        while( inFile >> movie1 )
        {
            ++rowNumber;
            movies.push_back(movie1);
        }
        
        // Display the number of events processed
        
        cout << rowNumber << MOVIES_PROCESSED << endl << endl;
        
        // Close the input file
        
        inFile.close();
        
    }
    
    // Catch an invalid filename
    
    catch ( invalid_argument &invArg1 )
    {
        throw;
    }
    
    // Catches an error opening the file
    
    catch ( logic_error &logError1 )
    {
        throw;
    }
    
    // Catches an unknown exception
    
    catch ( ... )
    {
        cout << ERR_READ_MOVIES << endl;
        throw;
    }
    
} // END readMovies function for DailySchedule class
