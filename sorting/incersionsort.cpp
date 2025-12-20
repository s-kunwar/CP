#include <iostream>
#include <vector>
using namespace std;

/*
arr  = 2 8 5 3 9 4

take 2, place it on the correct postion on left side
-2 8 5 3 9 4
take 8, place it on the correct postion on left side
-2 8 5 3 9 4
take 5, place it on the correct postion on the left side
-2 5 8 3 9 4

note that when you take any element j, terms on its left that from
0to(j-1) terms will be sorted.
eg::
if j=5, then 0to4 are already sorted
so lets say after you swapped 5 with 4th element, and find that the 
3rd < 4rth element already, that means this step is done now, as everything
on the left will be sorted too
*/

void incersionsort(vector<int>&arr){

    for(int x=0; x<arr.size(); x++){
        int j=x;
        while(j>0 && arr[j]<arr[j-1]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }

}

int main(){
vector<int>arr={56,4,5,8,2,9};

incersionsort(arr);

for(int x=0; x<arr.size();x++){
    cout<<arr[x]<<' ';
}

return 0;
} 