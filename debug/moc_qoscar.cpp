/****************************************************************************
** Meta object code from reading C++ file 'qoscar.h'
**
** Created: Thu 28. Jan 14:39:28 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QOSCAR/qoscar.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qoscar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QOSCAR[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: signature, parameters, type, tag, flags
      10,    8,    7,    7, 0x05,
      37,    8,    7,    7, 0x05,
      63,    7,    7,    7, 0x05,
      75,    7,    7,    7, 0x05,
     102,    7,    7,    7, 0x05,
     116,    7,    7,    7, 0x05,
     129,    7,    7,    7, 0x05,
     151,  142,    7,    7, 0x05,
     202,  178,    7,    7, 0x05,

 // slots: signature, parameters, type, tag, flags
     238,    7,    7,    7, 0x08,
     251,    7,    7,    7, 0x08,
     279,  267,    7,    7, 0x08,
     316,    7,    7,    7, 0x08,
     329,    7,    7,    7, 0x08,
     340,    7,    7,    7, 0x08,
     362,  354,    7,    7, 0x08,
     382,  142,    7,    7, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_QOSCAR[] = {
    "QOSCAR\0\0,\0fError(QErrorType,QString)\0"
    "fWarning(quint16,QString)\0fLoggedIn()\0"
    "fMessageReceived(QMessage)\0fCLReceived()\0"
    "fLoggedOff()\0fCLHandled()\0u16Level\0"
    "fEvilNotification(quint16)\0"
    "sSN,sReason,bAuthorized\0"
    "fAuthResponse(QString,QString,bool)\0"
    "oConnected()\0oDisconnected()\0socketError\0"
    "oError(QAbstractSocket::SocketError)\0"
    "oReadyRead()\0oTimeOut()\0onCLHandled()\0"
    "message\0onMessage(QMessage)\0"
    "onEvilNotification(quint16)\0"
};

const QMetaObject QOSCAR::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QOSCAR,
      qt_meta_data_QOSCAR, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QOSCAR::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QOSCAR::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QOSCAR::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QOSCAR))
        return static_cast<void*>(const_cast< QOSCAR*>(this));
    return QObject::qt_metacast(_clname);
}

int QOSCAR::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: fError((*reinterpret_cast< QErrorType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: fWarning((*reinterpret_cast< const quint16(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 2: fLoggedIn(); break;
        case 3: fMessageReceived((*reinterpret_cast< QMessage(*)>(_a[1]))); break;
        case 4: fCLReceived(); break;
        case 5: fLoggedOff(); break;
        case 6: fCLHandled(); break;
        case 7: fEvilNotification((*reinterpret_cast< const quint16(*)>(_a[1]))); break;
        case 8: fAuthResponse((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const bool(*)>(_a[3]))); break;
        case 9: oConnected(); break;
        case 10: oDisconnected(); break;
        case 11: oError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 12: oReadyRead(); break;
        case 13: oTimeOut(); break;
        case 14: onCLHandled(); break;
        case 15: onMessage((*reinterpret_cast< const QMessage(*)>(_a[1]))); break;
        case 16: onEvilNotification((*reinterpret_cast< const quint16(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void QOSCAR::fError(QErrorType _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QOSCAR::fWarning(const quint16 _t1, const QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QOSCAR::fLoggedIn()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void QOSCAR::fMessageReceived(QMessage _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QOSCAR::fCLReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}

// SIGNAL 5
void QOSCAR::fLoggedOff()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void QOSCAR::fCLHandled()
{
    QMetaObject::activate(this, &staticMetaObject, 6, 0);
}

// SIGNAL 7
void QOSCAR::fEvilNotification(const quint16 _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void QOSCAR::fAuthResponse(const QString & _t1, const QString & _t2, const bool _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
