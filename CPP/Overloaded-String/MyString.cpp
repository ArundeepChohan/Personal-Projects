/*
Description: This program implements a string class with overloaded operators.
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
using namespace std;
const int DEFAULT_CAPACITY = 100;

class MyString {
public:
   MyString();
   MyString(const char* chars);
   MyString(const MyString & S);//copy constructor
   ~MyString();//deconstructor

   MyString& operator =(const MyString& S1);//assignment constructor

   int length() const;
   char& getChar(int index) const;

   //Overload these operators [], +, +=, <<, >>, ==, !=, <, <=, >, >=
   friend ostream& operator << (ostream & OS,const MyString &S);// out stream displays the string
   friend istream& operator >> (istream & IS,MyString &S);//instream takes in a string and creates and object

   friend bool operator ==(const MyString& S1, const MyString & S2);// checks if both strings are equal
   friend bool operator != (const MyString& S1, const MyString & S2);// checks if strings arent equal
   friend bool operator <= (const MyString& S1, const MyString & S2);// checks if 
   friend bool operator >= (const MyString& S1, const MyString & S2);// checks if 

   MyString& operator+=( const MyString &right);
   MyString operator + (const MyString& S1)const;

   char & operator [] (int index);
   char operator [](int index)const;
   
   friend bool operator <(const MyString& S1, const MyString & S2);// checks if 
   friend bool operator >(const MyString& S1, const MyString & S2);// checks if 
   
private:
  		char* value;
  		int size;
}; 

MyString::MyString()
{
   value = new char[DEFAULT_CAPACITY];
   value[DEFAULT_CAPACITY-1]= '\0';
}

MyString::MyString(const char* chars)
{
   size = strlen(chars);
   value = new char[size + 1];
   strcpy(value,chars);
}

MyString::MyString(const MyString & S)
{
   size = S.size;
   value = new char[size];
   strcpy(value, S.value);
}

MyString::~MyString()
{
   delete [] value;
}

int MyString::length()const
{
   return size;
}

char& MyString::getChar(int index)const
{
   return value[index];
}

ostream& operator <<(ostream & OS, const MyString& S)
{
   OS << S.value;
   return OS;
}

istream& operator >>(istream & IN,MyString& S)
{
   char* ptr = new char[DEFAULT_CAPACITY];
   IN >> ptr;
   S = MyString(ptr);
   delete ptr;
   
   return IN;
}

MyString& MyString :: operator+=(const MyString &S1)
{
   char * temp = value;
   value = new char[strlen(value) + S1.length() + 1];
   strcpy(value, temp);
   strcat(value, S1.value);
   if(size != 0)
   {
      delete [] temp;
   }
   size = strlen(value);
   return *this;
}

MyString& MyString::operator=(const MyString& S1)
{
   if (S1.value == 0)
   {
      delete[] value;
      value = 0;
      size = 0;
      return *this;
   }
   if (this != &S1)
   {
      delete[] value;
      value = new char[S1.size + 1];
      strcpy(value, S1.value );
      size = S1.size;
   }
   return *this;
}

MyString MyString::operator + (const MyString& S1)const
{
   
   return((MyString )(strcat(value, S1.value))); 

}
bool operator == (const MyString& s1, const MyString& s2)
{
   return (strcmp(s1.value, s2.value) == 0);
}

bool operator != (const MyString& s1, const MyString& s2)
{
   return !(s1 == s2);
}

bool operator > (const MyString& s1, const MyString& s2)
{
   return (!(s1 == s2) && !(s1 < s2));
}

bool operator < (const MyString& s1, const MyString& s2)
{
   return (strcmp(s1.value, s2.value) < 0);
}

bool operator <= (const MyString& s1, const MyString& s2)
{
   return ((s1 < s2) || (s1 == s2));
}

bool operator >= (const MyString& s1, const MyString& s2)
{
   return (!(s1 < s2));
}

char& MyString::operator[](int index)
{
   
   if (index < 0 || index >= size)
   {
      cout << "subscript error" << endl;
      exit(0);
   }
   else
   {
     return value[index];
   }
   
   return value[index];;
}

char MyString::operator[](int index)const
{
   if ((index < 0) || (index >= size))
   {
      cout << "subscript error" << endl;
      exit(0);
   }
   else
   {
     return value[index];
   }
   
   return value[index];
}

void test_copy_and_destructor(const MyString S)
{
	cout << "test: copy constructor and destructor calls: " << endl;
   MyString* temp = new MyString(S);
    
   for(int i =0;i<((temp->length())-1);i++)
   {
      cout<<temp->getChar(i)<<endl;
   }
   delete temp;
   
	cout << "temp inside function test_copy_and_destructor: " << temp << endl;
}

int main() 
{

	MyString st1("abc abc");
	MyString st2("9fgth");
	
	cout << "Copy constructor , << operator" << endl;
	
	MyString st3(st1);
	
	cout << "st3: " << st3 << endl;
	
	test_copy_and_destructor(st2);
	
	MyString  st4;
	
	cout << "operator + " << endl;
	
	st4 = st3 + st2;
	
	cout << "st4: " << st4 << endl;
	
	cout << "st1 + st2: " << (st1 + st2) << endl;

	cout << "operators  [ ] " << endl;
	
	for (int i = 0; i < st2.length(); i++)
   {
		cout << st2[i] << " ";
   }
   
	cout << endl;

	cout << "operators  += , ==, != " << endl;
	
	if (st3 == st1)
		cout << "st3 and st1 are identical " << endl;
	else 
      cout << "st3 and st1 are not identical " << endl;
	
	if (st2 != st1)
		cout << "st2 and st1 are not identical " << endl;
	else 
      cout << "st2 and st1 are identical " << endl;
	
	cout << "operators  < , <=, >, >= " << endl;
	
	if (st2 < st1)
		cout << "st2 < st1 " << endl;
	else 
      cout << "st2 is not less than st1 " << endl;
	
	if (st1 <= st2)
		cout << "st1 <= st2 " << endl;
	else 
      cout << "st1 is not less than or equal to st2 " << endl;
	
	if (st1 > st2)
		cout << "st1 > st2 " << endl;
	else 
      cout << "not (st1 >  st2) " << endl;
	
	if (st1 >= st2)
		cout << "st1 >= st2 " << endl;
	else 
      cout << "not (st1 >=  st2) " << endl;

	cout << "operator >> " << endl;
	
	//Open the data file
	ifstream input("A9_input.txt");
	if (input.fail()) 
   {
		cout << "unable to open input file A9_input.txt, Exiting..... "<<endl;
	}
   else
   {
	   MyString temp1;
	   MyString temp2("aaa");
	   input >> temp1;
	   input >> temp2;
	   cout << "first element of input file: " << temp1 << endl;
	   cout << "second element of input file: " << temp2 << endl;
	   input.close();

	   cout << "MyString says farewell..... "<< endl;
   }
   
	return 0;
}