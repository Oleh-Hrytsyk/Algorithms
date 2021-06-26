#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void cycleSort(std::vector<T> &t_array){

    T currElement;
    int pos;

    for(unsigned long outerIndex = 0; outerIndex < t_array.size()-2; ++outerIndex ){

        currElement = t_array[outerIndex];

        pos = outerIndex + std::count_if(t_array.begin()+outerIndex+1, t_array.end(), [&currElement](T arrElement) -> bool{
            return currElement>arrElement;
        });

        if(currElement>t_array[outerIndex]){
            --pos;
        }

        if(pos == outerIndex){
            continue;
        }

        while (currElement == t_array[pos]) {
            ++pos;
        }

        if(pos != outerIndex){
          std::swap(currElement, t_array[pos]);
        }

        while(pos != outerIndex){
            pos = outerIndex + std::count_if(t_array.begin()+outerIndex+1, t_array.end(), [&currElement](T arrElement) -> bool{
                return currElement>arrElement;
            });

            if(currElement > t_array[outerIndex]){
                --pos;
            }
            while (currElement == t_array[pos]) {
                ++pos;
            }
            if(currElement != t_array[pos]){
                std::swap(currElement, t_array[pos]);
            }
        }
    }
}

int main()
{
    std::vector<int> arr = { 11, 5, 8, 2, 14, 14, -1, 2, 7, 3, 2, 2, 2};

    cycleSort<int>(arr);

    for(unsigned int i = 0; i<arr.size(); ++i){
        std::cout << arr[i] << std::endl;
    }

    return 0;
}
