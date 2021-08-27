#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

const double delta = 1E-6;
struct answers{
    double root1;
    double root2;
    int k;
};


int Comparison_of_double(double d1, double d2)
{
    if ( -delta < (d1 - d2) && (d1 - d2) < delta )
        return 1;
    return 0;    
}

double Solution_of_a_lineal_equation(double b, double c)
{
    return -c/b;
}

answers Solution_of_a_quadratic_equation( double a, double b, double c )
{
    double D = 0;
    answers roots;
    roots = {NAN, NAN, 0};
    // 0 - no roots, 1 - one root, 2 - two roots, 3 - inf of roots
    if (Comparison_of_double(a, 0))
    {
        if (Comparison_of_double(b, 0))
            if (Comparison_of_double(c, 0))
            {
                roots.k = 3;
                return roots;
            }
        roots.root1=roots.root2=Solution_of_a_lineal_equation(b, c);
        roots.k = 1;
        return roots;
    }
    D = b * b - 4 * a * c;
    if (D < 0)
    {
        roots.k = 0;
        return roots;
    }    
    if (Comparison_of_double(D, 0))
    {
        roots.root1 = roots.root2 = -b/(2*a);
        roots.k = 1;
        return roots;
    }
    D = sqrt(D);
    roots.root1 = (-b + D)/(2*a);
    roots.root2 = (-b - D)/(2*a);
    roots.k = 2;
    return roots;
}


int Quadratic_equation()
{
    double a = 0, b = 0, c = 0;
    answers ans;
    ans.k = ans.root1 = ans.root2 = 0; 
    printf("Enter the coefficients of the quadratic equation a, b, c in this order separated by spaces." 
    "Put numbers and nothig more!"
    "(Everything that you enter after these numbers does not interest the program!)\n");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
        { 
          printf("Uncorrect\n");
          return 0;
        }
    ans = Solution_of_a_quadratic_equation(a, b, c);
    if ( Comparison_of_double(ans.k, 0) )
        printf("No roots\n");
    if ( Comparison_of_double(ans.k, 1) )
        printf("One root is %lf\n", ans.root1);
    if ( Comparison_of_double(ans.k, 2) ) 
        printf("Two roots: %lf and %lf\n", ans.root1, ans.root2);   
    if ( Comparison_of_double(ans.k, 3) )  
        printf("Inf of roots\n");      
    return 0;
}

void unit_test()
{
    int k = 0;
    for(k = 0; k < 100; k++)
        Solution_of_a_quadratic_equation(rand(), rand(), rand());    
}

int main()
{
    unit_test();
    return Quadratic_equation();
}
