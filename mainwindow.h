#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include "classes/graphicsscene.h"
#include "classes/rectitem.h"
#include "classes/ellipseitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_insertRectButton_clicked();
    void on_insertEllipseButton_clicked();

    void on_unionButton_clicked();

    void on_differenceButton_clicked();

private:
    Ui::MainWindow *ui;
    GraphicsScene* myScene;

};

#endif // MAINWINDOW_H
