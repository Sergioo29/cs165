/***********************************************************************
* Program:
*    Assignment 01, GENETIC GENEALOGY
*    Brother Alvey, CS165
* Author:
*    Sergio Henrique
* Summary:
*    A code that uses a genetic marker to allow a user to search
*   for relatives. In this case that we use a single genetic marker.
*
*    Estimated:  3.0 hrs
*    Actual:     5.0 hrs
*    Hard: Figure out how to compute the percentage of matching DNA
************************************************************************/

#include <iostream>
using namespace std;

/**********************************************************************
 * Just prompts for the User's DNA
 ***********************************************************************/
void askYourDna(char userDna[])
{
   cout << "Enter your DNA sequence: ";
   cin >> userDna;
}

/**********************************************************************
 * Just prompts the total number of relatives we are going to deal with.
 ***********************************************************************/
int askNrelatives()
{
   int n;
   cout << "Enter the number of potential relatives: ";
   cin >> n;
   return n;
}

/**********************************************************************
 * Ask for each relative name, the number of prompts depends on the given
 * number of the other function.
 ***********************************************************************/
void relativeNames(char names[][256], int nRelat)
{
   for (int i = 0; i < nRelat; i++)
   {
      cout << "Please enter the name of relative #" << (i + 1) << ": ";
      cin >> names[i];
   }
}

/**********************************************************************
 * A loop to ask and store the relatives DNA
 ***********************************************************************/
void relativeDNA(char names[][256], int nRelat, char relatDna[][10])
{
   for (int i = 0; i < nRelat; i++)
   {
      cout << "Please enter the DNA sequence for " << names[i] << ": ";
      cin >> relatDna[i];
   }
}

/**********************************************************************
 * Displays the percentage of matching DNA
 ***********************************************************************/
void match(char userDna[], char names[][256], int nRelat, char relatDna[][10])
{
   for (int r = 0; r < nRelat; r++)
   {
      int percent = 0;
      for (int i = 0; i <= 10; i++)
      {
         if (userDna[i] == relatDna[r][i])
            percent += 10;
      }
      cout << "Percent match for " << names[r] << ": " << percent << "%\n";
   }

}

/**********************************************************************
 * The main just create the arrays and call the other functions
 ***********************************************************************/
int main()
{
   char userDna[10];
   askYourDna (userDna);
   int nRelatives = askNrelatives();
   cout << endl;

   char names[50][256];
   relativeNames(names, nRelatives);
   cout << endl;

   char relatDna[50][10];
   relativeDNA(names, nRelatives, relatDna);
   cout << endl;

   match(userDna, names, nRelatives, relatDna);
   return 0;
}
