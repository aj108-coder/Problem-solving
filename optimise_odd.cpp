#include<iostream>
#include<cstdlib>
using namespace std;

void random_input(int* arr,int n);

void print(int* arr,int n);

void odd_prime(int arr[],int n);


int main()
{         

//creating array dynamically is good practsies and does not cause --> {Stackoverflow : when n is so large} 
// reason: dynamic memeory allocated on heap which is very large nd handle big inputs regarding memory management
    int n; 
        cin>>n;
    int*arr = new int[n]; //  we declare array dynamically  arr -->array of integer which stores integer in continous mmemory


//random functions helps to take input random variable
   random_input(arr, n);

//print_array() helps to print the array 
cout<<endl<<"Given array : "<<endl;
   print(arr,n);

//call odd_prime function
odd_prime(arr,n);

//there,we delete the dynamically crete array ,,not required for statically declared 
delete []arr;

}

void random_input(int* arr,int n)
{
     for(int i=0;i<n;i++)
    {
        arr[i] = rand() % 100; //rand()-->return random integer using cstdlib in c++ and stdlib.h in c
    }

}

void print(int* arr,int n)
{
    
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
}




void odd_prime(int arr[],int n)
{
    int temp_odd[n]; //temp_odd[n]-->stores all odd integers
        int index1 = 0; //index1 is helps to travese on temp_odd

    int temp_prime[n];//temp_prime[n]-->stores all prime integers
        int index2 = 0; //index1 is helps to travese on temp_prime
   
    
    for(int i=0;i<n;i++)
    {
        if(arr[i] % 2 != 0) 
        {
            temp_odd[index1] = arr[i];  
                index1++; 
        }
            int j=3; // j is for travesing to check the element of array is prime or not -->helps in condition
     if( arr[i] > 2  && arr[i] % j != 0 && j < arr[i] )
        {
            temp_prime[index2] = arr[i];
                index2++;
                   j++;
               
        }
      

    }

    cout<<endl<<"Odd Numbers : "<<endl;

    print(temp_odd,index1);  //print an array of odd numbers

    cout<<endl<<"Prime Numbers : "<<endl;

    print(temp_prime,index2); //print an array of prime numbers

   


}