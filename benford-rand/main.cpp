#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <map>
#include "benford_rand.cpp"



int count_digit(int n){
    
    unsigned int number_of_digits = 0;
    
    do{
        ++number_of_digits;
        n/=10;
        
    }while(n);
    return number_of_digits;
     
    return 1;
}



int main(int argc, const char * argv[]) {
    
    int seed = 10000;
    benford_rand b_rand;
    std::map<int,int> int_map;
    
    for (int i = 0; i<10;i++){
        int_map[i]=0;
    }
    
    for(int i = 0; i < 10000; i++){
        int ran_num = b_rand.rand(seed);
        
        for (int p = 0;p<count_digit(ran_num);p++){
            int div_num = pow(10,p);
            int n = (ran_num / div_num)  % 10;
            int_map[n]+=1;
        }
    }
    
    for (int i = 0; i<10;i++){
        std::cout << "Digit: " << i << " Count: " << int_map[i] << std::endl;
    }
    
    return 0;
}
