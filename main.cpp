#include <stdio.h>
#include <math.h>
#include <string.h>

struct answers{
    double root1;
    double root2;
    int k;
};
/*int Equation1( double a, double b, double c )
{
    double disk = 0, root1 = 0, root2 = 0;
    if (a == 0)
    {
        if (b == 0)
            if (c == 0)
            {
                printf("Inf of roots\n");
                return 0;
            }
        root1=root2=-c/b;
        printf("One root of lineal is %lf\n", root1);
        return 0;
    }
    disk = b*b - 4*a*c;
    if (disk < 0)
    {
        printf("No roots\n");
        return 0;
    }    
    if (disk == 0)
    {
        root1 = root2 = -b/(2*a);
        printf("One root is %lf\n", root1);
        return 0;
    }
    disk = sqrt(disk);
    root1 = (-b + disk)/(2*a);
    root2 = (-b - disk)/(2*a);
    printf("Two roots: %lf and %lf\n", root1, root2);
    return 0;
}


int main1()
{
    double a = 0, b = 0, c = 0;
    
    return (printf("Put numbers and nothig more!(Everything that you enter after these numbers does not interest the program!)\n") && ((scanf("%lf %lf %lf", &a, &b, &c) != 3 || Equation1
    (a, b,c)) && printf("Uncorrect\n")));
    
}*/

answers Equation2( double a, double b, double c )
{
    double disk = 0;
    answers roots;
    roots.root1 = roots.root2 = roots.k = 0;
    // 0 - no roots, 1 - one root, 2 - two roots, 3 - inf of roots
    if (a == 0)
    {
        if (b == 0)
            if (c == 0)
            {
                roots.k = 3;
                return roots;
            }
        roots.root1=roots.root2=-c/b;
        roots.k = 1;
        return roots;
    }
    disk = b*b - 4*a*c;
    if (disk < 0)
    {
        roots.k = 0;
        return roots;
    }    
    if (disk == 0)
    {
        roots.root1 = roots.root2 = -b/(2*a);
        roots.k = 1;
        return roots;
    }
    disk = sqrt(disk);
    roots.root1 = (-b + disk)/(2*a);
    roots.root2 = (-b - disk)/(2*a);
    roots.k = 2;
    return roots;
}

int main()
{
    double a = 0, b = 0, c = 0;
    answers ans;
    ans.k = ans.root1 = ans.root2 = 0; 

    printf("Put numbers and nothig more!(Everything that you enter after these numbers does not interest the program!)\n");
    if (scanf("%lf %lf %lf", &a, &b, &c) != 3)
        { 
          printf("Uncorrect\n");
          return 0;
        }
    ans = Equation2(a, b, c);
    if ( ans.k == 0 )
        printf("No roots\n");
    if ( ans.k == 1 )
        printf("One root is %lf\n", ans.root1);
    if ( ans.k == 2 ) 
        printf("Two roots: %lf and %lf\n", ans.root1, ans.root2);   
    if ( ans.k == 3 )  
        printf("Inf of roots\n");      
    return 0;
}

