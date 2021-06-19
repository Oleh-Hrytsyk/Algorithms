#include <iostream>

long long exponentiationBySquaring(long long number, const int exponent){
    long long result = 1;
    if (number == 0)
        return 0;
    else{
        for(int i = 0; (exponent >> i) != 0; i++){
            if(((exponent >> i) & 1) == 1){
                result*=number;
            }
            number*=number;
        }
    }
    return result;
}

int main()
{
    std::cout << exponentiationBySquaring(9, 9) << std::endl;
    return 0;
}
