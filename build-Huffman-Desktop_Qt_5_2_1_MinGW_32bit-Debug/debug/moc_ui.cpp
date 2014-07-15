/****************************************************************************
** Meta object code from reading C++ file 'ui.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Huffman/ui.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UI_t {
    QByteArrayData data[9];
    char stringdata[161];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UI_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UI_t qt_meta_stringdata_UI = {
    {
QT_MOC_LITERAL(0, 0, 2),
QT_MOC_LITERAL(1, 3, 24),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 5),
QT_MOC_LITERAL(4, 35, 25),
QT_MOC_LITERAL(5, 61, 22),
QT_MOC_LITERAL(6, 84, 24),
QT_MOC_LITERAL(7, 109, 26),
QT_MOC_LITERAL(8, 136, 23)
    },
    "UI\0on_directoryTree_clicked\0\0index\0"
    "on_compressButton_clicked\0"
    "on_radioButton_clicked\0on_compressRadio_clicked\0"
    "on_uncompressRadio_clicked\0"
    "on_actionButton_clicked\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UI[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08,
       4,    0,   47,    2, 0x08,
       5,    0,   48,    2, 0x08,
       6,    0,   49,    2, 0x08,
       7,    0,   50,    2, 0x08,
       8,    0,   51,    2, 0x08,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void UI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UI *_t = static_cast<UI *>(_o);
        switch (_id) {
        case 0: _t->on_directoryTree_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->on_compressButton_clicked(); break;
        case 2: _t->on_radioButton_clicked(); break;
        case 3: _t->on_compressRadio_clicked(); break;
        case 4: _t->on_uncompressRadio_clicked(); break;
        case 5: _t->on_actionButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject UI::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_UI.data,
      qt_meta_data_UI,  qt_static_metacall, 0, 0}
};


const QMetaObject *UI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UI::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UI.stringdata))
        return static_cast<void*>(const_cast< UI*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int UI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
