// Mach_C++_Programming_Assignments: This file contains the 'main' function. Program execution begins and ends there.
// ITCS 2530
// Chris Mach
// 05/20/26

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    //Declaring Variables
    string users_name;
    string favorite_book;
    int books_owned;
    int target_library_size;
    int months_to_completion;
    int years_to_completion;
    double read_time_per_week;
    int time_to_read_a_book;
    double collection_read_time;

    //commenting these out for now since txt files don't support it
    //constants for formatting
    //const string GREEN = "\033[32m";
    //const string RESET = "\033[0m";


    //Split the orignal cout and added formatting to meet requirements
    cout << "Welcome to your Personal Library Application.\n";
    //Getting input from user for variables
    cout << "Please Enter Your Name : \n";
    //Uses getline to cover spaces
    getline(cin, users_name);
    cout << "What is your favorite book of all time?\n";
    getline(cin, favorite_book);
    cout << "How many books do you currently own?\n";
    //Adding validation to inputs using an if statment for all int inputs. 
    //While would be better since using if forces me to exit the program to get valid input.
    if (!(cin >> books_owned))
    {
        cout << "Invalid entry please enter an integer! ";
        return -1;
    }
    //Converting variable to constant to keep a starting point for later calculations
    //as the users library grows or shrinks
    //Don't need to validate this since books_owned is being validated.
    const int STARTING_BOOKS_OWNED = books_owned;
    cout << "How many hours do you read per week the the nearest half hour?\n";
    if (!(cin >> read_time_per_week))
    {
        cout << "Invalid entry please enter a valid number! ";
        return -1;
    }
    cout << "On average how many hours does it take to read a book?\n";
    if (!(cin >> time_to_read_a_book))
    {
        cout << "Invalid entry please enter an integer! ";
        return -1;
    }
    //Wasn't sure about the calculation part of the instructions below
    //so I added this question and did some basic math.
    //Your program needs to use variables and do some sort of calculation that is related to your
    //hobby or interest. 
    cout << "What is the target size of your collection?\n";
    if (!(cin >> target_library_size))
    {
        cout << "Invalid entry please enter an integer! ";
        return -1;
    }
    //some basic maf
    //12.0 needed to round properly
    months_to_completion = target_library_size - STARTING_BOOKS_OWNED;
    years_to_completion = round(months_to_completion / 12.0);
    //added this to account for the need for a double as well as precision formatting in the assignment.
    collection_read_time = books_owned * time_to_read_a_book / read_time_per_week;

    //Copied the file write code and changed to cout so I still have the banner in the window
    cout
        << "\nHello " << users_name << ". !Welcome to your own little library!\n"
        << "Your Personal Library is starting with " << STARTING_BOOKS_OWNED
        << " books. Hopefully you own " << favorite_book << ".\n";
    cout
        << "If you purchase one book a month you will reach your target library size in about "
        << years_to_completion << " years or "
        << months_to_completion << " months.\n"
        << "If you read your collection from start to finish it will take you "
        //setting precision for decimals and forcing them to display even if an int is stored  
        //in the double
        << fixed << setprecision(2) << collection_read_time << " weeks to read the whole collection\n\n";

    //setting up a summary table
    cout
        << left << setw(15) << setfill('*')
        << "Summary"
        << right << setw(49)
        << "Time to Collection Completion"
        << setw(42) << "Collection Read Time"
        << "\n"
        << setfill(' ')
        ;
    cout
        << left
        << setw(10) << "Name"
        << right
        << setw(20) << "Books Owned"
        << setw(15) << "Years"
        << setw(5) << "or"
        << setw(10) << "Months"
        << setw(45) << "Weeks to read"
        << endl
        ;
    cout
        << setfill('=')
        << setw(105)
        << ""
        << endl
        ;
    cout
        << setfill(' ')
        ;
    cout
        << left
        << setw(10) << users_name
        << right
        << setw(20) << books_owned
        << setw(15) << years_to_completion
        << setw(15) << months_to_completion
        << setw(45) << collection_read_time
        << endl
        ;
    //This needs to be changed later as right now due to assignment constratins I am saving
    //the file to the same folder as the cpp
    cout << "\nYour Library Report can be found in your documents.\n\n";

    //Creates a new file or overwrites if it exists
    //This needs to be changed later as right now due to assignment constratins
    //the file to the same folder as the cpp I want to write it to my documents relative to the user.
    ofstream file("Report.txt");
    
    //File write intro / banner
    file
        << "\nHello " << users_name << ". !Welcome to your own little library!\n"
        << "Your Personal Library is starting with " << STARTING_BOOKS_OWNED
        << " books. Hopefully you own " << favorite_book << ".\n";
    file
        << "If you purchase one book a month you will reach your target library size in about "
        << years_to_completion << " years or "
        << months_to_completion << " months.\n"
        << "If you read your collection from start to finish it will take you "
        //setting precision for decimals and forcing them to display even if an int is stored  
        //in the double
        << fixed << setprecision(2) << collection_read_time << " weeks to read the whole collection.\n\n";

    //setting up a summary table
    file
        << left << setw(15) << setfill('*')
        << "Summary"
        << right << setw(49)
        << "Time to Collection Completion"
        << setw(42) << "Collection Read Time"
        << "\n"
        << setfill(' ')
        ;
    file
        << left
        << setw(10) << "Name"
        << right
        << setw(20) << "Books Owned"
        << setw(15) << "Years"
        << setw(5) << "or"
        << setw(10) << "Months"
        << setw(45) << "Weeks to read"
        << endl
        ;
    file
        << setfill('=')
        << setw(105)
        << ""
        << endl
        ;
    file
        << setfill(' ')
        ;
    file
        << left
        << setw(10) << users_name
        << right
        << setw(20) << books_owned
        << setw(15) << years_to_completion
        << setw(15) << months_to_completion
        << setw(45) << collection_read_time
        << endl
        ;
    file.close();
}