/****************************************************************************
** Meta object code from reading C++ file 'osvr_controller_viewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../osvr_controller_viewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'osvr_controller_viewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_OSVR_Controller_Viewer_t {
    QByteArrayData data[6];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_OSVR_Controller_Viewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_OSVR_Controller_Viewer_t qt_meta_stringdata_OSVR_Controller_Viewer = {
    {
QT_MOC_LITERAL(0, 0, 22), // "OSVR_Controller_Viewer"
QT_MOC_LITERAL(1, 23, 24), // "update_interface_details"
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 16), // "QTreeWidgetItem*"
QT_MOC_LITERAL(4, 66, 13), // "tree_elem_ptr"
QT_MOC_LITERAL(5, 80, 18) // "update_details_box"

    },
    "OSVR_Controller_Viewer\0update_interface_details\0"
    "\0QTreeWidgetItem*\0tree_elem_ptr\0"
    "update_details_box"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_OSVR_Controller_Viewer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       5,    0,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void OSVR_Controller_Viewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        OSVR_Controller_Viewer *_t = static_cast<OSVR_Controller_Viewer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update_interface_details((*reinterpret_cast< QTreeWidgetItem*(*)>(_a[1]))); break;
        case 1: _t->update_details_box(); break;
        default: ;
        }
    }
}

const QMetaObject OSVR_Controller_Viewer::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_OSVR_Controller_Viewer.data,
      qt_meta_data_OSVR_Controller_Viewer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *OSVR_Controller_Viewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OSVR_Controller_Viewer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_OSVR_Controller_Viewer.stringdata0))
        return static_cast<void*>(const_cast< OSVR_Controller_Viewer*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int OSVR_Controller_Viewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
