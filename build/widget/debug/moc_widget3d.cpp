/****************************************************************************
** Meta object code from reading C++ file 'widget3d.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../widget/widget3d.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget3d.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget3D_t {
    QByteArrayData data[20];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget3D_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget3D_t qt_meta_stringdata_Widget3D = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Widget3D"
QT_MOC_LITERAL(1, 9, 9), // "updatePlt"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 15), // "QVector<double>"
QT_MOC_LITERAL(4, 36, 6), // "values"
QT_MOC_LITERAL(5, 43, 10), // "updatePlt2"
QT_MOC_LITERAL(6, 54, 9), // "sendAngle"
QT_MOC_LITERAL(7, 64, 5), // "angle"
QT_MOC_LITERAL(8, 70, 11), // "getToolData"
QT_MOC_LITERAL(9, 82, 14), // "getPolarisData"
QT_MOC_LITERAL(10, 97, 17), // "getCalibratorData"
QT_MOC_LITERAL(11, 115, 9), // "drawPoint"
QT_MOC_LITERAL(12, 125, 8), // "position"
QT_MOC_LITERAL(13, 134, 4), // "size"
QT_MOC_LITERAL(14, 139, 5), // "color"
QT_MOC_LITERAL(15, 145, 15), // "deleteAllPoints"
QT_MOC_LITERAL(16, 161, 14), // "deleteAllLines"
QT_MOC_LITERAL(17, 176, 24), // "addCylinderBetweenPoints"
QT_MOC_LITERAL(18, 201, 10), // "startPoint"
QT_MOC_LITERAL(19, 212, 8) // "endPoint"

    },
    "Widget3D\0updatePlt\0\0QVector<double>\0"
    "values\0updatePlt2\0sendAngle\0angle\0"
    "getToolData\0getPolarisData\0getCalibratorData\0"
    "drawPoint\0position\0size\0color\0"
    "deleteAllPoints\0deleteAllLines\0"
    "addCylinderBetweenPoints\0startPoint\0"
    "endPoint"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget3D[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       5,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   73,    2, 0x0a /* Public */,
       9,    1,   76,    2, 0x0a /* Public */,
      10,    1,   79,    2, 0x0a /* Public */,
      11,    3,   82,    2, 0x0a /* Public */,
      15,    0,   89,    2, 0x0a /* Public */,
      16,    0,   90,    2, 0x0a /* Public */,
      17,    2,   91,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Float,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::Float, QMetaType::QColor,   12,   13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,   18,   19,

       0        // eod
};

void Widget3D::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget3D *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatePlt((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 1: _t->updatePlt2((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 2: _t->sendAngle((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->getToolData((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 4: _t->getPolarisData((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 5: _t->getCalibratorData((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 6: _t->drawPoint((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2])),(*reinterpret_cast< QColor(*)>(_a[3]))); break;
        case 7: _t->deleteAllPoints(); break;
        case 8: _t->deleteAllLines(); break;
        case 9: _t->addCylinderBetweenPoints((*reinterpret_cast< const QVector3D(*)>(_a[1])),(*reinterpret_cast< const QVector3D(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<double> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget3D::*)(QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget3D::updatePlt)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Widget3D::*)(QVector<double> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget3D::updatePlt2)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Widget3D::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget3D::sendAngle)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget3D::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget3D.data,
    qt_meta_data_Widget3D,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget3D::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget3D::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget3D.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget3D::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Widget3D::updatePlt(QVector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget3D::updatePlt2(QVector<double> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Widget3D::sendAngle(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
