#include "qoscaricbm.h"

//QString unicodeToUtf8(const QByteArray &array)
//{
//	QByteArray msg2;

//	 for ( int i = 0; i < array.length(); i += 2 ){
//	     if ( array.length() <= i + 1 )
//		 break;

//	    quint16 symbol = static_cast<quint16>((quint16)(array.at(i) * 0x100) + (quint8)array.at(i+1));

//	    if ( symbol < 0x0080)
//		msg2.append((unsigned char) symbol);
//	    else if (symbol < 0x0800) {
//		msg2.append(0xc0 | ( symbol >> 6));
//		msg2.append(0x80 | (symbol & 0x3f));
//	    } else {
//		msg2.append(0xe0 | ( symbol >> 12));
//		msg2.append(0x80 | ((symbol >>6 )& 0x3f));
//		msg2.append(0x80 | (symbol & 0x3f));
//	    }
//	 }
//	 return QString::fromUtf8(msg2);
//}

//! Create outcoming message
//! \param sn
//! \param message
//! \return
//! \sa QOscarBA
QOscarBA QOscarIcbm::createICBM__MESSAGE_TO_HOST(const QString &sn, const QString &message)
{
    QOscarBA ba((quint32) 0x00), tmpBa;
    QTextCodec *codec = QTextCodec::codecForName(oscarEncoding.toAscii());
    ba.addString(codec->fromUnicode(message));
//    ba.addString(message);

    tmpBa.append(QTlv::toByteArray(0x0501, QOscarBA((quint16) 0x0101)));
    tmpBa.append(QTlv::toByteArray(0x0101, ba));
    ba.clear();

    ba.addU32(qrand() % 100200);
    ba.addU32(qrand() % 800900);
    ba.addU16(0x01);
    ba.addU8(sn.length());
    ba.addString(sn);
    ba.append(QTlv::toByteArray(0x0002, tmpBa));
    ba.append(QTlv::toByteArray(0x0006));

    return QSnac::toByteArray(0x04, 0x06, 0x00, 0x00000006, ba);
}
//! ICBM Client Event (e.g. type notify)
//! \param sn
//! \param event
//! \return
//! \sa QOscarBA
QOscarBA QOscarIcbm::createICBM__CLIENT_EVENT(const QString &sn, quint16 event)
{
    QOscarBA ba((quint32) 0x00);
    ba.addU32(0x00);
    ba.addU16(0x01);	//  channel - IM
    ba.addU8(sn.length());
    ba.addString(sn);
    ba.addU16(event);

    return QSnac::toByteArray(0x04, 0x14, 0x00, 0x00000014, ba);
}
//! REQUESTING offline messages
//! \param sn
//! \return
//! \sa QOscarBA
QOscarBA QOscarIcbm::createICBM__REQOFFLINEMSGS(const QString &sn)
{
    QOscarBA ba(true, 0x08);
    ba.addSnLE(sn);
    ba.addU16LE(0x3C);
    ba.addU16(0x29);

    return QSnac::toByteArray(0x15, 0x02, 0x00, 0x00010002, QTlv::toByteArray(0x0001, ba));
}
//! Handle ICBM Packet
//! \param snac
//! \sa QSnac
void QOscarIcbm::handlePacket(const QSnac &snac)
{
    QSnac tempSnac(snac);

    switch ( tempSnac.getType() ) {

	case 0x0007:		// Incoming message
	    handleMessage(tempSnac.data());
	    break;

    }
}
//! Handle incoming message (04,07)
//! \param data
//! \sa QOscarBA
void QOscarIcbm::handleMessage(const QOscarBA &data)
{
    if ( data.length() < 11 )
	return;

    QOscarBA ba(data);
    ba.remove(0, 16);

    QMessage message;
    message.channel = ba.readU16();
    quint8 snLen = ba.readU8(2);
    ba.remove(0, 3);
    if ( (ba.length() < snLen + 4) || snLen == 0 )
	return;

    message.sender = ba.mid(0, snLen);
    ba.remove(0, snLen);
    message.warningLevel = ba.readU16();
    quint16 tlvCount = ba.readU16(2);
    ba.remove(0, 4);
    if ( (tlvCount == 0) || (ba.length() < tlvCount * 4) )
	return;

    bool isLast = false;

    while ( ! isLast ) {

	QTlv tlv(ba);
	if ( ! tlv.isValid() ) {
//	    qDebug() << "[ICBM] {Error} Parsing message: TLV is not valid!";
	    break;
	}

        switch ( tlv.getType() ) {

	    case 0x0006:		    // User status !! warning! it's a FULL status with flags!
                message.senderStatus = tlv.getData().readU32();
		break;

	    case 0x0005:		    // Sender member since (timestamp)
//		message.senderMemberSince.addSecs( = tlv.data();
		break;

	    case 0x000F:		    // Sender online time
                message.senderOnline = tlv.getData().readU32();
		break;

	    case 0x0016:		    // Send time (timestamp)
//		message.sendTime = tlv.data();
		break;

	    case 0x0002: {		    // IM Data
                QOscarBA baTemp(tlv.getData());
//		qDebug() << baTemp.toHex();
		if ( baTemp.length() < 6 )
		    return;
//		baTemp.remove(0, 2);
		QTlv tlv0501(baTemp);
                baTemp.remove(0, tlv0501.getLength() + 4);
		QTlv tlv0101(baTemp);
                baTemp = tlv0101.getData();
//		if ( baTemp.length() < 4 )
//		    return;
		message.encoding = baTemp.readU16(0);
		message.language = baTemp.readU16(2);
		baTemp.remove(0, 4);
		QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
		message.text = codec->toUnicode(baTemp);
		break;
	    }

	    default:
		break;
	}

        if ( ba.length() < tlv.getLength() )
	    break;
        ba.remove(0, tlv.getLength() + 2 + 2);
	isLast = tlv.isLast();
    }
    emit onMessage(message);
}
//! Alternative way to handle SNAC 04,07 (HACK!)
//! \param data
//! \sa QOscarBA
void QOscarIcbm::handleMessageAlt(const QOscarBA &data)
{
    QOscarBA tmpData(data);
    if ( tmpData.length() < 20 )
	return;

    QMessage message;

    tmpData.remove(0, 18); // Cookie & channel
    quint8 uinLen = tmpData.readU8();
    message.sender = tmpData.mid(1, uinLen);
    tmpData.remove(0, uinLen + 1);

    qint32 index = tmpData.indexOf(QByteArray::fromHex("0501"));
    index += 4;
    tmpData.remove(0, index);
    if ( tmpData.isEmpty() )
	return;

    index = tmpData.indexOf(QByteArray::fromHex("0101"));
    tmpData.remove(0, index);
    QTlv tlv0101(tmpData);
    if ( ! tlv0101.isValid() )
	return;

    tmpData.remove(0, 8);
//    message.text = unicodeToUtf8(tmpData.mid(0, tlv0101.length() - 4));
    emit onMessage(message);
}
//! Set Encoding
//! \param encoding
void QOscarIcbm::setEncoding(const QString &encoding)
{
    oscarEncoding = encoding;
}
//! Get encoding
QString QOscarIcbm::getEncoding()
{
    return oscarEncoding;
}
