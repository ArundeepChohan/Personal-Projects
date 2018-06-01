/*
Description: 
2.	Show any misspelled word and the corresponding line number. Count Blank Lines.
3.	Run your program once with a Hash Table of size 1000, and another time 500.
4.	Count the number of Collisions for each cell of the Hash Table when loading the dictionary – words.rtf – and store/display the data 20 per line (or some reasonable number).
5.	Count the number of words in the test file gettysburg_address.txt that are misspelled and the ones that are correct. In each case, count the number of operations performed and store/display these numbers. Also, store/display the average number of operations for a misspelled and correct word. Note that number of operations refers to number of nodes visited in the linked list for each word.
6.	Output: All output must be displayed on the monitor and also saved in files results_500.txt, results_1000.txt that correspond to the size of the Hash Table, respectively.
*/

#ifndef HASH_H
#define HASH_H
#include <string>
#include "LinkedList.h"

#define LARGE_INT 1024*1024*1024
const int SIZE = 1000;
using List::Node;
using namespace std;
namespace HashTable
{
   class Hash
   {
      public:
         Hash();
         ~Hash();//deconstructor
         unsigned int computeHash(string s)const;
         void put(string s);
         bool containsString(string s) const;

      private:
         Node<string> *hashArray[SIZE];
   };
}
#endif //HASH_H