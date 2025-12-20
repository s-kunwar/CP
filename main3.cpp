#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int even_len=0, odd_len=0;

    for(int i=0;i<n;i++){
        int num=arr[i];
        int sum=0;
        while(num){
            sum+=num%10;
            num/=10;
        }
        if(sum%2==0){
            even_len=max(even_len, odd_len+1);
        }
        else{
            odd_len=max(odd_len, even_len+1);
        }
    }

    cout<<max(even_len, odd_len)<<endl; 


    return 0;
}