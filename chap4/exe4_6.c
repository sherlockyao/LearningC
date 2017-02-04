#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAXOP   100 /* max size of operand  or operator */
#define NVAR    26

#define NUMBER  '0' /* signal that a number was found */
#define SIN     '1'
#define COS     '2'
#define EXP     '3'
#define POW     '4'
#define VAR_SET '5'
#define VAR_GET '6'

int getop(char []);
void push(double);
double pop(void);
double top(void);
int str_cmp(char s1[], char s2[]);

double var[NVAR];

main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
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
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                push ((int) pop() % (int) op2);
                break;
            case SIN:
                push(sin(pop()));
                break;
            case COS:
                push(cos(pop()));
                break;
            case EXP:
                push(exp(pop()));
                break;
            case POW:
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case VAR_SET:
                var[s[0] - 'A'] = top();
                break;
            case VAR_GET:
                push(var[s[0] - 'a']);
                break;
            case '\n':
                printf ("\t%.8g\n", op2 = pop());
                var['R' - 'A'] = op2;
                break;
            default:
                printf ("error: unknown command %s", s);
                break;
        }
    }
    return 0;
}

#define MAXVAL  100 /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f){
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void){
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double top(void){
    if (sp > 0){
        return val[sp - 1];
    } else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next character or numeric operand */
int getop(char s[]){

    int c, next, i;

    while ((s[0] = c = getch()) == ' ' || c == '\t') ;

    if (c == '\n' || c == EOF)
        return c;

    next = getch();
    ungetch(next);

    if (isdigit(c) || (( c == '+' || c == '-') && isdigit(next))){
        s[i = 0] = c;
        while (isdigit(s[++i] = c = getch())) ;
        if (c == '.'){
            while (isdigit(s[++i] = c = getch())) ;
        } else {
            ungetch(c);
        }
        s[i] = '\0';
        c = NUMBER;
    } else if (isalpha(c)){
        i = 0;
        while (isalpha(s[++i] = c = getch())) ;
        ungetch(c);
        s[i] = '\0';
        if (i > 1){
            if (!str_cmp(s, "SIN")){
                return SIN;
            } else if (!str_cmp(s, "COS")){
                return COS;
            } else if (!str_cmp(s, "EXP")){
                return EXP;
            } else if (!str_cmp(s, "POW")){
                return POW;
            } else {
                printf("error: unknow functions %s\n", s);
            }
        } else {
            if  (islower(s[0]))
                return VAR_GET;
            else
                return VAR_SET;
        }
    } else {
        s[0] = c;
        s[1] = '\0';
    }
    return c;
}

#define BUFSIZE 100

int buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next gree position in buf */

int getch(void) /* get a (possibly pushed-back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* get character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int str_cmp(char s1[], char s2[]){
    int i, c;
    for (i = 0; (c = s1[i] - s2[i]) == 0 && s1[i] != '\0'; i++);
    return c;
}
