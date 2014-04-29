/****************************************************************************
** Meta object code from reading C++ file 'client.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "client.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'client.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_client_t {
    QByteArrayData data[8];
    char stringdata[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_client_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_client_t qt_meta_stringdata_client = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 9),
QT_MOC_LITERAL(2, 17, 0),
QT_MOC_LITERAL(3, 18, 11),
QT_MOC_LITERAL(4, 30, 6),
QT_MOC_LITERAL(5, 37, 15),
QT_MOC_LITERAL(6, 53, 12),
QT_MOC_LITERAL(7, 66, 12)
    },
    "client\0readytogo\0\0std::string\0buffer\0"
    "readydisconnect\0client_ready\0client_disco\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x05,
       5,    0,   37,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       6,    0,   38,    2, 0x08,
       7,    0,   39,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        client *_t = static_cast<client *>(_o);
        switch (_id) {
        case 0: _t->readytogo((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 1: _t->readydisconnect(); break;
        case 2: _t->client_ready(); break;
        case 3: _t->client_disco(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (client::*_t)(std::string );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::readytogo)) {
                *result = 0;
            }
        }
        {
            typedef void (client::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&client::readydisconnect)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject client::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_client.data,
      qt_meta_data_client,  qt_static_metacall, 0, 0}
};


const QMetaObject *client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *client::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_client.stringdata))
        return static_cast<void*>(const_cast< client*>(this));
    return QDialog::qt_metacast(_clname);
}

int client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void client::readytogo(std::string _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void client::readydisconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
