#ifndef STARTERPAGE_H
#define STARTERPAGE_H

#include <QGraphicsScene>
#include <QWidget>

class QPushButton;

namespace Ui {
class StarterPage;
}

class StarterPage : public QWidget
{
    Q_OBJECT

public:
    explicit StarterPage(QWidget *parent = nullptr);
    ~StarterPage();


signals:
    void playClicked();
    void quitClicked();
    void howToClicked();

private:
    Ui::StarterPage *ui;
    QPushButton *playButton;
    QPushButton *quitButton;
    QPushButton *howToButton;
    QGraphicsScene *scene;
};

#endif // STARTERPAGE_H
