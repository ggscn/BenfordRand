
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>


int count_digits(int n){
    unsigned int number_of_digits = 0;
    
    do{
        ++number_of_digits;
        n/=10;
        
    }while(n);
    return number_of_digits;
}

int test(int argc, const char * argv[]) {
    std::map<int,int> int_map;
    for (int i = 0; i<10;i++){
        int_map[i]=0;
    }
    for(int i = 0; i < 1000000; i++){
        int ran_num = rand();
        for (int p = 0;p<count_digits(ran_num);p++){
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
