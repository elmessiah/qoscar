/****************************************************************************
** Meta object code from reading C++ file 'qoscaroservice.h'
**
** Created: Mon Jun 7 19:41:26 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qoscar/qoscaroservice.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qoscaroservice.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QOscarOService[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_QOscarOService[] = {
    "QOscarOService\0\0onLoggedIn()\0"
};

const QMetaObject QOscarOService::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QOscarOService,
      qt_meta_data_QOscarOService, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QOscarOService::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QOscarOService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QOscarOService::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QOscarOService))
        return static_cast<void*>(const_cast< QOscarOService*>(this));
    return QObject::qt_metacast(_clname);
}

int QOscarOService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onLoggedIn(); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QOscarOService::onLoggedIn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
