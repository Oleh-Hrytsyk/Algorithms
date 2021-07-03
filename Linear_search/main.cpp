#include <iostream>

using namespace std;

template<typename T>
int linearSearch(const T* t_arr, size_t t_size, T t_target_element){
    for(size_t i = 0; i < t_size; i++){
        if(t_arr[i] == t_target_element){
            return i;
        }
    }
    return -1;
}


int main()
{
    float arr[3] = {1.2, 2.3, 3.4};
    cout << linearSearch<float>(arr, 3, 2.3) << endl;
    return 0;
}
