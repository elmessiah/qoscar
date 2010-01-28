#ifndef QOSCARIDENT_H
#define QOSCARIDENT_H

#include <QObject>

#include "qoscarbasic.h"

/* Struct for ident packet */
struct QIdent { QString clientName,
                        language,
                        country;
                quint16 majorVersion,
                        minorVersion,
                        lesserVersion,
                        build,
                        unknown;
                quint32 subBuild; };


QByteArray createCLI_IDENT(QIdent ident, const QString &ScreenName,
                            const QString &Password);
QByteArray createCLI_Cookie(const QByteArray &baCookie);
QByteArray createCLI_GOODBYE();
QByteArray createChangePassword(const QString &sNewPassword,
                                 const QString &ScreenName);



#endif // QOSCARIDENT_H
