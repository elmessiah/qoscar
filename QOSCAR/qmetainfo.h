#ifndef QMETAINFO_H
#define QMETAINFO_H

#include <QObject>
#include <QDebug>

#include "qoscarconsts.h"
#include "qoscarbasic.h"

struct QInterest {quint16 usCategory;
                  QString sInterest;};

struct QSNInfo {QString    sScreenName,
                           sNickName,
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
                           sOriginCity,
                           sOriginState,
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
                quint16    u16HomeCountry,
                           u16OriginCountry,
                           u16WorkCountry,
                           u16WorkOccupation,
                           u16UserAge,
                           u16UserLang,
                           u16WAStatus,
                           u16FoundLeft,
                           u16Found;
                quint8     u8GMT,
                           u8UserGender,
                           u8UserMarital,
                           u8AuthFlag,
                           u8WebAwareFlag,
                           u8DCPermissions,
                           u8PublishEMail,
                           u8BirthYear,
                           u8BirthMonth,
                           u8BirthDay,
                           u8Lang1,
                           u8Lang2,
                           u8Lang3,
                           u8TimeZone;
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

class QOSCARMetaInfo : public QObject
{
    Q_OBJECT

    public:
        QOSCARMetaInfo() {}

        void handlePacket(const QSnac &snac);

        QByteArray createSearchBySN(const QString &sSN, const QString &selfSN);

        QByteArray createCLI_METAREQINFO(const QString &sSN, const QString &sSelfSN);
        QByteArray createSEND_BASIC_INFO(const QSNInfo &snInfo,
                                         const QString &sScreenName);
        // HACK!!!1111
        QByteArray createIMD__REQUEST_AUTH_INFO(const QString &sSN,
                                                const bool webAware,
                                                const bool authFlag);

    private:
        void handleInfo(const QByteArray &bafData);
        void handleGeneral(const QByteArray &bafData);
        void handleMore(const QByteArray &bafData);
        void handleWork(const QByteArray &bafData);
        void handleLast(const QByteArray &bafData);

    signals:
        void onMetaInfo(const QSNInfo&, const quint8);

};


#endif // QMETAINFO_H
