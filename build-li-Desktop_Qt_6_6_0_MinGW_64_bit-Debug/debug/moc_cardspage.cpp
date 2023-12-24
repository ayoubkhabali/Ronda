/****************************************************************************
** Meta object code from reading C++ file 'cardspage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../li/cardspage.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cardspage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCardsPageENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCardsPageENDCLASS = QtMocHelpers::stringData(
    "CardsPage",
    "onPlayerCardClicked",
    "",
    "Player&",
    "player",
    "Card",
    "card",
    "exitGame"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCardsPageENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[10];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[8];
    char stringdata4[7];
    char stringdata5[5];
    char stringdata6[5];
    char stringdata7[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCardsPageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCardsPageENDCLASS_t qt_meta_stringdata_CLASSCardsPageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 9),  // "CardsPage"
        QT_MOC_LITERAL(10, 19),  // "onPlayerCardClicked"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 7),  // "Player&"
        QT_MOC_LITERAL(39, 6),  // "player"
        QT_MOC_LITERAL(46, 4),  // "Card"
        QT_MOC_LITERAL(51, 4),  // "card"
        QT_MOC_LITERAL(56, 8)   // "exitGame"
    },
    "CardsPage",
    "onPlayerCardClicked",
    "",
    "Player&",
    "player",
    "Card",
    "card",
    "exitGame"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCardsPageENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   26,    2, 0x08,    1 /* Private */,
       7,    0,   31,    2, 0x08,    4 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject CardsPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSCardsPageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCardsPageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCardsPageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CardsPage, std::true_type>,
        // method 'onPlayerCardClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<Player &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const Card &, std::false_type>,
        // method 'exitGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void CardsPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CardsPage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onPlayerCardClicked((*reinterpret_cast< std::add_pointer_t<Player&>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<Card>>(_a[2]))); break;
        case 1: _t->exitGame(); break;
        default: ;
        }
    }
}

const QMetaObject *CardsPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CardsPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCardsPageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CardsPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
