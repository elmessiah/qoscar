/****************************************************************************
** Meta object code from reading C++ file 'qoscar.h'
**
** Created: Mon Jun 7 19:41:17 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qoscar/qoscar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qoscar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QOscar[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       8,    7,    7,    7, 0x05,
      21,    7,    7,    7, 0x05,
      41,   35,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
      62,    7,    7,    7, 0x0a,
      70,    7,    7,    7, 0x0a,
      82,   79,    7,    7, 0x0a,
     106,   97,    7,    7, 0x0a,
     134,  127,    7,    7, 0x0a,
     158,  153,    7,    7, 0x0a,
     181,  175,    7,    7, 0x0a,
     206,  199,    7,    7, 0x0a,
     237,  225,    7,    7, 0x0a,
     267,  261,    7,    7, 0x0a,
     300,  289,    7,    7, 0x0a,
     329,    7,    7,    7, 0x08,
     349,    7,    7,    7, 0x08,
     384,  372,    7,    7, 0x08,
     433,  428,    7,    7, 0x08,
     460,    7,    7,    7, 0x08,
     489,  481,    7,    7, 0x08,
     513,    7,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QOscar[] = {
    "QOscar\0\0onLoggedIn()\0onLoggedOff()\0"
    "error\0onError(QOscarError)\0login()\0"
    "logoff()\0sn\0setSN(QString)\0password\0"
    "setPassword(QString)\0server\0"
    "setServer(QString)\0port\0setPort(quint16)\0"
    "codec\0setCodec(QString)\0status\0"
    "setStatus(quint16)\0statusFlags\0"
    "setStatusFlags(quint16)\0ident\0"
    "setIdent(QOscarIdent)\0sn,message\0"
    "sendMessage(QString,QString)\0"
    "onSocketConnected()\0onSocketDisconnected()\0"
    "socketError\0onSocketError(QAbstractSocket::SocketError)\0"
    "data\0onSocketDataRead(QOscarBA)\0"
    "onOserviceLoggedIn()\0message\0"
    "onIcbmMessage(QMessage)\0onPingTimer()\0"
};

const QMetaObject QOscar::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QOscar,
      qt_meta_data_QOscar, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QOscar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QOscar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QOscar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QOscar))
        return static_cast<void*>(const_cast< QOscar*>(this));
    return QObject::qt_metacast(_clname);
}

int QOscar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onLoggedIn(); break;
        case 1: onLoggedOff(); break;
        case 2: onError((*reinterpret_cast< QOscarError(*)>(_a[1]))); break;
        case 3: login(); break;
        case 4: logoff(); break;
        case 5: setSN((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: setPassword((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: setServer((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: setPort((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 9: setCodec((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: setStatus((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 11: setStatusFlags((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 12: setIdent((*reinterpret_cast< const QOscarIdent(*)>(_a[1]))); break;
        case 13: sendMessage((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 14: onSocketConnected(); break;
        case 15: onSocketDisconnected(); break;
        case 16: onSocketError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 17: onSocketDataRead((*reinterpret_cast< const QOscarBA(*)>(_a[1]))); break;
        case 18: onOserviceLoggedIn(); break;
        case 19: onIcbmMessage((*reinterpret_cast< const QMessage(*)>(_a[1]))); break;
        case 20: onPingTimer(); break;
        default: ;
        }
        _id -= 21;
    }
    return _id;
}

// SIGNAL 0
void QOscar::onLoggedIn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QOscar::onLoggedOff()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void QOscar::onError(QOscarError _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
