#include <stdio.h>
#include <math.h>
double auto_correlation_test(int* data, int n, int lag)
{
    int i;
    double mean = 0.0;
    double var = 0.0;
    double autocorrelation = 0.0;
    double z_value, p_value;
    // calculate mean and variance of the data
    for (i = 0; i < n; i++)
    {
        mean += data[i];
    }
    mean /= (double) n;
    for (i = 0; i < n; i++)
    {
        var += (data[i] - mean) * (data[i] - mean);
    }
    var /= (double) (n - 1);
    // calculate autocorrelation at lag
    for (i = 0; i < n - lag; i++)
    {
        autocorrelation += (data[i] - mean) * (data[i + lag] - mean);
    }
    autocorrelation /= (double) (n - lag);
    autocorrelation /= var;
    // calculate z-value and p-value
    z_value = autocorrelation * sqrt((double) (n - lag) / (1 - autocorrelation * autocorrelation));
    p_value = 0.5 * erfc(-z_value / sqrt(2));
    return p_value;
}
int main(void)
{
    int data[] = {80, 200, 14, 49, 54, 74, 15, 82, 79, 105};
    int n = sizeof(data) / sizeof(data[0]);
    int lag = 1;
    double p_value = auto_correlation_test(data, n, lag);
    printf("Auto Correlation Test p-value at lag %d: %f\n", lag, p_value);
    return 0;
}
