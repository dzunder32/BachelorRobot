/****************************************************************************
** Meta object code from reading C++ file 'robotcontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../melfaRobots/robotcontrol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robotcontrol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RobotControl_t {
    QByteArrayData data[10];
    char stringdata0[103];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotControl_t qt_meta_stringdata_RobotControl = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RobotControl"
QT_MOC_LITERAL(1, 13, 10), // "TextOutput"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "text"
QT_MOC_LITERAL(4, 30, 15), // "_connectClicked"
QT_MOC_LITERAL(5, 46, 13), // "_servoClicked"
QT_MOC_LITERAL(6, 60, 12), // "_stopClicked"
QT_MOC_LITERAL(7, 73, 7), // "_update"
QT_MOC_LITERAL(8, 81, 13), // "_directUpdate"
QT_MOC_LITERAL(9, 95, 7) // "checked"

    },
    "RobotControl\0TextOutput\0\0text\0"
    "_connectClicked\0_servoClicked\0"
    "_stopClicked\0_update\0_directUpdate\0"
    "checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    9,

       0        // eod
};

void RobotControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RobotControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->TextOutput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->_connectClicked(); break;
        case 2: _t->_servoClicked(); break;
        case 3: _t->_stopClicked(); break;
        case 4: _t->_update(); break;
        case 5: _t->_directUpdate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RobotControl::staticMetaObject = { {
    QMetaObject::SuperData::link<SubWindow::staticMetaObject>(),
    qt_meta_stringdata_RobotControl.data,
    qt_meta_data_RobotControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RobotControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RobotControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RobotControl.stringdata0))
        return static_cast<void*>(this);
    return SubWindow::qt_metacast(_clname);
}

int RobotControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SubWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
