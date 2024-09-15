#ifndef MOUSEPOSITIONFILTER_H
#define MOUSEPOSITIONFILTER_H

#include <QApplication>
#include <QTextEdit>
#include <QDebug>
#include <QMouseEvent>

class MousePositionFilter : public QObject {
    Q_OBJECT
public:
    explicit MousePositionFilter(QObject *parent = nullptr) : QObject(parent) {}

signals:
    void mousePressed(QPoint globalPos);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // MOUSEPOSITIONFILTER_H

