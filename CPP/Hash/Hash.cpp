#include <string>
#include "linkedlist.h"
#include "linkedlist.cpp"
#include "Hash.h"
#define HASH_WEIGHT  13

using LinkedList::Node;
using LinkedList::search;
using LinkedList::headInsert;
using namespace std;

namespace HashTable
{

   Hash::Hash()
   {
      for (int i = 0; i < SIZE; i++)
      {
         hashArray[i] = NULL;
      }
   }

   Hash::~Hash()
   {
      for (int i=0; i<SIZE; i++)
      {
         Node<string> *next = hashArray[i];
         while (next != NULL)
         {
            Node<string> *discard = next;
            next = next->getLink( );
            delete discard;
         }
      }
   }
 
   unsigned int HashTable::computeHash(string s) const
   {
      unsigned hash = 0;
      for (int i = 0; i < s.length(); i++) 
      {
	      hash = HASH_WEIGHT * hash + s[i];
	      if (hash >= LARGE_INT)
		      hash %= SIZE;
      }
      return hash % SIZE; //size of  hash table array
   }

   void Hash::put(string s)
   {
      int hash = computeHash(s);
      if (search(hashArray[hash], s) == NULL)
      {
         // Only add the target if it's not in the list
         headInsert(hashArray[hash], s);
      }
   }

   bool Hash::containsString(string target) const
   {
      int hash = this->computeHash(target);
      Node<string>* result = search(hashArray[hash], target);
      if (result == NULL)
      {
         return false;
      }
      return true;
   }
}

