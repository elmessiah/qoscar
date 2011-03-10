#ifndef QOSCARBASIC_H
#define QOSCARBASIC_H

#include "qoscarba.h"

/** ************************************************************* **/
/**		BASIC OSCAR TYPES				  **/
/** ************************************************************* **/

//! TLV implementation
class QTlv
{
    public:
	QTlv(const QOscarBA &data = QOscarBA());
	QTlv(quint16 type = 0, const QOscarBA &data = QOscarBA(), bool le = false);

        quint16 getType();
        quint16 getLength();
        QOscarBA getData();
        bool isLast();
        bool isValid();
        bool isLE();

        void setType(quint16 type);
        void setData(const QOscarBA &data);

	QOscarBA toByteArray();
	static QOscarBA toByteArray(quint16 type = 0, const QOscarBA &data = QOscarBA(), bool le = false);

    private:
	quint16 tlvType;
	quint16 tlvLength;
	QOscarBA tlvData;
	bool tlvIsLast;
	bool tlvIsValid;
	bool tlvIsLE;
};
//! SNAC implementation
class QSnac
{
    public:
	QSnac(const QOscarBA &data = QOscarBA());
	QSnac(quint16 group, quint16 type, quint16 flags, quint32 reqId, const QOscarBA &data);

        quint16 getGroup();
        quint16 getType();
        quint16 getFlags();
        quint32 getRequestId();

        QOscarBA getData();
        quint32 getLength();
        bool isValid();

	QOscarBA toByteArray();
	static QOscarBA toByteArray(quint16 group, quint16 type, quint16 flags, quint32 reqId, const QOscarBA &data);

    private:
	quint16 snacGroup;
	quint16 snacType;
	quint16 snacFlags;
	quint32 snacReqId;
	QOscarBA snacData;
	bool snacIsValid;
};
//! FLAP implementation
class QFlap
{
    public:
	QFlap(const QOscarBA &data = QOscarBA());    // if incoming
	QFlap(quint8 channel, quint16 sequence, const QOscarBA &data);

        quint8 getChannel();
        quint16 getSequence();
        quint32 getLength();
        bool isValid();
        bool isLast();
        QOscarBA getData();
	QOscarBA toByteArray(bool isFirst = false);

    private:
	quint8 flapChannel;
	quint16 flapSequence;
	QOscarBA flapData;
	bool flapIsValid;
	bool flapIsLast;
};





#endif // QOSCARBASIC_H
