#include <stdio.h>
#include <string.h>


const char * global_name = "3_Rev3rs1ng";

int part2_letS_StarT(void) {
    int a= 3;
    int b=2;
    return a+b;
}

__attribute__((section(".part4_thE_World"))) int dummy(void) {
    return 0;
}


int main() {
    char user_input[50];
    printf("Enter input: ");
    scanf("%s", user_input);

    char *flag_part1 = "1_inTr0ducT1on1";
    if (strcmp(user_input, flag_part1) == 0) {
        printf("correct!\n");
    } else {
        printf("Try again.\n");
    }

    return 0;
}
