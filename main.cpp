#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    std::cin>>test;
    std::string str;

    while (test--){
        std::getline(std::cin >> std::ws , str);
        int pos=0;

        for (int i=0; i<str.length(); i++){
            if (str.at(i)==' ' || i==(str.length()-1) ){
            
                for (int x=pos; x<i; x++){
                    if ( str.at(x)==toupper(str.at(x)) ){continue;}
                    else{
                        for (int y=pos; y<i; y++){str.at(y)=tolower(str.at(y));}
                    }
                }

                if (str.at(pos)==toupper(str.at(pos)) && str.at(pos+1)==toupper(str.at(pos+1)) ) { pos=i+1; }
                else {
                    str.at(pos)=toupper(str.at(pos));
                    pos=i+1;
                }



            }
        }
        std::cout<<str<<'\n';

    }
        
}

        

