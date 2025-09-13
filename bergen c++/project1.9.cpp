#include <iostream>
using namespace std;
int main()
{
int Store1, Store2, Store3;
cout << "Please enter the sales for each store rounded to the nearest $100.\n";
do
{
cout << "Enter today’s sales for sotre 1: ";
cin >> Store1;
if (Store1 < 0)
cout << "Error! Sales figures must be greater than $0.00.\n";
}while (Store1 < 0);
do
{
cout << "Enter today’s sales for sotre 2: ";
cin >> Store2;
if (Store2 < 0)
cout << "Error! Sales figures must be greater than $0.00.\n";
}while (Store2 < 0);
do
{
cout << "Enter today’s sales for sotre 3: ";
cin >> Store3;
if (Store3 < 0)
cout << "Error! Sales figures must be greater than $0.00.\n";
}while (Store3 < 0);
Store1 /= 100;
Store2 /= 100;
Store3 /= 100;
cout << "\n DAILY SALES\n (each * = $100)\n"
<< "Store 1: ";
for (int i = 0; i < Store1; ++i)
{
cout << "* ";
}
cout << "\nStore 2: ";
for (int i = 0; i < Store2; ++i)
{
cout << "* ";
}
cout << "\nStore 3: ";
for (int i = 0; i < Store3; ++i)
{
cout << "* ";
}
cout << endl;
return 0;
}
