/****************************************************************************
** Meta object code from reading C++ file 'qoscarsocket.h'
**
** Created: Mon Jun 7 19:41:21 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qoscar/qoscarsocket.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qoscarsocket.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QOscarSocket[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      28,   13,   13,   13, 0x05,
      57,   45,   13,   13, 0x05,
     100,   95,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
     133,  121,   13,   13, 0x0a,
     166,   13,   13,   13, 0x0a,
     184,   13,   13,   13, 0x0a,
     207,   13,   13,   13, 0x08,
     217,   13,   13,   13, 0x08,
     237,   13,   13,   13, 0x08,
     260,   13,   13,   13, 0x08,
     280,   45,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QOscarSocket[] = {
    "QOscarSocket\0\0onConnected()\0"
    "onDisconnected()\0socketError\0"
    "onError(QAbstractSocket::SocketError)\0"
    "data\0onDataRead(QOscarBA)\0Server,port\0"
    "connectToServer(QString,quint16)\0"
    "connectToServer()\0disconnectFromServer()\0"
    "onTimer()\0onSocketConnected()\0"
    "onSocketDisconnected()\0onSocketReadyRead()\0"
    "onSocketError(QAbstractSocket::SocketError)\0"
};

const QMetaObject QOscarSocket::staticMetaObject = {
    { &QTcpSocket::staticMetaObject, qt_meta_stringdata_QOscarSocket,
      qt_meta_data_QOscarSocket, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QOscarSocket::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QOscarSocket::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QOscarSocket::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QOscarSocket))
        return static_cast<void*>(const_cast< QOscarSocket*>(this));
    return QTcpSocket::qt_metacast(_clname);
}

int QOscarSocket::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpSocket::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onConnected(); break;
        case 1: onDisconnected(); break;
        case 2: onError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 3: onDataRead((*reinterpret_cast< const QOscarBA(*)>(_a[1]))); break;
        case 4: connectToServer((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< quint16(*)>(_a[2]))); break;
        case 5: connectToServer(); break;
        case 6: disconnectFromServer(); break;
        case 7: onTimer(); break;
        case 8: onSocketConnected(); break;
        case 9: onSocketDisconnected(); break;
        case 10: onSocketReadyRead(); break;
        case 11: onSocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void QOscarSocket::onConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QOscarSocket::onDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QOscarSocket::onError(QAbstractSocket::SocketError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QOscarSocket::onDataRead(const QOscarBA & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
