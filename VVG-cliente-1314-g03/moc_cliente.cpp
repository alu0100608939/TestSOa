/****************************************************************************
** Meta object code from reading C++ file 'cliente.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "cliente.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cliente.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_cliente_t {
    QByteArrayData data[8];
    char stringdata[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_cliente_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_cliente_t qt_meta_stringdata_cliente = {
    {
QT_MOC_LITERAL(0, 0, 7),
QT_MOC_LITERAL(1, 8, 13),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 4),
QT_MOC_LITERAL(4, 28, 7),
QT_MOC_LITERAL(5, 36, 5),
QT_MOC_LITERAL(6, 42, 13),
QT_MOC_LITERAL(7, 56, 11)
    },
    "cliente\0movie_updated\0\0rect\0image_s\0"
    "image\0ConnectToHost\0StreamVideo\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cliente[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a,
       4,    1,   37,    2, 0x0a,
       6,    0,   40,    2, 0x0a,
       7,    0,   41,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::QRect,    3,
    QMetaType::Void, QMetaType::QImage,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void cliente::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cliente *_t = static_cast<cliente *>(_o);
        switch (_id) {
        case 0: _t->movie_updated((*reinterpret_cast< const QRect(*)>(_a[1]))); break;
        case 1: _t->image_s((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 2: _t->ConnectToHost(); break;
        case 3: _t->StreamVideo(); break;
        default: ;
        }
    }
}

const QMetaObject cliente::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_cliente.data,
      qt_meta_data_cliente,  qt_static_metacall, 0, 0}
};


const QMetaObject *cliente::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cliente::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_cliente.stringdata))
        return static_cast<void*>(const_cast< cliente*>(this));
    return QObject::qt_metacast(_clname);
}

int cliente::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
