/****************************************************************************
** Meta object code from reading C++ file 'robot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../robot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Robot_t {
    QByteArrayData data[16];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Robot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Robot_t qt_meta_stringdata_Robot = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Robot"
QT_MOC_LITERAL(1, 6, 11), // "robotAnswer"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 12), // "robotCommand"
QT_MOC_LITERAL(4, 32, 18), // "alternativeCommand"
QT_MOC_LITERAL(5, 51, 7), // "running"
QT_MOC_LITERAL(6, 59, 16), // "_positionChanged"
QT_MOC_LITERAL(7, 76, 14), // "UpdatePosition"
QT_MOC_LITERAL(8, 91, 5), // "Write"
QT_MOC_LITERAL(9, 97, 7), // "Connect"
QT_MOC_LITERAL(10, 105, 11), // "IsConnected"
QT_MOC_LITERAL(11, 117, 4), // "Stop"
QT_MOC_LITERAL(12, 122, 10), // "Disconnect"
QT_MOC_LITERAL(13, 133, 7), // "ServoOn"
QT_MOC_LITERAL(14, 141, 13), // "EmergencyStop"
QT_MOC_LITERAL(15, 155, 20) // "UpdatePositionFromUi"

    },
    "Robot\0robotAnswer\0\0robotCommand\0"
    "alternativeCommand\0running\0_positionChanged\0"
    "UpdatePosition\0Write\0Connect\0IsConnected\0"
    "Stop\0Disconnect\0ServoOn\0EmergencyStop\0"
    "UpdatePositionFromUi"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Robot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       3,    1,   87,    2, 0x06 /* Public */,
       4,    1,   90,    2, 0x06 /* Public */,
       5,    1,   93,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   96,    2, 0x08 /* Private */,
       7,    0,   97,    2, 0x0a /* Public */,
       8,    1,   98,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x0a /* Public */,
      10,    0,  102,    2, 0x0a /* Public */,
      11,    0,  103,    2, 0x0a /* Public */,
      12,    0,  104,    2, 0x0a /* Public */,
      13,    1,  105,    2, 0x0a /* Public */,
      14,    0,  108,    2, 0x0a /* Public */,
      15,    0,  109,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Robot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Robot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->robotAnswer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->robotCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->alternativeCommand((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->running((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->_positionChanged(); break;
        case 5: _t->UpdatePosition(); break;
        case 6: _t->Write((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->Connect(); break;
        case 8: { bool _r = _t->IsConnected();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->Stop(); break;
        case 10: _t->Disconnect(); break;
        case 11: _t->ServoOn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->EmergencyStop(); break;
        case 13: _t->UpdatePositionFromUi(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Robot::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Robot::robotAnswer)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Robot::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Robot::robotCommand)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Robot::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Robot::alternativeCommand)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Robot::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Robot::running)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Robot::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_Robot.data,
    qt_meta_data_Robot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Robot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Robot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Robot.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Robot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Robot::robotAnswer(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Robot::robotCommand(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Robot::alternativeCommand(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Robot::running(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
