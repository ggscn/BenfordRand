#include "benford_rand.hpp"

#include <iostream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <cmath>
#include <algorithm>

class benford_rand{
    
    private:
        int ms_time(){
            //Get current time in microseconds
            namespace c = std::chrono;
            long int nanos = static_cast<long int>(c::duration_cast<c::nanoseconds>(c::high_resolution_clock::now().time_since_epoch()).count());
            return abs((int)nanos);
        }

        int time_rand(int min, int max){
            //Generate random number from microsecond time stamps
            int nanos = ms_time();
            for (int i = 3; i < 10; i++){
                if (nanos % i == 0){
                    return min + (nanos) % (int)(max - min + 1);
                }
                nanos = ms_time();
            }
            
            return min + (nanos) % (int)(max - min + 1);
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
    
    public:
        int rand(int pool_size = 100000){
            unsigned int arr_size = 0;
            
            for (int i = 0; i < 10; i++){
                double probability = get_probability(i*1.0);
                arr_size += (int)((probability*pool_size)+0.5);
                
            }
            
            int array[arr_size];
            int arr_counter = 0;
            for (int i = 0 ; i < 10; i++){
                double probability = get_probability(i*1.0);
                int n_norm_probability = (int)((probability*pool_size)+0.5);
                for (int p = 0; p < n_norm_probability; p++){
                    array[arr_counter] = i;
                    arr_counter+=1;
                }
            }
            std::random_shuffle(&array[0],&array[arr_size]);
            int rand_size_min = 1;
            int rand_size_max = 9;
            int rand_size = time_rand(rand_size_min,rand_size_max);
            std::string rand_str;
            for (int i = 0; i < rand_size;i++){
                int rand_index_min = 1;
                int rand_index_max = arr_size;
                int rand_index = time_rand(rand_index_min,rand_index_max);
                rand_str += std::to_string(array[rand_index]);
            }
            std::cout << rand_str << std::endl;
            int rand = std::stoi(rand_str);
            return rand;
        }
};
