#include <stdio.h>
#include <string.h>

void search(char* pat, char* txt) {
    int M = strlen(pat);
    int N = strlen(txt);

    /* A loop to slide pat[] one by one */
    for (int i = 0; i <= N - M; i++) {
        int j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
            printf("Pattern found at index %d \n", i);
    }
}

int main() {
    char txt[1000], pat[1000];
    char txt_file[100], pat_file[100];

    printf("Enter the path of the text file: ");
    scanf("%s", txt_file);
    FILE* txt_ptr = fopen(txt_file, "r");

    if (txt_ptr == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    fgets(txt, sizeof(txt), txt_ptr);

    fclose(txt_ptr);

    printf("Enter the path of the pattern file: ");
    scanf("%s", pat_file);
    FILE* pat_ptr = fopen(pat_file, "r");

    if (pat_ptr == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    fgets(pat, sizeof(pat), pat_ptr);

    fclose(pat_ptr);

    // Remove newline characters if any
    strtok(txt, "\n");
    strtok(pat, "\n");

    // Function call
    search(pat, txt);
    return 0;
}
