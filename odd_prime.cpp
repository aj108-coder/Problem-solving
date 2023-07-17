#include<iostream>
using namespace std;

void odd(int arr[],int n);

void prime(int arr[],int n);
int main()
{         
    int n; //take input size of array -->Bad practise  {Stackoverflow : when n is so large}
        cin>>n;
    int arr[n]; //arr -->array of integer which stores integer in continous mmemory

//loop helps to take user input an integers
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];   
    }

//given array :
    cout<<endl<<"Given array : "<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }

//Here we call odd functions 
cout<<endl<<"Odd numbers are : ";
    odd(arr,n);

//Here we call prime function
cout<<endl<<"Prime Numbers are : ";
    prime(arr,n);
}

void odd(int arr[],int n) //odd number is a no. which is not divisible by 2
{     
    int temp[n];
   
    int index=0;
    for(int i=0;i<n;i++) //loop is for traverse the array
    {    
         

        if(arr[i] % 2 != 0) //conditions helps to check the given element is odd or even
        {
            temp[index] = arr[i];
            index++;
        }
    }

    for(int i=0;i<index;i++) //loop used for traversing the array for printing all elemnts
    {
        cout<<temp[i]<<" ";
    }
}

void prime(int arr[], int n)
{
    int temp[n];
    int index = 0;
    bool check = true;
  
    for(int i=2;i<n;i++)
    {
        if(arr[i] % i == 0)
        {
            check =false;

        }

        else{
            check = true;
        }

        if(check == true )
        {
            temp[index] = arr[i];
            index++;
        }
    }

    for(int i=0;i<index;i++)
    {
        cout<<temp[i]<<" ";
    }
}