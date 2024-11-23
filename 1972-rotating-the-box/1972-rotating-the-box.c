void Swap(char* a, char* b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
char** rotateTheBox(char** box, int boxSize, int* boxColSize, int* returnSize, int** returnColumnSizes){
    char **arr = (char **)malloc(*boxColSize * sizeof(char *));
    if (arr == NULL) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < *boxColSize; ++i) {
        arr[i] = (char *)malloc(boxSize  * sizeof(char)); 
        if (arr[i] == NULL) {
            *returnSize = 0;
            return NULL;
        }
    }
    for (int i = 0; i < *boxColSize; ++i) {
        for (int j = 0; j < boxSize; ++j) {
            arr[i][j] = box[boxSize -1 - j][i];
        }
    }
 
    for (int i = *boxColSize-2; i > -1; --i) {
        for (int j = 0; j < boxSize; ++j) {
            if (arr[i][j] == '#') {
                int k = 1;
                while (i + k < *boxColSize && arr[i + k][j] == '.') {
                    Swap(&arr[i + k - 1][j], &arr[i + k][j]);
                    ++k;
                }
            }
        }
    }
    *returnSize = *boxColSize;
    *returnColumnSizes = (int *)malloc(*boxColSize * sizeof(int));
    if (*returnColumnSizes == NULL) {
        *returnSize = 0;
        return NULL;
    }
    for (int i = 0; i < *boxColSize; ++i) {
        (*returnColumnSizes)[i] = boxSize;
    }
    return arr;
}