# Apprentice-Challenge-Solution

BACKGROUND

My name is Christian Collier and welcome to my solution to the Apprentice Challenge!

This repository contains two main components, a folder containing all of the header and implementation files, along with a Makefile to 
run this program on the command line, and a sample input file of movies.

INSTALLATION

To install my solution program, download the contents of the folder Coding Challenge to your desktop, as well as the sample input file 
MovieData.txt (if you have a particular input file of your own, then there is no need to download the sample I have provided).

Place all of the files in a folder on the Desktop.

If you are running this program on a Mac computer, it is best to run this on the command line using Terminal.
To do so, open the Terminal window and type the following commands first:

cd desktop
cd Coding Challenge

To compile the program, type the following command: make
This command will compile all of the .cpp files and create an executable program called MovieTheaterSchedule.

To run this program on the command line, simply type the command ./MovieTheaterSchedule INPUT_FILE_NAME.txt
where INPUT_FILE_NAME.txt is the input file of your choice. The program should then begin to run.

To install and run this on a Windows computer, it is better to do so using an IDE. Therefore, it is not necessary to download the Makefile
only the .cpp and .h files. Try running this through that particular IDE and let me know if any errors are encountered.

HOW TO RUN THE PROGRAM

This program is written in C++. Once the program is run, it will offer a brief description of what it does then it will read the movies in.
NOTE: the read function for the file containing the movies reads in the first line and disregards it, as that first line should not contain
any data.  It's simply a heading as displayed in the sample.

Then the program will ask for a specific day of the week and date.  Assuming the input entered is correct, the program will then display
the schedule of movies for that given day and date.


If you have any questions or comments, please let me know and I will be happy to discuss.
