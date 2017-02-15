#include <sys/time.h>

int main()
{
  timeval timeBefore, timeAfter;
  long diffSeconds, diffUSeconds;

  int step = 1000, n = 100000, A[n], *smallA;

  for (int i = 0; i < n; i++) // make a random master array
    A[i] = rand() % n;

  /*----- Do this for each sorting algorithm ------*/
  cout << "Heap Sort" << endl;
  for (int len = step; len <= n; len += step)
  {
    smallA = new int[len];
    for (int j = 0; j < len; j++) // make a fresh slice for each run
      smallA[j] = A[j];

    gettimeofday(&timeBefore, NULL);
    heapSort(smallA);
    gettimeofday(&timeAfter, NULL);

    diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;
    diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec;
    cout << "n = " << len << ": " << diffSeconds + diffUSeconds/1000000.0 << " seconds" << endl;

    delete [] smallA;
  }
  return 0;
}
