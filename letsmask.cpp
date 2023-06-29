    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    int comp(const void *a, const void *b) {
    return *(const long long *)b
      - *(const long long *)a;
}
    int main() {
        long long bitmask = 0;
        char str[500001];
        long long arr[1025] = {0};
        arr[0] = 1;
        scanf("%s", str);
        int s =  strlen(str);
        for(int i = 0; i < s; i++) {
            int c = str[i] - '0';
            bitmask = (bitmask ^ (1 << c));
            arr[bitmask]++;
        }
         qsort(arr,1025, sizeof(long long), comp);
         unsigned long long sum = 0;
         for(int i = 0; i < 1025; i++) {
            if(arr[i] <= 1) break;
            sum += ((arr[i] - 1) * (arr[i])) / 2;
         }
          printf("%llu", sum);
            return 0;
    }