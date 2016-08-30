#include <iostream>

using namespace std;

int main()
{
    
   int a[10][10]={0}; //Two dimensional array of size 10 * 10 = 100 int(4 bytes in this case) memory location
   
   int* a1=&a[0][0]; // pointer to an integer which is initialized to address of a[0][0]
   
   int **a2=new int*[3]; //pointer to pointer to an integer which is allocated memory on the heap having the size of 3 integers
  
   /*The three pointers are assigned with address of first three integers of multidimentional array a respectively */
   a2[0]=&a[0][0]; 
   a2[1]=&a[0][1];
   a2[2]=&a[0][2];
   
   /* Both couts print the address values 2-d array a as assigned above*/
   cout<<a2[0]<<' '<<a2[1]<<' '<<a2[2]<<endl; //ex - 0x7fff3d70ed20 0x7fff3d70ed24 0x7fff3d70ed28 
   cout<<*a2<<' '<<*(a2+1)<<' '<<*(a2+2)<<endl;
   
   for (int i=0;i<3;i++)
   *a2[i]=i*101;   //values 0,101,202 are assigned to locations pointed by a2[i] which is a[0][0],a[0][1] & a[0][2] 
   
   a[0][9]=25;
 
 /* Will print 25*/
   cout<<a[0][9]<<endl; 
   cout<<a1[9]<<endl;
   cout<<*(a1+9)<<endl;
   
   a1[9]=3456;
   
   /* Will print 3456*/
   cout<<a[0][9]<<endl;
   cout<<a1[9]<<endl;
   cout<<*(a1+9)<<endl;
   
  // delete a2;
 
 /* Will print 0 101 102 */
   cout<<a[0][0]<<' '<<a[0][1]<<' '<<a[0][2]<<endl;
   cout<<*a2[0]<<' '<<*a2[1]<<' '<<*a2[2]<<endl;
   cout<<*(*a2)<<' '<<*(*a2+1)<<' '<<*(*a2+2)<<endl;
   
   delete a2; //clean up dynamic memory 
   
   return 0;
}