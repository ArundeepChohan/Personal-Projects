#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <string>
#include "Hash.h"
using namespace std;
using HashTable::Hash;

void upToLow(string & str);
void removePunct(string & str);
 
int main()
{
   Hash a;
   string currWord;
   string word;
   int countMisspelled = 0;
   int countCorrect = 0;

   int countMisOperations = 0;
   int countCorOperations = 0;
   //Get input from words.rtf
   ifstream dictionary("words.txt");
   
   //Output file
   ofstream myfile("result.txt");

   //File checking
   if (dictionary.fail())
   {
      cout << "File does not exist" << endl;
      cout << "Exit program" << endl;  
   }

   //Create the dictionary as a hash table

   while(dictionary >> currWord)
   {
      a.put(currWord);
   }
   dictionary.close();

   //Get input from gettysburg_address.txt
   ifstream input("gettysburg_address.txt");
 
    //File checking
   if (input.fail())
   {
      cout << "File does not exist" << endl;
      cout << "Exit program" << endl;
   }
	 
   //Spell check gettysburg_address.txt
   cout << "Misspelled words : " << endl;
   cout << endl;
   
   if(myfile.is_open()&&!input.fail())
   {
      //If a word is not in the dictionary assume misspelled
      while(input >> word)	    
      {
         removePunct(word);
         upToLow(word);
         if(a.containsString(word) == false)
         {
            countMisspelled++; // Increment misspelled words count
            cout << word << " ";
            if(countMisspelled % 20 == 0) // Display misspelled words 20 per line
            {
               myfile <<"Correct: " <<word;
               cout << endl;
               countMisOperations+=a.computeHash(word);
            }
         }
         else
         {
            myfile <<"Incorrect: " <<word;
            countCorrect++; // Increment correct words count
            countCorOperations+=a.computeHash(word);
         }
      }
   }
   
   myfile<<"Average Correct Operation:"<<(countCorOperations/countCorrect);
   myfile<<"Average Mis Operation:"<<(countMisOperations/countMisspelled);
   myfile<< "Number of misspelled words : " << countMisspelled;
   myfile << "Number of correct words : " << countCorrect;
   myfile.close();
   input.close();
	 
   cout << endl;
   cout << endl;
   
   cout<<"Average Correct Operation:"<<(countCorOperations/countCorrect);
   cout<<"Average Mis Operation:"<<(countMisOperations/countMisspelled);
   cout << "Number of misspelled words : " << countMisspelled << endl;
   cout << "Number of correct words : " << countCorrect << endl;
	 
   return 0;
}

/*Function to convert uppercase letters to lowercase*/
void upToLow(string & str)
{
   for (unsigned int i = 0; i < strlen(str.c_str()); i++)
   {
      if (str[i] >= 0x41 && str[i] <= 0x5A)
      {
         str[i] = str[i] + 0x20;
      }
   }
}
	 

/*Function to remove punctuation from string*/
void removePunct(string & str)
{	    
      str.erase(remove_if(str.begin(), str.end(), static_cast<int(*)(int)>(&ispunct)),str.end());
}