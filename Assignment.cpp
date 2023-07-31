#include<iostream>
#include<climits>
#include<cstdlib>

using namespace std;


int base_calculation(string str)
{
    
    int length = str.size();  // FINDS THE SIZE OF STRING

    int arr[length];  // ARR :-> STORES THE CORESPONDING INTEGER VALUE TO THE ALPHABETS OR CHARACTERS EX.:-> A:10 B:11 ETC.
    int right = length - 1; //RIGHT POINTER HELPS TO INDEXING AND TRAVERSING
    char last_char ;  //STORES THE LAST CHARACTER OF EACH STRING
    while(!str.empty())  // LOOP WORK TILL STR IS NOT EMPTY
    {
        
        last_char = str.back();  //FETCH THE LAST CHARACTER OF EACH STRING

        if( last_char >= 'A' && last_char <= 'F')
        {
            arr[right--] = (last_char - 'A')+10;   // LOGIC :->OPERATION ASCII CODE TO CONVERT CHARACTR TO INTEGER
        }

        else if( last_char >= '0' && last_char <= '9')
        {
            arr[right--] =(last_char - '0'); 
        }

        str.pop_back(); //REMOVE LAST CHARACTR : IF IT IS NOT :->LOOP RUNS INFINITELY
    }

    int max = INT_MIN;  // INT_MIN USING CLIMITS HEADE FILE :-> INT_MIN : SMAALEST NUMBER IN RANGE OF INTEGER

    for(int i = 0 ; i < length ; i++)
    {
        if(arr[i]  > max )
        {
            max = arr[i];  //UPDATING BASE VALUE :-> BASE = MAXIMUM DIGIT OF NUMER + 1
        }
    }

    return (max+1);  // RETURN THE INTEGER TYPE VALUE
}
char integer_to_character(int num)  // CONVERT INTEGER TO CHARACTERS
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

int main()  //starting point of our code
{
    int length; //this decides the number of characters in string
    cout<<"Enter the length of string what you want : ";
        cin>>length;

    char* str = new char[length+1];  // dynamically allocated char aaray which stores random character & (LENGTH+1) :-> +1 POSIITON STORES THE NULL CHARACTER
    int i ;
   for(i= 0 ; i < length ; i++)
    {
        int random_value = rand() % 15;  // rand() :-> return random number between 0 to 15

        int corresponding_character = integer_to_character(random_value);  // corresponding character stores the character cooresponds to itnger 10:'A' , 11: 'B' , 12:'C' 13:'D' 14:'E' 15:'F' EC;

        str[i] = corresponding_character;  //STR :->SRING STORES THE RANDOM CHARACTER
    }

    str[i] = '\0';  // NULL CHARACTER WHICH ENDING POINT OF EVERY STRING 

cout<<"Given string : ";
    for(int i = 0 ; i < length ; i++)
    {
        cout<<str[i];  // PRINT THE GIVNEN STRING
    }

int base = base_calculation(str); //CALCULATE THE BASE

cout<<endl<<"Base : "<<base; //PRINT THE BASE

delete[] str; // FREE THE DYNAMICALLY ALLOCATED MEMORY :-> IF NO :_-> IT RESULTS MEMORY LEAKAGE
    
}
