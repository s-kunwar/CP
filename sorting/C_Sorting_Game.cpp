#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s;
        cin >> n >> s;

        int i1=-1,i2=-1;

        for(int i=0; i<n; i++) {
            if(s[i]== '1') {
                i1= i;
                break;
            }
        }
        if (i1==-1) {cout<<"Bob\n";continue;}
            
        for(int j= i1+1; j <n;j++) { if (s[j]=='0') {i2=j;break;} }

        if (i2==-1) {cout<<"Bob\n"; continue;}

        cout<<"Alice\n";
        cout<<2 <<"\n";
        cout<<i1+1<<" " <<i2+1<<"\n"; 
    }

    return 0;
}
