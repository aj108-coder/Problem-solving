#include<iostream>
#include<cstdlib>
using namespace std;

void print(int* arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

bool check_prime(int x)
{
    if (x < 2)
    {
        return false;
    }

    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }

    return true;
    }

bool  is_odd_not_prime(int x )
{   if(x == 1)
{
    return true;
}
    if(x % 2 != 0)
    {
       if( check_prime(x) == 0)
        {
            return true;
        }
        

    }
    

}

int main()
{
    int n;  // n -->size of an array
        cin>>n;  // take input size

        int* arr = new int [n];  // arr -> dynamic allocation of array in c++ {Dynamic allocation does not cause stackoverflow}

    for(int i=0;i<n;i++)
    {
        arr[i] = rand() % 100; // rand() : this function return random integer
    }

//print given array

for(int i=0 ;i<n;i++)
{
    cout<<arr[i]<<" ";
}
cout<<endl;

//
int* temp_odd = new int[n]; //temp_odd is an array which stores odd intgers only 
  int odd_index=0;                 // odd_index is a variable helps to traverse the temp_odd array .
for(int i=0;i<n;i++)
{
   if( is_odd_not_prime(arr[i]) == 1) // here , we call is_odd_not_prime () functions which search all odd integers which are not prime
    {
        temp_odd[odd_index] = arr[i];
        odd_index++;   
    }
}
//print all odd intgers
cout<<"Odd numbers :";
        print(temp_odd,odd_index);
cout<<endl;

//print all prime numbers

int* temp_prime = new int[n];
    int prime_index = 0;

for(int i=0;i<n;i++)
{
    if(check_prime(arr[i]) == 1)
    {
        temp_prime[prime_index] = arr[i];
        prime_index++;
    }
}

cout<<"Prime Numbers are :  ";
    print(temp_prime , prime_index);

    delete[] temp_odd; //release the temp_odd [] array : because it dynamic memoery allocated  ,if do not delete it leads memory leakage
    delete[] temp_prime; //same_as_above
    delete[] arr; //same_as_above
}