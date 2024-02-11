#include <stdio.h>
//(-f * (x*x) * (2*i - 1) * (2*i - 1))/(4 * (i * i) + 2 * i);
float calculateElement(float x, float i, float prev) {
    float res = (-prev * (x*x) * (2*i - 1) * (2*i - 1))/(4 * (i * i) + 2 * i);
//    printf(" el = %4.6lf\n", res);
    return res;
}

unsigned int calculateI(unsigned int n) {
    return (n + 1) - n;
}

float calculateArshMethodOne(float x, unsigned int n, float prev, float p) {
    float i = 0.0f;

    if (n == 1) {
        i = p;
        printf("x = %4.6lf; n = %d; prev = %4.6lf; p = %4.6lf;\n", x, n, prev, p);
    } else {
        prev = calculateElement(x, calculateI(n), prev);
        p += prev;
        i = calculateArshMethodOne(x, n-1, prev, p);
        printf("x = %4.6lf; n = %d; prev = %4.6lf; p = %4.6lf;\n", x, n, prev, p);
    }


    return i;
}

struct Result {
    float i;
    float prev;
};

struct Result calculateArshMethodTwo(float x, unsigned int n, float prev) {
    struct Result r;

    if (n == 1) {
        r.i = x;
        r.prev = x;
        return r;
    }
    r = calculateArshMethodTwo(x, n-1, prev);
    r.prev = calculateElement(x, n, r.prev);
    r.i += r.prev;


    return r;
}

float calculateArshLoop(float x, float n) {
//    printf("%d\n", 1);
    float sum = x;
    float prev = x;
//    printf("i = %d, prev = %4.6lf\n", 1, prev);
    for (int i = 2; i <= n; ++i) {
//        printf("%d\n", i);
        prev = calculateElement(x, i, prev);
//        printf("i = %d, prev = %4.6lf\n", i, prev);
        sum += prev;
    }

    return sum;
}




int main() {
    printf("%4.6lf\n", calculateArshLoop(0.8f, 5));
//    printf("%4.6lf", calculateArshMethodTwo(0.8f, 5, 0.8f).i);
    printf("%4.6lf", calculateArshMethodOne(0.8f, 5, 0.8f, 0.0f));
    return 0;
}
