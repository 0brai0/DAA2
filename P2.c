#include <stdio.h>
#include <string.h>

#define MAXCHAR 256

void preprocessShiftTable(int shiftTable[], const char *pattern, int patternLength) {
    for (int i = 0; i < MAXCHAR; i++) {
        shiftTable[i] = patternLength;
    }

    for (int i = 0; i < patternLength - 1; i++) {
        shiftTable[(int)pattern[i]] = patternLength - 1 - i;
    }
}

void horspoolSearch(const char *text, const char *pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    int shiftTable[MAXCHAR];
    preprocessShiftTable(shiftTable, pattern, patternLength);

    int i = patternLength - 1;
    while (i < textLength) {
        int k = 0;
        while (k < patternLength && pattern[patternLength - 1 - k] == text[i - k]) {
            k++;
        }
        
        if (k == patternLength) {
            printf("Pattern found at index %d\n", i - patternLength + 1);
            i += patternLength;
        } else {
            i += shiftTable[(int)text[i]];
        }
    }

    if (i == patternLength - 1) {
        printf("Pattern not found in the text.\n");
    }
}

int main() {
    char text[100];
    char pattern[50];

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter the pattern: ");
    scanf("%s", pattern);

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    horspoolSearch(text, pattern);

    return 0;
}
