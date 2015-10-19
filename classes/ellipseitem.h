#ifndef ELLIPSEITEM_H
#define ELLIPSEITEM_H

#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QCursor>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>

class EllipseItem : public QGraphicsEllipseItem
{
public:
    EllipseItem(QGraphicsItem *parent = 0);
    ~EllipseItem(){}

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event);

private:
    bool mResizeLeft;
    bool mResizeRight;
    bool mResizeBottom;
    bool mResizeTop;

    void resizeLeft(const QPointF &pt);
    void resizeRight(const QPointF &pt);
    void resizeBottom(const QPointF &pt);
    void resizeTop(const QPointF &pt);
};

#endif // ELLIPSEITEM_H
