#include "rectitem.h"

RectItem::RectItem(QGraphicsItem *parent):
    QGraphicsRectItem(parent),
    mResizeLeft(false),
    mResizeRight(false),
    mResizeBottom(false),
    mResizeTop(false),
    mRotate(false)
{
    setAcceptHoverEvents(true);
    setFlags(QGraphicsItem::ItemIsSelectable |
             QGraphicsItem::ItemIsMovable |
             QGraphicsItem::ItemSendsGeometryChanges);
}

void RectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED( option )
    Q_UNUSED( widget )
    painter->setRenderHint(QPainter::Antialiasing);

    if (isSelected() ){ // draw dashed line rectangle
        painter->setPen( Qt::DashLine );
        painter->drawRect( rect() );
    }
    else
        painter->drawRect( rect() ); // Draw normal rectanlge
}

void RectItem::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    QPointF pt = event->pos(); // The current position of the mouse
    qreal drx = pt.x() - rect().right(); // Distance between the mouse and the right
    qreal dlx = pt.x() - rect().left(); // Distance between the mouse and the left

    qreal dby = pt.y() - rect().top(); // Distance between the mouse and the top
    qreal dty = pt.y() - rect().bottom(); // Distance between the mouse and the bottom

    // If the mouse position is within a radius of 7
    // to a certain side( top, left, bottom or right)
    // we set the Boolean to true or false accordingly
    // make the item not movable and change the cursor
    // and we repeat this for each side

    // Top side
    if( dby < 7 && dby > -7 ){
        mResizeBottom = false;
        mResizeTop = true;
        mResizeRight = false;
        mResizeLeft = false;
        mRotate = false;
        setFlag( ItemIsMovable , false );
        setCursor( QCursor( Qt::SizeVerCursor ) );
    }

    // Bottom side
    else if( dty < 7 && dty > -7 ){
        mResizeBottom = true;
        mResizeTop = false;
        mResizeRight = false;
        mResizeLeft = false;
        mRotate = false;
        setFlag( ItemIsMovable , false );
        setCursor( QCursor( Qt::SizeVerCursor ) );
    }

    // Right side
    else if( drx < 7 && drx > -7 ){
        mResizeBottom = false;
        mResizeTop = false;
        mResizeRight = true;
        mResizeLeft = false;
        mRotate = false;
        setFlag( ItemIsMovable , false );
        setCursor( QCursor( Qt::SizeHorCursor ) );
    }

    // Left side
    else if( dlx < 7 && dlx > -7 ){
        mResizeBottom = false;
        mResizeTop = false;
        mResizeRight = false;
        mResizeLeft = true;
        mRotate = false;
        setFlag( ItemIsMovable , false );
        setCursor( QCursor( Qt::SizeHorCursor ) );
    }

    // No side
    else{
        mResizeLeft = false;
        mResizeRight = false;
        mResizeBottom = false;
        mResizeTop = false;
        mRotate = true;
        setFlag( ItemIsMovable , true );
        setCursor( QCursor() );
    }

    QGraphicsItem::hoverMoveEvent( event );
}

void RectItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    mResizeBottom = false;
    mResizeTop = false;
    mResizeLeft = false;
    mResizeRight = false;
    setCursor( QCursor( ) );
    QGraphicsItem::hoverLeaveEvent( event );
}

void RectItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pt = event->pos();
    if ( mResizeTop )
        resizeTop( pt );
    else if ( mResizeBottom )
        resizeBottom( pt );
    else if ( mResizeRight )
        resizeRight( pt );
    else if ( mResizeLeft )
        resizeLeft( pt );

    QGraphicsItem::mouseMoveEvent( event );
}

void RectItem::resizeLeft(const QPointF &pt)
{
    QRectF tmpRect = rect();
    // if the mouse is on the right side we return
    if( pt.x() > tmpRect.right() )
        return;
    qreal widthOffset =  ( pt.x() - tmpRect.right() );
    // limit the minimum width
    if( widthOffset > -10 )
        return;
    // if it's negative we set it to a positive width value
    if( widthOffset < 0 )
        tmpRect.setWidth( -widthOffset );
    else
        tmpRect.setWidth( widthOffset );
    // Since it's a left side , the rectange will increase in size
    // but keeps the topLeft as it was
    tmpRect.translate( rect().width() - tmpRect.width() , 0 );
    prepareGeometryChange();
    // Set the ne geometry
    setRect( tmpRect );
    // Update to see the result
    update();
}

void RectItem::resizeRight(const QPointF &pt)
{
    QRectF tmpRect = rect();
    if( pt.x() < tmpRect.left() )
        return;
    qreal widthOffset =  ( pt.x() - tmpRect.left() );
    if( widthOffset < 10 ) /// limit
        return;
    if( widthOffset < 10)
        tmpRect.setWidth( -widthOffset );
    else
        tmpRect.setWidth( widthOffset );
    prepareGeometryChange();
    setRect( tmpRect );
    update();
}

void RectItem::resizeTop(const QPointF &pt)
{
    QRectF tmpRect = rect();
    if( pt.y() > tmpRect.bottom() )
        return;
    qreal heightOffset =  ( pt.y() - tmpRect.bottom() );
    if( heightOffset > -11 ) /// limit
        return;
    if( heightOffset < 0)
        tmpRect.setHeight( -heightOffset );
    else
        tmpRect.setHeight( heightOffset );
    tmpRect.translate( 0 , rect().height() - tmpRect.height() );
    prepareGeometryChange();
    setRect( tmpRect );
    update();
}

void RectItem::resizeBottom(const QPointF &pt)
{
    QRectF tmpRect = rect();
    if( pt.y() < tmpRect.top() )
        return;
    qreal heightOffset =  ( pt.y() - tmpRect.top() );
    if( heightOffset < 11 ) /// limit
        return;
    if( heightOffset < 0)
        tmpRect.setHeight( -heightOffset );
    else
        tmpRect.setHeight( heightOffset );
    prepareGeometryChange();
    setRect( tmpRect );
    update();
}
