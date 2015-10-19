#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QPainter>
#include <QApplication>


class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GraphicsScene(QObject *parent = 0);
    int getGridSize() const {return this->gridSize;}
protected:
    void drawBackground(QPainter *painter, const QRectF &rect);
private:
    int gridSize;

};

#endif // GRAPHICSSCENE_H
