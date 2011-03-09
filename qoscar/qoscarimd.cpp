#include "qoscarimd.h"


//! IMD Request to set auth and web aware
//! \param sn
//! \param auth
//! \param webStatus
//! \return
//! \sa QOscarBA
QOscarBA QOscarIMD::createIMD__REQUEST_SET_WEBSTATUS(const QString &sn, bool auth, bool webStatus)
{
    QOscarBA data;
    data.addSnLE(sn);
    data.addU16(0xD007);
    data.addU16(0x0700);
    data.addU16(0x3A0C);
    data.append(QTlv::toByteArray(0x030C, QOscarBA((quint8) auth), true));
    data.append(QTlv::toByteArray(0x02F8, QOscarBA((quint8) webStatus), true));
    data.addU16LE(data.length(), 0);

    return QSnac::toByteArray(0x15, 0x02, 0x00, 0x02, QTlv::toByteArray(0x0001, data));
}

//! IMD Request to set FULL info
//! \param sn
//! \param info
//! \return
//! \sa QOscarBA, QOscarUserInfo
QOscarBA QOscarIMD::createIMD__REQUEST_SET_FULL_INFO(const QString &sn, const QOscarUserInfo &info)
{
    QOscarBA ba, result;

    result.addSnLE(sn);
    result.addU16(0xD007);
    result.addU16(0x0700);
    result.addU16(0x3A0C);

    result.append(QTlv::toByteArray(0x0154, QOscarBA::fromStringLE(info.nickName), true));
    result.append(QTlv::toByteArray(0x0140,  QOscarBA::fromStringLE(info.firstName), true));
    result.append(QTlv::toByteArray(0x014A,  QOscarBA::fromStringLE(info.lastName), true));

    ba =  QOscarBA::fromStringLE(info.email1);
    ba.addU8((quint8) info.publishEMail1);
    result.append(QTlv::toByteArray(0x015E, ba, true));

    ba = QOscarBA::fromStringLE(info.email2);
    ba.addU8((quint8) info.publishEMail2);
    result.append(QTlv::toByteArray(0x015E, ba, true));

    ba =  QOscarBA::fromStringLE(info.email3);
    ba.addU8((quint8) info.publishEMail3);
    result.append(QTlv::toByteArray(0x015E, ba, true));

    result.append(QTlv::toByteArray(0x01A4, QOscarBA(true, info.homeCountry), true));
    result.append(QTlv::toByteArray(0x0190, QOscarBA::fromStringLE(info.homeCity), true));
    result.append(QTlv::toByteArray(0x019A, QOscarBA::fromStringLE(info.homeState), true));
    result.append(QTlv::toByteArray(0x026D, QOscarBA::fromStringLE(info.homeZip), true));
    result.append(QTlv::toByteArray(0x0276, QOscarBA::fromStringLE(info.homePhone), true));
    result.append(QTlv::toByteArray(0x0280, QOscarBA::fromStringLE(info.homeFax), true));
    result.append(QTlv::toByteArray(0x028A, QOscarBA::fromStringLE(info.homeCell), true));
    result.append(QTlv::toByteArray(0x0262, QOscarBA::fromStringLE(info.homeStreet), true));
    result.append(QTlv::toByteArray(0x0334, QOscarBA(true, info.origCountry), true));
    result.append(QTlv::toByteArray(0x0320, QOscarBA::fromStringLE(info.origStreet), true));
    result.append(QTlv::toByteArray(0x032A, QOscarBA::fromStringLE(info.origState), true));
    result.append(QTlv::toByteArray(0x0316, QOscarBA((quint8) info.gmt), true));
    result.append(QTlv::toByteArray(0x02B2, QOscarBA(true, info.homeCountry), true));
    result.append(QTlv::toByteArray(0x029E, QOscarBA::fromStringLE(info.workCity), true));
    result.append(QTlv::toByteArray(0x02A8, QOscarBA::fromStringLE(info.workState), true));
    result.append(QTlv::toByteArray(0x02BD, QOscarBA::fromStringLE(info.workZip), true));
    result.append(QTlv::toByteArray(0x02C6, QOscarBA::fromStringLE(info.workPhone), true));
    result.append(QTlv::toByteArray(0x02D0, QOscarBA::fromStringLE(info.workFax), true));
    result.append(QTlv::toByteArray(0x0294, QOscarBA::fromStringLE(info.workStreet), true));
    result.append(QTlv::toByteArray(0x01AE, QOscarBA::fromStringLE(info.workName), true));
    result.append(QTlv::toByteArray(0x01B8, QOscarBA::fromStringLE(info.workDiv), true));
    result.append(QTlv::toByteArray(0x01CC, QOscarBA(true, info.workOccupation), true));
    result.append(QTlv::toByteArray(0x01C2, QOscarBA::fromStringLE(info.workPosition), true));
    result.append(QTlv::toByteArray(0x02DA, QOscarBA::fromStringLE(info.workWebPage), true));
    result.append(QTlv::toByteArray(0x017C, QOscarBA((quint8) info.gender), true));
    result.append(QTlv::toByteArray(0x0172, QOscarBA(true, info.userAge), true));
    result.append(QTlv::toByteArray(0x033E, QOscarBA((quint8) info.userMarital), true));
    result.append(QTlv::toByteArray(0x0213, QOscarBA::fromStringLE(info.userWebPage), true));

    ba = QOscarBA(true, info.birthYear);
    ba.addU16LE(info.birthMonth);
    ba.addU16LE(info.birthDay);
    result.append(QTlv::toByteArray(0x023A, ba, true));

    result.append(QTlv::toByteArray(0x0186, QOscarBA(true, info.userLang1), true));
    result.append(QTlv::toByteArray(0x0186, QOscarBA(true, info.userLang2), true));
    result.append(QTlv::toByteArray(0x0186, QOscarBA(true, info.userLang3), true));

    ba = QOscarBA(true, info.interest1.category);
    ba.append(QOscarBA::fromStringLE(info.interest1.interest));
    result.append(QTlv::toByteArray(0x01EA, ba, true));

    ba = QOscarBA(true, info.interest2.category);
    ba.append(QOscarBA::fromStringLE(info.interest2.interest));
    result.append(QTlv::toByteArray(0x01EA, ba, true));

    ba = QOscarBA(true, info.interest3.category);
    ba.append(QOscarBA::fromStringLE(info.interest3.interest));
    result.append(QTlv::toByteArray(0x01EA, ba, true));

    ba = QOscarBA(true, info.interest4.category);
    ba.append(QOscarBA::fromStringLE(info.interest4.interest));
    result.append(QTlv::toByteArray(0x01EA, ba, true));

    ba = QOscarBA(true, info.affiliations1.category);
    ba.append(QOscarBA::fromStringLE(info.affiliations1.interest));
    result.append(QTlv::toByteArray(0x01EA, ba, true));

    ba = QOscarBA(true, info.affiliations2.category);
    ba.append(QOscarBA::fromStringLE(info.affiliations2.interest));
    result.append(QTlv::toByteArray(0x01EA, ba, true));

    ba = QOscarBA(true, info.affiliations3.category);
    ba.append(QOscarBA::fromStringLE(info.affiliations3.interest));
    result.append(QTlv::toByteArray(0x01EA, ba, true));

    ba = QOscarBA(true, info.past1.category);
    ba.append(QOscarBA::fromStringLE(info.past1.interest));
    result.append(QTlv::toByteArray(0x01EA, ba, true));

    ba = QOscarBA(true, info.past2.category);
    ba.append(QOscarBA::fromStringLE(info.past2.interest));
    result.append(QTlv::toByteArray(0x01EA, ba, true));

    ba = QOscarBA(true, info.past3.category);
    ba.append(QOscarBA::fromStringLE(info.past3.interest));
    result.append(QTlv::toByteArray(0x01EA, ba, true));

    result.append(QTlv::toByteArray(0x0258, QOscarBA::fromStringLE(info.about), true));

    result.addU16LE(result.length(), 0);

    return QSnac::toByteArray(0x15, 0x02, 0x00, 0x02, QTlv::toByteArray(0x0001, result));
}


