/***********************************************************************
* Program:
*    Assignment 03, Digital Forensics with Corrupt Files
*    Brother Alvey, CS165
* Author:
*    Sergio Henrique
* Summary:
*    A program to scan through that log to identify users who accessed files
*    in a particular window of time. But now we Gotta Catch'em All (the errors).
*
*    Estimated:  3.0 hrs
*    Actual:     2.0 hrs
*    Difficult part: The concept of the "stringstream".
*                    The "getline" condition in the while loop inside readFile.
*                    Thanks for the video, bro Alvey. Dynamic videos helps a lot
*                    on my learning proccess.
************************************************************************/
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
struct AccessRecord
{
   char username[500];
   char filename[500];
   long timestamp;
};

/********************************************************************************
 Prompt the user for the file name.
 ********************************************************************************/
void getFile(char file[])
{
   cout << "Enter the access record file: ";
   cin >> file;
   cin.ignore();
}

/********************************************************************************
 Parse the file line-upon-line precep..., with some if rules to catch errors.
 ********************************************************************************/
AccessRecord parseLine(string line)
{
   stringstream ss;
   ss.str(line);
   AccessRecord record;
   ss >> record.filename;
   ss >> record.username;
   ss >> record.timestamp;

   if (ss.fail() || record.timestamp < 1000000000 || record.timestamp > 10000000000)
   {
      throw string("Error parsing line: ") + line; // I didn't know we can use +
   }
   return record;
}

/********************************************************************************
 Reads the file and stores its content on a structure array. Added Try/Catch.
 ********************************************************************************/
int readFile(char file[], AccessRecord records[])
{
   ifstream fin(file);
   if (fin.fail())
   {
      cout << "\nERROR: Unable to open the file: " << file << endl << endl;
      return -1;
   }

   int i = 0;
   string line;
   while (getline(fin, line))
   {
      try
      {
         AccessRecord record = parseLine(line);
         records[i] = record;
         i++;
      }
      catch (string error)
      {
         cout << error << endl;
      }
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
 Main calls the other functions and create some variables and arrays.
 ********************************************************************************/
int main()
{
   char file[256];
   getFile(file);

   AccessRecord records[100];
   int totalRec = readFile(file, records);
   if (totalRec == -1) // if read the file fails, the program shuts down.
      return 0;

   long start;
   long end;
   getTimestamps(start, end);
   display(records, totalRec, start, end);
   return 0;
}
