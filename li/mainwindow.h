#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QPushButton>

class StarterPage;
class CardsPage;


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getSelectedDifficulty() const;

private slots:
    void startGame();
    void quitGame();




private:
    Ui::MainWindow *ui;
    QStackedWidget *stackedWidget;
    StarterPage *starterPage;
    CardsPage *cardsPage;
    int selectedDifficulty;
};
#endif // MAINWINDOW_H
