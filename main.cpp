#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

const double delta = 1E-6;
 enum NumOfRoots{
        Zero, 
        One, 
        Two, 
        Infinity 
    };

enum Comparison{
        Less, 
        Equal, 
        More
    };


struct Solve{
    double root1;
    double root2;
    enum NumOfRoots k;
};

#define INIT_Solve(X) Solve X = {.root1 = NAN, .root2 = NAN, .k = Zero}


enum Comparison Comparison_of_double(double d1, double d2)
{
    if ( -delta < (d1 - d2) && (d1 - d2) < delta )
        return Equal;
    if ( d1 < d2 )
        return Less;
    return More;        
}

double Solve_of_a_linear_equation(double b, double c)
{
    if ( Comparison_of_double(b, 0) != Equal)
        return -c/b;
    return NAN;    
}

Solve Solve_of_a_quadratic_equation( double a, double b, double c )
{
    double D = 0;
    //Solve roots;
    INIT_Solve(roots);
    //roots = {NAN, NAN, Zero};
    //roots.root1 = roots.root2 = NAN;
    //roots.k = Zero;
    // 0 - no roots, 1 - one root, 2 - two roots, 3 - inf of roots
    if (Comparison_of_double(a, 0) == Equal)
    {
        if (Comparison_of_double(b, 0) == Equal)
        {
            if (Comparison_of_double(c, 0) == Equal)
            {
                roots.k = Infinity;
                return roots;
            }
            else 
            {
                roots.k = Zero;
                return roots; 
            }
        }
        roots.root1=roots.root2=Solve_of_a_linear_equation(b, c);
        roots.k = One;
        return roots;
    }
    D = b * b - 4 * a * c;
    if (Comparison_of_double(D, 0) == Less)
    {
        roots.k = Zero;
        return roots;
    }    
    if (Comparison_of_double(D, 0) == Equal)
    {
        roots.root1 = roots.root2 = -b/(2*a);
        roots.k = One;
        return roots;
    }
    D = sqrt(D);
    roots.root1 = (-b + D)/(2*a);
    roots.root2 = (-b - D)/(2*a);
    roots.k = Two;
    return roots;
}

//гит клон и адрес
//гит стадж
//enum(на счёт к)
int Quadratic_equation()
{
    double a = 0, b = 0, c = 0;
    INIT_Solve(ans);
    ans.root1 = ans.root2 = NAN; 
    ans.k = Zero;
    printf("Enter the coefficients of the quadratic equation a, b, c in this order separated by spaces." 
    "Put numbers and nothig more!"
    "(Everything that you enter after these numbers does not interest the program!)\n");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
        { 
          printf("Typing error\n");
          return 0;
        }
    ans = Solve_of_a_quadratic_equation(a, b, c);
    if ( ans.k == Zero )
        printf("No roots\n");
    if ( ans.k == One )
        printf("One root is %lf\n", ans.root1);
    if ( ans.k == Two) 
        printf("Two roots: %lf and %lf\n", ans.root1, ans.root2);   
    if ( ans.k == Infinity )  
        printf("Inf of roots\n");      
    return 0;
}

void unit_test()
{
    INIT_Solve(ans);
    ans = Solve_of_a_quadratic_equation(1, 1, 1);
    if ( ans.k != Zero )
        printf("Error 1 in Unit test!!\n");

    ans = Solve_of_a_quadratic_equation(0, 0, 1);
    if ( ans.k != Zero )
        printf("Error 2 in Unit test!!\n");  

    ans = Solve_of_a_quadratic_equation(0, 2, 4);
    if ( ans.k != One || Comparison_of_double(-2, ans.root1) != Equal)
        printf("Error 3 in Unit test!!\n");

    ans = Solve_of_a_quadratic_equation(1, -4, 4);
    if ( ans.k != One || Comparison_of_double(2, ans.root1) != Equal)
        printf("Error 4 in Unit test!!\n");    

    ans = Solve_of_a_quadratic_equation(1, 0, -1);
    if ( ans.k != Two || Comparison_of_double(1, ans.root1) != Equal || Comparison_of_double(-1, ans.root2) != Equal )
        printf("Error 5 in Unit test!!\n");           
}


int main()
{
    unit_test();
    return Quadratic_equation();
}
