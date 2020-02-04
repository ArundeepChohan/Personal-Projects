/*
This program is a recursive function that computes all the permutations of some distinct symbols 
as a c-string.
*/

#include <iostream>
#include <iostream>
#include <fstream>
#include <string>

void displayPermutation(char* symbols);
void permutation(char * arr, int curr, int size);
void swap(char *fir, char *sec);

using namespace std;

const int ARRAYSIZE = 50; // 2. Assume that the maximum number of symbols, in each line, will not exceed 50.
int COUNT;//The number of permutations

int main()
{

	char * symbols = new char[ARRAYSIZE]; 
	string temp;
	ifstream fin("symbols.txt"); 
   
	//1.	Test your code by reading from the given file symbols.txt. Each line has text composed of distinct symbols. Find the permutations for each line of the input file.
   	if(fin.is_open())
	{
      		cout << "File Opened successfully!!!. Reading data from file into array" << endl;

		while(fin.getline(symbols,ARRAYSIZE))//Get each line and store in char array.
		{
         	//~ for(int i =0;i<arraySize&&symbols[i]!=NULL;i++)//check to see if symbols are retrieved
         	//~ {
            	//~ cout<<symbols[i];
         	//~ }
         		COUNT = 0;
         		displayPermutation(symbols);
		}
		fin.close();
	}
	else 
	{
		cout << "File could not be opened." << endl;
	}
   
   return 0;
}
 
/*
This method figures the starts and end of the array.
*/
void displayPermutation(char* symbols)
{
	int start = 0;
   	int end = 0;
   
   	for(int i = 0;(i < ARRAYSIZE) && (symbols[i]!=NULL);i++)//where to stop to avoid null pointer
   	{
      		end++;
   	} 
   	permutation(symbols,start,end);
}

/* 
This method changes the pointer to reference another.
@param fir The values to be changed.
@param sec The values to be changed.
*/
void swap(char *fir, char *sec)
{ 
   	char temp = *fir;
   	*fir = *sec;
   	*sec = temp;
}

/*
This method finds out all possible permutations of a char array.
@param arr Stored array of symbols.
@param curr The start position.
@param size The end of the array to avoid null pointers.
*/
void permutation(char * arr, int curr, int size)
{

   	if(curr == size-1)
   	{
		for(int a = 0; a < size; a++)
      		{
         		cout << arr[a];
      		}
      		cout << endl;
   	}
   	else
   	{
      		for(int i = curr; i < size; i++)
      		{
         		swap(&arr[curr], &arr[i]);
         		permutation(arr, curr+1, size);
         		swap(&arr[curr], &arr[i]);
      		}
   	}
   
}
       
