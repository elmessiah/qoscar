/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu 28. Jan 19:09:29 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      26,   11,   11,   11, 0x08,
      52,   11,   11,   11, 0x08,
      80,   11,   11,   11, 0x08,
     106,   11,   11,   11, 0x08,
     130,   11,   11,   11, 0x08,
     167,   11,   11,   11, 0x08,
     193,   11,   11,   11, 0x08,
     217,   11,   11,   11, 0x08,
     238,   11,   11,   11, 0x08,
     263,   11,   11,   11, 0x08,
     295,  273,   11,   11, 0x08,
     323,   11,   11,   11, 0x08,
     333,   11,   11,   11, 0x08,
     353,   11,   11,   11, 0x08,
     364,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0sShowNotify()\0"
    "on_typeEndedBtn_clicked()\0"
    "on_typeStartedBtn_clicked()\0"
    "on_pushButton_2_clicked()\0"
    "on_pushButton_clicked()\0"
    "on_treeWidget_itemSelectionChanged()\0"
    "on_requestCLBtn_clicked()\0"
    "on_setInfoBtn_clicked()\0on_SendBtn_clicked()\0"
    "on_loginButton_clicked()\0onTimer()\0"
    "errorType,errorString\0onError(QErrorType,QString)\0"
    "onLogin()\0onMessage(QMessage)\0onLogOff()\0"
    "onCLHandled()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sShowNotify(); break;
        case 1: on_typeEndedBtn_clicked(); break;
        case 2: on_typeStartedBtn_clicked(); break;
        case 3: on_pushButton_2_clicked(); break;
        case 4: on_pushButton_clicked(); break;
        case 5: on_treeWidget_itemSelectionChanged(); break;
        case 6: on_requestCLBtn_clicked(); break;
        case 7: on_setInfoBtn_clicked(); break;
        case 8: on_SendBtn_clicked(); break;
        case 9: on_loginButton_clicked(); break;
        case 10: onTimer(); break;
        case 11: onError((*reinterpret_cast< QErrorType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 12: onLogin(); break;
        case 13: onMessage((*reinterpret_cast< QMessage(*)>(_a[1]))); break;
        case 14: onLogOff(); break;
        case 15: onCLHandled(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::sShowNotify()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
