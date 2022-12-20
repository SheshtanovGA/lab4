#include <stdio.h>
#include <string.h>
#include <math.h>

char isDigit(char c) {
    if ((c >= '0')&&(c <= '9'))
        return 1;
    return 0;
}

double polynom(const char *expr, double x) {
    char sign[5];
    for (int i = 0; i < 5; i++) sign[i] = '+';
    char e[5] = { 0 };
    char k[5] = { 0 };
    int n = 0;
    int i = 0;
    while (i < strlen(expr)) {
        if (expr[i] == ' ') {
            i++;
            continue;
        }
        if ((expr[i] == 'x')) {
            if (k[n] == 0) {
                k[n] = 1;
            }
            e[n] = 1;
            i++;
            if (expr[i] == '^') {
                i++;
                e[n] = (expr[i] - '0');
                i++;
                n++;            
            } else n++;
            continue;
        }

        if (((expr[i] == '-')||(expr[i] == '+'))) {
            sign[n] = expr[i];
            i++;
            continue;
        }

        if ((isDigit(expr[i]))) {
            k[n] = expr[i] - '0';
            i++;
            while (isDigit(expr[i])) {
                k[n] *= 10;
                k[n] += (expr[i] - '0');
                i++;
            }
            if (expr[i] == '*') {
                i++;
                e[n] = 1;
                i++;
                if (expr[i] == '^') {
                    i++;
                    e[n] = (expr[i] - '0');
                    i++;
                    n++;            
                } else n++;
            } else n++;
            continue;
        }
    }
    for (int i = 0; i < 5; i++) {
        printf("%c %d %d\n", sign[i], k[i], e[i]);
    }
    double result = 0;
    for (int i = 0; i < 5; i++) {
        ( (sign[i] == '+') ? (result += (k[i] * pow(x, e[i]))) : (result -= (k[i] * pow(x, e[i]))) );
    }
    return result;
}

int main() {
    const char *expr = "x^4+15*x^3-3*x^2+x+100";
    double x = 1;

    printf("y(%f)=%s returns %2f", x, expr, polynom(expr, x));
}