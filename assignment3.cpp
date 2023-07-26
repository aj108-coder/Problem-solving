#include<iostream>
using namespace std;
string generateRandomHexadecimal(int length) {

//Note : for this function I am taking help from some refernce and all other part code is tootally designed by me
    const string hexChars = "0123456789ABCDEF"; // const means :-> hexchars is fixed :->it does not change
    string result;  //result to store the generated hexadecimal string

    // Seed the random number generator with the current time
    // srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < length; ++i) {
        result += hexChars[rand() % hexChars.length()];  // I am confuse with dry of this line // what logic is behind it
    }

    return result;
}

int main()

{
    int length;  // length is the size of string to be generated
        cout<<"Enter the length of slphanumerci string what you want : ";
            cin>>length;
        

    string hexadecimal = generateRandomHexadecimal(length);

    // condiiton is manadtory because if length = 0 ;->then nothing is orint :->failed a test cases

    if(length > 0)  // condition for handling the test case
    {
        cout<<"The randomly generated characters are : "<<hexadecimal;
    }

    else
    {
        cout<<"Enter the valid length of alphanumeric string ( Range of length : 0 < length <=your choice) ";
    }

}