#ifndef QMETAINFO_H
#define QMETAINFO_H

#include <QObject>

#include "qoscarbasic.h"

class QOSCARMetaData
{
    public:
    QOSCARMetaData() { usDataType = 0xD007; }
        quint16 usDataSize,
                usDataType,
                usSeqNum,
                usDataSubType;
        quint32 ulReqOurSN;
        QByteArray baData;

        QByteArray toByteArray();
};

struct QInterest {quint16 usCategory;
                  QString sInterest;};

struct QSNInfo {QString    sNickName,
                           sFirstName,
                           sLastName,
                           sEMail,
                           sHomeCity,
                           sHomeState,
                           sHomeZip,
                           sHomePhone,
                           sHomeFax,
                           sHomeCellular,
                           sHomeStreet,
                           sOriginalCity,
                           sOriginalState,
                           sWorkCity,
                           sWorkState,
                           sWorkZip,
                           sWorkPhone,
                           sWorkFax,
                           sWorkStreet,
                           sWorkName,
                           sWorkDepaertment,
                           sWorkPosition,
                           sWorkWebPage,
                           sHomePage,
                           sAbout;
                quint16    usHomeCountry,
                           usOriginalCountry,
                           usWorkCountry,
                           usWorkOccupation,
                           usUserAge,
                           usBirthYear,
                           usBirthMonth,
                           usBirthDay,
                           usUserLang;
                quint8     us8GMT,
                           us8UserGender,
                           us8UserMarital;
                QInterest  iInterest1,
                           iInterest2,
                           iInterest3,
                           iInterest4,
                           iAffiliation1,
                           iAffiliation2,
                           iAffilition3,
                           iPast1,
                           iPast2,
                           iPast3;
                };

/* Struct for setting Up info */

struct QStructMetaData {quint16 usDataSize,
                                usUIN,
                                usSeqNum,
                                usCmd;
                        quint32 ulReqOurSN;
                        QByteArray baData; };

QByteArray createSend_Full_Info(   const QString &basicNick,
                                   const QString &basicFirst,
                                   const QString &basicLast,
                                   const QString &basicEmail,
                                   const QString &publishEmail,
                                   const char country,
                                   const QString &basicCity,
                                   const QString &basicState,
                                   const QString &basicAddress,
                                   const char zip,
                                   const QString &basicPhone,
                                   const QString &basicFax,
                                   const QString &basicCell,
                                   const char moreCountry,
                                   const QString &moreCity,
                                   const QString &moreState,
                                   const char workCountry,
                                   const QString &workCity,
                                   const QString &workState,
                                   const char wzip,
                                   const QString &workPhone,
                                   const QString &workFax,
                                   const QString &workCell,
                                   const QString &workCompany,
                                   const quint16 workOccupation,
                                   const QString &workDepartment,
                                   const QString &workAddress,
                                   const QString &workPosition,
                                   const QString &workWebPage,
                                   const quint16 foundedGender,
                                   const QString &homepage,
                                   const quint16 moreBirthYear,
                                   const quint16 moreBirthMonth,
                                   const quint16 moreBirthDay,
                                   const quint16 moreLang1,
                                   const quint16 moreLang2,
                                   const quint16 moreLang3,
                                   const quint16 interCode1,
                                   const QString &interKeyWords1,
                                   const quint16 interCode2,
                                   const QString &interKeyWords2,
                                   const quint16 interCode3,
                                   const QString &interKeyWords3,
                                   const quint16 interCode4,
                                   const QString &interKeyWords4,
                                   const QString &about,
                                   const bool webAware,
                                   const bool authFlag,
                                   const QString &myUin,
                                   const quint16 flapReq);

QByteArray convertToLEByteArray(const quint16 &d);
QByteArray convertUinToArray(const QString &uin);

QByteArray createSEND_BASIC_INFO(const QSNInfo &snInfo,
                                 const QString &sScreenName);

// HACK!!!1111
QByteArray createIMD__REQUEST_AUTH_INFO(const QString &sSN,
                                         const bool webAware,
                                         const bool authFlag);

#endif // QMETAINFO_H
