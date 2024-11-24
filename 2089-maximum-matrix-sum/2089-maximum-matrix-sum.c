long long maxMatrixSum(int** matrix, int matrixSize, int* matrixColSize) {
    int min_pol_el = INT_MAX, max_neg_el = INT_MIN;
    int count = 0, iindex_minpol = -1, iindex_maxneg = -1, jindex_minpol = -1, jindex_maxneg = -1;
    for (int i = 0; i < matrixSize; ++i){
        for (int j = 0; j < *matrixColSize; ++j) {
            if (matrix[i][j] < 0) {
                ++count;
                if (matrix[i][j] > max_neg_el){
                    iindex_maxneg = i;
                    jindex_maxneg = j;
                    max_neg_el = matrix[i][j];
                }
            }
            else if (matrix[i][j] < min_pol_el) {
                iindex_minpol = i;
                jindex_minpol = j;
                min_pol_el = matrix[i][j];
            } 
        }
    }
    long  long summa = 0;
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < *matrixColSize; ++j) {
             summa += abs(matrix[i][j]);
        }
    }
    if (count % 2 == 1){
        if (abs(max_neg_el) <= min_pol_el) {
            iindex_minpol = iindex_maxneg;
            jindex_minpol = jindex_maxneg;
        }
        matrix[iindex_minpol][jindex_minpol] = -abs(matrix[iindex_minpol][jindex_minpol]);
        summa += 2* matrix[iindex_minpol][jindex_minpol] ;
    }
    return summa;
}