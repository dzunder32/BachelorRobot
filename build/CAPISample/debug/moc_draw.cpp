/****************************************************************************
** Meta object code from reading C++ file 'draw.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../CAPISample/draw.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'draw.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Draw_t {
    QByteArrayData data[15];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Draw_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Draw_t qt_meta_stringdata_Draw = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Draw"
QT_MOC_LITERAL(1, 5, 9), // "sendPoint"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 8), // "sendLine"
QT_MOC_LITERAL(4, 25, 12), // "deletePoints"
QT_MOC_LITERAL(5, 38, 11), // "deleteLines"
QT_MOC_LITERAL(6, 50, 13), // "stopTimerDraw"
QT_MOC_LITERAL(7, 64, 14), // "draw_onTimeout"
QT_MOC_LITERAL(8, 79, 19), // "CreatePointsFromTxt"
QT_MOC_LITERAL(9, 99, 4), // "size"
QT_MOC_LITERAL(10, 104, 14), // "draw_TimerStop"
QT_MOC_LITERAL(11, 119, 22), // "draw_TimerStartNoReset"
QT_MOC_LITERAL(12, 142, 24), // "setIncrementCounterValue"
QT_MOC_LITERAL(13, 167, 3), // "val"
QT_MOC_LITERAL(14, 171, 15) // "StartSimulation"

    },
    "Draw\0sendPoint\0\0sendLine\0deletePoints\0"
    "deleteLines\0stopTimerDraw\0draw_onTimeout\0"
    "CreatePointsFromTxt\0size\0draw_TimerStop\0"
    "draw_TimerStartNoReset\0setIncrementCounterValue\0"
    "val\0StartSimulation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Draw[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x06 /* Public */,
       3,    2,   74,    2, 0x06 /* Public */,
       4,    0,   79,    2, 0x06 /* Public */,
       5,    0,   80,    2, 0x06 /* Public */,
       6,    0,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   82,    2, 0x0a /* Public */,
       8,    1,   83,    2, 0x0a /* Public */,
      10,    0,   86,    2, 0x0a /* Public */,
      11,    0,   87,    2, 0x0a /* Public */,
      12,    1,   88,    2, 0x0a /* Public */,
      14,    1,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVector3D, QMetaType::Float,    2,    2,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void Draw::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Draw *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendPoint((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 1: _t->sendLine((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2]))); break;
        case 2: _t->deletePoints(); break;
        case 3: _t->deleteLines(); break;
        case 4: _t->stopTimerDraw(); break;
        case 5: _t->draw_onTimeout(); break;
        case 6: _t->CreatePointsFromTxt((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 7: _t->draw_TimerStop(); break;
        case 8: _t->draw_TimerStartNoReset(); break;
        case 9: _t->setIncrementCounterValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->StartSimulation((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Draw::*)(QVector3D , float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Draw::sendPoint)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Draw::*)(QVector3D , QVector3D );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Draw::sendLine)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Draw::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Draw::deletePoints)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Draw::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Draw::deleteLines)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Draw::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Draw::stopTimerDraw)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Draw::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Draw.data,
    qt_meta_data_Draw,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Draw::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Draw::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Draw.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Draw::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Draw::sendPoint(QVector3D _t1, float _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Draw::sendLine(QVector3D _t1, QVector3D _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Draw::deletePoints()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Draw::deleteLines()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Draw::stopTimerDraw()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
