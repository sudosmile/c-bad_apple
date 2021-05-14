#include "main.h"

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
        fclose(fptr);
    }
}

int main()
{
    int current_frame = 0;
    int max_frames = 6569;
    char filename[30];

    system("clear");
    while (current_frame <= max_frames) {
        printf ("\033[H");
        sprintf(filename, "frames/BA (%d).txt%c", current_frame, '\0');
        print_file(filename);
        current_frame++;
        usleep(25000);
    }
    return 0;
}
