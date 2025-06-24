#include <bits/stdc++.h>
#include <iostream>

int main() {
    int test;
    std::cout<<'.';
    std::cin>>test;

    std::string hidden;
    std::string guess;
   

    while (test--){
        
        std::cin>>hidden;
        std::cin>>guess;

        for (int x=0; x<5; x++){
            if (hidden.at(x)==guess.at(x)){
                std::cout<<'G';
            }
            else{
                std::cout<<'B';
            }
        }
        std::cout<<'\n';

    }

}
