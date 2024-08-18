#include <iostream>

using namespace std;

 //Function Prototypes
void log(void);
void trig(double x);
void nth_root(double arg, int n);
double nth_power(double y, int n);

int main()
{
    
    int ch;
    double x=0;
    cout<<"Enter '1' for basic mathematical operations. (+,-,*,/ etc.)\n";
    cout<<"Enter '2' for logarithmic operations.\n";
    cout<<"Enter '3' for trigonometric operations.\n";
    cout<<"Enter '4' to raise to the power '1/n'.\n";
    cout<<"Enter '5' to raise to the power 'n'."<<endl;
    
    cin>>ch;
    
    switch(ch)
    {
        case 1:
        cout<<"Enter the expression:"; 
        /*C++ by default calculates simple arithmetic expressions.
        No requirement of separate code.*/                            
        break;
        case 2:
        log();
        break;
        case 3:
        {
            cout<<"Enter the argument in radians:"<<endl;
            cin>>x;
            trig(x);
        }
        break;
        case 4:
        {
            cout<<"Enter the argument:"<<endl;
            int n;
            cin>>x;
            cout<<"Enter the value of 'n', to find the nth root:"<<endl;
            cin>>n;
            nth_root(x,n);
        }
        break;
        case 5:
        {
            int n;
            cout<<"Enter the argument:"<<endl;
            cin>>x;
            cout<<"Enter the exponent:"<<endl;
            cin>>n;
            cout<<nth_power(x,n+1)<<endl;
        }
        break;
        default:
        cout<<"Invalid Input\n";

    }

    return 0;
}



//logarithmic operations
void log()
{
    double x,y,sum_1=0,sum_2=0,w;
    cout<<"Enter the base:"<<endl;
    cin>>x;
    y=(x-1)/(x+1);
    cout<<"Enter the argument:"<<endl;
    cin>>w;
    for (int i = 1; i < 502; i+=2) //Mercator series is put to use.
    {
        double z=1;
        for(int j=1;j<=i;j++)
        z*=y;
        z/=i;
        sum_1+=z;
    }
    y=(w-1)/(w+1);
    for (int i = 1; i < 502; i+=2)
    {
        double z=1;
        for(int j=1;j<=i;j++)
        z*=y;
        z/=i;
        sum_2+=z;
    }
    cout<<"The log of "<<w<<" to the base "<<x<<" is: "<<(sum_2/sum_1)<<endl;
}

//nth power
double nth_power(double y, int n)
{
    double w=1;
    for(int i=1;i<=(n-1);i++)
    w*=y;
    return w;
}
    
//nth root
void nth_root(double arg,int n)
{
    double x=0,y=0,z;
    x=arg;
    do        // Newton's Method of approximating 'nth' root
    {
        y=x;
        z=nth_power(y,n);
        x=((n-1)*y + arg/z)/n;
    } while ((y-x)>0.0001);
    cout<<x<<endl;
}
double fact=1,sign=1,sum=0;

//sine function
double sine(double y)
    {
        double num=y;
        fact=1;
        sign=1;
        for (int i = 1; i <= 500; i++)  // Taylor series
        {
            fact*=i;
            if(i%2!=0)
            {
                sum+=(num/fact)*sign;
                sign*=(-1);
            }
            num*=y;
        }
        return sum;
    }

//cosine function
double cosine(double y)
    {
        double num=y;
        sum=1;
        sign=-1;
        fact=1;
        for (int i = 1; i <= 500; i++)   //Taylor series
        {
            fact*=i;
            if(i%2==0)
            {
                sum+=(num/fact)*sign;
                sign*=(-1);
            }
            num*=y;
        }
        return (sum);
        
    }



//trigonometric operations
void trig(double y)
{
    const double pi=3.14159265359;
    int count=0;
    while(y>pi)   //Reducing larger numbers to numbers between 0 and pi for ease of convergence
    {
        y-=pi;
        count++;   // gives an idea of the quadrant in which the argument is present
    }
    
    int m;
    cout<<"Enter 1 for sin."<<endl;
    cout<<"Enter 2 for cos."<<endl;
    cout<<"Enter 3 for tan."<<endl;
    cout<<"Enter 4 for cot."<<endl;
    cout<<"Enter 5 for sec."<<endl;
    cout<<"Enter 6 for cosec."<<endl;
    cin>>m;
    switch(m)
    {
        case 1: //sine
    {
        if(count%2==1)
        cout<<sine(y)*(-1)<<endl;
        else
        cout<<sine(y)<<endl;
    }
    break;
    case 2: //cosine
    {
        if((count%2==0 && y>0.5*pi) || (count%2==1 && y<0.5*pi))
        cout<<(-1)*cosine(y)<<endl;
        else
        cout<<cosine(y)<<endl;
    }
    break;
    case 3: //tangent
    {
        if (y<0.5*pi)
        cout<<sine(y)/cosine(y)<<endl;
        else
        cout<<(-1)*sine(y)/cosine(y)<<endl;
    }
    break;
    case 4: //cotanget
    {
        if (y<0.5*pi)
        cout<<cosine(y)/sine(y)<<endl;
        else
        cout<<(-1)*cosine(y)/sine(y)<<endl;
    }
    break;
    case 5: //secant
    {
        if((count%2==0 && y>0.5*pi) || (count%2==1 && y<0.5*pi))
        cout<<(-1)/cosine(y)<<endl;
        else
        cout<<1/cosine(y)<<endl;
    }
    break;
    case 6: //cosecant
    {
        if(count%2==1)
        cout<<(1/sine(y))*(-1)<<endl;
        else
        cout<<(1/sine(y))<<endl;
    }
    break;
    default:
    cout<<"Invalid input!"<<endl;
    }
}





