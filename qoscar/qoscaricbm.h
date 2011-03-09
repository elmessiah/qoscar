#ifndef QOSCARICBM_H
#define QOSCARICBM_H

#include <QTextCodec>
#include <QObject>
#include <QDebug>
#include <QTime>

#include "qoscarstuff.h"

/* Message */
typedef struct
{
    QString	sender;
    QString	target;
    QString	text;
    QTime	senderMemberSince;
    QTime	sendTime;
    quint32	senderOnline;
    quint32	senderStatus;
    quint16	channel;
    quint16	warningLevel;
    quint16	encoding;
    quint16	language;
    quint8	messageType;
} QMessage;

/* SMS info reply */
typedef struct
{
    QString carrier;
    QString carrierURL;
    QString phoneCode;
    quint16 free;
    quint16 asciiLength;
    quint16 utf8Length;
} QSMSInfoReply;

class QOscarIcbm : public QObject
{
    Q_OBJECT

    public:
	explicit QOscarIcbm() { oscarEncoding = "Windows-1251"; }

	QOscarBA createICBM__MESSAGE_TO_HOST(const QString &sn, const QString &message);
	QOscarBA createICBM__CLIENT_EVENT(const QString &sn, quint16 event);
	QOscarBA createICBM__REQOFFLINEMSGS(const QString &sn);

	void handlePacket(const QSnac &snac);
	void setEncoding(const QString &encoding) { oscarEncoding = encoding; }

        QString getEncoding() const { return oscarEncoding; }

    private:
	QString oscarEncoding;

	void handleMessage(const QOscarBA &data);
	void handleMessageAlt(const QOscarBA &data);

    signals:
	void onMessage(const QMessage &message);
};

#endif // QOSCARICBM_H