//! MDIR request - offline messages
//! \param sn
//! \return
//! \sa QOscarBA
QOscarBA QOscarIMD::createIMD__REQUEST_OFFLINE_MESSAGES(const QString &sn)
{
    QOscarBA ba(true, sn.length());
    ba.addSnLE(sn);
    ba.addU16LE(0x003C);
    ba.addU16LE(0x2900);

    return QSnac::toByteArray(0x15, 0x02, 0x00, 0x00020002, QTlv::toByteArray(0x0001, ba));
}


//! MDIR request - offline messages done
//! \param sn
//! \return
//! \sa QOscarBA
QOscarBA QOscarIMD::createIMD__ACK_OFFLINE_MESSAGES(const QString &sn)
{
    QOscarBA ba(true, sn.length());
    ba.addSnLE(sn);
    ba.addU16LE(0x003E);
    ba.addU16LE(0x2348);

    return QSnac::toByteArray(0x15, 0x02, 0x00, 0x00020002, QTlv::toByteArray(0x0001, ba));
}

//! MDIR - handle packet
//! \param snac
//! \sa QOscarBA, QSnac
void QOscarIMD::handlePacket(const QSnac &snac)
{
    QSnac tempSnac(snac);

    switch ( tempSnac.type() ) {

	case 0x03:	    // Offline message
	    handleOfflineMessage(tempSnac.data());
	    break;

	default:
	    break;

    }
}

//! MDIR - handle offline message
//! \param data
//! \sa QOscarBA
void QOscarIMD::handleOfflineMessage(const QOscarBA &data)
{
    QTlv tlv(data);
    if ( (! tlv.isValid()) || (tlv.data().length() < 24) )
	return;
    QOscarBA ba(tlv.data());

    ba.remove(0, 10);
    QOfflineMessage message;
    message.sender.setNum(ba.readU32LE());
    message.time.addYears(ba.readU16(4));
    message.time.addMonths(ba.readU8(6));
    message.time.addDays(ba.readU8(7));
    message.time.addSecs(ba.readU8(8) * 60 * 60 + ba.readU8(9) * 60 + ba.readU8(10));
    ba.remove(0, 12);
    message.text = ba.mid(2, ba.readU16());

    emit onOfflineMessage(message);
}
