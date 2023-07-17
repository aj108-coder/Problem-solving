#include<iostream>
#include<cmath>
using namespace std;

void binary_to_decimal(int binary_number);

int main()
{
    int binary_number;
        cin>>binary_number;

//function call by value which convert the binary number to decimal number
    binary_to_decimal(binary_number);
    return 0;
}

void binary_to_decimal(int binary_number)
{
    int last_digit = 0;
    int decimal_number = 0;
    int temp=binary_number;
    int k=0; // k is a helping variable -->helps in evlauating power
    while(temp)
    {
        last_digit = temp % 10;
            temp /=10;
        
        decimal_number += last_digit*pow(2,k);

        k++;
    }

    cout<<decimal_number;
}