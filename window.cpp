#include "window.h"
#include <unistd.h>
#include <QApplication>
#include <QKeyEvent>
#include <QLabel>
#include "board.h"
#include "preview.h"
#include "state.h"
#include <iostream>
using namespace std;
Window::Window() 
{
  board =new Board;
  preview= new Preview;
  level = new QLabel;
  score = new QLabel;
  state = new State; 
  
   
  QObject::connect(state, SIGNAL(scorechanged(int)), this, SLOT(update_score(int)));
  QObject::connect(state, SIGNAL(levelchanged(int)), this, SLOT(update_level(int)));
  QObject::connect(state, SIGNAL(boardchanged(int**)), board, SLOT(update_board(int**)));
  QObject::connect(state, SIGNAL(previewchanged(int)), preview, SLOT(update_preview(int)));
  QObject::connect(this, SIGNAL(press_left()), state, SLOT(left_pressed()));
  QObject::connect(this, SIGNAL(press_right()), state, SLOT(right_pressed()));
  QObject::connect(this, SIGNAL(press_up()), state, SLOT(up_pressed()));
  QObject::connect(this, SIGNAL(press_down()), state, SLOT(down_pressed()));
  QObject::connect(this, SIGNAL(press_z()), state, SLOT(z_pressed()));
  QObject::connect(this, SIGNAL(press_x()), state, SLOT(x_pressed()));
       
  QGridLayout *mainLayout = new QGridLayout;
  mainLayout->addWidget(board,0,0,6,3);
  mainLayout->addWidget(preview,1,4,3,5);
  mainLayout->addWidget(level,4,4);
  mainLayout->addWidget(score,5,4);
  setLayout(mainLayout);
  state->initialize();
  board->show();
  preview->show();
  level->show();
  score->show();
  resize(350,350);
  
} 

void Window::update_level(int cur_level){ 
  char buffer[256];
  bzero(buffer,256);
  sprintf(buffer,"Level: %d",cur_level);
  level->setText(buffer);
}

void Window::update_score(int cur_score){ 
  char buffer[256];
  bzero(buffer,256);
  sprintf(buffer,"Score: %d",cur_score);
  score->setText(buffer);
}

void Window::keyPressEvent(QKeyEvent *event)
{
   if(event->key()==Qt::Key_Left){
       emit  press_left();}
     if(event->key()==Qt::Key_Right){
       emit  press_right();}
     if(event->key()==Qt::Key_Up){
       emit  press_up();}
    if(event->key()==Qt::Key_Down){
       emit  press_down();}
     if(event->key()==Qt::Key_Z){
       emit  press_z();}
    if(event->key()==Qt::Key_X){
       emit  press_x();}
}