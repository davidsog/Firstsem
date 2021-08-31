#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

const double delta = 1E-6;

enum NumOfRoots{
        UNDEF = -1,
        ZERO, 
        ONE, 
        TWO, 
        INF 
    };

enum Comparison{
        Less, 
        Equal, 
        More
    };

enum Condition
{
    NDEF,
    DEF
};    

struct Quadratic_equ{
    double a;
    double b;
    double c;
    enum Condition status;
};


struct Solve{
    double root1;
    double root2;
    enum NumOfRoots status;
};

struct Test_example{
    double a;
    double b;
    double c;
    double root1;
    double root2;
    enum NumOfRoots status;
} ;

const int Num_of_unit_tests = 6;

enum Comparison Comparison_of_double(double d1, double d2)
{
    if ( -delta < (d1 - d2) && (d1 - d2) < delta )
        return Equal;
    if ( d1 < d2 )
        return Less;
    return More;        
}

Solve Solve_of_a_linear_equation(double b, double c)
{
    Solve roots = {NAN, NAN, UNDEF};
    if (Comparison_of_double(b, 0) == Equal)
        {
            if (Comparison_of_double(c, 0) == Equal)
            {
                roots.status = INF;
                return roots;
            }
            else 
            { 
                roots.status = ZERO;
                return roots; 
            }
        }
        roots.root1= -c/b;
        roots.status = ONE;
        return roots;
}

Solve Solve_of_a_quadratic_equation( double a, double b, double c )
{
    double D =  NAN, sqD = NAN;
    Solve roots = {NAN, NAN, UNDEF};
    if (Comparison_of_double(a, 0) == Equal)
    {
        roots = Solve_of_a_linear_equation(b, c);
        if (roots.status != UNDEF)
            return roots;
    }
    D = b * b - 4 * a * c;
    if (Comparison_of_double(D, 0) == Less)
    {
        roots.status = ZERO;
        return roots;
    }    
    if (Comparison_of_double(D, 0) == Equal)
    {
        roots.root1 =  -b/(2*a);
        roots.status = ONE;
        return roots;
    }                                                                                                                                                                                                                                           D = 0;
    sqD = sqrt(D);
    roots.root1 = (-b + sqD)/(2*a);
    roots.root2 = (-b - sqD)/(2*a);
    roots.status = TWO;
    return roots;
}

void Welcome_output()
{
    printf("Enter the coefficients of the quadratic equation a, b, c in this order separated by spaces." 
    "Put numbers and nothig more!"
    "(Everything that you enter after these numbers does not interest the program!)\n");
}

Quadratic_equ Input_of_coefficients()
{
    Quadratic_equ QE = {NAN, NAN, NAN, NDEF};
    if ( scanf("%lf %lf %lf", &QE.a, &QE.b, &QE.c) != 3 )
        { 
            scanf("%*s"); //TODO: Clean output
            printf("Typing error\n");
            QE.status = NDEF;
            return QE;
        } 
    QE.status = DEF;
    return QE;    
}

void Analysis_of_answer( Solve ans )
{
    switch( ans.status )
    {
        case UNDEF:
            printf("NO ANSWERS\n");
            break;    

        case ZERO:
            printf("No roots\n");
            break;

        case ONE:
            printf("One root is %lf\n", ans.root1);
            break;

        case TWO: 
            printf("Two roots: %lf and %lf\n", ans.root1, ans.root2); 
            break;  

        case INF:  
            printf("Inf of roots\n");
            break;
    }     
}

int Input_and_solution_quadratic_equation()
{
    int i = 0;
    Quadratic_equ QE = {NAN, NAN, NAN, NDEF};
    Solve ans = {NAN, NAN, UNDEF};

    Welcome_output();
    QE = Input_of_coefficients();

    for (i = 0; QE.status == NDEF && i < 3; i++ )
    {
        QE = Input_of_coefficients();
    }    

    if ( QE.status == NDEF )
        return 0;

    ans = Solve_of_a_quadratic_equation(QE.a, QE.b, QE.c);
    Analysis_of_answer(ans); 
    return 0;
}

int IsNAN (double x)
{
    if (x != x)
        return 1;
    return 0;    
}

void unit_test()
{
    Solve ans = {NAN, NAN, UNDEF};
    int i = 0;
    Test_model test[Num_of_unit_tests] = {
        {1, 1, 1, NAN, NAN, ZERO},
        {1, 0, -1, 1, -1, TWO},
        {1, 2, 1, -1, NAN, ONE},
        {0, 0, 0, NAN, NAN, INF},
        {0, 0, 1, NAN, NAN, ZERO},
        {0, 2, -4, 2, NAN, ONE}
    };

    for ( i = 0; i < Num_of_unit_tests; i++ )
    {
        ans.root1 = ans.root2 = NAN;
        ans = Solve_of_a_quadratic_equation(test[i].a, test[i].b, test[i].c);

        printf("a = %f, b = %f, c = %f\n", test[i].a, test[i].b, test[i].c);
        printf("Got:       x1 = %f, x2 = %f, status = %u\n", ans.root1, ans.root2, ans.status);
        printf("Should be: x1 = %f, x2 = %f, status = %u\n", test[i].root1, test[i].root2, test[i].status);
        
        if ((ans.root1 == test[i].root1 || (IsNAN(ans.root1) && IsNAN(test[i].root1)) && 
            (ans.root2 == test[i].root2 || (IsNAN(ans.root1) && IsNAN(test[i].root1))) && ans.status == test[i].status ))
            printf("    ...Correct\n\n");
        else
            printf("    ...Mistake\n\n");    
    }    
}

int main()
{
    unit_test();
    return Input_and_solution_quadratic_equation();
}
//TODO: const ...
//TODO: NAMES!!
//TODO: prototipes
