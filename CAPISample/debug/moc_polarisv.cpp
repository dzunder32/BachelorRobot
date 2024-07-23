/****************************************************************************
** Meta object code from reading C++ file 'polarisv.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../polarisv.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'polarisv.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PolarisV_t {
    QByteArrayData data[14];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PolarisV_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PolarisV_t qt_meta_stringdata_PolarisV = {
    {
QT_MOC_LITERAL(0, 0, 8), // "PolarisV"
QT_MOC_LITERAL(1, 9, 16), // "streamingStopped"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 8), // "sendData"
QT_MOC_LITERAL(4, 36, 12), // "sendToolData"
QT_MOC_LITERAL(5, 49, 8), // "ToolData"
QT_MOC_LITERAL(6, 58, 14), // "startStreaming"
QT_MOC_LITERAL(7, 73, 8), // "writeCSV"
QT_MOC_LITERAL(8, 82, 11), // "std::string"
QT_MOC_LITERAL(9, 94, 8), // "fileName"
QT_MOC_LITERAL(10, 103, 13), // "numberOfLines"
QT_MOC_LITERAL(11, 117, 7), // "getData"
QT_MOC_LITERAL(12, 125, 6), // "number"
QT_MOC_LITERAL(13, 132, 8) // "getFrame"

    },
    "PolarisV\0streamingStopped\0\0sendData\0"
    "sendToolData\0ToolData\0startStreaming\0"
    "writeCSV\0std::string\0fileName\0"
    "numberOfLines\0getData\0number\0getFrame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PolarisV[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,
       4,    1,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   56,    2, 0x0a /* Public */,
       7,    2,   57,    2, 0x0a /* Public */,
      11,    1,   62,    2, 0x0a /* Public */,
      13,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, 0x80000000 | 5,    2,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int,    9,   10,
    QMetaType::Int, QMetaType::Int,   12,
    QMetaType::Int,

       0        // eod
};

void PolarisV::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PolarisV *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->streamingStopped(); break;
        case 1: _t->sendData((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sendToolData((*reinterpret_cast< ToolData(*)>(_a[1]))); break;
        case 3: { int _r = _t->startStreaming();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->writeCSV((*reinterpret_cast< std::string(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: { int _r = _t->getData((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->getFrame();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PolarisV::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PolarisV::streamingStopped)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PolarisV::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PolarisV::sendData)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (PolarisV::*)(ToolData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PolarisV::sendToolData)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PolarisV::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_PolarisV.data,
    qt_meta_data_PolarisV,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PolarisV::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PolarisV::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PolarisV.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PolarisV::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void PolarisV::streamingStopped()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PolarisV::sendData(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PolarisV::sendToolData(ToolData _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
