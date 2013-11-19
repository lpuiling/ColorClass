#ifndef MYSQUARE_H
#define MYSQUARE_H
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>

class mysquare : public QGraphicsItem
{
public:
    mysquare();

    QRectF boundingRect() const;
    //paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool Pressed;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MYSQUARE_H
