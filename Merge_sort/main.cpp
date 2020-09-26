#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> merge(vector<T> l_arr, vector<T> r_arr) {
    vector<T> result;
    T* left=&l_arr[0];
    T* right = &r_arr[0];
    T* left_end = &l_arr[l_arr.size()-1];
    T* right_end = &r_arr[r_arr.size() - 1];
    while (result.size()<(l_arr.size()+r_arr.size()))
    {
        if (left == nullptr) {
            result.push_back(*right);
            if (right != right_end)
                right++;
            else
                right = nullptr;
            continue;
        }
        else if (right == nullptr) {
            result.push_back(*left);
            if (left != left_end)
                left++;
            else
                left = nullptr;
            continue;
        }
        if (*left>*right)
        {
            result.push_back(*right);
            if (right != right_end)
                right++;
            else
                right = nullptr;
        }
        else {
            result.push_back(*left);
            if (left != left_end)
                left++;
            else
                left = nullptr;
        }
    }
    return result;
}

template<typename T>
vector<T> merge_sort(vector<T> arr) {
    if (arr.size() == 1) {
        return arr;
    }
    else {
        vector<T> l_part, r_part, result;
        for (int i = 0; i < arr.size(); i++)
        {
            if (i < arr.size() / 2)
                l_part.push_back(arr[i]);
            else
                r_part.push_back(arr[i]);
        }
        result = merge(merge_sort(l_part), merge_sort(r_part));
        return result;
    }
}



int main()
{
    vector<int> arr = { 4,17,256,1,167,13,9};
    cout<<"input array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i]<<' ';
    }
    cout<<endl<<endl;
    arr=merge_sort(arr);
        cout<<"output array: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i]<<' ';
    }
    cout<<endl<<endl;

}
