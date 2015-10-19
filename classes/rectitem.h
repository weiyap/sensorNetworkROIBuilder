#ifndef RECTITEM_H
#define RECTITEM_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QCursor>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>

class RectItem : public QGraphicsRectItem
{
public:
    RectItem(QGraphicsItem *parent = 0);
    ~RectItem(){}

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
    bool mRotate;

    void resizeLeft(const QPointF &pt);
    void resizeRight(const QPointF &pt);
    void resizeBottom(const QPointF &pt);
    void resizeTop(const QPointF &pt);
};

#endif // RECTITEM_H
