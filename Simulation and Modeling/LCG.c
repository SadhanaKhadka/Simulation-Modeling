#include<stdio.h>
#include<conio.h>
int main() {
    int x0, x1, x2;                   // x0=seed, x1=next random number, x2=next next random number
    int a, c, m;                      // a=constant multiplier, c=increment, m=modulus
    int i, n, num, method;
    int array[20];                // to store the random numbers generated
    printf("Choose the method:\n");
    printf("\n1.Linear congruential Method");
    printf("\n2.Exit\n");
    scanf("%d", &method);
    switch(method) {
        case 1:                   // Linear congruential method
            printf("\nEnter the seed value x0: ");
            scanf("%d", &x0);
            printf("\nEnter the modulus m: ");
            scanf("%d", &m);
            printf("\nHow many random numbers you want to generate: ");
            scanf("%d", &n);
            printf("\nWhich method you want to perform");
            printf("\n1.Mixed congruential");
            printf("\n2.Additive congruential");
            printf("\n3.Multiplicative congruential\n");
            scanf("\n%d", &num);
            switch(num) {
                case 1:                      // Mixed congruential
                    printf("\nEnter the constant multiplier a: ");
                    scanf("%d", &a);
                    printf("\nEnter the increment c: ");
                    scanf("%d", &c);
                    if (c != 0) {
                        for(i = 1; i <= n; i++) {                     // loop to generate random numbers
                            x1 = (a * x0 + c) % m;
                            array[i] = x1;
                            x0 = x1;
                        }
                        printf("\nThe generated random numbers are: ");
                        for(i = 1; i <= n; i++) {
                            printf("\nX%d=%d", i, array[i]);
                            printf("\t");
                        }
                    } else {
                        printf("For mixed congruential, the value of c cannot be zero");
                    }
                    break;
                case 2:               // Additive congruential
                    printf("\nEnter the increment c: ");
                    scanf("%d", &c);
                    for(i = 1; i <= n; i++) {
                        x1 = (1 * x0 + c) % m;
                        array[i] = x1;
                        x0 = x1;
                    }
                    printf("\nThe generated random numbers are: ");
                    for(i = 1; i <= n; i++) {
                        printf("\nX%d=%d", i, array[i]);
                        printf("\t");
                    }
                    break;
                case 3:                 // Multiplicative congruential
                    printf("\nEnter the constant multiplier a: ");
                    scanf("%d", &a);

                    for(i = 1; i <= n; i++) {
                        x1 = (a * x0) % m;
                        array[i] = x1;
                        x0 = x1;
                    }
                    printf("\nThe generated random numbers are: ");
                    for(i = 1; i <= n; i++) {
                        printf("\nX%d=%d", i, array[i]);
                        printf("\t");
                    }
                    break;
                default:
                    printf("Please choose either 1 or 2 or 3");
            }
            break;
        case 2:
            break;
        default:
            printf("Please choose either 1 or 2");
    }
    return 0;
}
