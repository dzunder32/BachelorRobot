/****************************************************************************
** Meta object code from reading C++ file 'robotdrawui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../CAPISample/robotdrawui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotdrawui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RobotDrawUi_t {
    QByteArrayData data[24];
    char stringdata0[420];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotDrawUi_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotDrawUi_t qt_meta_stringdata_RobotDrawUi = {
    {
QT_MOC_LITERAL(0, 0, 11), // "RobotDrawUi"
QT_MOC_LITERAL(1, 12, 12), // "startDrawing"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 11), // "stopDrawing"
QT_MOC_LITERAL(4, 38, 26), // "on_pushButtonStart_clicked"
QT_MOC_LITERAL(5, 65, 27), // "on_pushButtonDelete_clicked"
QT_MOC_LITERAL(6, 93, 31), // "on_timerSpeedSlider_sliderMoved"
QT_MOC_LITERAL(7, 125, 8), // "position"
QT_MOC_LITERAL(8, 134, 27), // "on_pushButton_setP1_clicked"
QT_MOC_LITERAL(9, 162, 27), // "on_pushButton_setP2_clicked"
QT_MOC_LITERAL(10, 190, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(11, 212, 29), // "on_pushButton_addLine_clicked"
QT_MOC_LITERAL(12, 242, 27), // "on_pushButton_addP1_clicked"
QT_MOC_LITERAL(13, 270, 27), // "on_pushButton_addP2_clicked"
QT_MOC_LITERAL(14, 298, 29), // "on_pushButton_History_clicked"
QT_MOC_LITERAL(15, 328, 15), // "widgetDrawPoint"
QT_MOC_LITERAL(16, 344, 5), // "point"
QT_MOC_LITERAL(17, 350, 9), // "thickness"
QT_MOC_LITERAL(18, 360, 5), // "color"
QT_MOC_LITERAL(19, 366, 14), // "startDrawTimer"
QT_MOC_LITERAL(20, 381, 13), // "stopDrawTimer"
QT_MOC_LITERAL(21, 395, 14), // "drawLineWidget"
QT_MOC_LITERAL(22, 410, 5), // "start"
QT_MOC_LITERAL(23, 416, 3) // "end"

    },
    "RobotDrawUi\0startDrawing\0\0stopDrawing\0"
    "on_pushButtonStart_clicked\0"
    "on_pushButtonDelete_clicked\0"
    "on_timerSpeedSlider_sliderMoved\0"
    "position\0on_pushButton_setP1_clicked\0"
    "on_pushButton_setP2_clicked\0"
    "on_pushButton_clicked\0"
    "on_pushButton_addLine_clicked\0"
    "on_pushButton_addP1_clicked\0"
    "on_pushButton_addP2_clicked\0"
    "on_pushButton_History_clicked\0"
    "widgetDrawPoint\0point\0thickness\0color\0"
    "startDrawTimer\0stopDrawTimer\0"
    "drawLineWidget\0start\0end"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotDrawUi[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   96,    2, 0x08 /* Private */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    1,   98,    2, 0x08 /* Private */,
       8,    0,  101,    2, 0x08 /* Private */,
       9,    0,  102,    2, 0x08 /* Private */,
      10,    0,  103,    2, 0x08 /* Private */,
      11,    0,  104,    2, 0x08 /* Private */,
      12,    0,  105,    2, 0x08 /* Private */,
      13,    0,  106,    2, 0x08 /* Private */,
      14,    0,  107,    2, 0x08 /* Private */,
      15,    3,  108,    2, 0x08 /* Private */,
      19,    0,  115,    2, 0x0a /* Public */,
      20,    0,  116,    2, 0x0a /* Public */,
      21,    2,  117,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::Float, QMetaType::QColor,   16,   17,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,   22,   23,

       0        // eod
};

void RobotDrawUi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RobotDrawUi *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startDrawing(); break;
        case 1: _t->stopDrawing(); break;
        case 2: _t->on_pushButtonStart_clicked(); break;
        case 3: _t->on_pushButtonDelete_clicked(); break;
        case 4: _t->on_timerSpeedSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_pushButton_setP1_clicked(); break;
        case 6: _t->on_pushButton_setP2_clicked(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_pushButton_addLine_clicked(); break;
        case 9: _t->on_pushButton_addP1_clicked(); break;
        case 10: _t->on_pushButton_addP2_clicked(); break;
        case 11: _t->on_pushButton_History_clicked(); break;
        case 12: _t->widgetDrawPoint((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3]))); break;
        case 13: _t->startDrawTimer(); break;
        case 14: _t->stopDrawTimer(); break;
        case 15: _t->drawLineWidget((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RobotDrawUi::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotDrawUi::startDrawing)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RobotDrawUi::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotDrawUi::stopDrawing)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RobotDrawUi::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_RobotDrawUi.data,
    qt_meta_data_RobotDrawUi,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RobotDrawUi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotDrawUi::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RobotDrawUi.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int RobotDrawUi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void RobotDrawUi::startDrawing()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RobotDrawUi::stopDrawing()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
