#include <iostream>
#include <vector>
using namespace std;

/*
1:Select min and swap with the right postion
2:Now, the left side array is sorted, so repeat it for right half

if you dont pass and operator in argument, func creates a local copy 
of the array in the stack

TC=Nsq

*/

void selectionsort(vector<int>&arr){

    for (int i=0;i<arr.size()-1;i++){

        int min=i;
        for(int j=i; j<arr.size(); j++){
            if(arr[j]<arr[min]) min=j;
        }

        int temp = arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }

}


int main(){

vector<int>arr={56,4,5,8,2,9};

selectionsort(arr);

for(int x=0; x<arr.size();x++){
    cout<<arr[x]<<' ';
}

return 0;
}