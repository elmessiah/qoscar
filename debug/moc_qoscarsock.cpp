/****************************************************************************
** Meta object code from reading C++ file 'qoscarsock.h'
**
** Created: Tue 26. Jan 14:26:52 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QOSCAR/qoscarsock.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qoscarsock.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QOSCARSock[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      25,   11,   11,   11, 0x05,
      41,   11,   11,   11, 0x05,
      78,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      91,   11,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     132,  120,   11,   11, 0x08,
     169,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QOSCARSock[] = {
    "QOSCARSock\0\0sConnected()\0sDisconnected()\0"
    "sError(QAbstractSocket::SocketError)\0"
    "sReadyRead()\0fConnected()\0fDisconnected()\0"
    "socketError\0fError(QAbstractSocket::SocketError)\0"
    "fReadyRead()\0"
};

const QMetaObject QOSCARSock::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QOSCARSock,
      qt_meta_data_QOSCARSock, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QOSCARSock::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QOSCARSock::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QOSCARSock::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QOSCARSock))
        return static_cast<void*>(const_cast< QOSCARSock*>(this));
    return QObject::qt_metacast(_clname);
}

int QOSCARSock::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sConnected(); break;
        case 1: sDisconnected(); break;
        case 2: sError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 3: sReadyRead(); break;
        case 4: fConnected(); break;
        case 5: fDisconnected(); break;
        case 6: fError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: fReadyRead(); break;
        default: ;
        }
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void QOSCARSock::sConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QOSCARSock::sDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QOSCARSock::sError(QAbstractSocket::SocketError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QOSCARSock::sReadyRead()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
