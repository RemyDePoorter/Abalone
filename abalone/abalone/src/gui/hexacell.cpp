#include "hexacell.h"

#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QBrush>
#include <QPainter>

#include <iostream>
#include <cmath>

#include "point.hpp"

using namespace abalone;

double const HexaCell::zValMax = 10000;//arbitrary

HexaCell::HexaCell(double rad, double dx, double dy, QGraphicsItem *parent, Status status)
    : QGraphicsPolygonItem(parent),
      rad(rad), dx(dx), dy(dy),
      mouseover(false), moved(false), selected(0), _status(status)
{
    this->setAcceptHoverEvents(true);
    zval = zValue();

    static const double piOver6 = atan(1) * 4 / 6;

    QPolygonF polygon;
    auto&& corners = orbit({dx, dy}, 6, rad, piOver6);
    for(auto& p : corners)
        polygon << QPointF(p.first, p.second);

    setPolygon(polygon);
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
void HexaCell::paint(QPainter *painter,
                     const QStyleOptionGraphicsItem *option,
                     QWidget *widget)
{
    if(selected==2)
    {
        QPen pen(Qt::blue, 5);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::red);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);

    }else if(selected==1)
    {
        QPen pen(Qt::blue, 5);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::yellow);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    else if(mouseover)
    {
        QPen pen(Qt::black, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::green);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }
    else if(_status==Status::BLACK)
    {
        QPen pen(Qt::white, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::black);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);

    }
    else if(_status==Status::WHITE)
    {
        QPen pen(Qt::black, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(Qt::white);
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);

    }
    else
    {
        QPen pen(Qt::black, 1);
        painter->setPen(pen);

        QBrush brush;
        brush.setColor(QColor(139,69,19));
        brush.setStyle(Qt::SolidPattern);

        painter->setBrush(brush);
    }

    painter->drawPolygon(polygon());
}

Status HexaCell::getStatus(){
    return _status;
}

void HexaCell::setStatus(Status status){
    _status=status;
}

int HexaCell::getSelected(){
    return selected;
}

void HexaCell::setSelected(bool s){
    selected=s;
    update();
}

void HexaCell::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    mouseover = true;
    update();
}

void HexaCell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    mouseover = false;
    update();
}

void HexaCell::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    moved = false;
    selected = (selected+1)%3; //I'd like to put this in "released"
    update();

    //relaunches the event in order to allow dragging
    QGraphicsItem::mousePressEvent(event);
}

void HexaCell::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //why isn't this ever fired ?
}

void HexaCell::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    moved = true;
}

void HexaCell::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    //write stuff here
    //rad +/-= 10 ?

    QGraphicsItem::wheelEvent(event);
}
#pragma GCC diagnostic pop

