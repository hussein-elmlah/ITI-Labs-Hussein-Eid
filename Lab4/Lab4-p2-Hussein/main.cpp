#include <iostream>

using namespace std;

class Complex
{
private:
    int real;
    int image;
public:
    Complex (int r=0, int i=0)
    {
        real = r;
        image = i;
    }
    friend Complex sub (Complex, Complex );
    friend ostream & operator << (ostream &out, const Complex &c);
    friend istream & operator >> (istream &in,  Complex &c);
    void setReal (int r)
    {
        real = r;
    }
    void setImaginary (int i)
    {
        image = i;
    }
    void setComplex (int r, int i)
    {
        real = r;
        image = i;
    }
    int getReal (void)
    {
        return real;
    }
    int getImaginary (void)
    {
        return image;
    }
    void print (void)
    {
        cout<<endl<<real;
        if (image>0)
        {
            cout<<"+"<<image<<"J";
        }
        else
        {
            cout<<image<<"J";
        }
    }
    Complex add (Complex c2)
    {
        Complex res;
        res.setReal( real + c2.real);
        res.setImaginary( image + c2.image);
        return res;
    }
    Complex sub (Complex c2)
    {
        Complex res;
        res.setReal( real - c2.real);
        res.setImaginary( image - c2.image);
        return res;
    }

    Complex operator + (Complex c)
    {
        Complex res (real+c.real,image+c.image);
        return res;
    }
    Complex operator - (Complex c)
    {
        Complex res (real-c.real,image-c.image);
        return res;
    }
    int operator == (Complex c)
    {
        if(real == c.real && image == c.image)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void operator float()
    {
        return  real;
    }
    void operator += (Complex c )
    {
        real =real +c.real;
        image += c.image;
    }
    Complex operator++ () //Prefix
    {
        real++;
        return *this;
    }
    Complex operator++ (int) //Postfix
    {
        Complex Temp = *this;
        real++;
        return Temp;
    }
    Complex operator-- () //Prefix
    {
        real--;
        return *this;
    }
    Complex operator-- (int) //Postfix
    {
        Complex Temp = *this;
        real--;
        return Temp;
    }
        Complex operator() (int r, int i)
    {
        real = r;
        image = i;
    }
    int operator[] (int a)
    {
        switch(a)
        {
        case 0:
            return real;
            break;
        case 1:
            return image;
            break;
        default:
            break;
        }
    }
    int operator[] (char *a)
    {
        if ("real" == a)
        {
            return real;
        }
        else if ("imag" == a)
        {
            return image;
        }
        else
        {
            return '\0';
        }

    }
};//End of class.

void print (Complex c);
Complex add (Complex c1, Complex c2);
Complex sub (Complex c1, Complex c2);

ostream & operator << (ostream &out, const Complex &c)
{
    out << c.real;
    out << "+i" << c.image << endl;
    return out;
}

istream & operator >> (istream &in,  Complex &c)
{
    cout << "Enter Real Part ";
    in >> c.real;
    cout << "Enter Imaginary Part ";
    in >> c.image;
    return in;
}

int main()
{
    Complex c1, c2, c3, c4, c5;
    c1.setReal(5);
    c1.setImaginary(5);
    c1.print();
    c2.setReal(3);
    c2.setImaginary(3);
    c2.print();
    c3 = c1.add(c2);
    c3.print();
    c4 = c1.sub(c2);
    c4.print();
    c4.setComplex(9,9);
    c4.print();
    print(c1);
    cout<<endl<<"=================================="<<endl;
    c4 = c3+c2;
    c5 = c2-c3;
    c5 = c4;
    cout<<(c5==c4)<<endl;
    c5.print();
    c5 += c4;
    c5.print();
    cout<<endl<<(float)c5<<endl;

    cout<<endl<<++c5<<endl;
    cout<<endl<<c5++<<endl;
    cout<<endl<<--c5<<endl;
    cout<<endl<<c5--<<endl;
    cout<<endl<<c5<<endl;
    cout<<endl<<"=================================="<<endl;
    c5(1,2);
    //cin>>c5;
    cout<<c5<<endl;
    cout<<c5[0]<<endl;
    cout<<c5[1]<<endl;
    cout<<c5["real"]<<endl;
    cout<<c5["imag"]<<endl;


    cout<<endl;
    return 0;
}


void print (Complex c)
{
    int real = c.getReal();
    int imaginary = c.getImaginary();
    cout<<endl<<real;
    if (imaginary>0)
    {
        cout<<"+"<<imaginary<<"J";
    }
    else
    {
        cout<<imaginary<<"J";
    }
}

Complex add (Complex c1, Complex c2)
{
    Complex res;
    res.setReal( c1.getReal() + c2.getReal());
    res.setImaginary( c1.getImaginary() + c2.getImaginary());
    return res;
}

Complex sub (Complex c1, Complex c2)
{
    Complex res;
    res.setReal( c1.real - c2.real);
    res.setImaginary( c1.image - c2.image);
    return res;
}
