#include "mousepositionfilter.h"


bool MousePositionFilter::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress && obj == static_cast<QObject*>(parent())) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        emit mousePressed(mouseEvent->globalPos());
    }
    return QObject::eventFilter(obj, event);
}
