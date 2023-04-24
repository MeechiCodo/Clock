// clocks.cpp
// Demetri Pighetti
// CS 210 Programming Languages
// Professor Cory Thoma

#include <iostream>
#include <iomanip>
using namespace std;


//used to print time in 24 hour format
void displayTime24(int hours, int minutes, int seconds) {
    cout << setfill('0') << setw(2) << hours << ":" << setw(2) << minutes << ":" << setw(2) << seconds;
}

//used to print time in 12 hour format
void displayTime12(int hours, int minutes, int seconds) {
    int hours12 = hours % 12 == 0 ? 12 : hours % 12;
    cout << setfill('0') << setw(2) << hours12 << ":" << setw(2) << minutes << ":" << setw(2) << seconds << (hours < 12 ? " AM" : " PM") ;
}

int main()
{
    // declaring hours, minutes, and seconds as ints and setting their initial values to 0
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    bool validHour = false;
    bool validMin = false;
    bool validSec = false;
    
    // Asking user to input time and checking to see if user input is valid
    
    while (!validHour) {
        cout << "Please enter the current hour (values accepted 0-23)" << endl;
        cin >> hours;
        if (hours < 0 || hours > 23) {
            cout << "Invalid input, value did not lie between 0 and 23" << endl;
        }
        else {
            validHour = true;
        }
    }
    while (!validMin) {
        cout << "Please enter the current minute (values accepted 0-59)" << endl;
        cin >> minutes;
        if (minutes < 0 || minutes > 59) {
            cout << "Invalid input, value did not lie between 0 and 59" << endl;
        }
        else {
            validMin = true;
        }
    }
    while (!validSec) {
        cout << "Please enter the current second (values accepted 0-59)" << endl;
        cin >> seconds;
        if (seconds < 0 || seconds > 59) {
            cout << "Invalid input, value did not lie between 0 and 59" << endl;
        }
        else {
            validSec = true;
        }
    }

    while (true) {


        // display time in boxes

        cout << "**************************" << "     " << "**************************" << endl;
        cout << "*" << "        ";
        //24 hour time
        displayTime24(hours, minutes, seconds);
        cout << "        " << "*" << "     " << "*" << "        ";
        //12 hour time
        displayTime12(hours, minutes, seconds);
        cout << "     " << "*" << endl;
        cout << "**************************" << "     " << "**************************" << endl;
        
        // Ask for user input
        cout << "             " << "*******************************" << endl;
        cout << "             " << "*" << "1-Add One Hour" << "               " << "*" << endl;
        cout << "             " << "*" << "2-Add One Minute" << "             " << "*" << endl;
        cout << "             " << "*" << "3-Add One Second" << "             " << "*" << endl;
        cout << "             " << "*" << "4-Exit Program" << "               " << "*" << endl;
        cout << "             " << "*******************************" << endl;
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            hours = (hours + 1) % 24; // add 1 hour and wrap around to 0 after 24
            break;
        case 2:
            minutes = (minutes + 1) % 60; // add 1 minute and wrap around to 0 after 60
            break;
        case 3:
            seconds = (seconds + 1) % 60; // add 1 second and wrap around to 0 after 60
            break;
        case 4:
            return 0; // exit program
        default:
            cout << "Invalid choice. Please enter values 1 2 3 or 4" << endl;
            break;
        }
    }

    return 0;
}