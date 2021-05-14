#include "main.h"
#include "frames.h"

static void print_frame(int frame)
{
    for (int i = (LENGTH * WIDTH * frame);
            i < (LENGTH * WIDTH * (frame + 1));
            i++) {
        putchar(all_frames[i]);
    }
}

int main()
{
    int current_frame = 0;
    int start_frame = 0;
    int time_taken = 0;
    int to_wait = 0;

    system("clear");
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
