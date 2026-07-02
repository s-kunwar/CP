#include <iostream>
#include <vector>
using namespace std;


int lb(vector<int>arr,int n,int target);
int up(vector<int>arr,int n,int target);


int main()
{
    //LOWER BOUND( lowest ind for which arr[ind] >= x(any target) )
    //UPPER BOUND( lowest ind for which arr[ind] >  x(any target) )

    vector<int>arr={1, 5, 6, 8, 10, 13, 20, 24}; //len=8
    int len=arr.size(),x=13; //for x=11 it is ind=5, for x=9, its ind=4, for 30 its hypothetical ind=8

    cout << lb(arr,len-1,x)<<'\n';
    cout << up(arr,len-1,x)<<'\n';

    

    return 0;
}

int lb(vector<int>arr,int n,int target)
{
    int l=0,h=n;
    int ind=n+1; //Last case scenario is n+1=len of array

    while(l<=h){
        int m=(l+h)/2;

        if(arr[m]>=target){
            ind=m;
            h=m-1;
        }
        else{
            l=m+1;
        }
    }
    return ind;
}

int up(vector<int>arr,int n,int target)
{
    int l=0,h=n;
    int ind=n+1; //Last case scenario is n+1=len of array

    while(l<h){
        int m=(l+h)/2;

        if(arr[m]>target){
            ind=m;
            h=m-1;
        }
        else{
            l=m+1;
        }
    }
    return ind;
}
