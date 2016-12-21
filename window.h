#include <qapplication.h>
#include <QWidget>
#include <QtGui>
#include "board.h"
#include "preview.h"
#include "state.h"
#include <QKeyEvent>


#ifndef WINDOW
#define WINDOW

class Qlabel;

class Window:public QWidget
{
  Q_OBJECT
public:
  Window();
protected:
   void keyPressEvent(QKeyEvent *);
   //void keyReleaseEvent(QKeyEvent *);
private:
  Board *board;
  QLabel *level;
  QLabel *score;
  Preview *preview;
  State *state;
public slots: 
  void update_level(int);
  void update_score(int);
signals:
  signals:
  void press_left();
  void press_right();
  void press_up();
  void press_down();
  void press_z();
  void press_x();
};
  

#endif