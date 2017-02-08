// #include <stdio.h>
// #include <ctype.h>
// #include <stdlib.h>
//
// #define MAXVAL  100 /* maximum depth of val stack */
//
// #define MAXOP   100 /* max size of operand  or operator */
//
// #define NUMBER  '0' /* signal that a number was found */
//
// int sp = 0;         /* next free stack position */
// double val[MAXVAL]; /* value stack */
//
// /* push: push f onto value stack */
// void push(double f){
//     if (sp < MAXVAL)
//         val[sp++] = f;
//     else
//         printf("error: stack full, can't push %g\n", f);
// }
//
// double pop(void){
//     if (sp > 0)
//         return val[--sp];
//     else {
//         printf("error: stack empty\n");
//         return 0.0;
//     }
// }
//
// int getop(char *s, char *op){
//     printf("%s\n", s);
//
//     if (NULL == s) {
//         return EOF;
//     }
//
//     int c = *s++;
//     *op = c;
//
//     if (isdigit(c) || (( c == '+' || c == '-') && isdigit(*s))) {
//         while (isdigit(*++op = c = *s++)) ;
//         if (c == '.'){
//             while (isdigit(*++op = c = *s++)) ;
//         }
//         *++op = '\0';
//         c = NUMBER;
//     } else {
//         *++op = '\0';
//     }
//     return c;
// }
//
// int main(int argc, char *argv[]) {
//     int type;
//     double op2;
//     char s[MAXOP];
//
//     while ((type = getop(*++argv, s)) != EOF) {
//         switch(type) {
//             case NUMBER:
//                 push(atof(s));
//                 break;
//             case '+':
//                 push(pop() + pop());
//                 break;
//             case '*':
//                 push(pop() * pop());
//                 break;
//             case '-':
//                 op2 = pop();
//                 push(pop() - op2);
//                 break;
//             case '/':
//                 op2 = pop();
//                 if (op2 != 0.0)
//                     push(pop() / op2);
//                 else
//                     printf("error: zero divisor\n");
//                 break;
//             case '%':
//                 op2 = pop();
//                 push ((int) pop() % (int) op2);
//                 break;
//             case '\n':
//                 printf ("\t%.8g\n", op2 = pop());
//                 break;
//             default:
//                 printf ("error: unknown command %s", s);
//                 break;
//         }
//     }
//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUMBER '0'

double pop(void);
void push(double);
int getop(char *);

int main(int argc, char *argv[])
{
    int c;
    double op2;

    while (--argc > 0) {
	switch (c = getop(*++argv)) {
	case NUMBER:
	    push(atof(*argv));
	    break;
	case '+':
	    push(pop() + pop());
	    break;
	case '*':
	    push(pop() * pop());
	    break;
	case '-':
	    op2 = pop();
	    push(pop() - op2);
	    break;
	case '/':
	    op2 = pop();
	    if (op2 != 0)
		push(pop() / op2);
	    else
		printf ("error: division by zero\n");
	    break;
	default:
	    printf ("error: invalid operation %c\n", c);
	    return 1;
	    break;
	}
    }
    printf ("\t%f\n", pop());
    return 0;
}

int getop(char *s)
{
    printf("%s\n", s);
    if (!isdigit(s[0]) && s[1] == '\0')
	return s[0];
    return NUMBER;
}

#define STACKSIZE 10000

double val[STACKSIZE]; /* stack value */
int sp = 0; /* stack position: next free position */

double pop(void)
{
    if (sp > 0)
	return val[--sp];
    else
	printf ("error: empty stack\n");
    return 0.0;
}

void push(double f)
{
    if (sp < STACKSIZE)
	val[sp++] = f;
    else
	printf ("error: full stack\n");
}
