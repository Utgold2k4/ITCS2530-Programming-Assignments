// Week01_Programming_Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
// ITCS 2530
// Chris Mach
// 05/20/26

#include <iostream>
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

    //constants for formatting
    const string GREEN = "\033[32m";
    const string RESET = "\033[0m";

    //Getting input from user for variables
    cout << "Welcome to your Personal Library Application.\nPlease Enter Your Name:\n";
    //I know you said to concentrate on cin/cout but I can't deal with my programing skipping inputs due to spaces, newline, and buffers
    getline(cin, users_name);
    cout << "What is your favorite book of all time?\n";
    getline(cin, favorite_book);
    cout << "How many books do you currently own?\n";
    //Really want to run validation to for int input
    cin >> books_owned;
    //Converting variable to constant to keep a starting point for later calculations as the users library grows or shrinks
    const int STARTING_BOOKS_OWNED = books_owned;
    //Wasn't sure about the calculation part of the instructions below so I added this question and did some basic math.
    //Your program needs to use variables and do some sort of calculation that is related to your hobby or interest. 
    cout << "What is the target size of your collection?\n";
    cin >> target_library_size;
    //some basic maf
    //12.0 needed to round properly
    months_to_completion = target_library_size - STARTING_BOOKS_OWNED;
    years_to_completion = round(months_to_completion / 12.0);
    //Messsage playing back gathered info
    //Added 2 newlines at the end becuase that closing message in the debugger really annoys me need to remember to remove this later.
    //Added some formatting for flair
    cout << "Hello " << GREEN << users_name << RESET << " Your Personal Library is starting with "
         << GREEN << STARTING_BOOKS_OWNED << RESET << " books. Hopefully you own " << GREEN << favorite_book << RESET << ".\n";
    cout << "If you purchase one book a month you will reach you target library size in about " << GREEN << years_to_completion << RESET << " years" << " or " <<
         GREEN << months_to_completion << RESET << " months.\n\n";
}