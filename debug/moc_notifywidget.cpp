/****************************************************************************
** Meta object code from reading C++ file 'notifywidget.h'
**
** Created: Thu 28. Jan 19:09:38 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../notifywidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'notifywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_NotifyWidget[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_NotifyWidget[] = {
    "NotifyWidget\0\0onClicked()\0onTimer()\0"
};

const QMetaObject NotifyWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_NotifyWidget,
      qt_meta_data_NotifyWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &NotifyWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *NotifyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *NotifyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_NotifyWidget))
        return static_cast<void*>(const_cast< NotifyWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int NotifyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onClicked(); break;
        case 1: onTimer(); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void NotifyWidget::onClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
