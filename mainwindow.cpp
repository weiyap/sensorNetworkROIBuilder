#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myScene = new QGraphicsScene(this);
    ui->graphicsView->setScene(myScene);
    ui->graphicsView->setInteractive(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    QRectF myRect(10,10,10,10);
    QBrush myBrush(Qt::red);
    QPen myPen(Qt::black);
    myPen.setWidth(3);
    QGraphicsRectItem* thisItem = myScene->addRect(myRect,myPen,myBrush);
    thisItem->setFlag(QGraphicsItem::ItemIsMovable);
    thisItem->setFlag(QGraphicsItem::ItemIsSelectable);
    ui->graphicsView->fitInView(myScene->sceneRect(),Qt::KeepAspectRatio);
}
