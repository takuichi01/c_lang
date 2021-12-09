#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define EPS 1.0e-6

int main()
{
  float a[5][6], piv, del;
  int k, i, j;

  for (k = 1; k <= 4; k++)
  {
    for (j = 1; j <= 5; j++)
    {
      scanf("%f", &a[k][j]);
    }
  }

  for (i = 1; i <= 4; i++)
  {
    piv = a[i][i];
    if (fabs(piv) < EPS)
      exit(1);
    for (j = 1; j <= 5; j++)
    {
      a[i][j] = a[i][j] / piv;
    }

    for (k = 1; k <= 4; k++)
    {
      if (k != i)
      {
        del = a[k][i];
        for (j = 1; j <= 5; j++)
        {
          a[k][j] = a[k][j] - del * a[i][j];
        }
      }
    }
  }

  printf("answer:\n");
  for (i = 1; i <= 4; i++)
  {
    printf("X%d = %f\n", i, a[i][5]);
  }
}