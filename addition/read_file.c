#include <stdio.h>
#include <string.h>

int main() {
    char word[50];
    printf("Enter a word: ");
    scanf("%s", word);

    char file_name[50];
    printf("Enter a file name: ");
    scanf("%s", file_name);

    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Could not open file\n");
        return 1;
    }

    int count = 0;
    char current_word[50];
    while (fscanf(file, "%s", current_word) != EOF) {
        if (strcmp(current_word, word) == 0) {
            count++;
        }
    }

    printf("'%s' occurs %d times in %s\n", word, count, file_name);

    fclose(file);
}
