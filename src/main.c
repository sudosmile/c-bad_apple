#include "main.h"
#include "frames.h"
#include "../include/main.h"
#include "../include/frames.h"

volatile bool keepRunning = true;

void intHandler(int _)
{
    (void)_;
    keepRunning = false;
    puts(" stopped by signal");
}

static void print_frame(int frame)
{
    const int start_of_frame = (LENGTH * WIDTH * frame);
    const int end_of_frame = (LENGTH * WIDTH * (frame + 1));
    const int length_of_frame = end_of_frame - start_of_frame;
    char substr_frame[LENGTH * WIDTH];

    strncpy(substr_frame, all_frames + start_of_frame, length_of_frame);
    substr_frame[length_of_frame] = '\0';
    puts("\033[H");
    fputs(substr_frame, stdout);
}

int main(void)
{
    int current_frame = 0;
    int start_frame = 0;
    int time_taken = 0;
    struct timespec to_wait;
    struct timespec handler;
    struct sigaction act = {0};

    act.sa_handler = intHandler;
    sigaction(SIGINT, &act, NULL);
    puts("\033[2J");
    puts("\033[H");
    puts("\e[?25l");//remove cursor
    while (keepRunning && current_frame <= TOTAL_FRAMES) {
        start_frame = time(NULL);
        print_frame(current_frame);
        time_taken = start_frame - time(NULL);
        to_wait.tv_sec = 0;
        to_wait.tv_nsec = (1000000000 / FPS) - time_taken;
        if (to_wait.tv_nsec > 0)
            nanosleep(&to_wait, &handler);
        current_frame++;
    }
    printf("\e[?25h");
    return SUCCESS;
}
