/*
Description: This program deals with linear equations by taking input 
from a user given file and displaying the appropriate result to the console(whether if there is one or not).
*/
#include <iostream>
#include <fstream>

using namespace std;

class LinearEquation
{
   private:
      
      //Private data fields a, b, c, d, e, and f.
      double a,b,c,d,e,f;
   
   public:
      
      //A constructor with the arguments a, b, c, d, e, and f.
      LinearEquation(double,double,double,double,double,double);
   
      //Six get functions for a, b, c, d, e, and f.
      double getA()const;
      double getB()const;
      double getC()const;
      double getD()const;
      double getE()const;
      double getF()const;
   
      //A function named isSolvable() that returns true if ad-bc != 0.
      bool isSolvable();
   
      //Functions getX() and getY() that return the solution for the equation.
      double getX();
      double getY();
};

LinearEquation::LinearEquation(double a,double b,double c,double d,double e,double f)
{
   //cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f<<endl;
   this->a = a;
   this->b = b;
   this->c = c;
   this->d = d;
   this->e = e;
   this->f = f;
}

/*
These methods returns the values of a,b,c,d,e,f.
Precondition: The values must initialized.
*/
double LinearEquation::getA() const 
{ 
   return a; 
}
double LinearEquation::getB() const 
{ 
   return b; 
}
double LinearEquation::getC() const 
{ 
   return c; 
}
double LinearEquation::getD() const 
{ 
   return e; 
}
double LinearEquation::getE() const 
{ 
   return e; 
}
double LinearEquation::getF() const 
{ 
   return f; 
}

/*
Returns if solution is solvable or not.
Precondition: The values must initialized.
*/
bool LinearEquation::isSolvable()
{
   return (((a*d) - (b*c)) !=0);
}

/*
Retrieves the point of intersection.
Precondition: The values must initialized.
*/
double LinearEquation::getX()
{
   return ((f-e)/((a/b) - (c/d)));
}

double LinearEquation::getY()
{
  return (((a/b)*getX())+e);
}

int main()
{
   double x1,x2,x3,x4,y1,y2,y3,y4;//Given user input from file
   double m1,m2;
   
   ifstream file("coords.txt");
   if (file.is_open())
   {
      while(!file.eof())//Reads until end of file
      {
         file>>x1;
         file>>y1;
         file>>x2;
         file>>y2;
         file>>x3;
         file>>y3;
         file>>x4;
         file>>y4;
         
         m1 = ((y2 - y1)/(x2 - x1));//Finds the midpoint
         m2 = ((y4 - y3)/(x4 - x3));
       
         LinearEquation test((y2-y1),(x2-x1),(y4-y3),(x4-x3),(y1-(m1*x1)),(y3-(m2*x3)));
         
         if(test.isSolvable())
         {
            cout<<"Y = "<<(test.getA()/test.getB())<<"x + "<<test.getE() <<endl;//Displays Equation in point slope form.
            cout<<"Y = "<<(test.getC()/test.getD())<<"x + "<<test.getF()<<endl;
            
            cout<<"The solution intersects at: "<<endl;
            cout<<"X = "<<test.getX()<<endl;//Displays point of intersection between the two lines.
            cout<<"Y = "<<test.getY()<<endl;
         }
         else
         {
            cout<<"The solution is parallel and does not intersect."<<endl;
         }
         
         cout<<"----------------------------------------------------"<<endl;
      }
      file.close();
   }
   else
   {
      cout<<"Can't open file"<<endl;
   }
   
   return 0;
}
