/**
 * Problem 2942 - Find Words Containing Character
 *
 * Note: Use a frequency matrix to pair each word with its reverse and add one symmetric word in the center.
 *
 * Author: Lê Quốc Nam
 * Date: 2025-05-25
 */

int longestPalindrome(char** words, int wordsSize) {
    int count[26][26] = {0};
    int result = 0, tick = 2, a = 0,b = 0;

    for(int i = 0; i < wordsSize; i++){
        a = words[i][0] - 'a';
        b = words[i][1] - 'a';

        if(count[b][a] > 0){
            result += 4;
            count[b][a]--;
        }else{
            count[a][b]++;
        }
    }

    for(int i = 0; i < 26; i++){
        if(count[i][i] > 0){
            result += tick;
            tick = 0;
            break;
        }
    }
    return result;
}