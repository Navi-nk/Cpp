//Given an array of n integers and a number,d, perform d left rotations on the array. Then print the updated array as a single line of space-separated integers.
//ex : 5 4
//     1 2 3 4 5

//	   5 1 2 3 4	


#include <vector>
#include <iostream>
using namespace std;


int main() {
    int n=0,d=0;
    cin>>n;
    vector<long> a(n);
    cin>>d;
    
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //for d lefts to be done, each index can be written as (i+d)%n ex- if n is 5 and d is 4 means the 4th index(startin from 0) needs to be shown in 0th index. 
    //apply mod n to achieve circular shift of n
    for(int i=0;i<n;i++){
        cout<<a[(i+d)%n]<<" ";
    }
    
    return 0;
}
