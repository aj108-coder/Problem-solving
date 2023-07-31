#include<iostream>
#include<climits>
#include<cstdlib>

using namespace std;


int base_calculation(string str)
{
    
    int length = str.size();

    int arr[length];
    int right = length - 1;
    char last_char ;
    while(!str.empty())
    {
        
        last_char = str.back();

        if( last_char >= 'A' && last_char <= 'F')
        {
            arr[right--] = (last_char - 'A')+10;
        }

        else if( last_char >= '0' && last_char <= '9')
        {
            arr[right--] =(last_char - '0');
        }

        str.pop_back();
    }

    int max = INT_MIN;

    for(int i = 0 ; i < length ; i++)
    {
        if(arr[i]  > max )
        {
            max = arr[i];
        }
    }

    return (max+1);
}
char integer_to_character(int num)
{
    if( num >=0 && num <=9 )
    {
        return num + '0';
    }

    else if (num >= 10 && num <=15)
    {
        return ('A' + (num - 10));
    }
    
}

int main()
{
    int length;
        cin>>length;

    char* str = new char[length+1];

    int i ;
   for(i= 0 ; i < length ; i++)
    {
        int random_value = rand() % 15;

        int corresponding_character = integer_to_character(random_value);

        str[i] = corresponding_character;
    }

    str[i] = '\0';

cout<<"Given string : ";
    for(int i = 0 ; i < length ; i++)
    {
        cout<<str[i];
    }

int base = base_calculation(str);

cout<<endl<<"Base : "<<base;

delete[] str;
    
}