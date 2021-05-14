#include "main.h"
#include "frames.h"

static void print_frame(int frame)
{
    const int start_of_frame = (LENGTH * WIDTH * frame);                        // start of frame in the frames string
    const int end_of_frame = (LENGTH * WIDTH * (frame + 1));

    puts("\033[H");                                                             // reset cursor to 0 0
    for (int i = start_of_frame; i < end_of_frame; i++) {
        putchar(all_frames[i]);
    }
}

int main(void)
{
    int current_frame = 0;
    int start_frame = 0;
    int time_taken = 0;
    struct timespec to_wait;
    struct timespec handler;

    puts("\033[2J");                                                            // clear terminal
    puts("\033[H");
    while (current_frame <= TOTAL_FRAMES) {
        start_frame = time(NULL);
        print_frame(current_frame);
        time_taken = start_frame - time(NULL);
        to_wait.tv_sec = 0;
        to_wait.tv_nsec = (1000000000 / FPS) - time_taken;                      // set nanosecond wait to slow some frames to fit framerate
        if (to_wait.tv_nsec > 0)
            nanosleep(&to_wait, &handler);
        current_frame++;
    }
    return SUCCESS;
}
