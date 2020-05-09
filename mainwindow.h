#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QProcess"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void emitTextControl(QString text) const;

private slots:
    void displayTextControl(QString text);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QProcess* m_iQProcess;
};

#endif // MAINWINDOW_H
