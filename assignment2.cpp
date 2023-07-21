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
   long int n; /// size of array 
        cin>>n;
     
     int* arr = new int[n]; // Dynamically allocated array uses heap and the adress store at stack  :-> it restrict the stack overflow

//take input random numbers
cout<<"Enter the elements of array : ";
    for(int i = 0; i<n ; i++)
    {
        arr[i] = rand() % 10000000000 + 1000000;

        // cin>> arr[i];

    }

//given array :
cout<<"Given array : ";
    print(arr,n);

    cout<<endl;
// count[] :-> nice array which stores number of element respective their base

int* count = new int[16];

for(int i = 0 ;i < 16 ; i++ )
{
    count[i] = 0; // if we do not intialise the any variable ,then compiler assign garbage value to the variable
}


//Here we store the base and incremment the index according to base
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

for(int i=1 ; i<16; i++)
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
            maxNumber = count[i];   // maximum number helps to find the number of maximum coloumn
        }
    }

    for (int i = maxNumber; i > 0; i--) { //this print stars in coloumn
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
        cout << i << " ";       // this loop prints the numbers horizontally
    }
    cout << endl;

//free up the dynamically allocated memory : if do not free it then it would be a responsible for memory lekage which is bad efffect on code
    delete[] count;
    delete[] arr;

    return 0;
}
