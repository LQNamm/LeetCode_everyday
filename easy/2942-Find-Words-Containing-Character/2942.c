/**
 * Problem 2942 - Find Words Containing Character
 *
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * Author: Lê Quốc Nam
 * Date: 2025-05-24
 */

int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
    int* result = (int*)malloc(wordsSize * sizeof(int));
    *returnSize = 0;

    for(int i = 0; i < wordsSize; i++){
        if (strchr(words[i], x) != NULL) {
            result[(*returnSize) ++] = i;
        }
    }
    return result;
}
