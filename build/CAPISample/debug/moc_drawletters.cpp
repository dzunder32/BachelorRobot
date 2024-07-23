/****************************************************************************
** Meta object code from reading C++ file 'drawletters.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../CAPISample/drawletters.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawletters.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DrawLetters_t {
    QByteArrayData data[19];
    char stringdata0[295];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DrawLetters_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DrawLetters_t qt_meta_stringdata_DrawLetters = {
    {
QT_MOC_LITERAL(0, 0, 11), // "DrawLetters"
QT_MOC_LITERAL(1, 12, 15), // "drawPointWidget"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "point"
QT_MOC_LITERAL(4, 35, 9), // "thickness"
QT_MOC_LITERAL(5, 45, 17), // "deletePointWidget"
QT_MOC_LITERAL(6, 63, 16), // "deleteLineWidget"
QT_MOC_LITERAL(7, 80, 9), // "stopTimer"
QT_MOC_LITERAL(8, 90, 14), // "drawLineWidget"
QT_MOC_LITERAL(9, 105, 10), // "startPoint"
QT_MOC_LITERAL(10, 116, 8), // "endPoint"
QT_MOC_LITERAL(11, 125, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(12, 149, 28), // "on_buttonDeletePoint_clicked"
QT_MOC_LITERAL(13, 178, 15), // "pB_draw_clicked"
QT_MOC_LITERAL(14, 194, 34), // "on_spinBox_LetterSize_valueCh..."
QT_MOC_LITERAL(15, 229, 4), // "arg1"
QT_MOC_LITERAL(16, 234, 32), // "on_robotSpeedSlider_valueChanged"
QT_MOC_LITERAL(17, 267, 5), // "value"
QT_MOC_LITERAL(18, 273, 21) // "on_checkBox_2_clicked"

    },
    "DrawLetters\0drawPointWidget\0\0point\0"
    "thickness\0deletePointWidget\0"
    "deleteLineWidget\0stopTimer\0drawLineWidget\0"
    "startPoint\0endPoint\0on_pushButton_2_clicked\0"
    "on_buttonDeletePoint_clicked\0"
    "pB_draw_clicked\0on_spinBox_LetterSize_valueChanged\0"
    "arg1\0on_robotSpeedSlider_valueChanged\0"
    "value\0on_checkBox_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DrawLetters[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   69,    2, 0x0a /* Public */,
       5,    0,   74,    2, 0x0a /* Public */,
       6,    0,   75,    2, 0x0a /* Public */,
       7,    0,   76,    2, 0x0a /* Public */,
       8,    2,   77,    2, 0x0a /* Public */,
      11,    0,   82,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,
      13,    0,   84,    2, 0x08 /* Private */,
      14,    1,   85,    2, 0x08 /* Private */,
      16,    1,   88,    2, 0x08 /* Private */,
      18,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QVector3D, QMetaType::Float,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVector3D, QMetaType::QVector3D,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,

       0        // eod
};

void DrawLetters::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DrawLetters *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->drawPointWidget((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< float(*)>(_a[2]))); break;
        case 1: _t->deletePointWidget(); break;
        case 2: _t->deleteLineWidget(); break;
        case 3: _t->stopTimer(); break;
        case 4: _t->drawLineWidget((*reinterpret_cast< QVector3D(*)>(_a[1])),(*reinterpret_cast< QVector3D(*)>(_a[2]))); break;
        case 5: _t->on_pushButton_2_clicked(); break;
        case 6: _t->on_buttonDeletePoint_clicked(); break;
        case 7: _t->pB_draw_clicked(); break;
        case 8: _t->on_spinBox_LetterSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_robotSpeedSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_checkBox_2_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DrawLetters::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_DrawLetters.data,
    qt_meta_data_DrawLetters,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DrawLetters::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DrawLetters::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DrawLetters.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DrawLetters::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
