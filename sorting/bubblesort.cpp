#include <iostream>
#include <vector>
using namespace std;

/*

TC=Ns
arr=5 4 3 8

swap 5 4
- 4 5 3 8
swap 5 3
- 4 3 5 8
swap 5 8
-4 3 5 8

after one complete cycle form 0to3 ind, we know last element(n-1)
will be at its right position
so we repeat the process for 0to2ind
...
at last 0to1 ind

*/

void bubblesort(vector<int>&arr){
    //(best case tc=N, worst case tc=Nsq)
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int sorting_required=0;
        for(int j=0; j<arr.size()-i-1; j++){
        
            if(arr[j+1]<arr[j]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                sorting_required=1;
            }
        }
        if(sorting_required==0) break;
    }  


/* 
    //Without any condition to see if you actually need sorting(best case tc=Nsq, worst case tc=Nsq)

    for (int i=0;i<arr.size()-1;i++){

        for(int j=0; j<arr.size()-i-1; j++){
        
            if(arr[j+1]<arr[j]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }

        }

    }
*/

}


int main(){

vector<int>arr={56,4,5,8,2,9};

bubblesort(arr);

for(int x=0; x<arr.size();x++){
    cout<<arr[x]<<' ';
}

return 0;
}