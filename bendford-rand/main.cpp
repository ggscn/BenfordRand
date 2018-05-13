#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <cmath>
#include <map>

typedef std::chrono::system_clock Clock;

int ms_time(){
    //Get current time in microseconds
long int micros = static_cast<long int>(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count());
    return abs((int)micros);
}

int time_rand(int min, int max){
    //Generate random number from microsecond time stamps
    int t1 = ms_time();
    int t2 = ms_time();
    int t3 = ms_time();
    int t4 = ms_time();
    int time_rand =(min + (((t1*t2)/t3+t4)) % (int)(max - min + 1));
    return time_rand;
}

double get_probability(double n){
    //Probability a number will exist based on Bendford's law
    if (n == 0.0){
        return 0.12;
    }
    double probability;
    probability = log10(1+(1/n));
    return probability;
}

int randN(int seedSize = 100000){
    unsigned int arr_size = 0;
    
    for (int i = 0; i < 10; i++){
        double probability = get_probability(i*1.0);
        arr_size += (int)((probability*seedSize)+0.5);
        
    }
    
    int array[arr_size];
    int arr_counter = 0;
    for (int i = 0 ; i < 10; i++){
        double probability = get_probability(i*1.0);
        int n_norm_probability = (int)((probability*seedSize)+0.5);
        for (int p = 0; p < n_norm_probability; p++){
            array[arr_counter] = i;
            arr_counter+=1;
        }
    }
    
    int randSizeMin = 1;
    int randSizeMax = 9;
    int randSize = time_rand(randSizeMin,randSizeMax);
    std::string rand_str;
    for (int i = 0; i < randSize;i++){
        int randIndexMin = 1;
        int randIndexMax = arr_size;
        int randIndex = time_rand(randIndexMin,randIndexMax);
        rand_str += std::to_string(array[randIndex]);
    }
    std::cout << rand_str << std::endl;
    int rand = std::stoi(rand_str);
    return rand;
}

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
    
    double seed = 10000;
    std::map<int,int> int_map;
    
    for (int i = 0; i<10;i++){
        int_map[i]=0;
    }
    
    for(int i = 0; i < 10000; i++){
        int ran_num = randN(seed);
        
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
