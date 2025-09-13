#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
string month1, month2, month3;
float rainfallMonth1, rainfallMonth2, rainfallMonth3, total, average;
   
    cout << "Enter the name for month 1: ";
    cin >> month1;
    cout << "How many inches of rain fell for " << month1;
    cout << ": ";
    
    cin >> rainfallMonth1;
    cout << "Enter the name for month 2: ";
    cin >> month2;
    cout << "How many inches of rain fell for " << month2;
    cout << ": ";
    
    cin >> rainfallMonth2;
    cout << "Enter the name for month 3: ";
    cin >> month3;
    
    cout << "How many inches of rain fell for " << month3;
    cout << ": ";
    
    cin >> rainfallMonth3;
    total = rainfallMonth1 + rainfallMonth2 + rainfallMonth3;
    average = total / 3;
    
    cout << setprecision(2) << fixed;
    cout << "\nThe average rainfall for ";
    cout << month1 << ", ";
    cout << month2 << ", and ";
    cout << month3 << " is ";
    cout << average << " inches.\n";
    
    return 0;
    }
