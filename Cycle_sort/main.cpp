#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void cycleSort(std::vector<T> &t_array){
    T tmpVal;
    int index;
    std::vector<T> cycles = {};
    for(unsigned int i = 0; i<t_array.size(); ++i){

        std::vector<T> cycles = {};
        index = i;
        tmpVal = t_array[i];

        do{
            cycles.push_back(tmpVal);
            index = std::count_if(t_array.begin(), t_array.end(), [tmpVal, t_array,i](T b){
                return (tmpVal>=b);
            })-1;

            if(tmpVal < t_array[i]){
                ++index;
            }

            T tmpVal2 =  t_array[index];
            t_array[index] = tmpVal;
            tmpVal = tmpVal2;

        }while ((unsigned int)index != i);

        if(cycles.size()>1){
            std::cout <<"cycle { ";
            for(unsigned int i = 0; i<cycles.size(); ++i){
                std::cout << cycles[i] <<" ";
            }
            std::cout <<"} "<<std::endl;
        }
    }
}

int main()
{
    std::vector<int> arr = { 333,98, -1, 44, 7, 99, 2, 1000, 45, 1, 100};

    cycleSort<int>(arr);

    for(unsigned int i = 0; i<arr.size(); ++i){
        std::cout << arr[i] << std::endl;
    }

    return 0;
}
