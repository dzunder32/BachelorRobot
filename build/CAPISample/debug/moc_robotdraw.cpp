/****************************************************************************
** Meta object code from reading C++ file 'robotdraw.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../CAPISample/robotdraw.h"
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
    QByteArrayData data[15];
    char stringdata0[138];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotDraw_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotDraw_t qt_meta_stringdata_RobotDraw = {
    {
QT_MOC_LITERAL(0, 0, 9), // "RobotDraw"
QT_MOC_LITERAL(1, 10, 8), // "drawLine"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 5), // "start"
QT_MOC_LITERAL(4, 26, 3), // "end"
QT_MOC_LITERAL(5, 30, 16), // "drawPoint_Widget"
QT_MOC_LITERAL(6, 47, 5), // "point"
QT_MOC_LITERAL(7, 53, 9), // "thickness"
QT_MOC_LITERAL(8, 63, 5), // "color"
QT_MOC_LITERAL(9, 69, 14), // "startDrawTimer"
QT_MOC_LITERAL(10, 84, 13), // "stopDrawTimer"
QT_MOC_LITERAL(11, 98, 12), // "setTimerTime"
QT_MOC_LITERAL(12, 111, 2), // "ms"
QT_MOC_LITERAL(13, 114, 16), // "changeTimerSpeed"
QT_MOC_LITERAL(14, 131, 6) // "factor"

    },
    "RobotDraw\0drawLine\0\0start\0end\0"
    "drawPoint_Widget\0point\0thickness\0color\0"
    "startDrawTimer\0stopDrawTimer\0setTimerTime\0"
    "ms\0changeTimerSpeed\0factor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotDraw[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    3,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   56,    2, 0x0a /* Public */,
      10,    0,   57,    2, 0x0a /* Public */,
      11,    1,   58,    2, 0x0a /* Public */,
      13,    1,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,    3,    4,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::Float, QMetaType::QColor,    6,    7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Float,   14,

       0        // eod
};

void RobotDraw::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RobotDraw *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->drawLine((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2]))); break;
        case 1: _t->drawPoint_Widget((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3]))); break;
        case 2: _t->startDrawTimer(); break;
        case 3: _t->stopDrawTimer(); break;
        case 4: _t->setTimerTime((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->changeTimerSpeed((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RobotDraw::*)(QVector3D , QVector3D );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotDraw::drawLine)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RobotDraw::*)(QVector3D , float , QColor );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotDraw::drawPoint_Widget)) {
                *result = 1;
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
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void RobotDraw::drawLine(QVector3D _t1, QVector3D _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void RobotDraw::drawPoint_Widget(QVector3D _t1, float _t2, QColor _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
