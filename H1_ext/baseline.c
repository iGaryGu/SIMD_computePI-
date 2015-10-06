#include <time.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
double compute_pi(size_t dt)
{
    double pi = 0.0;
    double delta = 1.0 / dt;
    size_t i;
    for (i = 0; i < dt; i++) {
        double x = (double) i / dt;
        pi += delta / (1.0 + x * x);
    }
    return pi * 4.0;
}

int main(int argc, char* argv[])
{
    struct timespec tt1, tt2;
//    double pi;
    FILE* fpr = fopen("baseline_timing.txt","w");
    int i;
    for (i = 10000; i < 400000000; i+=1000000) {
	clock_gettime(CLOCK_REALTIME, &tt1);
	compute_pi(i);
	clock_gettime(CLOCK_REALTIME, &tt2);
	fprintf(fpr, "%d %lf\n", i, tt2.tv_sec-tt1.tv_sec + (tt2.tv_nsec-tt1.tv_nsec)*0.000000001);
    }
    fclose(fpr);
    return 0;
}
