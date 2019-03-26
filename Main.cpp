#include <ncurses.h>
#include <thread>
#include <unistd.h>
#include <Ball.h>
#include <vector>

using namespace std;

vector <std::thread*> threads;

 void create_box(int y, int x, int w, int h) {
    mvhline(y, x, '-', w);
    mvhline(y + h, x, '-', w);
    mvvline(y, x, '|', h);
    mvvline(y, x + w, '|', h);
 }

 int main(void) {

    srand(time(NULL));

    initscr();
    cbreak();
    keypad(stdscr, TRUE);
    noecho();

    create_box(0, 0, 78, 22);
    refresh();

    while(true){
        threads.push_back(new std::thread(&Ball::animate, new Ball()));
        usleep(3500000);
    }

    endwin();
    return 0;
}
