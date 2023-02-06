/*
 * Makes a Sierpinski triangle using the Pascal triangle
 */

#include <stdio.h>

unsigned long long int pascal_values (int n, int r, int sto[]){
    if (r == 0 || r == n)
        return 1;
    if (r == 1 || r == n - 1)
        return n&1;
    else
        return (sto[r] + sto[r + 1])&1;
}

void main (){
    int in, loop1, loop2, loop3, temp1, temp2 = 1;

    printf ("Enter the level of Sierpinski triangle: ");
    scanf ("%d", &in);

    int sto[in + 1];

    for (loop1 = 0; loop1 <= in; loop1++){
        for (loop2 = 0; loop2 < in - loop1; loop2++)
            printf (" ");
        for (loop3 = 0; loop3 <= loop1; loop3++){
            temp1 = pascal_values (loop1, loop3, sto);
            if (!temp1)
                printf ("  ");
            else
                printf ("A ");

            sto[loop3] = temp2;
            temp2 = temp1;
        }
        printf ("\n");
    }

    printf ("\n");
    main();
}
