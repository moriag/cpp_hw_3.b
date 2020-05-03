#include "solver.hpp"
#include <complex>
#include <iostream>
namespace solver{
    RealVariable RealVariable::operator+(RealVariable real){
        return RealVariable(c+real.c,b+real.b,a+real.a);
    }
    RealVariable RealVariable::operator-(RealVariable real){
        return RealVariable(c-real.c,b-real.b,a-real.a);
    }
    RealVariable RealVariable::operator*(RealVariable real){
        return RealVariable(c*real.c,c*real.b+b*real.c,b*real.b+a*real.c+c*real.a);
    }
    RealVariable RealVariable::operator/(double d){
        if(d==0)throw "ERR: /0";
        return RealVariable(c/d,b/d,a/d);
    }
    RealVariable RealVariable::operator^(int i){
        if(i==2)return (*this) * (*this);
        if(i==1)return *this;
        if(i==0)return RealVariable(1);
        throw "ERR: power must be 0, 1 or 2";            
    }
    RealVariable RealVariable::operator==(RealVariable real){
        return *this-real;
    }
    RealVariable operator * (double d,RealVariable real){
        return real*d;
    }
    RealVariable operator + (double d,RealVariable real){
        return real+d;
    }
    RealVariable operator - (double d,RealVariable real){
        return real-d;
    }
   
    ComplexVariable ComplexVariable::operator+(ComplexVariable comp){
        return ComplexVariable(c+comp.c,b+comp.b,a+comp.a);
    }
    ComplexVariable ComplexVariable::operator-(ComplexVariable comp){
        return ComplexVariable(c-comp.c,b-comp.b,a-comp.a);
    }
    ComplexVariable ComplexVariable::operator*(ComplexVariable comp){
        return ComplexVariable(c*comp.c,c*comp.b+b*comp.c,b*comp.b+a*comp.c+c*comp.a);
    }
    ComplexVariable ComplexVariable::operator/(complex<double> comp){
        if(comp==0.0)throw "ERR: /0";
        return ComplexVariable(c/comp,b/comp,a/comp);
    }
    ComplexVariable ComplexVariable::operator^(complex<double> i){
        if(i==2.0)return *this * *this;
        if(i==1.0)return *this;
        if(i==0.0)return ComplexVariable(1);
        throw "ERR: power must be 0, 1 or 2";  
    }
    ComplexVariable ComplexVariable::operator==(ComplexVariable comp){
        return *this-comp;
    }
    ComplexVariable operator * (std::complex<double> c,ComplexVariable comp){
        return comp*c;
    }
    ComplexVariable operator + (std::complex<double> c,ComplexVariable comp){
        return comp+c;
    }
    ComplexVariable operator - (std::complex<double> c,ComplexVariable comp){
        return comp-c;
    }
    
    
    double solve(RealVariable exp){
        if(exp.a!=0){
            double root =pow(exp.b,2)-4*exp.a*exp.c;
            if(root<0)throw "complex answer to real var";
            return ((-exp.b+ sqrt(root))/(2*exp.a));
        }
        if(exp.b!=0)return -exp.c/exp.b;
        throw "ERR no unknown variable"; 
    }
    std::complex<double> solve(ComplexVariable exp){
        if(exp.a!=0.0){
            complex<double> root = exp.b*exp.b-4.0*exp.a*exp.c;
            return ((-exp.b+ sqrt(root))/(2.0*exp.a));
        }
        if(exp.b!=0.0)return -exp.c/exp.b;
        throw "ERR no unknown variable"; 
    }
}
