#ifndef COLORCLASS_H
#define COLORCLASS_H

#include <QWidget>
#include <QColor>
#include <QPushButton>
#include <QEvent>
#include <QMouseEvent>
#include <QtCore>
#include <QPen>

namespace Ui {
class colorclass;
}

class colorclass : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color NOTIFY colorChanged)
public:
    explicit colorclass(QWidget *parent = 0);
    ~colorclass();
    QColor color() const
    {
       return m_color;
    }
    //QPushButton *OK;
   // QMouseEvent myMouse;
//protected:
    void mouseReleaseEvent ( QMouseEvent * e );
    void mousePressEvent ( QMouseEvent * e );
signals:
    void colorChanged(QColor arg);
    void mouseClickEvent();

private slots:
    void onColorChanged();

   //void on_OK_clicked();

    void on_ChooseThis_clicked();

private:
    Ui::colorclass *ui;
    QColor m_color;
    QColor p1;
    QPoint m_lastPoint;
    bool m_mouseClick;
    QPen pencil;
    QBrush brush;
    QColor myPenColor;


};

#endif // COLORCLASS_H
