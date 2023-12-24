// clickablepixmapitem.h
#ifndef CLICKABLEPIXMAPITEM_H
#define CLICKABLEPIXMAPITEM_H

#include <QGraphicsPixmapItem>
#include <QObject> // Add QObject include
#include <QGraphicsScene>

class ClickablePixmapItem : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    ClickablePixmapItem(const QPixmap& pixmap);
    using QGraphicsPixmapItem::QGraphicsPixmapItem;

signals:
    void clicked();
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // CLICKABLEPIXMAPITEM_H
