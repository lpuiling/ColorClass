#include "mysquare.h"

mysquare::mysquare()
{
}

QRectF mysquare::boundingRect() const
{

}

mysquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

void mysquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    Pressed=true;
    update();
    QGraphicsItem ::mousePressEvent(event);
}

void mysquare::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

}
