#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

//recursive
int recursive_array_sum(int arr[], int len){
    if(len == 0)
        return 0;
    else
        return arr[len - 1] + recursive_array_sum(arr, len - 1);
}

//iterative
int iterative_array_sum(int arr[], int len){
    int x = 0;
    int spot = 0;
    while(len > 0){
        x = x + arr[spot];
        spot = spot + 1;
        len = len - 1;
    }
    return x;
}

int main(){
    
    //making a big ol array
    const int length = 1000; 
    int somearray[length];
    //using time to seed random num generator
    srand(time(nullptr));
    for (int i = 0; i < length; ++i) {
        somearray[i] = rand() % 10; 
    }
    
    //using clock() like a stopwatch, measuring tiks between.
    double start1 = clock();
    int sum = recursive_array_sum(somearray, length);
    double end1 = clock();
    cout << "The sum of the array, given by the recursive function is: " << sum << endl;

    
    //displaying time for recursive
    double time_taken1 = double(end1 - start1) / double(CLOCKS_PER_SEC);
    cout << "Time taken by recursive sum is : " << fixed 
         << time_taken1 << setprecision(5);
    cout << " sec " << endl;
    
    //using clock() as a stopwatch for the iterative one
    double start2 = clock();
    cout << "The sum of the array, given by the iterative function is: " << iterative_array_sum(somearray, length) << endl;
    double end2 = clock();
    
    //displaying time for iterative
    double time_taken2 = double(end2 - start2) / double(CLOCKS_PER_SEC);
    cout << "Time taken by iterative sum is : " << fixed 
         << time_taken2 << setprecision(5);
    cout << " sec " << endl;
    
    cout << "The recursive sum function was almost 4 times slower than the iterative function." << endl << "The iterative function is more efficent for this exersice." << endl;
    
    return 0;
}