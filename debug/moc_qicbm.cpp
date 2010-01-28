/****************************************************************************
** Meta object code from reading C++ file 'qicbm.h'
**
** Created: Thu 28. Jan 14:06:08 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../QOSCAR/qicbm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qicbm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QICBM[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,    7,    6,    6, 0x05,
      59,   35,    6,    6, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QICBM[] = {
    "QICBM\0\0message\0onMessage(QMessage)\0"
    "u16Channel,sSN,u16Event\0"
    "onClientEvent(quint16,QString,quint16)\0"
};

const QMetaObject QICBM::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QICBM,
      qt_meta_data_QICBM, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QICBM::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QICBM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QICBM::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QICBM))
        return static_cast<void*>(const_cast< QICBM*>(this));
    return QObject::qt_metacast(_clname);
}

int QICBM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onMessage((*reinterpret_cast< const QMessage(*)>(_a[1]))); break;
        case 1: onClientEvent((*reinterpret_cast< const quint16(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const quint16(*)>(_a[3]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void QICBM::onMessage(const QMessage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QICBM::onClientEvent(const quint16 _t1, const QString & _t2, const quint16 _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
