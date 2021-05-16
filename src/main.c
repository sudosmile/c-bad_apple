#include "main.h"
#include "frames.h"

volatile bool keepRunning = true;

void intHandler(int _)
{
    (void)_;
    keepRunning = false;
}

static void print_frame(int frame)
{
    const int start_of_frame = (LENGTH * WIDTH * frame);
    const int end_of_frame = (LENGTH * WIDTH * (frame + 1));
    const int length_of_frame = end_of_frame - start_of_frame;
    char substr_frame[LENGTH * WIDTH] = "";

    strncpy(substr_frame, all_frames + start_of_frame, length_of_frame - 1);
    substr_frame[length_of_frame] = '\0';
    fputs("\033[H", stdout);
    fputs(substr_frame, stdout);
}

int main(void)
{
    int current_frame = 0;
    long int time_taken_nsec = 0;
    struct timespec to_wait = {0};
    struct timespec handler = {0};
    struct timeval start = {0};
    struct timeval end = {0};
    struct sigaction act = {0};

    act.sa_handler = intHandler;
    sigaction(SIGINT, &act, NULL);
    fputs("\033[2J\033[H\e[?25l", stdout);
    while (keepRunning && current_frame <= TOTAL_FRAMES) {
        gettimeofday(&start, NULL);
        print_frame(current_frame++);
        gettimeofday(&end, NULL);
        time_taken_nsec = (end.tv_usec - start.tv_usec) * 1000;
        to_wait.tv_nsec = (SECOND / FPS) - time_taken_nsec;
        if (to_wait.tv_nsec > 0)
            nanosleep(&to_wait, &handler);
    }
    fputs("\e[?25h\n", stdout);
    return SUCCESS;
}
