#include <iostream>
#include <vector>

using namespace std;

int main(){

    int t;
    vector <int> arr;
    cin>>t;

    for(int x=0;x<t;x++){
        int n;
        cin>>n;
        arr.push_back(n);
    }

    int closest=arr[0];
    for(int num: arr){
        if(abs(num)<abs(closest)){
            closest=num;
        }
    }

    cout<<abs(closest)<<endl;    

    return 0;
}