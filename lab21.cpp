#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}

ComplexNumber operator+(double r , const ComplexNumber &z){ return ComplexNumber(r+z.real, z.imag); }

ComplexNumber operator-(double r, const ComplexNumber &z){ return ComplexNumber(r-z.real, -1*z.imag); }

ComplexNumber ComplexNumber::operator*(const ComplexNumber &z) { return ComplexNumber((real*z.real)-(imag*z.imag),(imag*z.real)+(z.imag*real)); }
ComplexNumber operator*(double r, const ComplexNumber &z){ return ComplexNumber(z.real*r, z.imag*r); }

ComplexNumber ComplexNumber::operator/(const ComplexNumber &z) {return ComplexNumber(((real*z.real)+(imag*z.imag))/(pow(z.real,2)+pow(z.imag,2)),((imag*z.real)-(real*z.imag))/(pow(z.real,2)+pow(z.imag,2)));}
ComplexNumber operator/(double r, const ComplexNumber &z) { return ComplexNumber(r,0)/z; }

bool ComplexNumber::operator==(const ComplexNumber &z) { return (real == z.real && imag == z.imag);}
bool operator==(double r, const ComplexNumber &z) { return r==z.real&&z.imag == 0;}


double ComplexNumber::abs() { return sqrt(pow(real,2)+pow(imag,2)); }
double ComplexNumber::angle() { return (atan2(imag, real)*180/M_PI);}

ostream & operator<<(ostream &os, const ComplexNumber &z){
	if (z.imag == 0) return os << z.real;
	if (z.real == 0 && z.imag != 0) return os << z.imag << "i";
	if (z.imag >= 0) return os << z.real << "+" << z.imag << "i";
	return os << z.real << z.imag << "i";
}
int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
	cout << b << "\n";
	cout << c << "\n";
	cout << a+2.5 << "\n";
	cout << 2.5+a << "\n";
	cout << a-1.5 << "\n";
	cout << 1.5-a << "\n";
	cout << b+ComplexNumber(0,2.5) << "\n";
	cout << c-c << "\n";
	cout << "-----------------------------------\n";
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << e << "\n";
	cout << c*2 << "\n";
	cout << 0.5*c << "\n";
	cout << 1/c << "\n";
	cout << "-----------------------------------\n";
	
	cout << ComplexNumber(1,1).abs() << "\n";
	cout << ComplexNumber(-1,1).abs() << "\n";
	cout << ComplexNumber(1.5,2.4).abs() << "\n";
	cout << ComplexNumber(3,4).abs() << "\n";
	cout << ComplexNumber(69,-9).abs() << "\n";		
	cout << "-----------------------------------\n";	
	
	cout << ComplexNumber(1,1).angle() << "\n";
	cout << ComplexNumber(-1,1).angle() << "\n";
	cout << ComplexNumber(-1,-1).angle() << "\n";
	cout << ComplexNumber(1,-1).angle() << "\n";
	cout << ComplexNumber(5,2).angle() << "\n";
	cout << "-----------------------------------\n";
	
	cout << (ComplexNumber(1,1) == ComplexNumber(1,2)) << "\n";
	cout << (ComplexNumber(1,1) == 1) << "\n";
	cout << (0 == ComplexNumber()) << "\n";
}





