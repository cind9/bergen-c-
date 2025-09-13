#include <iostream>
using namespace std;
int main() {
    int day, hour, minute, second;
    int sechr = 3600;
    int secmin = 60;
    int secday = 86400;
    
    cout << "Enter a number of seconds: ";
    cin >> second;
        if (second >= secday)
        {
            day = second / secday;
            cout << "There is " << day << " days in " << second << " seconds.\n";
        }
        else if (second >= sechr)
        {
            hour = second / sechr;
            cout << "There is " << hour << " hours in " << second << " seconds.\n";
        }
        else if (second >= secmin)
        {
            minute = second / secmin;
            cout << "There is " << minute << " minutes in " << second << "seconds.\n";
        }
            return 0;
        }
