#include <stdio.h>

#include "dna.h"


void load_string(FILE *file, int *p, char *s, int t) {
    if (fscanf(file, "%d", p) != 1) {
        fprintf(stderr, "erro ao ler string do teste %d\n", t);
    }

    char c;
    do {
        c = getc(file);
    } while (c != '\n');

    fgets(s, *p + 1, file);
}

int max(int a, int b){
  if (a > b){
    return a;
  }
  return b;
}

int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1]) {
  if(n == 0 || m == 0){
    length[n][m] = 0;
  } else if(length[n][m] != -1){
    return length[n][m];
  }else if(a[n-1] == b[m-1]){
    length[n][m] = mlcs_w(a, n-1, b, m-1, length) + 1;
  } else{
    length[n][m] = max(mlcs_w(a, n-1, b, m, length), mlcs_w(a, n, b, m-1, length));
  }
  return length[n][m];
}


int mlcs(char a[], int n, char b[], int m) {
  int length[MAX_SIZE+1][MAX_SIZE+1];

  for(int l = 0; l <= n; l++){
    for(int c = 0; c <= m; c++){
      length[l][c] = -1;
    }
  }
  return mlcs_w(a, n, b, m, length);
}

int dlcs(char a[], int n, char b[], int m) {
  int length[MAX_SIZE+1][MAX_SIZE+1];
  int max_length = 0;

  for(int l = 0; l <= n; l++){
    for(int c = 0; c <= m; c++){
      if(l == 0 || c == 0){
        length[l][c] = 0;
      }
      else if(a[l-1] == b[c-1]){
        length[l][c] = length[l-1][c-1] + 1;
      }
      else{
        length[l][c] = max(length[l-1][c], length[l][c-1]);
      }
      if(length[l][c] > max_length){
        max_length = length[l][c];
      }
    }
  }
  return max_length;
}