
#ifndef PREVIEW
#define PREVIEW
 
#include <QWidget>
#include <QtGui>

class Qlabel;

class Preview : public QWidget
{
    Q_OBJECT
public:
    Preview(QWidget *parent = 0);
public slots:
     void update_preview(int c);
private:
    QPixmap *qpixmap;
    QLabel *myLabel;
    QVBoxLayout *mainLayout;
};

#endif // KEYPRESS_H