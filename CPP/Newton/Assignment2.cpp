/*
This program uses Newton’s Method to find the square root of a non-negative number 
and uses the square root to also find the roots of a quadratic equation.
*/
#include <iostream>
#include <cmath>
#include <fstream>

double mySqrt(double a, double precision);
using namespace std; 
int main()
{
   /* http://www.cplusplus.com/doc/tutorial/files/ */
   ifstream file("newton.txt");
   
   if (file.is_open())
   {
      while(!file.eof())//reads until end of file
      {
         double a,b,c,epsilon, disc,value,x1,x2;
         
         file >> epsilon;//Our input is provided in a txt file. Each line of the file contains 4 doubles: EPSILON, a, b, c, respectively.
         file >> a;
         file >> b;
         file >> c;
         
         disc = (b * b) - (4 * a *c);
         
         if((a !=0) &&(disc >= 0))//Note that  a cannot equal 0, otherwise, the equation is not quadratic.
         {
            value = mySqrt(disc,epsilon);//The square root
            
            x1 = (((-1) * b)+ value)/(2*a);//the 2 roots of a quadratic function
            x2 = (((-1) * b) - value)/(2*a);
            
            cout<<"X1: "<< x1 <<" X2: "<< x2 << endl;
         }
         else
         {
            cout << "Function is not a Quadratic Equation!"<< endl;
         }
         cout << "--------------------------------------"<< endl;
      }
   }
   else
   {
      cout <<"Can't open file!"<< endl;
   }
   
   return 0;
}

/*
Newtons method of finding a square root for a non-negative number.
*/
double mySqrt(double a, double precision)
{
 
   int count = 0;
   double sqRoot,x1,x0 =a/2;
   
   /*
      x0 = a/2
      x1= (1/2)(x0+(a/x0))
      */
   do
   {
      sqRoot = (x0+(a/x0))/2;
      x1 = x0;
      x0 = sqRoot;
      count = count+1;
   }
   while(abs(x1-sqRoot)>=precision);
   
   /*
      Prints the input values, the square root and the number of iterations that it performs to compute the square root.
      */
   cout << "Number of Interations: " << count << endl;
   cout << "A:" << a << endl;
   cout << "Square Root:" << sqRoot << endl;
   cout << "Precision:" << precision << endl;
   
   return sqRoot;
}

