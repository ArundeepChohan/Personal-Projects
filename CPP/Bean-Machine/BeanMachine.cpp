/*
This program simulates the bean machine, prompting user for input 
and providing a histogram for the output.
*/
#include <iostream>
#include <cstdlib>

int pathGenerator(int numOfSlots);
void print(int slots[],int numOfSlots);

using namespace std; 

int main()
{
   int numOfBalls,numOfSlots;
   
   do
   {
   cout<<"Enter the number of balls: "<<endl;
   cin >> numOfBalls;
   }
   while(numOfBalls <=0);
   
   do
   {
   cout<<"Enter the number of slots in the bean machine: "<<endl;
   cin >> numOfSlots;
   }
   while((numOfSlots > 50)||(numOfSlots <= 0));
   
   const int maxNumOfSlots = 50;//Maximum number of slots in bean machine
   int slots[maxNumOfSlots];
   
   for(int i = 0;i < maxNumOfSlots;i++)//Sets everything in the array to 0
   { 
      slots[i] = 0;
      
   }
   cout <<"------------" << endl;
   
   for(int i = 0; i < numOfBalls;i++)//Incremetes balls in slots
   {
      slots[pathGenerator(numOfSlots)]++;
   }
   cout <<"------------" << endl;
   
   print(slots,numOfSlots);
   
   return 0;
}

/*
This method returns the slot into which the ball took.
@param numberOfSlots: Takes the number of slots in the bean machine.
*/
int pathGenerator(int numberOfSlots)
{
   int location = 0,pathTaken;
   
   //Generates pathway
   for(int i = 1;i < numberOfSlots;i++)
   {
      pathTaken = rand() % 2;//Generate left or right(0 or 1)
      
      if(pathTaken == 1)
      {
         cout<<"R";
         location+=pathTaken;
      }
      else
      {
         cout<<"L";
      }
      
      
   }
   
   cout << endl;
   
   return location;
}

/*
This method prints the final build up of balls in a histogram.
@param slots: The buildup of balls.
@param numOfSlots: The slots into which the ball could have fallen.
*/
void print(int slots[],int numOfSlots)
{
   //Displays the final build up of balls in a histogram
   for(int i = 0; i < numOfSlots;i++)
   {
      int ballsInSlot = slots[i];
      if(ballsInSlot > 0)
      {
         for(int j = 0; j < ballsInSlot;j++)
         {
            cout<<"O";
         }
         cout << endl;
      }
      else
      {
         cout <<"No Balls" << endl;
      }
   }
}