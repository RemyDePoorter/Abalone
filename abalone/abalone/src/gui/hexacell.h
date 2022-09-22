#ifndef HEXACELL_H
#define HEXACELL_H

#include <QGraphicsPolygonItem>
#include <QGridLayout>
#include <QPolygonF>
#include <string>
#include <QPointF>
#include "status.h"

class QPainter;
class QStyleOptionGraphicsItem;
class QWidget;
class QGraphicsSceneHoverEvent;
class QGraphicsSceneMouseEvent;
class QGraphicsSceneWheelEvent;

namespace  abalone {


class HexaCell  : public QGraphicsPolygonItem
{
    static const double zValMax; //z-val of selected items
    double zval; //z-val at instanciation

protected:
    double rad, dx, dy;//hexagon radius, coordinate (x,y) of center
    bool mouseover, moved;//mouse interaction booleans
    int selected;

private:
    Status _status;

public:
    HexaCell(double rad = 100,
             double dx = 0,
             double dy = 0,
             QGraphicsItem * parent = 0,
             Status status = Status::FREE);

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);

    Status getStatus();
    void setStatus(Status status);

    inline QPointF coord(double x, double y) const;

    inline void setLocation(double x, double y);
    int getSelected();
    void setSelected(bool s);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent * event);
    void wheelEvent(QGraphicsSceneWheelEvent * event);
};

}
#endif // HEXACELL_H
