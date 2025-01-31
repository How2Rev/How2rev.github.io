#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

typedef struct
{
  __const char *dli_fname;        /* File name of defining object.  */
  void *dli_fbase;                /* Load address of that object.  */
  __const char *dli_sname;        /* Name of nearest symbol.  */
  void *dli_saddr;                /* Exact value of nearest symbol.  */
} Dl_info;

const char * global_name = "To_Rev3rs1ng";

int part2_letS_StarT(void) {
    int a= 3;
    int b=2;
    return a+b;
}

extern char custom_section_start, custom_section_end;

__attribute__((section(".custom_section_name")))
int dummy(void) {
    return 0;
}


int main() {
    char user_input[100];
    char final_flag[100];
    printf("Enter input: ");
    if (scanf("%50s", user_input) < 0) {
        return 1;
    }

    char *flag_part1 = "inTr0ducT1on1";

    snprintf(final_flag, sizeof(final_flag), "LRCTF{%s_%s_%x}", flag_part1, global_name, (int)&custom_section_start);

    if (strcmp(user_input, final_flag) == 0) {
        printf("correct!\n");
    } else {
        printf("Try again.\n");
    }

    return 0;
}
