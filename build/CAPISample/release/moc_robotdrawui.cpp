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
    QByteArrayData data[42];
    char stringdata0[861];
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
QT_MOC_LITERAL(4, 38, 11), // "changeSpeed"
QT_MOC_LITERAL(5, 50, 14), // "removeAllItems"
QT_MOC_LITERAL(6, 65, 26), // "on_pushButtonStart_clicked"
QT_MOC_LITERAL(7, 92, 25), // "on_pushButtonStop_clicked"
QT_MOC_LITERAL(8, 118, 31), // "on_timerSpeedSlider_sliderMoved"
QT_MOC_LITERAL(9, 150, 8), // "position"
QT_MOC_LITERAL(10, 159, 27), // "on_pushButton_setP1_clicked"
QT_MOC_LITERAL(11, 187, 27), // "on_pushButton_setP2_clicked"
QT_MOC_LITERAL(12, 215, 29), // "on_pushButton_addLine_clicked"
QT_MOC_LITERAL(13, 245, 27), // "on_pushButton_addP1_clicked"
QT_MOC_LITERAL(14, 273, 15), // "widgetDrawPoint"
QT_MOC_LITERAL(15, 289, 5), // "point"
QT_MOC_LITERAL(16, 295, 9), // "thickness"
QT_MOC_LITERAL(17, 305, 5), // "color"
QT_MOC_LITERAL(18, 311, 31), // "on_pushButton_addCircle_clicked"
QT_MOC_LITERAL(19, 343, 26), // "on_pushButton_draw_clicked"
QT_MOC_LITERAL(20, 370, 34), // "on_spinBox_letterSize_valueCh..."
QT_MOC_LITERAL(21, 405, 4), // "arg1"
QT_MOC_LITERAL(22, 410, 33), // "on_horizontalSlider_x_sliderM..."
QT_MOC_LITERAL(23, 444, 33), // "on_horizontalSlider_y_sliderM..."
QT_MOC_LITERAL(24, 478, 33), // "on_horizontalSlider_z_sliderM..."
QT_MOC_LITERAL(25, 512, 36), // "on_horizontalSlider_xRot_slid..."
QT_MOC_LITERAL(26, 549, 36), // "on_horizontalSlider_yRot_slid..."
QT_MOC_LITERAL(27, 586, 36), // "on_horizontalSlider_zRot_slid..."
QT_MOC_LITERAL(28, 623, 28), // "on_spinBox_dist_valueChanged"
QT_MOC_LITERAL(29, 652, 29), // "on_pushButton_History_clicked"
QT_MOC_LITERAL(30, 682, 14), // "onMousePressed"
QT_MOC_LITERAL(31, 697, 9), // "globalPos"
QT_MOC_LITERAL(32, 707, 26), // "on_pushButton_lift_clicked"
QT_MOC_LITERAL(33, 734, 32), // "on_pushButton_Registrate_clicked"
QT_MOC_LITERAL(34, 767, 14), // "drawLineWidget"
QT_MOC_LITERAL(35, 782, 5), // "start"
QT_MOC_LITERAL(36, 788, 3), // "end"
QT_MOC_LITERAL(37, 792, 16), // "adjustRobotRange"
QT_MOC_LITERAL(38, 809, 5), // "range"
QT_MOC_LITERAL(39, 815, 21), // "displayAngleReference"
QT_MOC_LITERAL(40, 837, 5), // "angle"
QT_MOC_LITERAL(41, 843, 17) // "planeRegistration"

    },
    "RobotDrawUi\0startDrawing\0\0stopDrawing\0"
    "changeSpeed\0removeAllItems\0"
    "on_pushButtonStart_clicked\0"
    "on_pushButtonStop_clicked\0"
    "on_timerSpeedSlider_sliderMoved\0"
    "position\0on_pushButton_setP1_clicked\0"
    "on_pushButton_setP2_clicked\0"
    "on_pushButton_addLine_clicked\0"
    "on_pushButton_addP1_clicked\0widgetDrawPoint\0"
    "point\0thickness\0color\0"
    "on_pushButton_addCircle_clicked\0"
    "on_pushButton_draw_clicked\0"
    "on_spinBox_letterSize_valueChanged\0"
    "arg1\0on_horizontalSlider_x_sliderMoved\0"
    "on_horizontalSlider_y_sliderMoved\0"
    "on_horizontalSlider_z_sliderMoved\0"
    "on_horizontalSlider_xRot_sliderMoved\0"
    "on_horizontalSlider_yRot_sliderMoved\0"
    "on_horizontalSlider_zRot_sliderMoved\0"
    "on_spinBox_dist_valueChanged\0"
    "on_pushButton_History_clicked\0"
    "onMousePressed\0globalPos\0"
    "on_pushButton_lift_clicked\0"
    "on_pushButton_Registrate_clicked\0"
    "drawLineWidget\0start\0end\0adjustRobotRange\0"
    "range\0displayAngleReference\0angle\0"
    "planeRegistration"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotDrawUi[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      30,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  164,    2, 0x06 /* Public */,
       3,    0,  165,    2, 0x06 /* Public */,
       4,    1,  166,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,  169,    2, 0x0a /* Public */,
       6,    0,  170,    2, 0x08 /* Private */,
       7,    0,  171,    2, 0x08 /* Private */,
       8,    1,  172,    2, 0x08 /* Private */,
      10,    0,  175,    2, 0x08 /* Private */,
      11,    0,  176,    2, 0x08 /* Private */,
      12,    0,  177,    2, 0x08 /* Private */,
      13,    0,  178,    2, 0x08 /* Private */,
      14,    3,  179,    2, 0x08 /* Private */,
      18,    0,  186,    2, 0x08 /* Private */,
      19,    0,  187,    2, 0x08 /* Private */,
      20,    1,  188,    2, 0x08 /* Private */,
      22,    1,  191,    2, 0x08 /* Private */,
      23,    1,  194,    2, 0x08 /* Private */,
      24,    1,  197,    2, 0x08 /* Private */,
      25,    1,  200,    2, 0x08 /* Private */,
      26,    1,  203,    2, 0x08 /* Private */,
      27,    1,  206,    2, 0x08 /* Private */,
      28,    1,  209,    2, 0x08 /* Private */,
      29,    0,  212,    2, 0x08 /* Private */,
      30,    1,  213,    2, 0x08 /* Private */,
      32,    0,  216,    2, 0x08 /* Private */,
      33,    0,  217,    2, 0x08 /* Private */,
      34,    2,  218,    2, 0x0a /* Public */,
      37,    1,  223,    2, 0x0a /* Public */,
      39,    1,  226,    2, 0x0a /* Public */,
      41,    0,  229,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::Float, QMetaType::QColor,   15,   16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QPoint,   31,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,   35,   36,
    QMetaType::Void, QMetaType::Float,   38,
    QMetaType::Void, QMetaType::Float,   40,
    QMetaType::Void,

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
        case 2: _t->changeSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->removeAllItems(); break;
        case 4: _t->on_pushButtonStart_clicked(); break;
        case 5: _t->on_pushButtonStop_clicked(); break;
        case 6: _t->on_timerSpeedSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_setP1_clicked(); break;
        case 8: _t->on_pushButton_setP2_clicked(); break;
        case 9: _t->on_pushButton_addLine_clicked(); break;
        case 10: _t->on_pushButton_addP1_clicked(); break;
        case 11: _t->widgetDrawPoint((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3]))); break;
        case 12: _t->on_pushButton_addCircle_clicked(); break;
        case 13: _t->on_pushButton_draw_clicked(); break;
        case 14: _t->on_spinBox_letterSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_horizontalSlider_x_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_horizontalSlider_y_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_horizontalSlider_z_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_horizontalSlider_xRot_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_horizontalSlider_yRot_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_horizontalSlider_zRot_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_spinBox_dist_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_pushButton_History_clicked(); break;
        case 23: _t->onMousePressed((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 24: _t->on_pushButton_lift_clicked(); break;
        case 25: _t->on_pushButton_Registrate_clicked(); break;
        case 26: _t->drawLineWidget((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2]))); break;
        case 27: _t->adjustRobotRange((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 28: _t->displayAngleReference((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 29: _t->planeRegistration(); break;
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
        {
            using _t = void (RobotDrawUi::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotDrawUi::changeSpeed)) {
                *result = 2;
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
        if (_id < 30)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 30;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 30)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 30;
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

// SIGNAL 2
void RobotDrawUi::changeSpeed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
