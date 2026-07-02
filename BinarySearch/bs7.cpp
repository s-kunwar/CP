#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int hours(vector<int>arr,int len,int speed);
int koko_bs(vector<int>arr,int len,int limit);
int kth_bs(vector<int> arr, int len, int missing);

int main()
{
    //KOKO EATING BANANAS

    /*koko has piles of bananas,she can only eat one pile at a time,a fixed speed of bananas eating per hour, she has to find the minimum number 
    of speed required to eat all piles within the time limit
    arr={3,6,7,11} and h=8
    so she has to complete all piles within 8 hours
    if her speed is 3bananas/hour, 1st pile take 1 hour,2>2h,3>3h,4>4hours, total of 10 hours
    for 4Bananas/hour, time will be 1+2+2+3=8 hours which is the minimum speed
    */

    vector<int>arr={3,6,7,11};
    cout<<koko_bs(arr,arr.size(),1);



    //**************************************************************************************



    //Kth missing value
    /*
    in this array missing values are 1,5,6,8,9,10
    you have to find the k=5th missing value
    so ans is 9

    for every num, know how many missing values are before it
    for arr[i] there are (arr[i]-(i+1)) missing values
    i.e the order of missing values are 1 1 1 3 6
    i.e, before 2 (1 value is missing = 1), before 3(1 value is missing = 1), before 4(1 value is missing=1)
    before 7(3 values are missing=1,5,6),before 11( 6 values are missing=1,5,6,8,9,10)

    for 1 1 1 3 6 we perform bs to find the final range of our answer, i.e we need 5th missing, so the final
    range is 3-6

    from 3 we need the next ((5-3)th) value, i.e ans is ( arr[i corresponding to 3]+ (5-3) )
    ans= arr[h]+(k-missed_before_h)
       = arr[h]+(k-(arr[h]-h-1)) ****
       = k+h+1 
    */
    vector<int> arr2 = {2, 3, 4, 7, 11};
    cout<<endl<<kth_bs(arr2,arr2.size(),5);


    return 0;
}

int hours(vector<int>arr,int len,int speed){
    int hour=0;
    for(int x=0; x<len; x++){
        if( arr[x]%speed != 0 ){ hour+=(arr[x]/speed)+1; }
        else{ hour+=(arr[x]/speed);}
    }
    return hour;
}

int koko_bs(vector<int> arr, int len, int limit){
    int l=1,h=arr[-1],time;
    //initially l is not possible value, and h is a possible value
    if(limit<len){return -1;}
    while (l<=h){
        int mid=(l+h)/2;
        time=hours(arr,len,mid);

        if(time>limit){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }

    return l;
}



int kth_bs(vector<int> arr, int len, int missing){

    int l=0,h=len-1;

    while(l<=h){
        int mid=(l+h)/2;
        int missed=arr[mid]-(mid+1);

        if(missed==missing){
            return (arr[mid]-1);
        }
        else if(missed<missing){
            l=mid+1;
        }
        else{
            h=mid-1;
        }
    }

    return missing+h+1;
}
