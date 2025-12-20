#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

float station_bf(vector<int>arr,int len,int k);
float optimised_station_bf(vector<int> arr, int len, int k);
float station_bs(vector<int>arr,int len, int k);
int stationspermitted(vector<int>arr,int len,float dist);


int main(){

    //MINIMUM GAS STATION PROBLEM
    /*
    We have a horizontal number line. On that number line,
    we have gas stations at positions stations[0], stations[1], ..., stations[n-1]. 
    Now, we add k more gas stations so that d, the maximum distance between adjacent gas stations,
    is minimized. We have to find the smallest possible value of d. 
    Find the answer exactly to 2 decimal places.
    Note: stations is in a strictly increasing order.

    Examples:

    Input: stations[] = [1, 2, 3, 4, 5], k = 2
    Output: 1.00

    Explanation: Since all gaps are already equal (1 unit each), 
    adding extra stations in between does not reduce the maximum distance.
    
    Input: stations[] = [3, 6, 12, 19, 33], k = 3
    Output: 6.00

    Explanation: The largest gap is 14 (between 19 and 33). 
    Adding 2 stations there splits it into approx 4.67. 
    The next largest gap is 7 (between 12 and 19). 
    Adding 1 station splits it into 3.5. Now the maximum gap left is 6.
    

    SOLUTION___________________________________________________________________

    Brute Forces-

    *You will always place new stations in between two already existing ones to minimise gap, 
    not on leftmost or rightmost side

    for k iterations do this
    -first find the gaps between all gas stations, take the largest gap, place a gas station there, update the new gap
    -keep a count of total stations placed at each gap
    -after all k iterations, use the station count at each gap to find the final max value
    */

    vector<int> arr = {3, 6, 12, 19, 33};

    cout<<station_bf(arr,arr.size(),4); //brute force

    //Optimised using priority queue (you keep gaps and ind in priority que, take out the top max gap ind and add a station to its station count)
    cout<<endl<<optimised_station_bf(arr,arr.size(),5);


    //Binary Search(This is a different kind, were we use low=mid and high=mid)
    cout<<endl<<station_bs(arr,arr.size(),5);


    return 0;
}




float station_bf(vector<int> arr,int len, int k){
    float gap=0;
    int maxgapind=0;
    vector <int> gapatstn(len-1,0); //keeping count of stations at all gaps

    while(k--){
        for(int x=0;x<len-1;x++){
            gap=(arr[x+1]-arr[x])/(float)(gapatstn[x]+1); //if orginal was 6, and there are 2 more staions in between, then the difference will be 6/(3extra gaps in between the orginal gap)
            cout<<gap<<',';
            if( gap > (arr[maxgapind+1]-arr[maxgapind])/(float)(gapatstn[maxgapind]+1) ){
                maxgapind=x;
            }  
        }
        gapatstn[maxgapind]++;
        cout<<endl;
    }

    //finding the resultant max gap
    maxgapind = 0;
    for(int x=0;x<len-1;x++){
        gap=(arr[x+1]-arr[x])/(gapatstn[x]+1); 
        if( gap >= (arr[maxgapind+1]-arr[maxgapind]) ){
            maxgapind=x;
        }  
    }

    return (arr[maxgapind+1]-arr[maxgapind])/(float)(gapatstn[maxgapind]+1);
}


//--------------------------------------------------------------------------


float optimised_station_bf(vector<int> arr, int len, int k){
    vector <int> gapatstn(len-1,0);
    priority_queue < pair<float,int> > gaps;

    //adding data to priority queue
    for(int x=0;x<len-1;x++){
        gaps.push( {arr[x+1]-arr[x],x} );
    }
    //actual solution
    int gasstnind = 0;
    while(k--){
        auto top=gaps.top(); //Store the top gap so we can use it, remove it so we can then update it
        gaps.pop();
        gapatstn[top.second]++;

        float gap=(arr[(top.second)+1]-arr[top.second])/(float)(gapatstn[top.second]+1);
        gaps.push({gap,top.second});
    }

    return gaps.top().first;
}


//----------------------------------------------------------------------



float station_bs(vector<int> arr, int len, int k){
    float mindist=1e-6;
    //answer limit will be from (0,maxgap], finding maxgap
    float maxgap=0;
    for(int x=0;x<len-1;x++){
        float gap=(arr[x+1]-arr[x]);
        maxgap=max(maxgap,gap);
    }
    //binary search
    float l=0,h=maxgap,ans;
    while((h-l)>mindist){
        float mid=(l+h)/2.00;
        int stn=stationspermitted(arr,len,mid);

        if(stn>k){
            l=mid;
        }
        else{
            h=mid;
        }
    }
    
    return h;
}

int stationspermitted(vector<int>arr,int len,float dist){
    float current_stn=0;
    int stn=0;

    for(int x=0; x<len-1; x++){
        float gap=arr[x+1]-arr[x];
        current_stn = gap / dist;

    int needed = floor(gap / dist);
    if (fabs(fmod(gap, dist)) < 1e-6) needed--;

        stn+=current_stn;
    }

    return stn;
}