#include "qoscarba.h"

//! Constructor
QOscarBA::QOscarBA()
{
    //
}
//! Constructor
//! \param data
QOscarBA::QOscarBA(const QString &data)
{
    append(data);
}
//! Constructor
//! \param data
QOscarBA::QOscarBA(quint8 data)
{
    addU8(data);
}
//! Constructor
//! \param data
QOscarBA::QOscarBA(quint16 data)
{
    addU16(data);
}
//! Constructor
//! \param data
QOscarBA::QOscarBA(quint32 data)
{
    addU32(data);
}
//! Constructor
//! \param ba
QOscarBA::QOscarBA(const QByteArray &ba)
{
    append(ba);
}
//! Constructor
//! \param le
//! \param data
QOscarBA::QOscarBA(bool le, quint16 data)
{
    if ( ! le )
	return;
    addU16LE(data);
}

/** *********************************************************************** **/
/**		WRITING NUMBERS TO BUFFER				    **/
/** *********************************************************************** **/


//! Add uint 8 to ByteArray
//! \param data
//! \param to
void QOscarBA::addU8(const quint8 data, const qint32 to)
{
    if ( to == -1 )
	append(data);
    else
	insert(to, data);
}

//! Add uint 16 to ByteArray
//! \param data
//! \param to
void QOscarBA::addU16(const quint16 data, const qint32 to)
{
    QByteArray ba;
    ba[0] = data / 0x100;
    ba[1] = data % 0x100;

    if ( to == -1 )
	append(ba);
    else
	insert(to, ba);
}

//! Add uint 32 to ByteArray
//! \param data
//! \param to
void QOscarBA::addU32(const quint32 data, const qint32 to)
{
    QByteArray ba;
    ba[0] = (data / 0x1000000);
    ba[1] = (data / 0x10000);
    ba[2] = (data / 0x100);
    ba[3] = (data % 0x100);

    if ( to == -1 )
	append(ba);
    else
	insert(to, ba);
}

//! Add uint 16 LE to ByteArray
//! \param data
//! \param to
void QOscarBA::addU16LE(quint16 data, const qint32 to)
{
    QByteArray ba;
    ba[0] = data % 0x100;
    ba[1] = data / 0x100;

    if ( to == -1 )
	append(ba);
    else
	insert(to, ba);
}

//! Add uint 32 LE to ByteArray
//! \param data
//! \param to
void QOscarBA::addU32LE(quint32 data, const qint32 to)
{
//    QByteArray ba;

//    if ( to == -1 )
//	append(ba);
//    else
//	insert(to, ba);
}

//! Add ScreenName to LE ByteArray
//! \param data
//! \param to
void QOscarBA::addSnLE(const QString &sn, const qint32 to)
{
    QByteArray ba;
    quint32 tmpSN = sn.toUInt();

    ba[0] = tmpSN % 0x100;
    ba[1] = tmpSN % 0x10000 / 0x100;
    ba[2] = tmpSN % 0x1000000 / 0x10000;
    ba[3] = tmpSN / 0x1000000;

    if ( to == -1 )
	append(ba);
    else
	insert(to, ba);
}

//! Add string to BA
//! \param data
//! \param to
void QOscarBA::addString(const QString &data, qint32 to)
{
    if ( to == -1 )
	append(data);
    else
	insert(to, data);
}

/** *********************************************************************** **/
/**		READING NUMBERS FROM BUFFER				    **/
/** *********************************************************************** **/


//! Read uint 8 from buffer
//! \param from
//! \return uint8
quint8 QOscarBA::readU8(const quint32 from)
{
    if ( (quint32) length() < from + 1 )
	return 0;

    return (quint8) at(from);
}

//! Read uint 16 from buffer
//! \param from
//! \return uint16
quint16 QOscarBA::readU16(const quint32 from)
{
    if ( (quint32) length() < from + 2 )
	return 0;

    return (quint16) (mid(from, 2).toHex().toUInt(0, 16));
}

//! Read uint 32 from buffer
//! \param from
//! \return uint32
quint32 QOscarBA::readU32(const quint32 from)
{
    if ( (quint32) length() < from + 4 )
	return 0;

    return (quint32) (mid(from, 4).toHex().toUInt(0, 16));
}

//! Read uint 16 LE from buffer
//! \param from
//! \return uint 16 LE
quint16 QOscarBA::readU16LE(const quint32 from)
{
    if ( (quint32) length() < from + 2 )
	return 0;

    quint16 tmp = (quint16) mid(from, 2).toHex().toUInt(0, 16);
    return ((tmp % 0x100) * 0x100 + (tmp) / 0x100);
}

//! Read uint 16 LE from buffer
//! \param from
//! \return uint 32 LE
quint32 QOscarBA::readU32LE(const quint32 from)
{
    if ( (quint32) length() < from + 4 )
	return 0;

    quint32 tmp = (quint32) mid(from, 4).toHex().toUInt(0, 16);
    return ( (tmp % 0x100) * 0x1000000 +
	     (tmp % 0x10000 / 0x100) * 0x10000 +
	     (tmp % 0x1000000 / 0x10000) * 0x100 +
	     (tmp)/0x1000000 );
}


/** *********************************************************************** **/
/**			OTHER STUFF					    **/
/** *********************************************************************** **/

//! Read "len" bytes from this starting from "from"
//! \param from
//! \param len
//! \return
//! \sa QOscarBA
QOscarBA QOscarBA::readData(quint32 from, quint32 len)
{
    if ( (quint32) length() < len + from )
	return QOscarBA();

    return QOscarBA(mid(from, len));
}

//! Create BA from QString LE
//! \param str
//! \param zero
//! \return
//! \sa QOscarBA
QOscarBA QOscarBA::fromStringLE(const QString &str, bool zero)
{
    QOscarBA ba;

    if ( zero ) {
	ba.addU16LE(str.length() + 1);
	ba.addString(str + '\0');
    } else {
	ba.addU16LE(str.length());
	ba.addString(str);
    }

    return ba;
}
