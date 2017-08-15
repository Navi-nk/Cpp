//Problem :
//First input is two integers n,m. Next m input will contain three integers a,b,k
//numbers in list are from 1 to n. you have to add value k to all the elements ranging from index a to b (both inclusive)
//Then at end find the max value of the list

//Ex: 5 3
//1 2 100
//2 5 100
//3 4 100

//After first update list will be 100 100 0 0 0.
//After second update list will be 100 200 100 100 100.
//After third update list will be 100 200 200 200 100.
//So the required answer will be 200.

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main() {
    long int n;
    long int m;
    long int temp=0,max=0;
    cin >> n >> m;

    vector<long int> list(n,0);
    for(long int i = 0; i < m; i++){
        long int a, b, k;

        cin >> a >> b >> k; 

            //instead of adding values to each element in the range of a to b. just add a value +k in the beginning of the list
            //and a value -k at the end of the list.
            //this way we can easily identify the overlapping sections 

            list[(a-1)] += k;
            list[b] -= k; 
    }
    for(long int j = 0; j < n; j++){
        //when we keep adding the each values in the list, The overlapping sections will have sums increase later will reach a max and then start decreasing(because of - values).
        temp += list[j];
        //we have to store largest peak values through out the traversal, this is because we can have localised overlapping sections and there might many number of these sections. 
        if(max < temp){
            max = temp;
        }

    }
    cout<< max;
    return 0;
}
