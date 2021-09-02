#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void Unit_test();
int Quadratic_equation_IO_interface();

/** 
    *Bias of double numbers
*/
const double DELTA = 1E-6; 

enum Num_of_roots{
    UNDEF = 'U',
    ZERO  = '0', 
    ONE   = '1', 
    TWO   = '2', 
    INF   = 'I' 
};

enum Double_comparsion_result{
    LESS  = 'L', 
    EQUAL = 'E', 
    MORE  = 'M'
};

enum Quadratic_equation_status{
    NDEF = 'N',
    DEF  = 'D'
};

/*!
    \brief Quadratic structure.

    Contains the coefficients of the equation and its status. 
*/
struct Quadratic_equation{
    double a;
    double b;
    double c;
    enum Quadratic_equation_status status;
};

/*!
    \brief Solution structure.

    Contains the roots of the equation and their number. 
*/
struct Solution{
    double root1;
    double root2;
    enum Num_of_roots status;
};

/*!
    \brief Test_info structure.

    Contains information about the test model: equation coefficients, correct answers and their number. 
*/
struct Test_info{
    double a;
    double b;
    double c;
    double root1;
    double root2;
    enum Num_of_roots status;
};

/** 
    *Number of input attempts
*/
const int NUM_INPUT = 3; 

/** 
   * Main function. No parametrs.
*/
int main()
{
    Unit_test();
    return Quadratic_equation_IO_interface();
}

/*! 
    Comparing of double numbers.

    \param[in] d1 first number
    \param[in] d2 second number

    \return Result of comparing of double numbers.
*/
enum Double_comparsion_result Comparison_of_double(const double d1, const double d2)
{
    if ( -DELTA < (d1 - d2) && (d1 - d2) < DELTA )
        return EQUAL;
    if ( d1 < d2 )
        return LESS;
    return MORE;        
}

/*! 
    Solving linear equation.

    \param[in] b first coefficient of linear equation
    \param[in] c second coefficient of linear equation

*/
Solution Solve_linear_equation(const double b, const double c)
{
    Solution roots = {NAN, NAN, UNDEF};
    if (Comparison_of_double(b, 0) == EQUAL)
        {
            if (Comparison_of_double(c, 0) == EQUAL)
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

/*! 
    Solve of quadratic equation.

    \param[in] a first coefficient of quadratic equation.
    \param[in] b second coefficient of quadratic equation.
    \param[in] c third coefficient of quadratic equation. 

    \return roots of quadratic equation.
*/
Solution Solve_quadratic_equation( const double a, const double b, const double c )
{
    Solution roots = {NAN, NAN, UNDEF};
    if (Comparison_of_double(a, 0) == EQUAL)
    {
        roots = Solve_linear_equation(b, c);
        if (roots.status != UNDEF)
            return roots;
    }
    const double D = b * b - 4 * a * c;
    if (Comparison_of_double(D, 0) == LESS)
    {
        roots.status = ZERO;
        return roots;
    }    
    if (Comparison_of_double(D, 0) == EQUAL)
    {
        roots.root1 =  -b/(2*a);
        roots.status = ONE;
        return roots;
    }                                                                                                                                                                                                                                        
    const double sqD = sqrt(D);
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

void Clean_output()
{
    while (getchar() != '\n')
        ; 
}

Quadratic_equation Input_of_coefficients()
{
    Quadratic_equation QE = {NAN, NAN, NAN, NDEF};
    if ( scanf("%lf %lf %lf", &QE.a, &QE.b, &QE.c) != 3 )
        { 
            Clean_output();
            printf("Typing error\n");
            QE.status = NDEF;
            return QE;
        } 
    QE.status = DEF;
    return QE;    
}

/*! 
    Analysis of answer.

    \param[in] ans struct of answers.
*/
void Analysis_of_answer( const Solution ans )
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

int Quadratic_equation_IO_interface()
{
    int i = 0;
    Quadratic_equation QE = {NAN, NAN, NAN, NDEF};
    Solution ans = {NAN, NAN, UNDEF};

    Welcome_output();
    QE = Input_of_coefficients();

    for (i = 0; QE.status == NDEF && i < NUM_INPUT; i++ )
    {
        QE = Input_of_coefficients();
    }    

    if ( QE.status == NDEF )
        return 0;

    ans = Solve_quadratic_equation(QE.a, QE.b, QE.c);
    Analysis_of_answer(ans); 
    return 0;
}

/*! 
    Checking of double number.

    \param[in] x double number.

    \return true or false answer.
*/
bool Is_NAN (const double x)
{
    return x != x;  
}

/*! 
    Comprassion of answers.

    \param[in] root1 practical answer.
    \param[in] root2 theoretical answer.

    \return true or false answer.
*/
bool Comparison_of_roots( const double root1, const double root2)
{
    return root1 == root2 || (Is_NAN(root1) && Is_NAN(root2));       
}

void Unit_test()
{
    Solution ans = {NAN, NAN, UNDEF};
    int i = 0;
    const Test_info test[] = {
        {1,  1,  1, NAN, NAN, ZERO },
        {1,  0, -1,   1,  -1, TWO  },
        {1,  2,  1,  -1, NAN, ONE  },
        {0,  0,  0, NAN, NAN, INF  },
        {0,  0,  1, NAN, NAN, ZERO },
        {0,  2, -4,   2, NAN, ONE  }
    };
    int Num = sizeof(test)/sizeof(test[0]);
    for ( i = 0; i < Num; i++ )
    {
        ans.root1 = ans.root2 = NAN;
        ans = Solve_quadratic_equation(test[i].a, test[i].b, test[i].c);

        printf("a = %f, b = %f, c = %f\n",
                test[i].a, test[i].b, test[i].c);
        printf("Got:       x1 = %f, x2 = %f, status = %u\n",
                ans.root1, ans.root2, ans.status);
        printf("Should be: x1 = %f, x2 = %f, status = %u\n",
                test[i].root1, test[i].root2, test[i].status);
        
        if (Comparison_of_roots(ans.root1, test[i].root1) && 
            Comparison_of_roots(ans.root2, test[i].root2) &&
            ans.status == test[i].status )
            printf("    ...Correct\n\n");
        else
            printf("    ...Mistake\n\n");    
    }    
}

//TODO: const ...  done 
//TODO: NAMES!!  done
//TODO: Prototipes  done
//TODO: Clean output done
