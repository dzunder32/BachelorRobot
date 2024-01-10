/****************************************************************************
** Meta object code from reading C++ file 'dialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../PolarisVega_Roboter2LV/widget/dialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Dialog_t {
    QByteArrayData data[15];
    char stringdata0[204];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Dialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Dialog_t qt_meta_stringdata_Dialog = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Dialog"
QT_MOC_LITERAL(1, 7, 9), // "XValueSet"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 5), // "value"
QT_MOC_LITERAL(4, 24, 9), // "YValueSet"
QT_MOC_LITERAL(5, 34, 9), // "ZValueSet"
QT_MOC_LITERAL(6, 44, 12), // "sendQuatData"
QT_MOC_LITERAL(7, 57, 4), // "Data"
QT_MOC_LITERAL(8, 62, 6), // "XValue"
QT_MOC_LITERAL(9, 69, 6), // "YValue"
QT_MOC_LITERAL(10, 76, 26), // "on_ScrollBarX_valueChanged"
QT_MOC_LITERAL(11, 103, 26), // "on_ScrollBarY_valueChanged"
QT_MOC_LITERAL(12, 130, 26), // "on_ScrollBarZ_valueChanged"
QT_MOC_LITERAL(13, 157, 23), // "on_rotateButton_clicked"
QT_MOC_LITERAL(14, 181, 22) // "on_clearButton_clicked"

    },
    "Dialog\0XValueSet\0\0value\0YValueSet\0"
    "ZValueSet\0sendQuatData\0Data\0XValue\0"
    "YValue\0on_ScrollBarX_valueChanged\0"
    "on_ScrollBarY_valueChanged\0"
    "on_ScrollBarZ_valueChanged\0"
    "on_rotateButton_clicked\0on_clearButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Dialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       5,    1,   75,    2, 0x06 /* Public */,
       6,    1,   78,    2, 0x06 /* Public */,
       8,    1,   81,    2, 0x06 /* Public */,
       9,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   87,    2, 0x0a /* Public */,
      11,    1,   90,    2, 0x0a /* Public */,
      12,    1,   93,    2, 0x0a /* Public */,
      13,    0,   96,    2, 0x08 /* Private */,
      14,    0,   97,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::Float,    3,
    QMetaType::Void, QMetaType::QQuaternion,    7,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Dialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Dialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->XValueSet((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 1: _t->YValueSet((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->ZValueSet((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->sendQuatData((*reinterpret_cast< QQuaternion(*)>(_a[1]))); break;
        case 4: _t->XValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->YValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_ScrollBarX_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_ScrollBarY_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_ScrollBarZ_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_rotateButton_clicked(); break;
        case 10: _t->on_clearButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Dialog::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::XValueSet)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::YValueSet)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::ZValueSet)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(QQuaternion );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::sendQuatData)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::XValue)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Dialog::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Dialog::YValue)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Dialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Dialog.data,
    qt_meta_data_Dialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Dialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Dialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Dialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Dialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
void Dialog::XValueSet(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Dialog::YValueSet(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Dialog::ZValueSet(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Dialog::sendQuatData(QQuaternion _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Dialog::XValue(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Dialog::YValue(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
