
void swap(int *, int *);
int part(int *, int, int, int);
void qsort(int *, int, int);

void qsort(int *data, int left, int right) {
  if (right > left) {
    int pivot = left;
    pivot = part(data, pivot, left, right);
    qsort(data, left, pivot - 1);
    qsort(data, pivot + 1, right);
  }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int part(int *data, int pivot, int left, int right) {
  swap(data + pivot, data + right);
  int storeindex = left;
  for (int i = left; i < right; i++) {
    if (data[i] < data[right]) {
      swap(data + i, data + storeindex);
      storeindex++;
    }
  }
  swap(data + right, data + storeindex);
  return storeindex;
}

int main() {
  int origindata[] = {6,    5,   4,   1234, 123523, 546, 3,     234, 457,
                      25,   457, 54,  23,   346,    56,  23,    865, 2345,
                      3545, 12,  223, 536,  453,    745, 23453, 2,   1};

  qsort(origindata, 0, sizeof(origindata) / sizeof(int) - 1);
  return 0;
}