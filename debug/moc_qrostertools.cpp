/****************************************************************************
** Meta object code from reading C++ file 'qrostertools.h'
**
** Created: Thu 28. Jan 02:11:37 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QOSCAR/qrostertools.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qrostertools.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QRoster[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      37,   23,    8,    8, 0x05,
      87,   75,    8,    8, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QRoster[] = {
    "QRoster\0\0onCLHandled()\0buddy,arrived\0"
    "onBuddyArrivedOrDeparted(QBuddy,bool)\0"
    "sSN,sReason\0onAuthRequest(QString,QString)\0"
};

const QMetaObject QRoster::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QRoster,
      qt_meta_data_QRoster, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QRoster::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QRoster::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QRoster::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QRoster))
        return static_cast<void*>(const_cast< QRoster*>(this));
    return QObject::qt_metacast(_clname);
}

int QRoster::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onCLHandled(); break;
        case 1: onBuddyArrivedOrDeparted((*reinterpret_cast< const QBuddy(*)>(_a[1])),(*reinterpret_cast< const bool(*)>(_a[2]))); break;
        case 2: onAuthRequest((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void QRoster::onCLHandled()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void QRoster::onBuddyArrivedOrDeparted(const QBuddy & _t1, const bool _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QRoster::onAuthRequest(const QString & _t1, const QString & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
