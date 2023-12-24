// Add this class definition to cardspage.h
class ClickableGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    ClickableGraphicsScene(QObject* parent = nullptr);

signals:
    void cardClicked(const Card& card);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};
