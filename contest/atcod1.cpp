#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h,w;
    cin>>h>>w;

    for (int i=0;i<h;i++){
        for (int j=0;j<w;j++){
            if(i==0 || i==h-1 || j==0 || j==w-1){
                cout << "#";
            } else {
                cout << ".";
            }
        }
        cout << endl;
    }


    return 0;
}