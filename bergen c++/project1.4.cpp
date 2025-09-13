
#include <iostream>
using namespace std;
int main()
{
    int month,day,year;
    cout<<"Enter month: ";
    cin>>month;
   
    if (month > 12|| month < 1)
        {
            cout << "invalid input please restart.";
        }
            cout << "Enter day: ";
            cin >> day;
    if (day > 31 || day < 1)
        {
            cout << "invalid input please restart.";
        }
            cout << "Enter two digit year: ";
            cin >> year;
            int day_month = day*month ;
    if (day_month == year)
        {
            cout << "This date is magic!";
        }
    else
        {
            cout << "This date is not magic.";
        }
            return 0;
        }
