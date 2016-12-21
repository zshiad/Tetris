#include "window.h"
#include <unistd.h>
#include <QApplication>
#include <QLabel>
#include "preview.h"
#include <QWidget>
//#include "state.h"


Preview::Preview(QWidget *parent) :
    QWidget(parent)
{
    myLabel = new QLabel;
    mainLayout = new QVBoxLayout;
    mainLayout->addWidget(myLabel);
    qpixmap=new QPixmap(100,160);
    qpixmap->fill();
    QPainter qPainter(qpixmap);
    setLayout(mainLayout);
    myLabel->setPixmap(QPixmap::fromImage(*qpixmap));
    myLabel->show();
}

void Preview::update_preview(int c){ 
    qpixmap=new QPixmap(100,160);
    qpixmap->fill();
    QPainter qPainter(qpixmap);
    qPainter.setPen(Qt::black);
	switch(c){
	case 0: break;
	case 1: 
	qPainter.setBrush(Qt::red);
        qPainter.drawRect(40,40,20,20);
	qPainter.drawRect(40,60,20,20);
	qPainter.drawRect(40,80,20,20);
	qPainter.drawRect(40,100,20,20);
	break;
	case 2: 
	qPainter.setBrush(Qt::green);
        qPainter.drawRect(20,60,20,20);
	qPainter.drawRect(40,60,20,20);
	qPainter.drawRect(20,80,20,20);
	qPainter.drawRect(40,80,20,20);
	break;
	case 3: 
	qPainter.setBrush(Qt::blue);
        qPainter.drawRect(20,60,20,20);
	qPainter.drawRect(20,80,20,20);
	qPainter.drawRect(40,80,20,20);
	qPainter.drawRect(40,100,20,20);
	break;
	case 4: 
	qPainter.setBrush(Qt::yellow);
        qPainter.drawRect(40,60,20,20);
	qPainter.drawRect(40,80,20,20);
	qPainter.drawRect(20,80,20,20);
	qPainter.drawRect(20,100,20,20);
	break;
	case 5: 
	qPainter.setBrush(Qt::cyan);
        qPainter.drawRect(20,60,20,20);
	qPainter.drawRect(20,80,20,20);
	qPainter.drawRect(20,100,20,20);
	qPainter.drawRect(40,100,20,20);
	break;
	case 6: 
	qPainter.setBrush(Qt::gray);
        qPainter.drawRect(40,60,20,20);
	qPainter.drawRect(40,80,20,20);
	qPainter.drawRect(40,100,20,20);
	qPainter.drawRect(20,100,20,20);
	break;
	case 7: 
	qPainter.setBrush(Qt::magenta);
        qPainter.drawRect(40,60,20,20);
	qPainter.drawRect(40,80,20,20);
	qPainter.drawRect(20,80,20,20);
	qPainter.drawRect(60,80,20,20);

	break;
    }  
    
    myLabel->setPixmap(QPixmap::fromImage(*qpixmap));
   

  
}
