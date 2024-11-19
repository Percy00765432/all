#include <stdio.h>
#include <math.h>
void main()
{
    int a,b,c,d;
    float root1,root2,imaginary,real;
    printf("Enter the three coefficients: ");
    scanf("%d%d%d",&a,&b,&c);
    d=(b*b)-(4*a*c);
    if (d > 0) {
        root1 = (-b + sqrt(d)) / (2 * a);
        root2 = (-b - sqrt(d)) / (2 * a);
        printf("Two real and different roots are: %f  %f\n", root1, root2);
    }
    else if (d == 0) {
        root1 = -b / (2.0 * a);
        printf("Two real and equal roots are: %f  %f\n", root1, root1);
    }
    else {
        real = -b / (2.0 * a);
        imaginary = sqrt(-d) / (2 * a);
        printf("The roots are complex and imaginary:\n");
        printf("%f + %fi and %f - %fi\n", real, imaginary, real, imaginary);
    }

}