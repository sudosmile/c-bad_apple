#include "main.h"
#include "../include/main.h"

static void print_file(const char *filename)
{
    FILE *fptr;
    char current_char;

    fptr = fopen(filename, "r");
    if (!fptr) {
        fclose(fptr);
        return;
    } else {
        while ((current_char = fgetc(fptr)) != EOF)
            printf("%c", current_char);
        fflush(stdout);
        fclose(fptr);
    }
}

int main()
{
    int current_frame = 0;
    int start_frame = 0;
    int time_taken = 0;
    char filename[30];

    system("clear");
    while (current_frame <= max_frames) {
        start_frame = time(NULL);
        printf ("\033[H");
        sprintf(filename, "frames/BA (%d).txt%c", current_frame, '\0');
        print_file(filename);
        time_taken = start_frame - time(NULL);
        usleep((1000000 / fps) - time_taken);
        current_frame++;
    }
    return 0;
}
