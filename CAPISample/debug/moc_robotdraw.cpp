/****************************************************************************
** Meta object code from reading C++ file 'robotdraw.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../robotdraw.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotdraw.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RobotDraw_t {
    QByteArrayData data[13];
    char stringdata0[114];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotDraw_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotDraw_t qt_meta_stringdata_RobotDraw = {
    {
QT_MOC_LITERAL(0, 0, 9), // "RobotDraw"
QT_MOC_LITERAL(1, 10, 9), // "stopTimer"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "startTimer"
QT_MOC_LITERAL(4, 32, 16), // "changeTimerSpeed"
QT_MOC_LITERAL(5, 49, 6), // "factor"
QT_MOC_LITERAL(6, 56, 8), // "drawLine"
QT_MOC_LITERAL(7, 65, 5), // "start"
QT_MOC_LITERAL(8, 71, 3), // "end"
QT_MOC_LITERAL(9, 75, 16), // "drawPoint_Widget"
QT_MOC_LITERAL(10, 92, 5), // "point"
QT_MOC_LITERAL(11, 98, 9), // "thickness"
QT_MOC_LITERAL(12, 108, 5) // "color"

    },
    "RobotDraw\0stopTimer\0\0startTimer\0"
    "changeTimerSpeed\0factor\0drawLine\0start\0"
    "end\0drawPoint_Widget\0point\0thickness\0"
    "color"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotDraw[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    1,   41,    2, 0x06 /* Public */,
       6,    2,   44,    2, 0x06 /* Public */,
       9,    3,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,    7,    8,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::Float, QMetaType::QColor,   10,   11,   12,

       0        // eod
};

void RobotDraw::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RobotDraw *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stopTimer(); break;
        case 1: _t->startTimer(); break;
        case 2: _t->changeTimerSpeed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->drawLine((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2]))); break;
        case 4: _t->drawPoint_Widget((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RobotDraw::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotDraw::stopTimer)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RobotDraw::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotDraw::startTimer)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RobotDraw::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotDraw::changeTimerSpeed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (RobotDraw::*)(QVector3D , QVector3D );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotDraw::drawLine)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (RobotDraw::*)(QVector3D , float , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotDraw::drawPoint_Widget)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RobotDraw::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_RobotDraw.data,
    qt_meta_data_RobotDraw,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RobotDraw::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotDraw::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RobotDraw.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int RobotDraw::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void RobotDraw::stopTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RobotDraw::startTimer()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void RobotDraw::changeTimerSpeed(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void RobotDraw::drawLine(QVector3D _t1, QVector3D _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void RobotDraw::drawPoint_Widget(QVector3D _t1, float _t2, QColor _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE