#include<conio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

#define new_cal 1
#define old_cal 0

// Creating stand_calc class to define standard calculator functions
class stand_calc
{
    // Creating prototype of standard calculator function. All functions are static so class objects need not be created to call these functions.
    public:
        static double addition(double,double);
        static double substract(double,double);
        static double multiplication(double,double);
        static double division(double,double *);
        static double modulus(double*,double *);
};

// Creating scie_calc class to define scientific calculator functions
class scien_calc
{
    public:
        static double square(double);
        static double cube(double);
        static double power(double,double);
        static double sq_root(double);
        static long int fact(double);
        static double sin_func(double);
        static double cos_func(double);
        static double tan_func(double);
};

// addition function addds two numbers
double stand_calc :: addition(double a, double b)
{
    return (a+b);
}

// substraction function substracts second number from first number
double stand_calc :: substract(double a, double b)
{
    return (a-b);
}

// multiplication function multiplies two numbers
double stand_calc:: multiplication(double a, double b)
{
    return(a*b);
}

// division function divides first number by second number.This function takes two arguments, one is copy of the variable another is pointer type. This is because the if the accepting divisor is zero then this function will show a massage to enter the divisor again.
double stand_calc:: division(double a,double *b)
{
    while (*b==0)
    {
        cout<<"\nCannot divide by zero!";
        cout<<"\n Enter second no. again: ";
        cin>>*b;
    }
    return(a/(*b));
}

// modulus function divides first number by second number and returns the remainder part of the division. Similar to division function this function takes two arguments, one is copy of the variable another is pointer type. This is because the if the accepting divisor is zero then this function will show a massage to enter the divisor again.Modulus  cannot be performed on double so we have to convert the numbers into integer.
double stand_calc:: modulus(double* a,double *b)
{
    while (*b==0)
    {
        cout<<"\nCannot divide by zero!";
        cout<<"\n Enter second no. again: ";
        cin>>*b;
    }
    // Converting double to integer.
    int x=(int)*a;
    int y=(int)*b;
     
    if(*a-x>0 || *b-y>0)
    {
        cout<<"\nConverting decimal number to integer to perform modulud.";
    }
    *a=x;
    *b=y;
    return(x%y);
}

// square function of the scien_calc class to return accepting number to power 2.
double scien_calc::square(double x)
{
    return (power(x,2));
}

// cube function of the scien_calc class to return accepting number to power 3.
double scien_calc::cube(double x)
{
    return(pow(x,3));
}

// power function of the scien_calc class to return accepting number1 to power of accepting number2.
double scien_calc::power(double x,double y)
{
    return(pow(x,y));
}

// sq_root function of the scien_calc class to return the quare root of the entered number.
double scien_calc::sq_root(double x)
{
    return (sqrt(x));
}

// fact function of the scien_calc class to return the factorial of the accepting numver in long integer form.
long int scien_calc::fact(double x)
{
    int n=(int)x;
    long int f=1;
    while(n>1)
    {
        f*=n;
        n--;
    }
    return f;
}

// sin function of scien_calc class to return sin value of x.
double scien_calc::sin_func(double x)
{
    return (sin(x));
}

// cos function of scien_calc class to return cos value of x.
double scien_calc::cos_func(double x)
{
    return (cos(x));
}

// tan function of scien_calc class to return tan value of x.
double scien_calc::tan_func(double x)
{
    return (tan(x));
}


//*** Displaying the menue to enter options and value.
int main()
{
    double num1,num2,num3,temp;
    int choice1=0,choice2,flag;

    //Loop of main menue that will show the menue to choose the type of calculator
    do
    {
        system("cls");
        cout<<"======== Type of Calculator ========";
        cout<<"\n1\tStandard Calculator\n2\tScientific Calculator\n3\tQuit";
        cout<<"\nChoose the type of Calculator: ";
        cin>>choice1;
        flag=new_cal;

        switch(choice1)
        {
            case 1:
                //Loop to display standard calculator menu
                do
                {
                    system("cls");
                    cout<<"======== Standard Calculator ========";
                    cout<<"\n1\tAddition\n2\tSubstraction\n3\tMultiplication\n4\tDivision\n5\tModulus\n6\tReturn to Previous Menu\n7\tQuit";
                    //Option 8 is only visible when working on old calculations.
                    if(flag==old_cal)
                    {
                        cout<<"\n8\tClear Memory";
                        cout<<"\n======== Remember to clear memory before new calculation ========";
                    }
                    cout<<"\nChoose Type of Calculation: ";
                    cin>>choice2;

                    //To perform operation and call functions of stn_calc class
                    switch (choice2)
                    {
                    case 1:
                        //Accept the first no. if a new calculation is to be done else previous result will be the first number.
                        if(flag==new_cal)
                        {
                            cout<<"Enter the first number: ";
                            cin>>num1;
                        }
                        else 
                        {
                            num1=temp;
                            cout<<"\nFirst number is "<<num1<<endl;
                        }
                        cout<<"Enter the second number: ";
                        cin>>num2;
                        num3=stand_calc::addition(num1,num2);
                        cout<<"\nAddition of "<<num1<<" and "<<num2<<" is "<<num3;
                        cout<<"\nPress any key to continue ........";
                        getch();
                        temp=num3;
                        flag=old_cal;
                        break;
                    
                    case 2:
                        if(flag==new_cal)
                        {
                            cout<<"Enter the first number: ";
                            cin>>num1;
                        }
                        else 
                        {
                            num1=temp;
                            cout<<"\nFirst number is "<<num1<<endl;
                        }
                        cout<<"Enter the second number: ";
                        cin>>num2;
                        num3=stand_calc::substract(num1,num2);
                        cout<<"\nSunstraction of "<<num2<<" from "<<num1<<" is "<<num3;
                        cout<<"\nPress any key to continue ........";
                        getch();
                        temp=num3;
                        flag=old_cal;
                        break;

                    case 3: 
                        if(flag==new_cal)
                        {
                            cout<<"Enter the first number: ";
                            cin>>num1;
                        }
                        else 
                        {
                            num1=temp;
                            cout<<"\nFirst number is "<<num1<<endl;
                        }
                        cout<<"Enter the second number: ";
                        cin>>num2;
                        num3=stand_calc::multiplication(num1,num2);
                        cout<<"\nMultiplication of "<<num1<<" and "<<num2<<" is "<<num3;
                        cout<<"\nPress any key to continue ........";
                        getch();
                        temp=num3;
                        flag=old_cal;
                        break;

                    case 4:
                        if(flag==new_cal)
                        {
                            cout<<"Enter the first number: ";
                            cin>>num1;
                        }
                        else 
                        {
                            num1=temp;
                            cout<<"\nFirst number is "<<num1<<endl;
                        }
                        cout<<"Enter the second number: ";
                        cin>>num2;
                        num3=stand_calc::division(num1,&num2);
                        cout<<"\nDivision of "<<num1<<" by "<<num2<<" is "<<num3;
                        cout<<"\nPress any key to continue ........";
                        getch();
                        temp=num3;
                        flag=old_cal;
                        break;
                    
                    case 5: 
                        if(flag==new_cal)
                        {
                            cout<<"Enter the first number: ";
                            cin>>num1;
                        }
                        else 
                        {
                            num1=temp;
                            cout<<"\nFirst number is "<<num1<<endl;
                        }
                        cout<<"Enter the second number: ";
                        cin>>num2;
                        num3=stand_calc::modulus(&num1,&num2);
                        cout<<"\nModulus of "<<num1<<" by "<<num2<<" is "<<num3;
                        cout<<"\nPress any key to continue ........";
                        getch();
                        temp=num3;
                        flag=old_cal;
                        break;

                    case 6: 
                        cout<<"\nReturning to previous menu.";
                        cout<<"\nPress any key to continue ........";
                        getch();
                        break;
    
                    case 7: 
                        cout<<"\nQuitting........";
                        cout<<"\nPress any key to continue ........";
                        getch();
                        exit(0);

                    case 8:
                    //If a new calculation is going on the 8 is an invalid option, else this is the option to start new calculation.
                        if(flag==new_cal)
                        {   
                            cout<<"\nInvalid choice.";
                            cout<<"\nPress any key to continue ........";
                            getch();
                            break;
                        }
                        else
                        {
                            temp=0;
                            flag=new_cal;
                        }
                        break;
                            
                    default : 
                        cout<<"\nInvalid choice.";
                        cout<<"\nPress any key to continue ........";
                        getch();
                        break;
                    }
                } while (choice2!=6);
                break;

            case 2:
                //Loop to display Scientific Calculator menu.
                do
                {
                    system("cls");
                    cout<<"======== Scientific Calculator ========";
                    cout<<"\n1\tSquare\n2\tCube\n3\tPower\n4\tSquare Root\n5\tSin\n6\tCos\n7\tTan\n8\tReturn to previous menu\n9\tQuit";
                    if(flag==old_cal)
                    {
                        cout<<"\n10\tClear Memory";
                        cout<<"\n======== Remember to clear memory before new calculation ========";
                    }
                    cout<<"\nChoose Type of Calculation: ";
                    cin>>choice2;
                    switch (choice2)
                    {
                    case 1:
                        if(flag==new_cal)
                        {
                            cout<<"Enter number to find square: ";
                            cin>>num1;
                        }
                        else
                        {
                            num1=temp;
                            cout<<"\nNumber is "<<num1<<endl;
                        }
                        num3=scien_calc::square(num1);
                        cout<<"Square of "<<num1<<" is "<<num3;
                        cout<<"\nPress Any key to continue ........";
                        getch();
                        temp=num3;
                        flag=old_cal;
                        break;
                    
                    case 2:
                        if(flag==new_cal)
                        {
                            cout<<"Enter number to find cube: ";
                            cin>>num1;
                        }
                        else
                        {
                            num1=temp;
                            cout<<"\nNumber is "<<num1<<endl;
                        }
                        num3=scien_calc::cube(num1);
                        cout<<"Cube of "<<num1<<" is "<<num3;
                        cout<<"\nPress Any key to continue ........";
                        getch();
                        temp=num3;
                        flag=old_cal;
                        break;

                    case 3:
                        if(flag==new_cal)
                        {
                            cout<<"Enter first number for base to find power: ";
                            cin>>num1;
                        }
                        else
                        {
                            num1=temp;
                            cout<<"\nFirst number is "<<num1<<endl;
                        }
                        cout<<"Enter second number for power to find power: ";
                        cin>>num2;
                        num3=scien_calc::power(num1,num2);
                        cout<<num1<<" to the power "<<num2<<" is "<<num3;
                        cout<<"\nPress Any key to continue ........";
                        getch();
                        temp=num3;
                        flag=old_cal;
                        break;
                    
                    case 4:
                        if(flag==new_cal)
                        {
                            cout<<"Enter number to find square root: ";
                            cin>>num1;
                        }
                        else
                        {
                            num1=temp;
                            cout<<"\nNumber is "<<num1<<endl;
                        }
                        num3=scien_calc::sq_root(num1);
                        cout<<"Square root of "<<num1<<" is "<<num3;
                        cout<<"\nPress Any key to continue ........";
                        getch();
                        temp=num3;
                        flag=old_cal;
                        break;

                    case 5: 
                        if(flag==new_cal)
                        {
                            cout<<"Enter number to find sin value: ";
                            cin>>num1;
                        }
                        else
                        {
                            num1=temp;
                            cout<<"\nNumber for sin value is "<<num1<<endl;
                        }
                        num3=scien_calc::sin_func(num1);
                        cout<<"Sin value of "<<num1<<" is "<<num3;
                        cout<<"\nPress Any key to continue ........";
                        getch();
                        temp=num3;
                        flag=old_cal;
                        break;

                    case 6:
                        if(flag==new_cal)
                        {
                            cout<<"Enter number to find cos value: ";
                            cin>>num1;
                        }
                        else
                        {
                            num1=temp;
                            cout<<"\nNumber for cos value is "<<num1<<endl;
                        }
                        num3=scien_calc::cos_func(num1);
                        cout<<"Cos value of "<<num1<<" is "<<num3;
                        cout<<"\nPress Any key to continue ........";
                        getch();
                        temp=num3;
                        flag=old_cal;
                        break;

                    case 7: 
                        if(flag==new_cal)
                        {
                            cout<<"Enter number to find tan value: ";
                            cin>>num1;
                        }
                        else
                        {
                            num1=temp;
                            cout<<"\nNumber for tan value is "<<num1<<endl;
                        }
                        num3=scien_calc::tan_func(num1);
                        cout<<"Tan value of "<<num1<<" is "<<num3;
                        cout<<"\nPress Any key to continue ........";
                        getch();
                        temp=num3;
                        flag=old_cal;
                        break;

                    case 8: 
                        cout<<"\nReturning to previous menu.";
                        cout<<"\nPress any key to continue ........";
                        getch();
                        break;

                    case 9:
                        cout<<"\nQuitting ........";
                        cout<<"\nPress Any key to continue ........";
                        getch();
                        exit(0);

                    case 10: 
                        if(flag==new_cal)
                        {
                            cout<<"\nInvalid Choice";
                            cout<<"\nPress Any key to continue ........";
                            getch();
                        }
                        else
                        {
                            temp=0;
                            flag=new_cal;
                        }
                        break;

                    default:
                        cout<<"\nInvalid Choice.";
                        cout<<"\nPress Any key to continue ........";
                        getch();
                        break;
                    }
                } while (choice2!=8);
                break;

            case 3:
                cout<<"\nQuitting ........";
                cout<<"\nPress Any key to continue ........";
                getch();
                break;

            default :
                cout<<"\nInvalid Choice.";
                cout<<"\nPress Any key to continue ........";
                getch();
                break;
        }
    } while (choice1!=3);
}