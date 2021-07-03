#include <iostream>

using namespace std;

template<typename T>
int binarySearch(const T* t_array, size_t t_size, T t_target_element){
   int left = 0, right = t_size - 1;
   int mid = 0;
   while (left <= right) {
        mid = left + (right - left) / 2;
        if(t_target_element > t_array[mid]){
            left = mid + 1;
        }
        else if(t_target_element < t_array[mid]){
            right = mid - 1;
        }
        else{
             return mid;
        }
   }
   return -1;
}


int main()
{
    int arr[6] = {1, 4, 5, 7, 10};
    cout << binarySearch(arr, 5, 10) << endl;
    cout << binarySearch(arr, 5, 7) << endl;
    cout << binarySearch(arr, 5, 5) << endl;
    cout << binarySearch(arr, 5, 4) << endl;
    cout << binarySearch(arr, 5, 1) << endl;
    cout << binarySearch(arr, 5, 99) << endl;
    cout << binarySearch(arr, 5, -99) << endl;


    return 0;
}
