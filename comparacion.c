#include <stdio.h>
#include <math.h>
#include <time.h>

double f(double x) {
    return x*x*x - x - 2;
}

double newton(double x) {
    for (int i = 0; i < 20; i++)
        x -= f(x) / (3*x*x - 1);
    return x;
}

double brent(double a, double b) {
    double fa=f(a), fb=f(b), c=a, fc=fa;
    double d=b-a, e=d;

    for(int i=0; i<100; i++) {
        if(fabs(fc)<fabs(fb)) {
            a=b; b=c; c=a;
            fa=fb; fb=fc; fc=fa;
        }

        double m=0.5*(c-b);

        if(fabs(m)<1e-12 || fb==0)
            return b;

        if(fabs(e)>1e-12 && fabs(fa)>fabs(fb)) {
            double s=fb/fa, p, q;

            if(a==c) {
                p=2*m*s;
                q=1-s;
            } else {
                double q1=fa/fc, q2=fb/fc;
                p=s*(2*m*q1*(q1-q2)-(b-a)*(q2-1));
                q=(q1-1)*(q2-1)*(s-1);
            }

            if(p>0) q=-q;
            else p=-p;

            if(2*p < fmin(3*m*q-fabs(1e-12*q),
                           fabs(e*q))) {
                e=d;
                d=p/q;
            } else {
                d=m;
                e=m;
            }
        } else {
            d=m;
            e=m;
        }

        a=b;
        fa=fb;

        b += fabs(d)>1e-12 ? d : (m>0 ? 1e-12 : -1e-12);
        fb=f(b);

        if((fb>0 && fc>0) || (fb<0 && fc<0)) {
            c=a;
            fc=fa;
            e=d=b-a;
        }
    }

    return b;
}

int main() {
    const int N=1000000;
    volatile double resultado=0;
    clock_t inicio;

    inicio=clock();

    for(int i=0;i<N;i++)
        resultado += newton(1.5);

    printf("Newton C: %.10f\n", resultado/N);
    printf("Tiempo Newton C: %.6f segundos\n",
           (double)(clock()-inicio)/CLOCKS_PER_SEC);

    resultado=0;
    inicio=clock();

    for(int i=0;i<N;i++)
        resultado += brent(1,2);

    printf("Brent C: %.10f\n", resultado/N);
    printf("Tiempo Brent C: %.6f segundos\n",
           (double)(clock()-inicio)/CLOCKS_PER_SEC);

    return 0;
}
