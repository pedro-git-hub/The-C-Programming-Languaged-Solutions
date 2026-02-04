#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LENGTH 30

int main(){
    int c, max, length, state, index, height_counter;
    int word_length[MAX_LENGTH];
    state = OUT;
    index = length = 0;
    for (int i = 0; i < MAX_LENGTH; i++)
        word_length[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if ((length >= 2) && (length <= 30)) {
                index = length - 2;
                word_length[index]++;
            }
            state = OUT;
            length = 0;
        } else if (state == OUT) {
            state = IN;
        }
        if (state)
            length++;
    }
    
    if (length >= 2 && length <= 30)
        word_length[length - 2]++;

    // Finding the most repetitions.
    if (word_length[0] >= word_length[1]) {
        max = word_length[0];
    } else {
        max = word_length[1];
    }

    for (int k = 2; k < MAX_LENGTH; k++) {
        if (max < word_length[k]) {
            max = word_length[k];
        }
    }

    height_counter = 0;
    while (height_counter < max) {
    printf("             ");
        for (int p = 0; p < MAX_LENGTH; p++) {
            if (word_length[p] >= (max - height_counter)) {
                printf("  # ");
            } else {
                printf("    ");
            }
        }
        printf("\n");
        height_counter++;
    }

    //  Printing the histogram header.
    printf("Word Length: ");
    for (int j = 0; j < (MAX_LENGTH - 1); j++)
        printf("%3d ", (j + 2));

    // Finding the most repetitions.

    return 0;
}
