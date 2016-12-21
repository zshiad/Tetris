#include "window.h"
#include <unistd.h>
#include <QApplication>
#include <QLabel>
#include "board.h"
#include <QWidget>
#include "state.h"
#include <qtimer.h>
#include <iostream>
using namespace std;

State::State(QWidget *parent) :
    QWidget(parent) { 
   arrptr=new int*[10];
    for(int i=0;i<10;i++){
      arrptr[i]=new int[20];
    }
    for(int x=0; x<10;x++){
      for(int y=0; y<20;y++){
      arrptr[x][y]=0;
    }  
    }

    piece1=new Item;
    piece1->setRandomShape();
    piece2=new Item;
    piece2->setRandomShape();
    score=0;
    level=1;
    bol=0;
 }
void State::initialize(){
   change_score(0);
    emit previewchanged(0);
    emit boardchanged(arrptr);
    emit levelchanged(1);
} 
void State::up_pressed(){
  if(bol==0){
    bol=1;
    score=0;
    level=1;
    change_score(0);
    add();
    emit previewchanged(piece2->shapenum);
    emit boardchanged(arrptr);
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(loop()));
    timer->start(1000 /* milliseconds */,true/* generate continously */); 
  }
}   

void State::loop(){ 
  if(bol==1){  
  if(judge_down()){
    clear();
    cy=cy+1; 
    draw();
    emit boardchanged(arrptr); 
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(loop()));
    timer->start(1000-(level-1)*100 /* milliseconds */,true/* generate continously */); 
   }
  else
  {
    piece1=piece2;
    piece2=new Item;
    piece2->setRandomShape();
    emit previewchanged(piece2->shapenum);
    check_row();
    
    if(check_game()){
    add();
    emit boardchanged(arrptr); 
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(loop()));
    timer->start(1000-(level-1)*100 /* milliseconds */,true/* generate continously */);  
    
     
    }
    else{
      bol=0;
      piece1->setRandomShape();
      piece2->setRandomShape();
      cx=5;
      cy=2;
      for(int x=0; x<10;x++){
        for(int y=0; y<20;y++){
          arrptr[x][y]=0;
	}  
    } 

}
}


}
}

void State::left_pressed(){
  if(bol==1){
   if(judge_left()){
    clear();
    cx=cx-1; 
    draw();
    emit boardchanged(arrptr);
   }
}
}
void State::right_pressed(){
  if(bol==1){ 
  if(judge_right()){
    clear();
    cx=cx+1; 
    draw();
    emit boardchanged(arrptr);
   }
}
}
void State::down_pressed(){
{ if(bol==1) { 
  if(judge_down()){
    clear();
    cy=cy+1; 
    draw();
    emit boardchanged(arrptr); 
   }
  else
  {
    check_row();
    piece1=piece2;
    piece2=new Item;
    piece2->setRandomShape();
    emit previewchanged(piece2->shapenum);

    
    if(check_game()){
          add();
	  emit boardchanged(arrptr); 
    }
     else{
       bol=0;
      piece1->setRandomShape();
      piece2->setRandomShape();
      cx=5;
      cy=2;
      for(int x=0; x<10;x++){
        for(int y=0; y<20;y++){
          arrptr[x][y]=0;
	}  
    } 
    }
  }
}
}
}
void State::z_pressed(){
   if(bol==1){ 
  if(judge_z()){
    clear();
    *piece1=piece1->rotatedRight();
    draw();
    emit boardchanged(arrptr); 
  }
}
}
void State::x_pressed(){
  if(bol==1){ 
  if(judge_x()){
    clear();
    *piece1=piece1->rotatedLeft();
    draw();
    emit boardchanged(arrptr); 
  }
}
}

void State::clear(){
  for(int i=0;i<4;i++){
      arrptr[cx+piece1->x(i)][cy+piece1->y(i)]=0;
    }
}
void State::draw(){
  for(int i=0;i<4;i++){
      arrptr[cx+piece1->x(i)][cy+piece1->y(i)]=piece1->shapenum;
    }
}
void State::add(){
  cx=5;
  cy=2;
  draw();
}

int State::check_game(){
    cx=5;
    cy=2;
  for(int i=0;i<10;i++){

    if(arrptr[i][0]>0){
      return 0;
    }
    if(arrptr[i][1]>0){
      return 0;
    }
     
  }
    for(int i=0;i<4;i++){
      if(arrptr[cx+piece1->x(i)][cy+piece1->y(i)]>0){
	return 0;
	  }
    }
    return 1;
  }
void State::check_row(){
   int line_num=0;
  for(int y1=0; y1<20;y1++){
     int k=0;
        for(int x1=0; x1<10;x1++){
          if(arrptr[x1][y1]>0){
	    k=k+1;
	  }
	}
	  if(k==10){
	    ++line_num;
	for(int y2=y1; y2>0;y2--){
        for(int x2=0; x2<10;x2++){
	   arrptr[x2][y2]=arrptr[x2][y2-1];
	 
	}  
    } 
    
  }        
  }
emit boardchanged(arrptr);
change_score(line_num);
}


int State::judge_down(){
  clear();
   cy=cy+1;
  if (judge(piece1)){ 
   cy=cy-1;
     draw();
     return 1;
}    
else{ 
  cy=cy-1;
  draw();
  return 0;}
} 
int State::judge_left(){
  clear();
  cx=cx-1;
  if (judge(piece1)){ 
    cx=cx+1;
     draw();
     return 1;
}    
else{ 
  cx=cx+1;
  draw();
  return 0;}
}  
int State::judge_right(){
  clear();
  cx=cx+1;
  if (judge(piece1)){ 
    cx=cx-1;
     draw();
     return 1;
}    
else{ 
  cx=cx-1;
  draw();
  return 0;}
 

}  
int State::judge_z(){
    clear();
   Item test_piece=piece1->rotatedRight();
   Item* test_ptr=&test_piece;
   if (judge(test_ptr)){
     draw();
     return 1;
}    
else{
  draw();
  return 0;
  
}
}
int State::judge_x(){
    clear();
   Item test_piece=piece1->rotatedLeft();
   Item *test_ptr=&test_piece;
   if (judge(test_ptr)){
     draw();
     return 1;
}    
else{
  draw();
  return 0;}
}
  
int State::judge(Item * test_piece){
   for(int i=0;i<4;i++){
     if(cx+test_piece->x(i)>9){
     return 0;}
     if(cy+test_piece->y(i)>19){
     return 0;}
     if(cx+test_piece->x(i)<0){
     return 0;}
     if(cy+test_piece->y(i)<0){
     return 0;}
   }
   
  for(int i=0;i<4;i++){
      if(arrptr[cx+test_piece->x(i)][cy+test_piece->y(i)]>0){
	return 0;
	  }
    }
    return 1;
}
  
void State::change_score(int line_num){
  score=score+line_num*line_num*10;
  emit scorechanged(score);
  if(score-(level-1)*100>99&&level<10){
    level++;
  }
  emit levelchanged(level);
}  


  

  
  
  
  