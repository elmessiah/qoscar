#ifndef QOSCARBASIC_H
#define QOSCARBASIC_H

#include "qoscarba.h"

/** ************************************************************* **/
/**		BASIC OSCAR TYPES				  **/
/** ************************************************************* **/

/** ****************** **/
/* TLV implementation */
/** ****************** **/
class QTlv
{
    public:
	QTlv(const QOscarBA &data = QOscarBA());
	QTlv(quint16 type = 0, const QOscarBA &data = QOscarBA(), bool le = false);

	quint16 type() const { return tlvType; }
	quint16 length() const { return tlvData.length(); }
	QOscarBA data() const { return tlvData; }
	bool isLast() const { return tlvIsLast; }
	bool isValid() const { return tlvIsValid; }
	bool isLE() const { return tlvIsLE; }

	void setType(quint16 type) { tlvType = type; }
	void setData(const QOscarBA &data) { tlvData = data; }

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

/** ****************** **/
/* SNAC implementation  */
/** ****************** **/

class QSnac
{
    public:
	QSnac(const QOscarBA &data = QOscarBA());
	QSnac(quint16 group, quint16 type, quint16 flags, quint32 reqId, const QOscarBA &data);

	quint16 group() const { return snacGroup; }
	quint16 type() const { return snacType; }
	quint16 flags() const { return snacFlags; }
	quint32 requestId() const { return snacReqId; }

	QOscarBA data() { return snacData; }
	quint32 length() const { return snacData.length(); }
	bool isValid() const { return snacIsValid; }

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

/** ****************** **/
/* FLAP implementation */
/** ****************** **/

class QFlap
{
    public:
	QFlap(const QOscarBA &data = QOscarBA());    // if incoming
	QFlap(quint8 channel, quint16 sequence, const QOscarBA &data);

	quint8 channel() const { return flapChannel; }
	quint16 sequence() const { return flapSequence; }
	quint32 length() const { return flapData.length(); }
	bool isValid() const { return flapIsValid; }
	bool isLast() const { return flapIsLast; }

	QOscarBA data() { return flapData; }
	QOscarBA toByteArray(bool isFirst = false);

    private:
	quint8 flapChannel;
	quint16 flapSequence;
	QOscarBA flapData;
	bool flapIsValid;
	bool flapIsLast;
};





#endif // QOSCARBASIC_H
