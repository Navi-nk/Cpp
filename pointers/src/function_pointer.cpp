#include <iostream>
#include <string.h>
#include <malloc.h>

using namespace std;

/*Pointer to pointer to character*/
char **a;
char **b;

/*function returning pointer to character pointer*/
char** test()
{
    
    a=new char*[10]; //Allocating 10 character memory locations on heap  - a will hold starting address of 10 char locations 
    for(unsigned int i = 0; i < 10; i++){
        
        a[i]=new char[strlen("Arya Noone ")]; // To the location pointed by a[i], a new memory location is assigned that will point to characters of size of "Arya Noone" + 1 (extra one memory space for storing terminating null character)
         
        strcpy(a[i],"Arya Noone"); //Copy value "Zara Ali" to the location pointed by a[i]
   }
    
    return a;
}

/*function returning pointer to character pointer*/
char** test1()
{
    b=new char*[10]; //Allocating 10 character memory locations on heap to pointer b - b will hold address of 10 char locations
    for(unsigned int i = 0; i < 10; i++){
        b[i]=new char[strlen("Snows Nothing ")]; // To the location pointed by b[i], a new memory location is assigned that will point to characters of size of "Snows Nothing" + 1 (extra one memory space for storing terminating null character)
        strcpy(b[i],"Snows Nothing"); //Copy value "Aravind anurag" to the location pointed by b[i]
   }
    
    return b;
}

int main()
{
    char **var;
  
  //char *(*(**foobar[][8])())[]={0};
  
   char** (**foobar)()={0}; //pointer to function pointer returning pointer to character pointer
  
   foobar=(char** (**)())malloc(sizeof(*foobar)*2); //allocate dynamic memory of size 2 * size of foobar
   
   foobar[0]=&test; //assign address of function test to foobar[0]
  *(foobar+1)=&test1; //assign address of function test1 to second location of foobar
  
   var=(*foobar)(); //function call to test using foobar
   cout<<var[2]<<endl; //print value returned by above call - Arya Noone
  
   
   var=(foobar[1])(); //function call to test1 using foobar
   cout<<var[2]<<endl; //print value returned by above call - Snows Nothing
   
   /*Clean memory allocated to a,b and foobar*/
   for(unsigned int i = 0; i < 10; i++)
   {
	     delete a[i];
       delete b[i];
   }
   delete[] a;
   delete[] b;
   
   free(foobar);
   
   return 0;
}

