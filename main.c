#include <stdio.h>
//(-f * (x*x) * (2*i - 1) * (2*i - 1))/(4 * (i * i) + 2 * i);
float calculateElement(float x, float i, float prev) {
    return (-prev * (x*x) * (2*i - 1) * (2*i - 1))/(4 * (i * i) + 2 * i);
}

struct Result {
    float i;
    float prev;
};

struct Result calculateArsh(float x, unsigned int n, float prev) {
    float i = 0.0f;
    struct Result r;


    if (n == 1) {
        printf("i = %d, prev = %4.6lf\n", n, prev);
        r.i = x;
        r.prev = x;
        return r;
    }
    r.prev = calculateElement(x, n, prev);
    printf("i = %d, prev = %4.6lf\n", n, r.prev);
    r.i += calculateArsh(x, n-1, prev).i;

    return r;
}

float calculateArshLoop(float x, float n) {
    printf("%d\n", 1);
    float sum = x;
    float prev = x;
    printf("i = %d, prev = %4.6lf\n", 1, prev);
    for (int i = 2; i <= n; ++i) {
        printf("%d\n", i);
        prev = calculateElement(x, i, prev);
        printf("i = %d, prev = %4.6lf\n", i, prev);
        sum += prev;
    }

    return sum;
}




int main() {
    printf("%4.6lf\n", calculateArshLoop(0.8f, 5));
    printf("%4.6lf", calculateArsh(0.8f, 5, 0.8f).i);
    return 0;
}
