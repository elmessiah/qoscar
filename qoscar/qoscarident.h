#ifndef QOSCARIDENT_H
#define QOSCARIDENT_H

#include "qoscarbasic.h"

/* Struct for ident packet */
struct QOscarIdent {	QString clientName;
			QString language;
			QString country;
			quint16 majorVersion;
			quint16 minorVersion;
			quint16 lesserVersion;
			quint16 build;
			quint16 unknown;
			quint32 subBuild;   };

QOscarBA createCLI__IDENT(const QOscarIdent &ident, const QString &sn, const QString &password);
QOscarBA createCLI__COOKIE(const QOscarBA &cookie);
QOscarBA createCLI__GOODBYE();


#endif // QOSCARIDENT_H
