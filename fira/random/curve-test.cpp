#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <string>
using namespace std;
double vald(double a[4], double u) {
  double w = 1;
  double ans = 0;
  for (int i = 1; i < 4; i++) {
    ans += w*a[i]*i;
    w *= u;
  }
  return ans;
}
double valdd(double a[4], double u) {
  double w = 1;
  double ans = 0;
  for (int i = 2; i < 4; i++) {
    ans += w*a[i]*i*(i-1);
    w *= u;
  }
  return ans;
}
int main(int argc, char const *argv[])
{
  double a[4], b[4];
  for (int i = 0; i < 4; i++ ) {
    a[3-i] = atof(argv[i+1]);
  }
  for (int i = 0; i < 4; i++ ){ 
    b[3-i] = atof(argv[i+1+4]);
  }
  double u_low, u_high;
  u_low = atof(argv[1+4+4+2+0]);
  u_high = atof(argv[1+4+4+2+1]);
  printf("(x): ");
  for (int i = 0; i < 4; ++i)
  {
    printf("%lf ", a[3-i]);
  }
  printf("\n(y): ");
  for (int i = 0; i < 4; i++) {
    printf("%lf ", b[3-i]);
  }
  printf("\n");
  double t_ext = (b[1]*a[3]-a[1]*b[3])/2./(a[2]*b[3]-b[2]*a[3]);
  printf("text = %lf\n", t_ext);
  double k_ext = (vald(a,t_ext)*valdd(b,t_ext)-vald(b,t_ext)*valdd(a,t_ext))/
    pow(vald(a,t_ext)*vald(a,t_ext)+vald(b,t_ext)*vald(b,t_ext), 1.5);
  printf("k at t_ext = %lf\n", k_ext);
  char buf[2000] = "set parametric\nset dummy t\nset autoscale\nset samples 160\nset title \"\"\nset key box\nset key below\n";
  FILE *dem = fopen("test.dem", "w");
  fprintf(dem, "%s", buf);
  fprintf(dem, "set trange [%lf:%lf]\n", u_low, u_high);
  fprintf(dem, "plot %lf*t*t*t+%lf*t*t+%lf*t+%lf, %lf*t*t*t+%lf*t*t+%lf*t+%lf\n", 
    a[3], a[2], a[1], a[0], b[3], b[2], b[1], b[0]);
  fclose(dem);
  return 0;
}