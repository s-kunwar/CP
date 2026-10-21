#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int squaresum(int n){
    ll sum=0;
    while(n!=0){
    sum+=(n%10)* (n%10);
        n=n/10;
    }
    return sum;
}

int thenightwemet(int n){
    int cycle[8 ] = { 4, 16, 37,58, 89,145 ,42 ,20};
    int daysgoneby=0;

    while(n!= 1) {
        int phase= -1;
        for(int i=0;i<8;i++){
            if(n == cycle[i]){
                phase=i;
                break;
            }
        }
        if(phase!=-1){
            int thenight=( phase-daysgoneby ) % 8;
            if(thenight<0) thenight += 8;
            return thenight;
        }
        n=squaresum(n);
        daysgoneby++;
    }
    return 8;//for numbers that end in 1
}


void updatevals(vector<int>& newarr){
    for(auto &val:newarr){
        val=thenightwemet(val);
    }
}

int checkpairs(vector<int> newarr){
    sort(newarr.begin(), newarr.end());
    ll pairs=0,crtstreak=1;

    for(int i=1; i<newarr.size(); i++){
        if(newarr[i] == newarr[i-1]) { crtstreak++;}
        else{ pairs+=crtstreak*(crtstreak-1)/2; crtstreak=1;}
    }
    pairs += crtstreak*(crtstreak-1)/2;
    return pairs;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>arr(n);
        for(int i=0;i<n; i++){cin>>arr[i];}
        vector<int>newarr = arr;

        updatevals(newarr);
        int pairs=checkpairs(newarr);
        cout<<pairs<<endl;
    }
    return 0;
}