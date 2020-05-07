#include "solver.hpp"
#include <complex>
#include <iostream>
namespace solver{
    // ####RealVariable####
    //add
    RealVariable RealVariable::operator+(RealVariable real){
        return RealVariable(c+real.c,b+real.b,a+real.a);
    }
    //subtract
    RealVariable RealVariable::operator-(RealVariable real){
        return RealVariable(c-real.c,b-real.b,a-real.a);
    }
    //multiply
    RealVariable RealVariable::operator*(RealVariable real){
        if((real.a!=0&&(a!=0||b!=0))||(a!=0&&(real.b!=0||real.a!=0)))
            throw "power cant be >2";
        return RealVariable(c*real.c,c*real.b+b*real.c,b*real.b+a*real.c+c*real.a);
    }
    //divide
    RealVariable RealVariable::operator/(double d){
        if(d==0)throw "ERR: /0";
        return RealVariable(c/d,b/d,a/d);
    }
    //power
    RealVariable RealVariable::operator^(int i){
        if(i==2)return (*this) * (*this);
        if(i==1)return *this;
        if(i==0)return RealVariable(1);
        throw "ERR: power must be 0, 1 or 2";            
    }
    //move all veriables to the left side
    RealVariable RealVariable::operator==(RealVariable real){
        return *this-real;
    }
    //multiply friend
    RealVariable operator * (double d,RealVariable real){
        return real*d;
    }
    //add to friend
    RealVariable operator + (double d,RealVariable real){
        return real+d;
    }
    //subtract from friend
    RealVariable operator - (double d,RealVariable real){
        return real-d;
    }


    // ####ComplexVariable####
    
    //add
    ComplexVariable ComplexVariable::operator+(ComplexVariable comp){
        return ComplexVariable(c+comp.c,b+comp.b,a+comp.a);
    }
    // subtract
    ComplexVariable ComplexVariable::operator-(ComplexVariable comp){
        return ComplexVariable(c-comp.c,b-comp.b,a-comp.a);
    }
    // multiply
    ComplexVariable ComplexVariable::operator*(ComplexVariable comp){
        if((comp.a!=0.0&&(a!=0.0||b!=0.0))||(a!=0.0&&(comp.b!=0.0||comp.a!=0.0)))
            throw "power cant be >2";
        return ComplexVariable(c*comp.c,c*comp.b+b*comp.c,b*comp.b+a*comp.c+c*comp.a);
    }
    // divid
    ComplexVariable ComplexVariable::operator/(complex<double> comp){
        if(comp==0.0)throw "ERR: /0";
        return ComplexVariable(c/comp,b/comp,a/comp);
    }
    // power
    ComplexVariable ComplexVariable::operator^(complex<double> i){
        if(i==2.0)return *this * *this;
        if(i==1.0)return *this;
        if(i==0.0)return ComplexVariable(1);
        throw "ERR: power must be 0, 1 or 2";  
    }
    // move variables to the left side
    ComplexVariable ComplexVariable::operator==(ComplexVariable comp){
        return *this-comp;
    }
    // multiply friend
    ComplexVariable operator * (std::complex<double> c,ComplexVariable comp){
        return comp*c;
    }
    // add friend
    ComplexVariable operator + (std::complex<double> c,ComplexVariable comp){
        return comp+c;
    }
    // subtract from friend
    ComplexVariable operator - (std::complex<double> c,ComplexVariable comp){
        return comp-c;
    }
    
// ######solve########

    // calculate and solve for RealVariables
    double solve(RealVariable exp){
        if(exp.a!=0){
            double root =pow(exp.b,2)-4*exp.a*exp.c;
            if(root<0)throw "complex answer to real var";
            return ((-exp.b+ sqrt(root))/(2*exp.a));
        }
        if(exp.b!=0)return -exp.c/exp.b;
        throw "ERR no unknown variable"; 
    }
    // calculate and solve for ComplexVariables
    std::complex<double> solve(ComplexVariable exp){
        if(exp.a!=0.0){
            complex<double> root = exp.b*exp.b-4.0*exp.a*exp.c;
            return ((-exp.b+ sqrt(root))/(2.0*exp.a));
        }
        if(exp.b!=0.0)return -exp.c/exp.b;
        throw "ERR no unknown variable"; 
    }
}
