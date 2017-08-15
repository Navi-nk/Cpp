//problem:
// Given 6x6 2d array, we define a hourglass as
//  a b c
//    d
//  e f g
//So in a array of 6x6 we have 16 hourglasses. find the hourglass which has max sum, where sum is found by adding all values present in the hourglass

// ex:
// 1 1 1 0 0 0
// 0 1 0 0 0 0
// 1 1 1 0 0 0
// 0 0 2 4 4 0
// 0 0 0 2 0 0
// 0 0 1 2 4 0

//max is 2 4 4
//         2
//       1 2 4
// = 19


#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

int main(){
    vector< vector<int> > arr(6,vector<int>(6));
    int r_offset=0,c_offset=0;
    int hourGlassSum=0,compSum=0;
    //store 6x6 array
    for(int arr_i = 0;arr_i < 6;arr_i++){
       for(int arr_j = 0;arr_j < 6;arr_j++){
          cin >> arr[arr_i][arr_j];
       }
    }

    // consider the row offset and column offset of 4 each then traverse the array using this offset. Basically dividing the entire array into sections of 4x4 then finding the sum.
        while(r_offset<4)
        {
            c_offset=0;
            while(c_offset<4)
            {
                compSum=0;
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        if((i!=1 || j!=0) && (i!=1 || j!=2)) // ignore a[1][0] and a[1][2] (consider only neck of hourglass)
                        compSum+= arr[i+r_offset][j+c_offset];   
                    }
                    
                }
               
                if(compSum >= hourGlassSum || (c_offset == 0 && r_offset == 0 ))
                    hourGlassSum = compSum;
                
                c_offset++;
            }
            r_offset++;
        }
        cout<<hourGlassSum;
    
    return 0;
}
