
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin>>n;

    if(n==0){
        cout<<"zero\n";
        return 0;
    }
    else if(n==1000){
        cout<<"thousand\n";
        return 0;
    }
    else if(n==100){
        cout<<"hundred\n";
        return 0;
    }

    vector<string> below_20={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
    vector<string> tens={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
    std::string result="";   
    if(n>=100){
        result+=below_20[n/100]+" hundred";
        n=n%100;
        if(n!=0) result+=" ";
    }   
    if(n>=20){
        result+=tens[n/10];
        n=n%10;
        if(n!=0) result+=" ";
    }
    if(n>0){
        result+=below_20[n];
    }
    cout<<result<<"\n";
    return 0;
}