#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int startFloor,n;
    cin>>startFloor>>n;

    vector<int>lower,upper;
    int near=-1;
    int mindist=1e9+7;
    string startdir;

    for(int i=0;i<n;i++){

        string type,dir;
        int floor;
        cin>>type>>floor>>dir;

        if(floor<startFloor) lower.push_back(floor);
        else if (floor > startFloor) upper.push_back(floor);
        
        int dist=abs(startFloor-floor);
        if (dist<mindist) {mindist=dist;near=floor;startdir=dir;}
    }

    sort(lower.rbegin(),  lower.rend());
    sort(upper.begin(), upper.end());

    if(startdir=="UP"){
        for (int x:upper)cout<<x<<'\n';
        for (int x:lower) cout<<x<<'\n';
    }
    else{
        for (int x:lower)cout<<x<<'\n';
        for (int x:upper)cout<<x<<'\n';
    }


    return 0;
}
