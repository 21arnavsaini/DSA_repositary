#include <stdio.h>

void strassen(int A[4][4], int B[4][4], int C[4][4])
{
    int A11[2][2], A12[2][2], A21[2][2], A22[2][2];
    int B11[2][2], B12[2][2], B21[2][2], B22[2][2];
    int M1[2][2], M2[2][2], M3[2][2], M4[2][2];
    int M5[2][2], M6[2][2], M7[2][2];
    int T1[2][2], T2[2][2];
     for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + 2];
            A21[i][j] = A[i + 2][j];
            A22[i][j] = A[i + 2][j + 2];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + 2];
            B21[i][j] = B[i + 2][j];
            B22[i][j] = B[i + 2][j + 2];
        }
}
//for m1
 for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            T1[i][j] = A11[i][j] + A22[i][j];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            T2[i][j] = B11[i][j] + B22[i][j];

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            M1[i][j] = T1[i][j] * T2[i][j];
//for m2
for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            M2[i][j] = (A21[i][j] + A22[i][j]) * B11[i][j];
 //for m3
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            M3[i][j] = A11[i][j] * (B12[i][j] - B22[i][j]);
//for m4
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            M4[i][j] = A22[i][j] * (B21[i][j] - B11[i][j]);
//for m5
 for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            M5[i][j] = (A11[i][j] + A12[i][j]) * B22[i][j];
//for m6
 for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            M6[i][j] = (A21[i][j] - A11[i][j])
                     * (B11[i][j] + B12[i][j]);
//for m7
  for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            M7[i][j] = (A12[i][j] - A22[i][j])
                     * (B21[i][j] + B22[i][j]);
//c
  for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];

            C[i][j + 2] = M3[i][j] + M5[i][j];

            C[i + 2][j] = M2[i][j] + M4[i][j];

            C[i + 2][j + 2] =
                M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }
}
int main()
{
    int A[4][4], B[4][4], C[4][4];

    printf("Enter elements of Matrix A (4x4):\n");
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B (4x4):\n");
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C);

    printf("\nResultant Matrix:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}

