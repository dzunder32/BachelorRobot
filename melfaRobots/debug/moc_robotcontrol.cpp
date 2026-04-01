/****************************************************************************
** Meta object code from reading C++ file 'robotcontrol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../robotcontrol.h"
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
    QByteArrayData data[12];
    char stringdata0[124];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RobotControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RobotControl_t qt_meta_stringdata_RobotControl = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RobotControl"
QT_MOC_LITERAL(1, 13, 13), // "connectStatus"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "status"
QT_MOC_LITERAL(4, 35, 10), // "TextOutput"
QT_MOC_LITERAL(5, 46, 4), // "text"
QT_MOC_LITERAL(6, 51, 15), // "_connectClicked"
QT_MOC_LITERAL(7, 67, 13), // "_servoClicked"
QT_MOC_LITERAL(8, 81, 12), // "_stopClicked"
QT_MOC_LITERAL(9, 94, 7), // "_update"
QT_MOC_LITERAL(10, 102, 13), // "_directUpdate"
QT_MOC_LITERAL(11, 116, 7) // "checked"

    },
    "RobotControl\0connectStatus\0\0status\0"
    "TextOutput\0text\0_connectClicked\0"
    "_servoClicked\0_stopClicked\0_update\0"
    "_directUpdate\0checked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RobotControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   52,    2, 0x0a /* Public */,
       6,    0,   55,    2, 0x08 /* Private */,
       7,    0,   56,    2, 0x08 /* Private */,
       8,    0,   57,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,

       0        // eod
};

void RobotControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RobotControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectStatus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->TextOutput((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->_connectClicked(); break;
        case 3: _t->_servoClicked(); break;
        case 4: _t->_stopClicked(); break;
        case 5: _t->_update(); break;
        case 6: _t->_directUpdate((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RobotControl::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RobotControl::connectStatus)) {
                *result = 0;
                return;
            }
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void RobotControl::connectStatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
