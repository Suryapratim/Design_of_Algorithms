#include <stdio.h>

int main()
{
  int array[100], n, c, d, swap,c1=0,c2=0;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1]) /* For decreasing order use < */
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;c1++;
      }c2++;
    }
  }

  printf("Sorted list in ascending order:\n");

  for (c = 0; c < n; c++)
     {printf("%d\n", array[c]);}
  printf("%d compare & %d swap",c1,c2);

  return 0;
}
