#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x,y;
    cin>>x>>y;

    if(y<=x){
        cout<<0<<endl;
    }
    else{
        cout<<100<<endl;
    }

    return 0;
}