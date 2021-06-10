#include <QCoreApplication>
#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> bubble_sort(vector<T> arr) {
    T tmp;
    bool check = true;
    while (check) {
        check = false;
        for (unsigned int i = 0; i < arr.size()-1; i++)
        {
            if (arr[i] > arr[i + 1]) {
                tmp = move(arr[i]);
                arr[i] = move(arr[i + 1]);
                arr[i + 1] = move(tmp);
                check = true;
            }
        }
        for(unsigned int i = 0; i< arr.size(); i++){
            cout<<arr[i]<<' ';
        }
        cout<<endl;

    }
    return arr;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> array = { 2,4,1,9,7,6,-2,142,-186 };
    cout<<"input array: ";
    for(unsigned int i = 0; i< array.size(); i++){
        cout<<array[i]<<' ';
    }
    cout<<endl;
    cout<<endl<<"Making bubble sort:"<<endl;
    array = bubble_sort(array);
    cout<<endl;
    cout<<endl<<"Output array: ";
    for(unsigned int i = 0; i< array.size(); i++){
        cout<<array[i]<<' ';
    }
    cout<<endl;
    return a.exec();
}
