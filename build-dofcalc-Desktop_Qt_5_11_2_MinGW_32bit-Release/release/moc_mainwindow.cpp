/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../dofcalc/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[17];
    char stringdata0[433];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 39), // "on_combo_background_currentIn..."
QT_MOC_LITERAL(2, 51, 0), // ""
QT_MOC_LITERAL(3, 52, 5), // "index"
QT_MOC_LITERAL(4, 58, 34), // "on_combo_model_currentIndexCh..."
QT_MOC_LITERAL(5, 93, 35), // "on_combo_sensor_currentIndexC..."
QT_MOC_LITERAL(6, 129, 25), // "on_spin_crop_valueChanged"
QT_MOC_LITERAL(7, 155, 4), // "arg1"
QT_MOC_LITERAL(8, 160, 30), // "on_slider_distance_sliderMoved"
QT_MOC_LITERAL(9, 191, 8), // "position"
QT_MOC_LITERAL(10, 200, 29), // "on_spin_distance_valueChanged"
QT_MOC_LITERAL(11, 230, 30), // "on_slider_focallen_sliderMoved"
QT_MOC_LITERAL(12, 261, 29), // "on_spin_focallen_valueChanged"
QT_MOC_LITERAL(13, 291, 30), // "on_slider_aperture_sliderMoved"
QT_MOC_LITERAL(14, 322, 40), // "on_slider_backgroun_distance_..."
QT_MOC_LITERAL(15, 363, 39), // "on_spin_backgrond_distance_va..."
QT_MOC_LITERAL(16, 403, 29) // "on_spin_aperture_valueChanged"

    },
    "MainWindow\0on_combo_background_currentIndexChanged\0"
    "\0index\0on_combo_model_currentIndexChanged\0"
    "on_combo_sensor_currentIndexChanged\0"
    "on_spin_crop_valueChanged\0arg1\0"
    "on_slider_distance_sliderMoved\0position\0"
    "on_spin_distance_valueChanged\0"
    "on_slider_focallen_sliderMoved\0"
    "on_spin_focallen_valueChanged\0"
    "on_slider_aperture_sliderMoved\0"
    "on_slider_backgroun_distance_sliderMoved\0"
    "on_spin_backgrond_distance_valueChanged\0"
    "on_spin_aperture_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x08 /* Private */,
       4,    1,   77,    2, 0x08 /* Private */,
       5,    1,   80,    2, 0x08 /* Private */,
       6,    1,   83,    2, 0x08 /* Private */,
       8,    1,   86,    2, 0x08 /* Private */,
      10,    1,   89,    2, 0x08 /* Private */,
      11,    1,   92,    2, 0x08 /* Private */,
      12,    1,   95,    2, 0x08 /* Private */,
      13,    1,   98,    2, 0x08 /* Private */,
      14,    1,  101,    2, 0x08 /* Private */,
      15,    1,  104,    2, 0x08 /* Private */,
      16,    1,  107,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    7,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_combo_background_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_combo_model_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_combo_sensor_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_spin_crop_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->on_slider_distance_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_spin_distance_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->on_slider_focallen_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_spin_focallen_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->on_slider_aperture_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_slider_backgroun_distance_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_spin_backgrond_distance_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->on_spin_aperture_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
