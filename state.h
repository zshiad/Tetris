#ifndef STATE
#define STATE
#include <qtimer.h>
#include <QWidget>
#include <QtGui>
#include "item.h"

class Qlabel;

class State : public QWidget
{
    Q_OBJECT
public:
    State(QWidget *parent = 0);
    int **arrptr;
public slots:
     void initialize();
     void left_pressed();
     void right_pressed();
     void up_pressed();
     void down_pressed();
     void z_pressed();
     void x_pressed();
signals:
  void scorechanged(int);
  void levelchanged(int);
  void boardchanged(int**);
  void previewchanged(int);
private slots:
  void loop();

private:
  Item *piece1;
  Item *piece2;
  int bol; 
  int cx;
  int cy;
  int score;
  int level;
  int judge_down();
  int judge_left();
  int judge_right();
  int judge_z();
  int judge_x();
  int judge(Item*);
  int check_game();
  void check_row();
  void clear();
  void draw();
  void add();
  void change_score(int);
  QTimer *timer;
};

#endif // KEYPRESS_H