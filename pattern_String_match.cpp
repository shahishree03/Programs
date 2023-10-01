#include <stdio.h>
#include <string.h>

int main() {
    char text[100], pattern[100];

    printf("Enter a text: ");
    scanf("%s", text);

    printf("Enter a pattern: ");
    scanf("%s", pattern);

    printf("\nYou entered: %s\n", text);
    printf("You entered: %s\n", pattern);

    int n = strlen(text);
    int m = strlen(pattern);

    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == m) {
                printf("Pattern found at index %d\n", i - j);
                j = 0;
            }
        } else {
            if (j != 0) {
                j = 0;
            } else {
                i++;
            }
        }
    }

    return 0;
}
