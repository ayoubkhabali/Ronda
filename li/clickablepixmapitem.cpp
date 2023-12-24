// clickablepixmapitem.cpp
#include "clickablepixmapitem.h"
#include <QGraphicsScene>

ClickablePixmapItem::ClickablePixmapItem(const QPixmap& pixmap) : QGraphicsPixmapItem(pixmap, nullptr)
{

}


void ClickablePixmapItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{

    QGraphicsScene* currentScene = scene();
    if (!currentScene)
    {
        QGraphicsScene* defaultScene = new QGraphicsScene;
        defaultScene->addItem(this);
    }

    emit clicked();

    QGraphicsPixmapItem::mousePressEvent(event);
}
