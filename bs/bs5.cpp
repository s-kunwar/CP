#include <iostream>
#include <vector>
using namespace std;

int min_bs(vector<int> arr, int n);

int main()
{

    // Search in a rotated sorted array for the minimum element(unique)
    vector<int> arr = {7, 8, 9,10, 2, 3, 4, 5, 6};
    int len = arr.size();
    cout << min_bs(arr, len - 1) << endl;

    //With duplicates






    //Find out how many times an array has been rotated(unique)
    //arr={3,4,5,1,2}, the min is 1 at ind=3, therfore arr is rotated 3 times
    vector<int> arr2={3,4,5,1,2};
    cout<<min_bs(arr2,(arr2.size())-1)<<endl;

    //With duplicates


    


    return 0;
}






int min_bs(vector<int> arr, int n){
    //check which side is sorted
    //check if the lowest term of sorted side is less than min, and update min
    //then, eliminate the sorted side
    int l=0,h=n,min=0;

    while(l<=h){
        int m=(l+h)/2;

        //optimization cond(explained below, you can start from the first (else if) too without getting any change in output)
        if((arr[l] < arr[h])&& arr[l]<arr[min]){
            return l;
        }
        else if(arr[m]<arr[min]){min=m;}
        //left is sorted
        else if( (arr[m]-arr[l])>0 ){
            if(arr[l]<arr[min]){min=l;}
            l=m+1;
        }
        //right must be sorted
        else{
            if(arr[m+1]<arr[min]){min=m+1;}
            h=m-1;
        }
    }
    return min;
}

//in case of a remaining arr like 0 1 2 having m=1
//you know that arr[l]<arr[m] and arr[m]<arr[h]
//therfore arr[l]<arr[h], that is the whole arr is sorted from l to h
//So you can just write this optimization condition in the code
/*
        if((arr[l] < arr[h])&& arr[l]<arr[min]){
            return l;
        }
*/