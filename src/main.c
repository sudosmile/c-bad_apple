#include "main.h"
#include "frames.h"

static void print_frame(int frame)
{
    int start_of_frame = (LENGTH * WIDTH * frame);
    int end_of_frame = (LENGTH * WIDTH * (frame + 1));

    for (int i = start_of_frame; i < end_of_frame; i++) {
        putchar(all_frames[i]);
    }
}

int main()
{
    int current_frame = 0;
    int start_frame = 0;
    int time_taken = 0;
    int to_wait = 0;

    puts("\033[2J");
    puts("\033[H");
    while (current_frame <= TOTAL_FRAMES) {
        start_frame = time(NULL);
        printf ("\033[H");
        print_frame(current_frame);
        time_taken = start_frame - time(NULL);
        to_wait = (1000000 / FPS) - time_taken;
        if (to_wait > 0)
            usleep(to_wait);
        current_frame++;
    }
    return 0;
}
