/* forcoder.c
// @author: Thomas x Meng [40455303@live.napier.ac.uk]
inspired by paper "Orchestration of APT malware evasive manoeuvers employed for eluding anti-virus and sandbox defense"
// Output the FORcoded cmd commands to its customer on a silver platter! 
*/ 
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    char command[256];
    strcpy(command, argv[1]);
    for (int i = 2; i < argc; i++) {
        strcat(command, " ");
        strcat(command, argv[i]);
    }

    int command_len = strlen(command);
    char unique_chars[256] = {0};
    int unique_char_count = 0;
    bool exists[256] = {0};

    for (int i = command_len - 1; i >= 0; i--) {
        unsigned char c = command[i];
        if (!exists[c]) {
            unique_chars[unique_char_count++] = c;
            exists[c] = true;
        }
    }

    printf("Indices:\n");
    int indices_count = 0;
    int indices[256] = {0};
    for (int i = 0; command[i]; i++) {
        unsigned char c = command[i];
        for (int j = 0; j < unique_char_count; j++) {
            if (unique_chars[j] == c) {
                indices[indices_count++] = j;
                break;
            }
        }
    }
    indices[indices_count++] = 1337;

    // Output the complete command
    printf("\nGenerated command:\ncmd /V:ON /C \"set unique=");
    for (int i = 0; i < unique_char_count; i++) {
        printf("%c", unique_chars[i]);
    }
    printf("&&FOR %%A IN (");
    for (int i = 0; i < indices_count - 1; i++) {
        printf("%d ", indices[i]);
    }
    printf("%d) DO set final=!final!!unique:~%%A,1!&& IF %%A==1337 CALL %%final:~-", indices[indices_count - 1]);
    printf("%d%%\"\n", indices_count-1);

    return 0;
}
