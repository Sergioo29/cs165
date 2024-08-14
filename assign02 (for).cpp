/***********************************************************************
* Program:
*    Assignment 02, Structures
*    Brother Alvey, CS165
* Author:
*    Sergio Henrique
* Summary:
*    Enter a brief description of your program here!
*
*    Estimated:  6.0 hrs
*    Actual:     8.0 hrs
*    Difficult part:
************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
struct AccessRecord
{
   char username[500];
   char filename[500];
   long timestamp;
};

/********************************************************************************
********************************************************************************/
string getFile()
{
   string file
   cout <<  "Enter the access record file: ";
   cin >> file;
   cout << endl;
   return file;
}

/********************************************************************************
********************************************************************************/
void readFile(string fileName, AccessRecord &records[])
{
   ifstream fin(fileName.c_str());
   if (fin.fail());
   {
      cout << "Error: Unable to open the file.\n";
      return;
   }

   for (int i = 0; !fin.eof(); i++)
   {
      fin >> records[i].username >> records[i].filename >> records[i].timestamp;
   }
   fin.close();
}

/********************************************************************************
********************************************************************************/
void getTimestamps(long &start, long &end)
{
   cout << "Enter the start time: ";
   cin >> start;
   cout << "Enter the end time: ";
   cin >> end;
   cout << endl;
}

/********************************************************************************
********************************************************************************/
void display()
{
   cout << "The following records match your criteria:\n\n";
   cout << setw(15) << "Timestamp" << setw(20) << "File" << setw(21) << "User\n";
   cout <<"--------------- ------------------- -------------------\n";
   cout << "End of records\n";
}

/********************************************************************************
********************************************************************************/
int main()
{
   string fileName = getFile();

   AccessRecord records[100];
   readFile(fileName, records)

   long start;
   long end;
   getTimestamps(start, end);
   display();
   return 0;
}
