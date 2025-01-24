#include <stdio.h>

// general functions
int factorial(int number) {
    int i;
    int fact = 1;
    if(number < 0) {
        printf("Error: entered invalid input, returning 0!\n");
        return 0;
    }
    for(i = 2; i <= number; i++) {
        fact *= i;
    }
    return fact;
}
int findMax(int array[], int length) {
    int i, j;
    int counter;
    for(i = 0; i < length; i++) {
        counter = 0;
        for(j = 0; j < length; j++) {
            if(array[i] >= array[j]) {
                counter++;
            }
        }
        if(counter == length) {
            return array[i];
        }
    }
    printf("Error: couldn't calculate maximum, returning 0!\n");
    return 0;
}
int findMin(int array[], int length) {
    int i, j;
    int counter;
    for(i = 0; i < length; i++) {
        counter = 0;
        for(j = 0; j < length; j++) {
            if(array[i] <= array[j]) {
                counter++;
            }
        }
        if(counter == length) {
            return array[i];
        }
    }
    printf("Error: couldn't calculate minimum, returning 0!\n");
    return 0;
}

// program specific functions
void buildLevel(int depth, int previousLevel[], int targetLevel[], int level) {
    int i, j;
    int n = factorial(depth) / factorial(level);
    int sub[level];
    for(i = 0; i < n; i++) {
        for(j = 0; j < level; j++) {
            sub[j] = previousLevel[i * level + j];
        }
        if((depth + level) % 2 == 0) {
             targetLevel[i] = findMax(sub, level);
        }
        if((depth + level) % 2 == 1) {
             targetLevel[i] = findMin(sub, level);
        }
    }
}

// main
int main(void) {

    // reception of input and initialisation
    int i;
    int depth;

    printf("Please enter the depth of the MiniMax tree (2 - 9):\n");
    scanf("%d", &depth);

    int tree[depth + 1][factorial(depth)];

    printf("Please enter the base of the tree (%d integers):\n", factorial(depth));
    for(i = 0; i < factorial(depth); i++) {
        scanf("%d", &tree[0][i]);
    }
    printf("\n--- Thank you! Calculating... ---\n\n");

    // calculation
    for(i = 1; i <= depth; i++) {
        buildLevel(depth, tree[i - 1], tree[i], i);
    }

    // output
    printf("The evaluation is: %d\n", tree[depth][0]);

    // exit
    return 0;

}
