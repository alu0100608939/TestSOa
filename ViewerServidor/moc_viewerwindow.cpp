/****************************************************************************
** Meta object code from reading C++ file 'viewerwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "viewerwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewerwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ViewerWindow_t {
    QByteArrayData data[13];
    char stringdata[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ViewerWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ViewerWindow_t qt_meta_stringdata_ViewerWindow = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 8),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 11),
QT_MOC_LITERAL(4, 35, 21),
QT_MOC_LITERAL(5, 57, 24),
QT_MOC_LITERAL(6, 82, 28),
QT_MOC_LITERAL(7, 111, 23),
QT_MOC_LITERAL(8, 135, 9),
QT_MOC_LITERAL(9, 145, 11),
QT_MOC_LITERAL(10, 157, 7),
QT_MOC_LITERAL(11, 165, 9),
QT_MOC_LITERAL(12, 175, 6)
    },
    "ViewerWindow\0received\0\0std::string\0"
    "on_pushButton_clicked\0on_actionSalir_triggered\0"
    "on_actionAcerca_de_triggered\0"
    "on_pushButton_4_clicked\0newSocket\0"
    "deleteLater\0client*\0newclient\0Stream\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ViewerWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x08,
       5,    0,   58,    2, 0x08,
       6,    0,   59,    2, 0x08,
       7,    0,   60,    2, 0x08,
       8,    0,   61,    2, 0x08,
       9,    1,   62,    2, 0x08,
      12,    1,   65,    2, 0x08,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void ViewerWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ViewerWindow *_t = static_cast<ViewerWindow *>(_o);
        switch (_id) {
        case 0: _t->received((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        case 1: _t->on_pushButton_clicked(); break;
        case 2: _t->on_actionSalir_triggered(); break;
        case 3: _t->on_actionAcerca_de_triggered(); break;
        case 4: _t->on_pushButton_4_clicked(); break;
        case 5: _t->newSocket(); break;
        case 6: _t->deleteLater((*reinterpret_cast< client*(*)>(_a[1]))); break;
        case 7: _t->Stream((*reinterpret_cast< const std::string(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< client* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ViewerWindow::*_t)(const std::string & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ViewerWindow::received)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ViewerWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ViewerWindow.data,
      qt_meta_data_ViewerWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *ViewerWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewerWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViewerWindow.stringdata))
        return static_cast<void*>(const_cast< ViewerWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ViewerWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void ViewerWindow::received(const std::string & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
