#include <iostream>
#include <vector>

using namespace std;

/*
find what is the best option for three terms, use the remaining term from these three terms with the next two children in line, also
keep the record of best sum obtained at every step

what im doing

calculating the best step for   a,b,c
which can be
+a+b or +a-c or -b+a or -b-c

at every step i do this, keep record of sum, and remaining element, use this element with d and e in next step

for odd n, whole line can be broken into 3 pairs
for even n, at last there would be 2 children to decide from
*/

int main(){

    int t;
    cin>>t;

    while(t--){

        int n;
        cin>>n;

        vector <long long> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];

        long long sum=0;
        vector <long long> choice(4);

        int r=2;
        long long term0=arr[0];

        while(r<=n){
            if(r==n){
                if(n%2==0){
                    sum=max((sum+arr[r-2]),(sum-arr[r-1]));
                    break;
                }
                else break;
            }

            long long a=term0,b=arr[r-1],c=arr[r];

            choice[0]=a+b;
            choice[1]=a-c;
            choice[2]=a-b;
            choice[3]=-b-c;

            long long bestchoice=max(choice[3],max(choice[2],max(choice[0],choice[1])));

            sum+=bestchoice;

            if(bestchoice==choice[0]) term0=c;
            else if(bestchoice==choice[1]) term0=b;
            else if(bestchoice==choice[2]) term0=c;
            else term0=a;

            r+=2;
        }

        cout<<sum<<endl;

    }
    
    return 0;
}