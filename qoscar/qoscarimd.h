#ifndef QOSCARIMD_H
#define QOSCARIMD_H

#include <QObject>
#include <QDateTime>

#include "qoscarbasic.h"

typedef struct
{
    quint16 category;
    QString interest;
} QOscarUserInterest;

//! \struct QOscarUserInfo
typedef struct
{
    QString nickName;
    QString firstName;
    QString lastName;
    QString email1;
    QString email2;
    QString email3;
    QString homeCity;
    QString homeState;
    QString homeZip;
    QString homePhone;
    QString homeFax;
    QString homeCell;
    QString homeStreet;
    QString origStreet;
    QString origState;
    QString workCity;
    QString workState;
    QString workZip;
    QString workPhone;
    QString workFax;
    QString workStreet;
    QString workName;	    //!< Company name
    QString workDiv;	    //!< Division
    QString workPosition;   //!< Prof. name
    QString workWebPage;
    QString userWebPage;
    QString about;

    quint16 homeCountry;
    quint16 origCountry;
    quint16 workCountry;
    quint16 workOccupation;
    quint16 userAge;
    quint16 birthYear;
    quint16 birthMonth;
    quint16 birthDay;
    quint16 userLang1;
    quint16 userLang2;
    quint16 userLang3;

    quint8 gmt;
    quint8 gender;          //!< 02 - male, 01 - female
    quint8 userMarital;

    bool publishEMail1;
    bool publishEMail2;
    bool publishEMail3;

    QOscarUserInterest interest1;
    QOscarUserInterest interest2;
    QOscarUserInterest interest3;
    QOscarUserInterest interest4;

    QOscarUserInterest affiliations1;
    QOscarUserInterest affiliations2;
    QOscarUserInterest affiliations3;

    QOscarUserInterest past1;
    QOscarUserInterest past2;
    QOscarUserInterest past3;
} QOscarUserInfo;

typedef struct
{
    QString   sender;
    QString   text;
    QDateTime time;
} QOfflineMessage;

class QOscarIMD : public QObject
{
    Q_OBJECT                    //!< \todo BUGZZZZZZZZZZ

    public:
	void handlePacket(const QSnac &snac);

	QOscarBA createIMD__REQUEST_SET_WEBSTATUS(const QString &sn, bool auth, bool webStatus);
	QOscarBA createIMD__REQUEST_SET_FULL_INFO(const QString &sn, const QOscarUserInfo &info);
	QOscarBA createIMD__REQUEST_OFFLINE_MESSAGES(const QString &sn);
	QOscarBA createIMD__ACK_OFFLINE_MESSAGES(const QString &sn);

    private:
	void handleOfflineMessage(const QOscarBA &data);

    signals:
	void onIMDError();
	void onOfflineMessage(const QOfflineMessage &message);
	void onOfflineMessagesDone();
};

#endif // QOSCARIMD_H
