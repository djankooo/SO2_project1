#include <thread>
#include <unistd.h>
#include <Ball.h>
#include <ctime>
#include <cstdlib>


 int generator(){
    float los = ((double)std::rand()/(RAND_MAX));
    if(los>0.66){
        return 1;
    } else if(los<0.66 && los > 0.33){
        return 0;
    }else{
        return -1;
    }
}

Ball::Ball(){

    this->posX = 40;
    this->posY = 10;

    int x = 0;
    int y = 0;

    while (x == 0 &&  y == 0){
        x = generator();
        y = generator();
    }

    this->dX = x;
    this->dY = y;

    curs_set(0);
}

Ball::~Ball(){
    this->clear_ball();
}

void Ball::animate(){
    this->move_ball();
}

void Ball::clear_ball(){
    mvaddch(this->posY, this->posX, ' ');
}

void Ball::move_ball(){
    while(startSpeed<300000){

        usleep(startSpeed);
        clear_ball();


        if(this->posX<=2 || this->posX>=76){
            dX *= -1;
            this->posX += this->dX;
            startSpeed+=35000;
        }
        else{
            this->posX += this->dX;
        }

        if(this->posY<2 || this->posY>20){
            dY *= -1;
            this->posY += this->dY;
            startSpeed+=35000;
        }
        else{
            this->posY += this->dY;
        }

        draw_ball();
        refresh();
    }

    delete this;

}

void Ball::draw_ball(){
    mvaddch(this->posY, this->posX, 'O');
}

