/*
*This program handles input from a text from using a dynamic 2d array.
*/
void locateLargest(double ** matrix, int n, int m, int rowCol[] );

#include <iostream>
#include <fstream>
using namespace std; 
int main()
{
 
   int n = 3,m = 4;

   double **a = new double*[n]; 

   int i,j;
   
   for(i=0; i < n; i++) 
   {
      a[i]= new double[m];
   }
   
   ifstream file("matrices.txt");
   
   if (file.is_open())
   {
      for(i=0; i < n; i++) 
      {
         for(j=0; j < m; j++) 
         {
            file>>a[i][j];
         }
      }
   
      for(i=0; i < n; i++) 
      {
         for(j=0; j < m; j++) 
         {
            cout<<a[i][j]<<" ";
         }
         cout<<endl;
      }
      
      int rowCol [2]= {0,0};
      
      locateLargest(a,n,m,rowCol);
  
      cout<<"The largest element is "<< a[rowCol[0]][rowCol[1]]<<" at location ("<<rowCol[0]<<", "<<rowCol[1]<<")" <<endl;
   }
   
   file.close();
   
   for(i = 0 ; i < n ; i++)
   {
      delete a[i];
   }
   
   delete []a;
   
   
 return 0;

}
/*
This method locates the position of the last occurence of the largest value.
*/
void locateLargest(double ** matrix, int n, int m, int rowCol[] )
{
   double tmp =0;
   int i,j;
   
   
   tmp = matrix[0][0];
   
   for(i=0; i < n; i++) 
   {
      for(j=0; j < m; j++) 
      {
         if(matrix[i][j] >= tmp)
         {
            rowCol[0]=i;
            rowCol[1]=j;
         }
      }
   }
      
   
}


  