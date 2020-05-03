#include <iostream>
#include <complex>
using namespace std;
namespace solver{
    class RealVariable{
        double a;
        double b;
        double c;
        public:
            RealVariable():a(0),b(1),c(0){}
            // RealVariable(int c):a(0),b(0),c(c){cout<<c<<endl;}
            RealVariable(double c,double b=0,double a=0):a(a),b(b),c(c){
                // cout<<c<<endl;
                }
            RealVariable operator+(RealVariable real);
            RealVariable operator-(RealVariable real);
            RealVariable operator*(RealVariable real);
            RealVariable operator/(double d);
            RealVariable operator^(int i);
            RealVariable operator==(RealVariable real);
           
            friend RealVariable operator * (double d,RealVariable real);
            friend RealVariable operator + (double d,RealVariable real);
            friend RealVariable operator - (double d,RealVariable real);
            friend double solve(RealVariable exp);
            
            
           
        
    };
    class ComplexVariable{
        complex<double> a;
        complex<double> b;
        complex<double> c;
        public:
            ComplexVariable():a(0),b(1),c(0){}
            ComplexVariable(double c):a(0),b(0),c(c){}
            ComplexVariable(complex<double> c,complex<double> b=0,complex<double> a=0):a(a),b(b),c(c){}

            ComplexVariable operator+(ComplexVariable comp);
            ComplexVariable operator-(ComplexVariable comp);
            ComplexVariable operator*(ComplexVariable comp);
            ComplexVariable operator/(complex<double> comp);
            ComplexVariable operator^(complex<double> i);
            ComplexVariable operator==(ComplexVariable comp);
            friend ComplexVariable operator * (std::complex<double> c,ComplexVariable comp);
            friend ComplexVariable operator + (std::complex<double> c,ComplexVariable comp);
            friend ComplexVariable operator - (std::complex<double> c,ComplexVariable comp);
            friend complex<double> solve(ComplexVariable exp);
    };

    double solve(RealVariable exp);
    std::complex<double> solve(ComplexVariable exp);

    
    


}