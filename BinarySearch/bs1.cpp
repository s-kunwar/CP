#include <iostream>
#include <vector>
using namespace std;

int i_bs(vector<int>arr,int n, int target);
int r_bs(vector<int>arr, int target, int l, int h);

int main()
{
    //BINARY SEARCH ( TC= O( log2(n) ) )
    vector<int> arr = {1, 5, 6, 8, 10, 13, 20, 24}; //len=8
    int len=arr.size();
    int target = 24;
    

    cout<< i_bs(arr,len-1,target) <<'\n';//iterative search
    cout<< r_bs(arr,target,0,len-1);//recursive search

    return 0;
}

int i_bs(vector<int>arr,int n, int target)
{
    int l=0,h=n;
    while(l<=h){
        int m=(l+h)/2;
        if(l==h){return m;}
        else if(arr[m]<target){l=m+1;}
        else{h=m-1;}
    }
    return -1;
}

int r_bs(vector<int>arr, int target,int low, int high){

    int l=low,h=high;
    if(l>h){return -1;}

    int m=(l+h)/2;

    if(l==h){return m;}
    else if(arr[m]<target){
        return r_bs(arr,target,m+1,h);
    }
    else{
        return r_bs(arr,target,l,m-1);
    }

}