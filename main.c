#include <stdio.h>
float calculateElement(float x, int i, float prev) {
    float res = (-prev * (x*x) * (2*i - 1) * (2*i - 1))/(4 * (i * i) + 2 * i);
    return res;
}

float calculateArshMethodOne(float x, unsigned int n, unsigned int i, float prev, float sum) {
    float output;

    if (n == 1) {
        if (i != 1) {
            prev = calculateElement(x, i, prev);
        } else {
            prev = x;
        }
        sum += prev;
        output = sum;
    } else {
        if (i != 1) {
            prev = calculateElement(x, i, prev);
        } else {
            prev = x;
        }
        sum += prev;
        output = calculateArshMethodOne(x, n - 1, i + 1, prev, sum);
    }

    return output;
}

float methodOne(float x, unsigned int n) {
    //1 - first element index
    //0.0f - initial sum value
    return calculateArshMethodOne(x, n, 1, x, 0.0f);
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

float methodTwo(float x, unsigned int n) {
    return calculateArshMethodTwo(x, n, x).i;
}


float calculateArshMethodThree(float x, unsigned int n, unsigned int i, float prev) {
    float sum = 0.0f;

    if (n == 1) {
        if (i != 1) {
            prev = calculateElement(x, i, prev);
        } else {
            prev = x;
        }
        sum = prev;
    } else {
        if (i != 1) {
            prev = calculateElement(x, i, prev);
        } else {
            prev = x;
        }
        sum += prev + calculateArshMethodThree(x, n-1, i+1, prev);
    }

    return sum;
}

float methodThree(float x, unsigned int n) {
    //1 - first element index
    return calculateArshMethodThree(x, n, 1, x);
}

float methodLoop(float x, float n) {
    float sum = x;
    float prev = x;

    for (int i = 2; i <= n; ++i) {
        prev = calculateElement(x, i, prev);
        sum += prev;
    }

    return sum;
}

int main() {
    printf("%4.6lf\n", methodLoop(0.8f, 5));
    printf("%4.6lf\n", methodOne(0.8f, 5));
    printf("%4.6lf\n", methodTwo(0.8f, 5));
    printf("%4.6lf\n\n", methodThree(0.8f, 5));
    unsigned int n = 1;
    printf("%4.6lf\n", methodLoop(-0.7f, n));
    printf("%4.6lf\n", methodOne(-0.7f, n));
    printf("%4.6lf\n", methodTwo(-0.7f, n));
    printf("%4.6lf\n", methodThree(-0.7f, n));
    return 0;
}
