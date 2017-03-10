/*
 * Author Name: Christian Collier
 *
 * The following is a solution to the Challenge.  This program takes user input and file-input
 * to create a schedule of movie times for a particular day and date written in C++.
 * Copyright © 2017 Christian Collier. All rights reserved.
 */

#include "main.h"

using namespace std;

int main(int argc, const char * argv[])
{
    // Verify that one file has been included as a command line argument.
    
    if (argc != MIN_ARGUMENTS)
    {
        cout << ERR_COMMAND_LINE_ARGS << endl;
        cout << GOODBYE << endl;
    }
    
    else
    {
        cout << "Welcome to the Movie Theater Scheduling program." << endl;
        cout << "This program displays the schedule of shows for \n"
             << "a particular day of week and date at a theater." << endl;
        
        // Create a DailySchedule object to read input and display a schedule
        // of shows for a particular day of the week and date.
        
        DailySchedule showsToday;
        
        string filename1 = argv[1];
        
        try
        {
            showsToday.readMovies( filename1 );
            
            showsToday.readDate( cin, showsToday );
            
            showsToday.printSchedule( showsToday );
            
            
        } // END try block
        
        catch ( invalid_argument &ia )
        {
            cout << "ERROR: invalid_argument exception caught in function main:" << endl;
            cout << ia.what() << endl;
        }
        
        catch ( ... )
        {
            cout << "ERROR: unknown exception caught in function main..." << endl;
        }
        
        cout << endl;
        
    } // END else block

    return 0;
    
} // END function main()
