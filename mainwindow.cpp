#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myScene = new GraphicsScene(this);
    ui->graphicsView->setScene(myScene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insertRectButton_clicked()
{
    RectItem * myRect = new RectItem();
    myRect->setRect(0,0,100,100);
    myRect->setBrush(QBrush(Qt::red));
    myScene->addItem(myRect);
}

void MainWindow::on_insertEllipseButton_clicked()
{
    EllipseItem * myEllipse = new EllipseItem();
    myEllipse->setRect(0,0,100,100);
    myEllipse->setBrush(QBrush(Qt::red));
    myScene->addItem(myEllipse);
}

void MainWindow::on_unionButton_clicked()
{
    QList<QGraphicsItem * > selectedShapes;
    selectedShapes = myScene->selectedItems();
    QPainterPath myPainterPath;

    if (selectedShapes.size() > 0)
    {
        myPainterPath.addPath(selectedShapes[0]->shape());
        myPainterPath.translate(selectedShapes[0]->pos());
        myScene->removeItem(selectedShapes[0]);
        for (int i = 1; i < selectedShapes.size(); i++)
        {
            QPainterPath localPath = selectedShapes[i]->shape();
            localPath.translate(selectedShapes[i]->pos());
            myPainterPath = myPainterPath.united(localPath);
            myScene->removeItem(selectedShapes[i]);
        }

        QGraphicsItem* myItem = myScene->addPath(myPainterPath);
        myItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);

    }

}

void MainWindow::on_differenceButton_clicked()
{

    QList<QGraphicsItem * > selectedShapes;
    selectedShapes = myScene->selectedItems();
    QPainterPath myPainterPath;

    if (selectedShapes.size() > 0)
    {
        myPainterPath.addPath(selectedShapes[0]->shape());
        myPainterPath.translate(selectedShapes[0]->pos());
        myScene->removeItem(selectedShapes[0]);
        for (int i = 1; i < selectedShapes.size(); i++)
        {
            QPainterPath localPath = selectedShapes[i]->shape();
            localPath.translate(selectedShapes[i]->pos());
            myPainterPath = myPainterPath.subtracted(localPath);
            myScene->removeItem(selectedShapes[i]);
        }

        QGraphicsItem* myItem = myScene->addPath(myPainterPath);
        myItem->setFlags(QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemIsSelectable);

    }
}
