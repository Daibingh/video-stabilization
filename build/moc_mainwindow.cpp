/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Videoplayer_t {
    QByteArrayData data[13];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Videoplayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Videoplayer_t qt_meta_stringdata_Videoplayer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "Videoplayer"
QT_MOC_LITERAL(1, 12, 9), // "img_ready"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "img"
QT_MOC_LITERAL(4, 27, 7), // "double*"
QT_MOC_LITERAL(5, 35, 1), // "x"
QT_MOC_LITERAL(6, 37, 1), // "y"
QT_MOC_LITERAL(7, 39, 1), // "a"
QT_MOC_LITERAL(8, 41, 9), // "frame_pos"
QT_MOC_LITERAL(9, 51, 13), // "process_ready"
QT_MOC_LITERAL(10, 65, 5), // "img_2"
QT_MOC_LITERAL(11, 71, 8), // "finished"
QT_MOC_LITERAL(12, 80, 4) // "play"

    },
    "Videoplayer\0img_ready\0\0img\0double*\0x\0"
    "y\0a\0frame_pos\0process_ready\0img_2\0"
    "finished\0play"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Videoplayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,   34,    2, 0x06 /* Public */,
       9,    6,   45,    2, 0x06 /* Public */,
      11,    0,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Int,    3,    5,    6,    7,    8,
    QMetaType::Void, QMetaType::QImage, QMetaType::QImage, 0x80000000 | 4, 0x80000000 | 4, 0x80000000 | 4, QMetaType::Int,    3,   10,    5,    6,    7,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Videoplayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Videoplayer *_t = static_cast<Videoplayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->img_ready((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< double*(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3])),(*reinterpret_cast< double*(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 1: _t->process_ready((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3])),(*reinterpret_cast< double*(*)>(_a[4])),(*reinterpret_cast< double*(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 2: _t->finished(); break;
        case 3: _t->play(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Videoplayer::*_t)(const QImage & , double * , double * , double * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Videoplayer::img_ready)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Videoplayer::*_t)(const QImage & , const QImage & , double * , double * , double * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Videoplayer::process_ready)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Videoplayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Videoplayer::finished)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Videoplayer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Videoplayer.data,
      qt_meta_data_Videoplayer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Videoplayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Videoplayer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Videoplayer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Videoplayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void Videoplayer::img_ready(const QImage & _t1, double * _t2, double * _t3, double * _t4, int _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Videoplayer::process_ready(const QImage & _t1, const QImage & _t2, double * _t3, double * _t4, double * _t5, int _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Videoplayer::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[222];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 5), // "start"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 23), // "on_actionopen_triggered"
QT_MOC_LITERAL(4, 42, 24), // "on_actionstart_triggered"
QT_MOC_LITERAL(5, 67, 8), // "show_img"
QT_MOC_LITERAL(6, 76, 3), // "img"
QT_MOC_LITERAL(7, 80, 7), // "double*"
QT_MOC_LITERAL(8, 88, 1), // "x"
QT_MOC_LITERAL(9, 90, 1), // "y"
QT_MOC_LITERAL(10, 92, 1), // "a"
QT_MOC_LITERAL(11, 94, 9), // "frame_pos"
QT_MOC_LITERAL(12, 104, 20), // "handle_process_ready"
QT_MOC_LITERAL(13, 125, 5), // "img_2"
QT_MOC_LITERAL(14, 131, 15), // "handle_finished"
QT_MOC_LITERAL(15, 147, 25), // "on_actionradius_triggered"
QT_MOC_LITERAL(16, 173, 23), // "on_actionstop_triggered"
QT_MOC_LITERAL(17, 197, 24) // "on_actionreset_triggered"

    },
    "MainWindow\0start\0\0on_actionopen_triggered\0"
    "on_actionstart_triggered\0show_img\0img\0"
    "double*\0x\0y\0a\0frame_pos\0handle_process_ready\0"
    "img_2\0handle_finished\0on_actionradius_triggered\0"
    "on_actionstop_triggered\0"
    "on_actionreset_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    5,   62,    2, 0x0a /* Public */,
      12,    6,   73,    2, 0x0a /* Public */,
      14,    0,   86,    2, 0x0a /* Public */,
      15,    0,   87,    2, 0x0a /* Public */,
      16,    0,   88,    2, 0x0a /* Public */,
      17,    0,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QImage, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7, QMetaType::Int,    6,    8,    9,   10,   11,
    QMetaType::Void, QMetaType::QImage, QMetaType::QImage, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 7, QMetaType::Int,    6,   13,    8,    9,   10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->start(); break;
        case 1: _t->on_actionopen_triggered(); break;
        case 2: _t->on_actionstart_triggered(); break;
        case 3: _t->show_img((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< double*(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3])),(*reinterpret_cast< double*(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 4: _t->handle_process_ready((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< const QImage(*)>(_a[2])),(*reinterpret_cast< double*(*)>(_a[3])),(*reinterpret_cast< double*(*)>(_a[4])),(*reinterpret_cast< double*(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 5: _t->handle_finished(); break;
        case 6: _t->on_actionradius_triggered(); break;
        case 7: _t->on_actionstop_triggered(); break;
        case 8: _t->on_actionreset_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::start)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
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
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::start()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
