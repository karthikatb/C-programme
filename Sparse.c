#include <stdio.h>
#define MAX 100

void readSparse(int sparse[MAX][MAX], int rows, int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &sparse[i][j]);
        }
    }
}

// Convert 2D matrix to triplet (sparse) form
int sparseToTriplet(int triplet[MAX][3], int sparse[MAX][MAX], int rows, int cols) {
    int k = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(sparse[i][j] != 0) {
                triplet[k][0] = i;
                triplet[k][1] = j;
                triplet[k][2] = sparse[i][j];
                k++;
            }
        }
    }
    triplet[0][0] = rows;
    triplet[0][1] = cols;
    triplet[0][2] = k - 1;
    return k;
}

void displayTriplet(int triplet[MAX][3], int count) {
    printf("Row\tCol\tValue\n");
    for(int i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", triplet[i][0], triplet[i][1], triplet[i][2]);
    }
}

// Add two triplet matrices
int addTriplet(int t1[MAX][3], int t2[MAX][3], int result[MAX][3]) {
    if(t1[0][0] != t2[0][0] || t1[0][1] != t2[0][1]) {
        printf("Matrices cannot be added. Dimensions mismatch.\n");
        return 0;
    }
    int i = 1, j = 1, k = 1;
    result[0][0] = t1[0][0];
    result[0][1] = t1[0][1];
    while(i <= t1[0][2] && j <= t2[0][2]) {
        if(t1[i][0] == t2[j][0] && t1[i][1] == t2[j][1]) {
            int sum = t1[i][2] + t2[j][2];
            if(sum != 0) {
                result[k][0] = t1[i][0];
                result[k][1] = t1[i][1];
                result[k][2] = sum;
                k++;
            }
            i++; j++;
        } else if(t1[i][0] < t2[j][0] || 
                 (t1[i][0] == t2[j][0] && t1[i][1] < t2[j][1])) {
            result[k][0] = t1[i][0];
            result[k][1] = t1[i][1];
            result[k][2] = t1[i][2];
            k++; i++;
        } else {
            result[k][0] = t2[j][0];
            result[k][1] = t2[j][1];
            result[k][2] = t2[j][2];
            k++; j++;
        }
    }
    while(i <= t1[0][2]) {
        result[k][0] = t1[i][0];
        result[k][1] = t1[i][1];
        result[k][2] = t1[i][2];
        k++; i++;
    }
    while(j <= t2[0][2]) {
        result[k][0] = t2[j][0];
        result[k][1] = t2[j][1];
        result[k][2] = t2[j][2];
        k++; j++;
    }
    result[0][2] = k - 1;
    return k;
}

// Compute transpose of a triplet sparse matrix
int transposeTriplet(int triplet[MAX][3], int transpose[MAX][3]) {
    int rows = triplet[0][0];
    int cols = triplet[0][1];
    int nonzeros = triplet[0][2];
    transpose[0][0] = cols;
    transpose[0][1] = rows;
    transpose[0][2] = nonzeros;

    int k = 1;
    for(int col = 0; col < cols; col++) {
        for(int i = 1; i <= nonzeros; i++) {
            if(triplet[i][1] == col) {
                transpose[k][0] = triplet[i][1];
                transpose[k][1] = triplet[i][0];
                transpose[k][2] = triplet[i][2];
                k++;
            }
        }
    }
    return k;
}

int main() {
    int sparse1[MAX][MAX], sparse2[MAX][MAX];
    int triplet1[MAX][3], triplet2[MAX][3], sum[MAX][3], trans[MAX][3];
    int rows1, cols1, rows2, cols2;
    int cnt1, cnt2, cntSum, cntTrans;

    printf("Enter number of rows for matrix 1: ");
    scanf("%d", &rows1);
    printf("Enter number of columns for matrix 1: ");
    scanf("%d", &cols1);
    printf("Enter matrix 1 elements (%dx%d):\n", rows1, cols1);
    readSparse(sparse1, rows1, cols1);
    cnt1 = sparseToTriplet(triplet1, sparse1, rows1, cols1);

    printf("Enter number of rows for matrix 2: ");
    scanf("%d", &rows2);
    printf("Enter number of columns for matrix 2: ");
    scanf("%d", &cols2);
    printf("Enter matrix 2 elements (%dx%d):\n", rows2, cols2);
    readSparse(sparse2, rows2, cols2);
    cnt2 = sparseToTriplet(triplet2, sparse2, rows2, cols2);

    printf("\nMatrix 1 in triplet form:\n");
    displayTriplet(triplet1, cnt1);

    printf("\nMatrix 2 in triplet form:\n");
    displayTriplet(triplet2, cnt2);

    cntSum = addTriplet(triplet1, triplet2, sum);
    if(cntSum == 0) return 1;

    printf("\nSum in triplet form:\n");
    displayTriplet(sum, cntSum);

    cntTrans = transposeTriplet(sum, trans);
    printf("\nTranspose of Sum in triplet form:\n");
    displayTriplet(trans, cntTrans);

    return 0;
}
