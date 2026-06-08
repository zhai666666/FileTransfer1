/****************************************************************************
** Meta object code from reading C++ file 'fileclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../fileclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fileclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FileClient_t {
    QByteArrayData data[11];
    char stringdata0[117];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FileClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FileClient_t qt_meta_stringdata_FileClient = {
    {
QT_MOC_LITERAL(0, 0, 10), // "FileClient"
QT_MOC_LITERAL(1, 11, 14), // "progressUpdate"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "bytesSent"
QT_MOC_LITERAL(4, 37, 10), // "totalBytes"
QT_MOC_LITERAL(5, 48, 16), // "transferFinished"
QT_MOC_LITERAL(6, 65, 13), // "errorOccurred"
QT_MOC_LITERAL(7, 79, 5), // "error"
QT_MOC_LITERAL(8, 85, 9), // "connected"
QT_MOC_LITERAL(9, 95, 8), // "sendData"
QT_MOC_LITERAL(10, 104, 12) // "disconnected"

    },
    "FileClient\0progressUpdate\0\0bytesSent\0"
    "totalBytes\0transferFinished\0errorOccurred\0"
    "error\0connected\0sendData\0disconnected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   44,    2, 0x06 /* Public */,
       5,    0,   49,    2, 0x06 /* Public */,
       6,    1,   50,    2, 0x06 /* Public */,
       8,    0,   53,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   54,    2, 0x08 /* Private */,
      10,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,    3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FileClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->progressUpdate((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 1: _t->transferFinished(); break;
        case 2: _t->errorOccurred((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->connected(); break;
        case 4: _t->sendData(); break;
        case 5: _t->disconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FileClient::*)(qint64 , qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileClient::progressUpdate)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FileClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileClient::transferFinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FileClient::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileClient::errorOccurred)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FileClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FileClient::connected)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FileClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_FileClient.data,
    qt_meta_data_FileClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FileClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FileClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void FileClient::progressUpdate(qint64 _t1, qint64 _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FileClient::transferFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FileClient::errorOccurred(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FileClient::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
