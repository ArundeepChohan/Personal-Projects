/*
Description: This program deals with Templates, Stacks, OO programming and Dynamic memory. 
It should duplicate the size of the stack when full, copy the contents into the larger array and 
release the old array.
*/

#include <iostream>
#include <string>
#include <stdexcept>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <stdio.h>
using namespace std;

template< class T >
class Stack {
public:
      Stack( int = 10 );  // default constructor (stack size 10)
   	// destructor
   	~Stack() { 
      		delete [] stackPtr; 
   	} 
   	bool push( const T& );  
   	bool pop( T& );
      void display();
      void ftoa(double f,char cs[]);      
      int getTop();     
   	// determine whether Stack is empty
   	bool isEmpty() const { 
      		return top == -1; 
   	} 
   	// determine whether Stack is full
   	bool isFull() const  { 
      		return top == size - 1; 
   	} 
private:
      int size;     // # of elements in the stack
      int top;      // location of the top element
      T *stackPtr;  // pointer to the stack
}; 

// constructor
template< class T >
Stack< T >::Stack( int s ) {
size = s > 0 ? s : 10;  
   	top = -1;  // Stack initially empty
   	stackPtr = new T[ size ]; // allocate memory for elements
} 
template< class T >
bool Stack< T >::push( const T &pushValue ) {
   	if ( !isFull() ) {
      	stackPtr[ ++top ] = pushValue;  
      	return true;  
   } 
   return false;  
} 
template< class T > 
bool Stack< T >::pop( T &popValue ) {
   	if ( !isEmpty() ) {
      	popValue = stackPtr[ top-- ];  // remove item from Stack
      	return true;  
   } 
   return false;  
}
template< class T > 
void Stack< T >::display( ) {
   
   for(int i =0;i<size;i++)
   {
      //Display all the elements on the stack by popping, approximately 20 per line.
      if((i!=0)&&(i%20==0))
      {
         cout<<endl;
      }
      cout<<stackPtr[top]<<" ";
      pop(stackPtr[top]);
   }
   cout<<endl;
}
template< class T > 
int Stack< T >::getTop( ) {
   if(top==-1)
   {
      return -1;
   }
   return stackPtr[top];
}

template< class T > 
void Stack< T >::ftoa( double f,char cs[]) {
   //converts decimal function into cstring
   sprintf(cs, "%2.2f", f);
}

int main()
{
   int i,pseudoNum/*,multiplier = 1*/;
   
   double dd;
   
   const int DEFAULT_SIZE = 100;
   //Do 1. to 7. once for elements of type integer, once for elements of type double, and once for elements of type string (the string object):
   
   const float floatDivision = 100.00;
   
   //1.	Create a Stack of default size,
   Stack<int> elemInt(DEFAULT_SIZE);
   Stack<double> elemDouble(DEFAULT_SIZE);
   Stack<string> elemString(DEFAULT_SIZE);
   
   /* initialize random seed: */
   srand (time(NULL));

   //2.	Use the pseudo random number generator “int rand()”  to push 100 integer elements onto the stack. The stack is full now.
   cout<<"Filling all elements by pushing: "<<endl;
   for(i = 0;i <= 100;i++)
   {
      /* generate number between 1 and 9*/
      pseudoNum = rand() % 9 + 1;
      if(!elemInt.push(pseudoNum))
      {
         cout<<"The stack is full."<<endl;
      }
   }  
   
   cout<<"Filling all elements by pushing: "<<endl;
   for(i = 0;i <= 100;i++)
   {
      /* generate number between 1 and 1000 */
      pseudoNum = rand() % 1000 + 1;
      if(!elemDouble.push(pseudoNum))
      {
         cout<<"The stack is full."<<endl;
      }
   }
   
   cout<<"Filling all elements by pushing: "<<endl;
   for(i = 0;i <= 100;i++)
   {
      /* generate number between 1 and 1000 */
      pseudoNum = rand() % 1000 + 1;
      dd = (double)pseudoNum/floatDivision;
      char cs[10];
      elemString.ftoa(dd,cs);
      string temp = cs;
      
      //cout<<temp<<endl;
      if(!elemString.push(temp))
      {
         cout<<"The stack is full."<<endl;
      }
   }  
   
   //3.	Display all the elements on the stack by popping, approximately 20 per line,  until the stack is empty. The stack is empty now but it has memory to hold 100 elements,
   cout<<"Displaying all elements by popping: "<<endl;
   elemInt.display();
   cout<<"Displaying all elements by popping: "<<endl;
   elemDouble.display();
   cout<<"Displaying all elements by popping: "<<endl;
   elemString.display();
   
   //4.	This time push 250 pseudo random integer elements onto the stack. The memory should get doubled twice; once when the 101st element is being pushed, and then when the 201st one comes along. 
   /*
   for(int i =0;i<250;i++)
   {
      // generate number between 1 and 9 
      pseudoNum = rand() % 9 + 1;
      if(!elemInt.push(pseudoNum))
      {
         cout<<"Memory is doubled."<<endl;
         multiplier*=2;
         Stack<int> p (DEFAULT_SIZE * multiplier);
         while(elemInt.getTop()!=-1)
         {
            p.push(elemInt.getTop());
            elemInt.pop(elemInt.getTop());
         }
         p.push(pseudoNum);
         ~elemInt;
      }
   }
   
   */
   
   //5.	Put a “cout statement” in the appropriate method to flag when the memory is getting Doubled.
   //6.	Display all the elements by popping the stack until it is empty, approximately 20 per line.
   /*
   cout<<"Displaying all elements by popping."<<endl;
   elemInt.display();
   elemDouble.display();
   elemString.display();
      */
   //7.	Repeat the above for elements of type double (decimal numbers), then for elements of type string. 

   return 0;
}

