#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int peak_bs(vector<int>arr,int len);
int nroot_bs(int n, int m);

int main()
{
    //FIND ANY PEAK ELEMENT (element n which is greater than element n-1 and element n+1)
    vector<int>arr={1,10,13,7,6,5,4,2,1,0};
    //you can plot these points on graph to better visualize the slope,peak
    /*
    here,it increases from 1to13 reaching peak 13, then decreases linearly from 13,7,6,5,4,2,1,0
    since its somewhat sorted,we can implement bs

    >-1 and nth index is taken as -infinity, so the first element is always 
    greater than the left element and the last element is always greater than its
    imaginary right side value

    >we write seperate cond for 1st and last to make bs without exceptions
    
    >For Bs
    case 1: if arr[m]>arr[m-1] && arr[m]>arr[m+1], then m is the peak
    case 2: if arr[m]>arr[m-1] && arr[m]<arr[m+1], then m lies on the increasing graph line
            therefore, the peak will be on the right side of m, hence eleminate the left side of arr
    case3: if arr[m]<arr[m-1] && arr[m]>arr[m+1], then m lies on the decreasing graph line
            therefore, the peak will be on the left side of m, hence eleminate the right side of arr
    case 4: is arr[m]<arr[m+1] && arr[m]<arr[m-1], then m is the trough of the graph
            therefore you will find peak on either sides of m, you can eliminate any side of arr
    */
    int len=arr.size();
    cout<<peak_bs(arr,len);


    //************************************************************************************ 


    //FIND THE NTH ROOT OF AN INTEGER
    /*
    4rth root of 8 is 2 because 8=2*2*2*2
    4rth root of 81 is 3 bcz 81=3*3*3*3
    for an integer n, mth root is a number x such that pow(x,m)=n
    */
    cout<<'\n'<<nroot_bs(121,2);


    return 0;

}



int peak_bs(vector<int> arr, int len){
    int l=1,h=len-2; //leaving the first and last element
    
    if(arr[0]>arr[1]){return 0;}
    else if(arr[len-1]>arr[len-2]){return len-1;}
    
    while(l<=h){
        int m=(l+h)/2;

        if(arr[m]>arr[m-1] && arr[m]>arr[m+1]){return m;}
        else if(arr[m]>arr[m-1] && arr[m]<arr[m+1]){
            l=m+1;
        }
        else if(arr[m]<arr[m-1] && arr[m]>arr[m+1]){
            h=m-1;
        }
        else{
            l=m+1; //choose any left or right (both sides you'll find a peak)
        }
    }
    return -1;
}



int nroot_bs(int n, int m) {
    if (n == 0 || n == 1) //edge case
        return n;

    int l = 1, h = n;

    while (l <= h) {
        int mid = l + (h - l) / 2; //prevent intmax overflow

        //since nums like 10pow8 can give really really large vals for pow(10pow4,expo), we break once we know its not the ans
        long long power = 1;
        for (int i = 0; i < m; i++) {
            power *= mid;
            if (power > n) break;  // prevent overflow
        }

        if (power == n)
            return mid;
        else if (power > n)
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1; // not found (if n isn't a perfect m-th power)
}