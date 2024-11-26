/****************************************************************************
** Meta object code from reading C++ file 'liveplot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../widget/liveplot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'liveplot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LivePlot_t {
    QByteArrayData data[13];
    char stringdata0[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LivePlot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LivePlot_t qt_meta_stringdata_LivePlot = {
    {
QT_MOC_LITERAL(0, 0, 8), // "LivePlot"
QT_MOC_LITERAL(1, 9, 17), // "sendDataExtract50"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "sendConfigName"
QT_MOC_LITERAL(4, 43, 10), // "configName"
QT_MOC_LITERAL(5, 54, 22), // "on_ClearButton_clicked"
QT_MOC_LITERAL(6, 77, 6), // "addPts"
QT_MOC_LITERAL(7, 84, 15), // "QVector<double>"
QT_MOC_LITERAL(8, 100, 6), // "values"
QT_MOC_LITERAL(9, 107, 21), // "on_DataButton_clicked"
QT_MOC_LITERAL(10, 129, 10), // "changeName"
QT_MOC_LITERAL(11, 140, 16), // "setDecimalPlaces"
QT_MOC_LITERAL(12, 157, 3) // "val"

    },
    "LivePlot\0sendDataExtract50\0\0sendConfigName\0"
    "configName\0on_ClearButton_clicked\0"
    "addPts\0QVector<double>\0values\0"
    "on_DataButton_clicked\0changeName\0"
    "setDecimalPlaces\0val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LivePlot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    1,   50,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   53,    2, 0x0a /* Public */,
       6,    1,   54,    2, 0x0a /* Public */,
       9,    0,   57,    2, 0x0a /* Public */,
      10,    0,   58,    2, 0x0a /* Public */,
      11,    1,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void LivePlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LivePlot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDataExtract50(); break;
        case 1: _t->sendConfigName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->on_ClearButton_clicked(); break;
        case 3: _t->addPts((*reinterpret_cast< QVector<double>(*)>(_a[1]))); break;
        case 4: _t->on_DataButton_clicked(); break;
        case 5: _t->changeName(); break;
        case 6: _t->setDecimalPlaces((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
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
            using _t = void (LivePlot::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LivePlot::sendDataExtract50)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LivePlot::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LivePlot::sendConfigName)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LivePlot::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_LivePlot.data,
    qt_meta_data_LivePlot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LivePlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LivePlot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LivePlot.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int LivePlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void LivePlot::sendDataExtract50()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LivePlot::sendConfigName(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
