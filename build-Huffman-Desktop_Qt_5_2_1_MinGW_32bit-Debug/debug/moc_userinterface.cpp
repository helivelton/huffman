/****************************************************************************
** Meta object code from reading C++ file 'userinterface.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Huffman/userinterface.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'userinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UserInterface_t {
    QByteArrayData data[7];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UserInterface_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UserInterface_t qt_meta_stringdata_UserInterface = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 24),
QT_MOC_LITERAL(2, 39, 0),
QT_MOC_LITERAL(3, 40, 26),
QT_MOC_LITERAL(4, 67, 20),
QT_MOC_LITERAL(5, 88, 5),
QT_MOC_LITERAL(6, 94, 23)
    },
    "UserInterface\0on_compressRadio_clicked\0"
    "\0on_uncompressRadio_clicked\0"
    "on_filesTree_clicked\0index\0"
    "on_actionButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UserInterface[] = {

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
       1,    0,   34,    2, 0x08,
       3,    0,   35,    2, 0x08,
       4,    1,   36,    2, 0x08,
       6,    0,   39,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    5,
    QMetaType::Void,

       0        // eod
};

void UserInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UserInterface *_t = static_cast<UserInterface *>(_o);
        switch (_id) {
        case 0: _t->on_compressRadio_clicked(); break;
        case 1: _t->on_uncompressRadio_clicked(); break;
        case 2: _t->on_filesTree_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->on_actionButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject UserInterface::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UserInterface.data,
      qt_meta_data_UserInterface,  qt_static_metacall, 0, 0}
};


const QMetaObject *UserInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UserInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserInterface.stringdata))
        return static_cast<void*>(const_cast< UserInterface*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UserInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
