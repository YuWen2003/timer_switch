#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

void clear_screen() {
    system("cls");
}

void print_timers(double clock1, double clock2) {
    printf("clock1: %.2f seconds\n", clock1);
    printf("clock2: %.2f seconds\n", clock2);
}

int main() {
    double clock1 = 0.0, clock2 = 0.0;
    int current_clock = 1;
    clock_t start_time, current_time, pause_time;

    while (1) {
        if (current_clock == 1) {
            start_time = clock();
            while (1) {
                clear_screen();
                current_time = clock();
                if ((double) (current_time - start_time) / CLOCKS_PER_SEC >= 1) {
                    clock1 += 1;
                    start_time = current_time;
                }
                print_timers(clock1, clock2);
                if (kbhit()) {
                    pause_time = clock();
                    current_clock = 2;
                    break;
                }
                Sleep(100);
            }
        } else if (current_clock == 2) {
            start_time = clock();
            while (1) {
                clear_screen();
                current_time = clock();
                if ((double) (current_time - start_time) / CLOCKS_PER_SEC >= 1) {
                    clock2 += 1;
                    start_time = current_time;
                }
                print_timers(clock1, clock2);
                if (kbhit()) {
                    pause_time = clock();
                    current_clock = 1;
                    break;
                }
                Sleep(100);
            }
        }
        // 暫停另一個計時器
        while (kbhit()) {
            getch();
        }
        if (current_clock == 1) {
            clock2 += ((double) (clock() - pause_time) / CLOCKS_PER_SEC);
        } else {
            clock1 += ((double) (clock() - pause_time) / CLOCKS_PER_SEC);
        }
    }
    return 0;
}
