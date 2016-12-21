#include "window.h"
#include <unistd.h>
#include <QApplication>
#include <QLabel>
#include "board.h"
#include <QWidget>
#include "state.h"


Board::Board(QWidget *parent) :
    QWidget(parent)
{
    myLabel = new QLabel;
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(myLabel);
    setLayout(mainLayout);
    myImage.load("background.bmp");
    myLabel->setPixmap(QPixmap::fromImage(myImage));
    myLabel->show();
}

void Board::update_board(int**position){ 
    myImage.load("background.bmp");
    QPainter qPainter(&myImage);
    qPainter.setPen(Qt::black);
    /*int **test;
    test=new int*[10];
    for(int i=0;i<10;i++){
      test[i]=new int[20];
    }
    for(int x=0; x<10;x++){
      for(int y=0; y<20;y++){
      test[x][y]=0;
    }  
    }
    
    test[4][2]=3;
    test[0][0]=6;
    test[9][19]=7;
    test[0][1]=1;
    test[1][0]=1;

    
    test[1][2]=2;
    position=test;*/
    
    
    for(int x=0; x<10;x++){
      for(int y=0; y<20;y++){
	int c=position[x][y];
	switch(c){
	case 0: break;
	case 1: 
	qPainter.setBrush(Qt::red);
        qPainter.drawRect(20*x,20*y,20,20);
	break;
	case 2: 
	qPainter.setBrush(Qt::green);
        qPainter.drawRect(20*x,20*y,20,20);
	break;
	case 3: 
	qPainter.setBrush(Qt::blue);
        qPainter.drawRect(20*x,20*y,20,20);
	break;
	case 4: 
	qPainter.setBrush(Qt::yellow);
        qPainter.drawRect(20*x,20*y,20,20);
	break;
	case 5: 
	qPainter.setBrush(Qt::cyan);
        qPainter.drawRect(20*x,20*y,20,20);
	break;
	case 6: 
	qPainter.setBrush(Qt::gray);
        qPainter.drawRect(20*x,20*y,20,20);
	break;
	case 7: 
	qPainter.setBrush(Qt::magenta);
        qPainter.drawRect(20*x,20*y,20,20);

	break;
    }  
    }
    myLabel->setPixmap(QPixmap::fromImage(myImage));
   

  
}
}