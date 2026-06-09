// Mach_C++_Programming_Assignments: This file contains the 'main' function. Program execution begins and ends there.
// ITCS 2530
// Chris Mach
// 05/20/26

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>
//PA4 Pretty sure just including random would be easier here
#include <cstdlib>
#include <ctime>
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
    double time_to_read_a_book;
    double collection_read_time;

    //Split the orignal cout and added formatting to meet requirements.
    cout << "Welcome to your Personal Library Application.\n";
    //Getting input from user for variables
    cout << "Please Enter Your Name : \n";
    //Uses getline to cover spaces
    getline(cin, users_name);
    cout << "What is your favorite book of all time?\n";
    getline(cin, favorite_book);
    //Adding validation to inputs using an if statment for all int inputs.
    //PA4 Changing these validation to while loop so the program doesnt exit for every error
        {
            bool validation_test = false;
            while (validation_test == false)
            {
                cout << "How many books do you currently own?\n";

                if (!(cin >> books_owned))
                {
                    cout << "Invalid entry please enter an integer!\n";
                    //fail state reset and safety buffer
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else
                {
                    validation_test = true;
                }
            }
        }

        //Converting variable to constant to keep a starting point for later calculations
        //as the users library grows or shrinks
        //Don't need to validate this since books_owned is being validated.
        const int STARTING_BOOKS_OWNED = books_owned;

        //PA4 while validation #2
        {
            bool validation_test = false;
            while (validation_test == false)
            {
                cout << "How many hours do you read per week the the nearest half hour?\n";
                //PA3 fixed 0 in denominator issues here which also aded another compound bool
                //PA4 fixed division by negative number issue
                if ((!(cin >> read_time_per_week)) || read_time_per_week <= 0)
                {
                    cout << "Invalid entry please enter a valid number greater than 0.\n";
                    //fail state reset and safety buffer
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else
                {
                    validation_test = true;
                }
            }
        }
        //PA4 while validation #3
        {
            bool validation_test = false;
            while (validation_test == false)
            {
                cout << "On average how many hours does it take to read a book?\n";
                if ((!(cin >> time_to_read_a_book)) || time_to_read_a_book <= 0)
                {
                    cout << "Invalid entry please enter an number greater than 0!\n";
                    //fail state reset and safety buffer
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else
                {
                    validation_test = true;
                }
            }
        }
        //PA4 while validation #4
        {
            bool validation_test = false;
            while (validation_test == false)
            {
                cout << "What is the target size of your collection?\n";
                if (!(cin >> target_library_size))
                {
                    cout << "Invalid entry please enter an integer!\n";
                    //fail state reset and safety buffer
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                else
                {
                    validation_test = true;
                }
            }
        }
    //some basic maf
    //12.0 needed to round properly
    months_to_completion = target_library_size - STARTING_BOOKS_OWNED;
    years_to_completion = round(months_to_completion / 12.0);
    //added this to account for the need for a double as well as precision formatting in the assignment.
    
    //PA4 replacing math collection_read_time = books_owned * time_to_read_a_book / read_time_per_week;
    //PA4 with a while loop to do the math to meet the fixed number of times loop.
    //collection_read_time = books_owned * time_to_read_a_book / read_time_per_week;
    collection_read_time = 0;
    for (int index = 0; index < books_owned; index++)
    {
        collection_read_time += time_to_read_a_book / read_time_per_week;
    }

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
        << fixed << setprecision(2)
        << collection_read_time
        << " weeks to read the whole collection\n";
    
    //PA3 1st if else block with double bool
    //PA3 Book ownership stats pulled from google
    if (books_owned >= 1 && books_owned <= 10)
    {
        cout << "Your library very small.\n\n";
    }
    else if (books_owned >= 11 && books_owned <= 25)
    {
        cout << "Your library is small.\n\n";
    }
    else if (books_owned >= 26 && books_owned <= 50)
    {
        cout << "Your library is averaged sized.\n\n";
    }
    else if (books_owned >= 51 && books_owned <= 500)
    {
        cout << "Your Library is large.\n\n";
    }
    else if (books_owned >= 501 && books_owned <= 1000)
    {
        cout << "!!Your library is huge!!\n\n";
    }
    else if (books_owned > 1000)
    {
        cout << "Congratulations you are in the top 3 percent of American book ownership!!\n";
    }
    else
    {
        cout << "??Why don't you own any books if you have this app??\n";
    }

    //PA3 logic block to drop variables when done with these if statements
    {
        //PA3 variables just for this portion
        string read_pace = "";
        string read_times = "";
        //PA3 2nd else if bool for read pace average
        if (time_to_read_a_book < 1)
        {
            cout << "Are you sure you can read that fast??\n";
        }
        else if (time_to_read_a_book >= 13 && time_to_read_a_book <= 20)
        {
            read_pace = "leisurely";
        }
        else if (time_to_read_a_book >= 8 && time_to_read_a_book <= 12)
        {
            read_pace = "average";
        }
        else
        {
            read_pace = "fast as lightning";
        }
        //PA3 3rd else if bool for read times per week average
        if (read_time_per_week < 1)
        {
            cout << "You need to read more often!\n\n";
        }
        else if (read_time_per_week >= 1 && read_time_per_week <= 4)
        {
            read_times = "low";
        }
        else if (read_time_per_week >= 5 && read_time_per_week <= 9)
        {
            read_times = "average";
        }
        else
        {
            read_times = "a lot";
        }
        //PA3 if statment to verify stings arent empty
        //PA3 really annoying that I can't just use .empty here but hey now I have another compound bool
        if (read_pace != "" && read_times != "")
        {
            cout << "Your reading pace is " << read_pace << ".\n";
            cout << "Your reading frequency is " << read_times << ".\n\n";
        }
        //PA3 no need for an else statement since the cout from the ifs will take care of low reading levels
    }

    //PA2 setting up a summary table
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
    //Reset
    cout
        << left
        << setfill(' ')
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
    //Reset
    file
        << left
        << setfill(' ')
        ;
    file.close();

    //PA3 starting the menu
    //will eventually turn the intro and reports into a structure or member function and add them to the
    //menu. will also use this menu to select the different functions of the program but for now
    //they are just basic cout statements.
    //PA3 case statement for menu

    //PA4 Needed to wrap this input for cin fails since entering things like leters caused infinite loops
    //PA4 in the book recommendation.
    int menu_input = 0;
    while (true)
    {
        cout << "Main Menu\n";
        cout << "   1) Add a book\n";
        cout << "   2) Remove a book\n";
        cout << "   3) Edit a book\n";
        cout << "   4) Exit\n";
        cout << "Please enter a number from the menu option\n";
        
        cin >> menu_input;

        if (cin.fail())
        {
            cout << "Invalid entry, please select an option 1 - 4.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (menu_input < 1 || menu_input > 4)
        {
            cout << "Out of range. Enter 1-4 only.\n";
            continue;
        }
        //PA4 exits loop on valid input
        break;
    }

    switch (menu_input) {
    case 1:
        cout << "Congratulations on your new book please enter its details.\n";
        break;
    case 2:
        cout << "Please select the book you would like to remove from your collection.\n";
        break;
    case 3:
        cout << "Please select the book you would like to edit.\n";
        break;
    case 4:
        cout << "See you next time.\n";
        return 0;
    //PA4 This is redundant now with the menu input validator but will be good later when I add more menu
    //PA4 options incase I forget to update the validator.
    default:
        cout << "Invalid entry, please select an option 1-4\n";
    }

    //PA4 Repeat loop until user decides to quit
    //PA4 In the future I will use array index to randomly select a book from the collection
    //PA4 I will also turn this into a function called from the menu.
    //PA4 Random book to read from collection reccomendation. Will always run at least once.
    {
        char user_continue = 'y';
        do
        {
            cout << "Your reading recommendtion is " << "Replace this with title array index " << ".\n";
            cout << "Would you like a different reccomendation? Y/N\n";
            cin >> user_continue;
            while (user_continue != 'y' && user_continue != 'Y' && user_continue != 'n' 
                  && user_continue != 'N')
            {
                cout << "Invalid entry please enter Y or N only\n";
                cin >> user_continue;
                //fail state reset and safety buffer
                //There are better ways to do this
                //cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.clear();
                cin.ignore(10000, '\n');
            }
        } while (user_continue == 'y' || user_continue == 'Y');
    }
}