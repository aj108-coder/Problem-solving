#include <iostream>
#include <limits>
#include<climits>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//use of sunction increases the modularity and readability

int base_calculation(string str);  // calculate base of each hexadeimal number

string generateRandomHexadecimal(int length) ;  // geenerate random hexadecimal numbers


bool is_input_hexadecimal(string str); // HANDLE INPUT TEST CASE :->if someone enters the wrong output it returns false

void input(string* arr, int size_of_array);  // it just take input the data -->hexadcimal numbers in array

void print(string* arr, int size_of_array); // it just print the given output


int main()  // starting point of c/c++ code :->call by O.S.
{
int size_of_array;
    cout << "Input the quantity of hexadecimal number to find the frequency of base : " << endl;
        cin >> size_of_array;

string* arr = new string[size_of_array]; // arr is dynamically allocated array which stores al the hexadecimal values or numbers

cout<<"1)USER-INPUT"<<endl;
cout<<"2)Randomly generated hexadecimal values "<<endl;
    int choice;
        cout<<"Enter your choice : ";
        cin>>choice;

    if(choice == 1)
    {
        cout << "Enter the " <<size_of_array <<" hexadecimal values: " << endl;
            input(arr, size_of_array);
    }

    if(choice == 2 )
    {   
        int length; 
        cout<<"Enter the lenght of hexadecimal you want ( 2 < hexadecimal length < 10) : ";
            cin>>length;

            for(int i = 0 ;i <size_of_array ; i++)
            {
                 arr[i] = generateRandomHexadecimal(length) ;

            }
    }
//print the array to know the hexadecimal number store in an array
    cout << endl << "Given array: " << endl;
        print(arr, size_of_array);

// count array stores the frequency of bases 
int* count = new int[16];  
    
      for(int i = 0 ;i <= 16 ; i++)
        {
            count[i] = 0;
        }

//this loops actaul fetch the base of each hexadecimal number and count the frequency of base   
    for(int  i = 0 ; i < size_of_array ; i++)
        {
            int base = base_calculation(arr[i]);
                count[base]++;
        }

cout<<endl;

//this loop actuall print the count array which sows the frequency of base
    for(int i = 0 ; i <= 16 ; i++)
        {
             cout<<count[i] <<" ";
         }

cout<<endl;

//this loops show the how much hexadecimal number have same bases
    for(int i=0 ; i<=16; i++)
    {
        cout<<"Base "<<i<<": "<<count[i]<<endl;
    }

cout << endl;

//let show the just like a graphical representation using star and number of star signify the frequency

    cout << "Graphical representation in star pattern : " << endl;

    int maxNumber = 0;
        for (int i = 1; i < 16; i++)
        {
            if (count[i] > maxNumber)
            {
                 maxNumber = count[i];   // maximum number helps to find the number of maximum column
            }
        }
// this loop prints the pattern
    int i =1;
    int temp = 1;
        for(  ;i  <=16 ; i++)
          {  
            if( i <=9)
              cout<<" "<<i<<": ";
              else{
                cout<<i<<": ";
              }
           if( count[i] > 0)
           { 
                 for(int j = 0 ;j <count[i] ; j++)
                    {
                
                        cout<<"* ";
                        temp++;
                    }

          }

                    cout << endl;
 
          }

        //   cout<<" ";
        //   for(int i = 1 ; i<= 16 ; i++)
        //   {
        //     cout<<i<<" ";
        //   }

    // Don't forget to release the memory allocated dunamcally because it lead to cause memory leakage
    
    delete[] arr;

    delete[] count;
    return 0;
}

bool is_input_hexadecimal(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (('0' <= str[i] && str[i] <= '9') || ('A' <= str[i] && str[i] <= 'F'))
        {
            return true;
        }
    }

    return false;
}

void input(string* arr, int size_of_array)
{
    for (int i = 0; i < size_of_array;)
    {
        cin >> arr[i];

        string str = arr[i];

        if (is_input_hexadecimal(arr[i]))
        {
            i++;
        }
        else
        {
            cout << "Enter a single hexadecimal digit between '0' to '9' and 'A' to 'F': ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void print(string* arr, int size_of_array)
{
    for (int i = 0; i < size_of_array; i++)
    {
        cout << arr[i] << " ";
    }
}
int base_calculation(string str)
{ 

    // through this we calculate the base of each hexadecimal value
    int base = 0 ;
   char last_char= 0 ; 
  int n = str.length();
  int last_integer[n] ;
  int right = n-1;

   while( !str.empty())
   {
       last_char = str.back(); //fetch the last eleement of string

 

         if ( last_char >= 'A' && last_char <= 'F')
        {
            last_integer[right--] = last_char - 'A' + 10;  //convert a character into a intger

        }


       else if(last_char >= '0' && last_char<='9' )
      {
        last_integer[right--] = last_char - '0';
     }
       
         str.pop_back();  //remove the last element of string
   }

   int max = INT_MIN ;  // intailse the max with INT_MIN(smallest number in the range of integer data type in c++)

   for( int  i = 0 ; i < n ; i++)
   {
       if(max < last_integer[i])
       {
        max = last_integer[i];       }
   }

   base = max;
    return (base+1); // base of hexadecimal number = maximum _number + 1 :-> ex : 123AB :-> maximum_nmber = B (11) :-> BASE = 11+1 = 12
}

string generateRandomHexadecimal(int length) {

//Note : for this function I am taking help from some refernce and all other part code is tootally designed by me
    const string hexChars = "0123456789ABCDEF";
    string result;

    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < length; ++i) {
        result += hexChars[std::rand() % hexChars.length()];
    }

    return result;
}



//BELOW INPUT AND OUTPTUT IS GIVEN  { OUTPTUT WINDOW }
/* 
Input the quantity of hexadecimal number to find the frequency of base : 
45
1)USER-INPUT
2)Randomly generated hexadecimal values 
Enter your choice : 1
Enter the 45 hexadecimal values: 
1
1
1
2
2
2
3
3
3
4
4
4 
5
5
5
6
6
6
7
7
7
8
8
8
9
9
9
A 
A
A
B
B
B
C
C
C
D
D
D
E
E
E
F
F
F

Given array:
1 1 1 2 2 2 3 3 3 4 4 4 5 5 5 6 6 6 7 7 7 8 8 8 9 9 9 A A A B B B C C C D D D E E E F F F 
0 0 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
Base 0: 0
Base 1: 0
Base 2: 3
Base 3: 3
Base 4: 3
Base 5: 3
Base 6: 3
Base 7: 3
Base 8: 3
Base 9: 3
Base 10: 3
Base 11: 3
Base 12: 3
Base 13: 3
Base 14: 3
Base 15: 3
Base 16: 3

Graphical representation in star pattern :
 1:
 2: * * *
 3: * * *
 4: * * *
 5: * * *
 6: * * *
 7: * * *
 8: * * *
 9: * * *
10: * * *
11: * * *
12: * * *
13: * * *
14: * * *
15: * * *
16: * * *
*/
