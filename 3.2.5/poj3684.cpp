#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>


using namespace std;
#define G_COFF 10

#define max(a,b) ((a) > (b) ? (a) : (b))
#define min(a,b) ((a) > (b) ? (b) : (a))

double solve(double height, double t) {
    if(t <= 0) return height;
    double half_time = sqrt(2.0 * height / G_COFF);
    double rt = half_time*2;
    t = t - (int)(t/rt) * rt;
#ifdef DEBUG
    printf("%lf -> %lf\n", half_time, rem);
#endif
    if (t > half_time) t = 2 * half_time - t;
    return height - 0.5 * G_COFF * t * t;
}


#define NUM_MAX 200

// This function doesn't work on GCC(WHY?)
int asc(const void *a1, const void *a2) {
    double da1 = *(double*)a1;
    double da2 = *(double*)a2;
    if(da1 > da2) return 1;
    return -1;
}

int main() {
    int Test;
    scanf("%d", &Test);
    static double arr[NUM_MAX];
    while (Test--){
        int N;
        int height, time;
        int rad;
        scanf("%d %d %d %d", &N, &height, &rad, &time);
        double R = 1.0 * rad / 100;
        for (int i = 0; i < N; i++) {
            arr[i] = solve(height, time - i);
        }
        qsort(arr, N, sizeof(double), asc);
        for (int i = 0; i < N; i++) {
            printf("%.2lf%c", arr[i] + 2 * i * R, (i == N - 1 ? '\n' : ' '));
        }
    }
}
