#include "qoscarident.h"

//! Create IDENT package
//! \param ident
//! \param sn
//! \param password
//! \return
//! \sa QOscarBA, QOscarIdent
QOscarBA createCLI__IDENT(const QOscarIdent &ident, const QString &sn, const QString &password)
{
    QOscarBA ba;
    ba.append(QTlv::toByteArray(0x01, QOscarBA(sn)));
    ba.append(QTlv::toByteArray(0x02, QOscarBA(password)));
    ba.append(QTlv::toByteArray(0x03, QOscarBA(ident.clientName)));
    ba.append(QTlv::toByteArray(0x17, QOscarBA(ident.majorVersion)));
    ba.append(QTlv::toByteArray(0x18, QOscarBA(ident.minorVersion)));
    ba.append(QTlv::toByteArray(0x19, QOscarBA(ident.lesserVersion)));
    ba.append(QTlv::toByteArray(0x1A, QOscarBA(ident.build)));
    ba.append(QTlv::toByteArray(0x16, QOscarBA(ident.unknown)));
    ba.append(QTlv::toByteArray(0x14, QOscarBA(ident.subBuild)));
    ba.append(QTlv::toByteArray(0x0F, QOscarBA(ident.language)));
    ba.append(QTlv::toByteArray(0x0E, QOscarBA(ident.country)));
    return ba;
}

//! Create CLI__COOKIE
//! \param cookie
//! \return
//! \sa QOscarBA
QOscarBA createCLI__COOKIE(const QOscarBA &cookie)
{
    return QTlv::toByteArray(0x0006, cookie);
}

//! Create CLI__GOODBYE
//! \sa QOscarBA
QOscarBA createCLI__GOODBYE()
{
    return QOscarBA();
}
