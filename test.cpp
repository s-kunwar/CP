#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include <climits>


int main(){

    int n,k;
    int ind=0;
    cin >>n>>k;

    map<int,int> forbs(n);
    int one_count=0;
    int min=INT_MAX;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        forbs[temp]++;
        if(forbs[i]==1) one_count++;
        min=std::min(min,forbs[i]);
    }
    if(one_count>0){
        cout << -1 << endl;
        return 0;
    }

    
    int count=0;

    if(min>k){
        cout<<k<<endl;
        return 0;
    }

    k-=min-1;

    /*
    for(int i=min;i<=10e9;i++){
        bool is_safe=true;
        for(int j=0;j<n;j++){
            if(i%forbs[j]==0){
                is_safe=false;
                break;
            }
        }
        if(is_safe){
            count++;
            if(count==k){
                cout<<i<<endl;
                return 0;
            }
        }
    }
    */
    /*
     
    */

    
    cout<<-1<<endl;

    return 0;
}