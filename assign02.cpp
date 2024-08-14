/***********************************************************************
* Program:
*    Assignment 02, Digital Forensics
*    Brother Alvey, CS165
* Author:
*    Sergio Henrique
* Summary:
*    A program to scan through that log to identify users who accessed files
*    in a particular window of time.
*
*    Estimated:  6.0 hrs
*    Actual:     8.0 hrs
*    Difficult part: The display function, how to compute the acceptable
*                    timestamp cap. And the readFile function, I kind of
*                    forgot how to deal with files.
************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
struct AccessRecord
{
   char username[500];
   char filename[500];
   long timestamp;
};

/********************************************************************************
 Prompt for the file name.
 ********************************************************************************/
void getFile(char file[])
{
   cout << "Enter the access record file: ";
   cin >> file;
   cin.ignore();
}

/********************************************************************************
 Reads the file and stores its content on a structure array.
 ********************************************************************************/
int readFile(char file[], AccessRecord records[])
{
   ifstream fin(file);
   if (fin.fail())
   {
      cout << "\nError: Unable to open the file: " << file << endl << endl;
      return -1;
   }

   int i = 0;
   while (!fin.eof())
   {
      fin >> records[i].filename;
      fin >> records[i].username;
      fin >> records[i].timestamp;

      if (!fin.fail())
         i++;
   }
   fin.close();
   return i;
}

/********************************************************************************
 Prompt the user for the initial and final timestamp for computation.
 ********************************************************************************/
void getTimestamps(long &start, long &end)
{
   cout << "\nEnter the start time: ";
   cin >> start;
   cout << "Enter the end time: ";
   cin >> end;
}

/********************************************************************************
 Display the results with a "spreadsheet looking" output.
 ********************************************************************************/
void display(AccessRecord records[], int count, long start, long end)
{
   cout << "\nThe following records match your criteria:\n\n";
   cout << setw(15) << "Timestamp" << setw(20) << "File" << setw(21) << "User\n";
   cout <<"--------------- ------------------- -------------------\n";
   for (int i = 0; i < count; i++)
   {
      if (start < records[i].timestamp && records[i].timestamp < end)
      {
         cout << setw(15) << records[i].timestamp
              << setw(20) << records[i].filename
              << setw(20) << records[i].username << endl;
      }
   }
   cout << "End of records\n";
}

/********************************************************************************
 Main calls all the other functions and create some variables.
 ********************************************************************************/
int main()
{
   char file[256];
   getFile(file);

   AccessRecord records[100];
   int totalRec = readFile(file, records);
   if (totalRec == -1)
      return 0;

   long start;
   long end;
   getTimestamps(start, end);
   display(records, totalRec, start, end);
   return 0;
}
