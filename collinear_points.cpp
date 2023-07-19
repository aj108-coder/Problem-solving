#include<iostream>
using namespace std;

bool check_collinearity_of_points(int x1 , int x2 ,int x3,int y1 ,int y2,int y3);
int main()
{
        //point1
    cout<<"Enter the coordinates of point 1 : ";
        cout<<"Enter x1 : ";
             int x1;
                cin>>x1;
       
            cout<<"Enter y1 : ";
                 int y1;
                    cin>>y1;

        //point 2
    cout<<"Enter the coordinates of point2 : ";
        cout<<"Enter the x2 : ";
                int x2;
                    cin>>x2;
        cout<<"Enter the y2 : ";
                int y2;
                    cin>>y2;
        //point 3
        cout<<"Enter the coordinates of point 3 : ";
            cout<<"Enter the x3 : ";
                int x3;
                    cin>>x3;
        cout<<"Enter the y3 : ";
        int y3;
            cin>>y3;
        
        
//Function call to check the points are on one straight line
    cout<<endl;

bool result = check_collinearity_of_points(x1,x2,x3,y1,y2,y3);
 if(result  == 1)
 {
    cout<<"True :"<<"All points are fall on one straight line ";
 }    

 else{
    cout<<"False : "<<"All points are not fall on one straight line ";
 }        
        
        
        
        
        
        
        return 0;
}


bool check_collinearity_of_points(int x1 , int x2 ,int x3 ,int y1 ,int y2,int y3)
{
    int slope1 = (y2 - y1 )/(x2 - x1);
    int slope2 = (y3 - y2 )/(x3 - x2);

    if(slope1 == slope2)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}
