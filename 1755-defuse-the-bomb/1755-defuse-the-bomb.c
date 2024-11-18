/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* decrypt(int* code, int codeSize, int k, int* returnSize) {
    int* ans = (int*)malloc(codeSize * sizeof(int));
    if (ans == NULL){
        *returnSize = 0;
        return 0;
    }
    *returnSize = codeSize;
    for (int i = 0; i < codeSize; ++i){
        ans[i] = 0;
    }
    if (k > 0){
        for (int i = 0; i < codeSize; ++i){
            for (int j = 1; j <= k; ++j){
                ans[i] += code[(i+j)%codeSize];
            }
        }
    }
    else if (k < 0){
        for (int i = 0; i < codeSize; ++i){
            for (int j = 1; j <= -k; ++j){
                ans[i] += code[(i-j+codeSize) % codeSize];
            }
        }
    }
    return ans;
}