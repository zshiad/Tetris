
#ifndef BOARD
#define BOARD
 
#include <QWidget>
#include <QtGui>

class Qlabel;

class Board : public QWidget
{
    Q_OBJECT
public:
    Board(QWidget *parent = 0);
public slots:
     void update_board(int**);
private:
    QImage myImage;
    QLabel *myLabel;
    QVBoxLayout *mainLayout;
};

#endif // KEYPRESS_H