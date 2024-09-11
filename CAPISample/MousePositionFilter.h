#ifndef MOUSEPOSITIONFILTER_H
#define MOUSEPOSITIONFILTER_H
#include <QTextEdit>
#include <QObject>
#include <QMouseEvent>
#include <QDebug>>
class MousePositionFilter : public QObject {
public:
    MousePositionFilter(QObject *parent = nullptr) : QObject(parent) {}

    bool eventFilter(QObject *obj, QEvent *event) override {
        QTextEdit *textEdit = qobject_cast<QTextEdit*>(obj);
        if (!textEdit || !event)
            return false;

        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
            QPoint pos = mouseEvent->pos();

            // Calculate cursor position
            int cursorPos = textEdit->cursorForPosition(pos).position();

            // Get the current cursor position
            QTextCursor cursor = textEdit->textCursor();
            cursor.setPosition(cursorPos);
            textEdit->setTextCursor(cursor);

            // Handle left or right mouse button click
            if (mouseEvent->button() == Qt::LeftButton) {
                qDebug() << "Left click at position" << cursorPos;
            } else if (mouseEvent->button() == Qt::RightButton) {
                qDebug() << "Right click at position" << cursorPos;
            }

            return false; // Allow QTextEdit to process the event normally
        }

        return QObject::eventFilter(obj, event);
    }
};



#endif // MOUSEPOSITIONFILTER_H
