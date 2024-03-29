#include <QDebug>
#include "qoscarbasic.h"

/** ************************************************************* **/
/**		BASIC OSCAR TYPES				  **/
/** ************************************************************* **/

/** ****************** **/
/* TLV Constructor */
/** ****************** **/

//! Constructor
//! \param data
//! \sa QOscarBA
QTlv::QTlv(const QOscarBA &data)
{
    if ( data.length() == 0 )
	return;

    if ( data.length() < 4 ) {
	tlvIsValid = false;
	return;
    }

    QOscarBA tmpData(data);
    tlvType = tmpData.readU16(0);
    tlvLength = tmpData.readU16(2);

    tlvIsValid = tmpData.length() >= tlvLength + 2 + 2;
    if ( ! tlvIsValid )
	return;

    tlvIsLast = tmpData.length() <= tlvLength + 2 + 2;
    tlvData = QOscarBA(tmpData.mid(4, tlvLength));
}

//! Constructor
//! \param type
//! \param data
//! \param le
//! \sa QOscarBA
QTlv::QTlv(quint16 type, const QOscarBA &data, bool le)
{
    tlvType = type;
    tlvData = data;
    tlvIsLE = le;
}
//! get type
//!
quint16 QTlv::getType()
{
    return tlvType;
}
//! get length
//!
quint16 QTlv::getLength()
{
    return tlvData.length();
}
//! get data
//!
QOscarBA QTlv::getData()
{
    return tlvData;
}
//! is last
//!
bool QTlv::isLast()
{
    return tlvIsLast;
}
//! is valid
//!
bool QTlv::isValid()
{
    return tlvIsValid;
}
//! is LE
//!
bool QTlv::isLE()
{
    return tlvIsLE;
}
//! set type
//! \param type
void QTlv::setType(quint16 type)
{
    tlvType = type;
}
//! set data
//! \param data
void QTlv:: setData(const QOscarBA &data)
{
    tlvData = data;
}
//! Convert TLV to ByteArray
//! \return
//! \sa QOscarBA
QOscarBA QTlv::toByteArray()
{
    QOscarBA ba;
    if ( tlvIsLE ) {
	ba.addU16LE(tlvType);
	ba.addU16LE(tlvData.length());
    } else {
	ba.addU16(tlvType);
	ba.addU16(tlvData.length());
    }
    ba.append(tlvData);
    return ba;
}

//! Static method to convert Tlv to Byte Array
//! \param type
//! \param data
//! \param le
//! \return
//! \sa QOscarBA
QOscarBA QTlv::toByteArray(quint16 type, const QOscarBA &data, bool le)
{
    QOscarBA ba;
    if ( le ) {
	ba.addU16LE(type);
	ba.addU16LE(data.length());
    } else {
	ba.addU16(type);
	ba.addU16(data.length());
    }
    ba.append(data);
    return ba;
}

/** ****************** **/
/* SNAC implementation */
/** ****************** **/

//! QSnac Constructor
//! \param data
//! \sa QOscarBA
QSnac::QSnac(const QOscarBA &data)
{
    if ( data.length() == 0 )
	return;

    snacIsValid = ( data.length() >= 10 );
    if ( ! snacIsValid )
	return;

    QOscarBA tmpData(data);

    snacGroup = tmpData.readU16(0);
    snacType = tmpData.readU16(2);
    snacFlags = tmpData.readU16(4);
    snacReqId = tmpData.readU32(6);

    snacData = QOscarBA(tmpData.mid(10));
}

//! QSnac Constructor
//! \param group
//! \param type
//! \param flags
//! \param reqId
//! \param data
//! \sa QOscarBA
QSnac::QSnac(quint16 group, quint16 type, quint16 flags, quint32 reqId, const QOscarBA &data)
{
    snacGroup = group;
    snacType = type;
    snacFlags = flags;
    snacReqId = reqId;
    snacData = data;
}
//! get group
//!
quint16 QSnac::getGroup()
{
    return snacGroup;
}
//! get type
//!
quint16 QSnac::getType()
{
    return snacType;
}
//! get flags
//!
quint16 QSnac::getFlags()
{
    return snacFlags;
}
//! get Request ID
//!
quint32 QSnac::getRequestId()
{
    return snacReqId;
}
//! get data
//!
QOscarBA QSnac::getData()
{
    return snacData;
}
//! get length
//!
quint32 QSnac::getLength()
{
    return snacData.length();
}
//! is valid
//!
bool QSnac::isValid()
{
    return snacIsValid;
}
//! Convert to ByteArray
//! \return
//! \sa QOscarBA
QOscarBA QSnac::toByteArray()
{
    QOscarBA ba(snacGroup);
    ba.addU16(snacType);
    ba.addU16(snacFlags);
    ba.addU32(snacReqId);
    ba.append(snacData);
    return ba;
}

//! Static conversion
//! \param group
//! \param type
//! \param flags
//! \param reqId
//! \param data
//! \return
//! \sa QOscarBA
QOscarBA QSnac::toByteArray(quint16 group, quint16 type, quint16 flags, quint32 reqId, const QOscarBA &data)
{
    QOscarBA ba(group);
    ba.addU16(type);
    ba.addU16(flags);
    ba.addU32(reqId);
    ba.append(data);
    return ba;
}

/** ****************** **/
/* FLAP implementation */
/** ****************** **/

//! Constructor
//! \param data
//! \sa QOscarBA
QFlap::QFlap(const QOscarBA &data)
{
    if ( data.length() == 0 )
	return;

    flapIsValid = ( data.length() >= 6 );
    if ( ! flapIsValid )
	return;

    QOscarBA tmpData(data);

    flapChannel = tmpData.readU8(1);
    flapSequence = tmpData.readU16(2);
    quint16 flapSize = tmpData.readU16(4);

    flapIsValid = ( tmpData.length() >= flapSize + 6 );
    if ( ! flapIsValid )
	return;

    flapData = QOscarBA(tmpData.mid(6, flapSize));

    flapIsLast = ! ( tmpData.length() > flapSize + 6 );
}

//! Constructor
//! \param channel
//! \param sequence
//! \param data
//! \sa QOscarBA
QFlap::QFlap(quint8 channel, quint16 sequence, const QOscarBA &data)
{
    flapChannel = channel;
    flapSequence = sequence;
    flapData = data;
}

//! To ByteArray
//! \param isFirst
//! \return
QOscarBA QFlap::toByteArray(bool isFirst)
{
    QOscarBA ba;

    ba.addU8(0x2a);
    ba.addU8(flapChannel);
    ba.addU16(flapSequence);

    if ( isFirst ) {
	ba.addU16(flapData.length() + 4);	// Ahtung!! + 4 or + 7 ??
	ba.addU16(0);
	ba.addU16(1);
    } else
	ba.addU16(flapData.length());

    ba.append(flapData);

    return ba;
}
//! get channel
//!
quint8 QFlap::getChannel()
{
    return flapChannel;
}
//! get seguence
//!
quint16 QFlap::getSequence()
{
    return flapSequence;
}
//! get length
//!
quint32 QFlap::getLength()
{
    return flapData.length();
}
//! is valid
//!
bool QFlap::isValid()
{
    return flapIsValid;
}
//! is last
//!
bool QFlap::isLast()
{
    return flapIsLast;
}
//! get data
//!
QOscarBA QFlap::getData()
{
    return flapData;
}
