#include<iostream>
#include<algorithm>
using namespace std;

void print(int* arr, int n)
{
    for(int i = 0;i < n ;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int base_calculation(int num)
{
     int base= 0;
     int remainder = 0;

     while(num != 0)
     {
        remainder = num % 10;

        if(remainder> base )
        {
            base = remainder ;
        }

        num /= 10;

     }
         return (base+1);
}

int main()
{
    int n;
        cin>>n;
    
    int* arr = new int[n];

cout<<"Enter the elements of array : ";
    for(int i = 0; i<n ; i++)
    {
        arr[i] = rand() % 1000;

        // cin>> arr[i];

    }

//given array :
cout<<"Given array : ";
    print(arr,n);

    cout<<endl;
// count[] :-> nice array which stores number of lement respective their base

int* count = new int[16];

for(int i = 0 ;i < 16 ; i++ )
{
    count[i] = 0;
}


    
for(int i = 0 ;i<n ;i++ )
{
    int base = base_calculation(arr[i]);

   count[base]++;
}

//print count arr

    cout<<endl;
for(int i = 0 ;i<16 ; i++)
{
    cout<< count[i]<<" ";
}

    cout<<endl;

for(int i=1 ; i<16 ; i++)
{
    cout<<"Base "<<i<<": "<<count[i]<<endl;
}

// int maxNumber = 0;
// for (int i = 1; i < 16; ++i) {
//         if (count[i] > maxNumber) {
//             maxNumber = count[i];
//         }
//     }


cout<<endl;

cout<<"Graphical representation in star pattern : "<<endl;

int maxNumber = 0;
    for (int i = 1; i < 16; i++) {
        if (count[i] > maxNumber) {
            maxNumber = count[i];
        }
    }

    for (int i = maxNumber; i > 0; i--) {
        for (int j = 1; j < 16; j++) {
            if (count[j] >= i) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    for (int i = 1; i < 16; i++) {
        cout << i << " ";
    }
    cout << endl;

    delete[] count;
    delete[] arr;

    return 0;
}