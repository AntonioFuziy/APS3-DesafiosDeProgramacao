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
    if(m == 0 || n == 0){
        return 0;
    } else if(a[n-1] == b[m-1]){
        return mlcs_w(a, n-1, b, m-1, length) + 1;
    }

    return max(mlcs_w(a, n-1, b, m, length), mlcs_w(a, n, b, m-1, length));
}


int mlcs(char a[], int n, char b[], int m) {
    int length[MAX_SIZE+1][MAX_SIZE+1];

    for(int l = 0; l < m; l++){
        for(int i = 0; i < n; i++){
            length[l][i] = a[i];
        }   
    }

    for(int c = 0; c < n; c++){
        for(int j = 0; j < m; j++){
            length[j][c] = b[j];
        }
    }

    return mlcs_w(a, n, b, m, length);
}


int dlcs(char a[], int n, char b[], int m) {
    int length[n][m];

    for(int l = 0; l < m; l++){
        for(int i = 0; i < n; i++){
            length[l][i] = a[i];
        }   
    }

    for(int c = 0; c < n; c++){
        for(int j = 0; j < m; j++){
            length[j][c] = b[j];
        }
    }

    if(n == 0 || m == 0){
        return 0;
    } else if(a[n-1] == b[m-1]){
        return length[n-1][m-1] + 1;
    }
    return max(length[n-1][m], length[n][m-1]);
}
