#include "qmetainfo.h"

QByteArray QOSCARMetaInfo::createIMD__REQUEST_AUTH_INFO(const QString &sSN,
                                                        const bool webAware,
                                                        const bool authFlag)
{
    QByteArray baResult, baMiddle;

    QTlv authTlv;
    authTlv.setType(0x030c);
    authTlv.setLe(true);
    authTlv.setData((quint8)webAware);
    baMiddle.append(authTlv.toByteArray());

    QTlv webTlv;
    webTlv.setType(0x02f8);
    webTlv.setLe(true);
    webTlv.setData((quint8)!authFlag);
    baMiddle.append(webTlv.toByteArray());

    //baResult.append(u16ToBA((quint16)(26 + baMiddle.length())));
    QSnac snac1502;
    snac1502.setFamilyId(0x0015);
    snac1502.setSubType(0x0002);
    snac1502.setReqId(0x00000000);

    baResult.append(snac1502.toByteArray());
    baResult.append(u16ToBA((quint16)0x0001));
    baResult.append(u16ToBA((quint16)(12 + baMiddle.length())));

    baResult.append(u16ToBALE((quint16)(baMiddle.length() + 10 )));
    baResult.append(snToBALE(sSN));
    baResult.append(u16ToBA((quint16)0xd007));
    baResult.append(u16ToBALE((quint16)0x0001));
    baResult.append(u16ToBA((quint16)0x3a0c));
    baResult.append(baMiddle);
    return baResult;
}

QByteArray QOSCARMetaInfo::createSEND_BASIC_INFO(const QSNInfo &snInfo, const QString &sScreenName)
{

    QByteArray baResult;
//    QStructMetaData metaData;
    QByteArray baMetaData;
    QByteArray baTmp;

    baResult.append((char) 0x3A);
    baResult.append((char) 0x0C);

    QTlv Tlv0154; //Nick
    Tlv0154.setLe(true);
    Tlv0154.setType(0x0154);
    baTmp.append(u16ToBALE(snInfo.sNickName.length() + 1));
    baTmp.append(snInfo.sNickName);
    baTmp.append((char) 0x00);
    Tlv0154.setData(baTmp);
    baTmp.clear();

    baResult.append(Tlv0154.toByteArray());

    QTlv Tlv0140; // First
    Tlv0140.setLe(true);
    Tlv0140.setType(0x0140);
    baTmp.append(u16ToBALE(snInfo.sFirstName.length() + 1));
    baTmp.append(snInfo.sFirstName);
    baTmp.append((char) 0x00);
    Tlv0140.setData(baTmp);
    baTmp.clear();

    baResult.append(Tlv0140.toByteArray());

    QTlv Tlv014A; // Last
    Tlv014A.setLe(true);
    Tlv014A.setType(0x014A);
    baTmp.append(u16ToBALE(snInfo.sLastName.length() + 1));
    baTmp.append(snInfo.sLastName);
    baTmp.append((char) 0x00);
    Tlv014A.setData(baTmp);
    baTmp.clear();

    baResult.append(Tlv014A.toByteArray());

    QTlv Tlv015E; // EMail
    Tlv015E.setType(0x015E);
    Tlv015E.setLe(true);
    baTmp.append(u16ToBALE(snInfo.sEMail.length() + 1));
    baTmp.append(snInfo.sEMail);
    baTmp.append((char) 0x00);
    baTmp.append((char) 0x01);
    Tlv015E.setData(baTmp);
    baTmp.clear();

    baResult.append(Tlv015E.toByteArray());

    QTlv Tlv01A4; // Home Country
    Tlv01A4.setType(0x01A4);
    Tlv01A4.setLe(true);
    baTmp.append(u16ToBALE(0x0002));
    baTmp.append(snInfo.u16HomeCountry);
    Tlv01A4.setData(baTmp);
    baTmp.clear();

    baResult.append(Tlv01A4.toByteArray());

    QTlv Tlv0190; // Home City
    Tlv0190.setType(0x0190);
    Tlv0190.setLe(true);
    baTmp.append(u16ToBALE(snInfo.sHomeCity.length() + 1));
    baTmp.append(snInfo.sHomeCity);
    baTmp.append((char) 0x00);
    Tlv0190.setData(baTmp);
    baTmp.clear();

    baResult.append(Tlv0190.toByteArray());

    QTlv Tlv019A; // Home State
    Tlv019A.setType(0x019A);
    Tlv019A.setLe(true);
    baTmp.append(u16ToBALE(snInfo.sHomeState.length() + 1));
    baTmp.append(snInfo.sHomeState);
    baTmp.append((char) 0x00);
    Tlv019A.setData(baTmp);
    baTmp.clear();

    baResult.append(Tlv019A.toByteArray());

    QTlv Tlv026D; // Home ZIP
    Tlv026D.setType(0x026D);
    Tlv026D.setLe(true);
    baTmp.append(u16ToBALE(snInfo.sHomeZip.length() + 1));
    baTmp.append(snInfo.sHomeZip);
    baTmp.append((char) 0x00);
    Tlv026D.setData(baTmp);
    baTmp.clear();

    baResult.append(Tlv026D.toByteArray());

    QTlv Tlv0276; // Home Phone
    Tlv0276.setType(0x026D);
    Tlv0276.setLe(true);
    baTmp.append(u16ToBALE(snInfo.sHomePhone.length() + 1));
    baTmp.append(snInfo.sHomePhone);
    baTmp.append((char) 0x00);
    Tlv0276.setData(baTmp);
    baTmp.clear();

    baResult.append(Tlv0276.toByteArray());

    QTlv Tlv028A; // Home mobile (xD)
    Tlv028A.setType(0x028A);
    Tlv028A.setLe(true);
    baTmp.append(u16ToBALE(snInfo.sHomeCellular.length() + 1));
    baTmp.append(snInfo.sHomeCellular);
    baTmp.append((char) 0x00);
    Tlv028A.setData(baTmp);
    baTmp.clear();

    baResult.append(Tlv028A.toByteArray());

    QTlv Tlv0262; // Home street
    Tlv0262.setType(0x0262);
    Tlv0262.setLe(true);
    baTmp.append(u16ToBALE(snInfo.sHomeStreet.length() + 1));
    baTmp.append(snInfo.sHomeStreet);
    baTmp.append((char) 0x00);
    Tlv0262.setData(baTmp);
    baTmp.clear();

    baResult.append(Tlv0262.toByteArray());

    QTlv Tlv017C; // User Gender
    Tlv017C.setType(0x017C);
    Tlv017C.setLe(true);
    Tlv017C.setData(snInfo.u8UserGender);

    baResult.append(Tlv017C.toByteArray());

    QTlv Tlv0172; // User Age
    Tlv0172.setType(0x0172);
    Tlv0172.setLe(true);
    Tlv0172.setData(u16ToBALE(snInfo.u16UserAge));

    baResult.append(Tlv0172.toByteArray());

    QTlv Tlv0258; // About
    Tlv0258.setType(0x0258);
    Tlv0258.setLe(true);
    baTmp.append(u16ToBALE(snInfo.sAbout.length() + 1));
    baTmp.append(snInfo.sAbout);
    baTmp.append((char) 0x00);
    Tlv0258.setData(baTmp);
    baTmp.clear();

    baResult.append(Tlv0258.toByteArray());

    QTlv Tlv023A; // Birthday date
    Tlv023A.setType(0x023A);
    Tlv023A.setLe(true);

    baTmp.append(snInfo.u8BirthYear);
    baTmp.append(snInfo.u8BirthMonth);
    baTmp.append(snInfo.u8BirthDay);
    Tlv023A.setData(baTmp);
    baTmp.clear();

    baResult.append(Tlv023A.toByteArray());

    baMetaData.append(u16ToBALE(8 + baResult.size()));
    baMetaData.append(snToBALE(sScreenName));

    baMetaData.append((char) 0xD0);
    baMetaData.append((char) 0x07);
    baMetaData.append((char) 0x02);
    baMetaData.append((char) 0x00);
    baMetaData.append(baResult);


    QTlv tlv1;
    tlv1.setType(0x0001);
    tlv1.setData(baMetaData);

    QSnac snac1502;
    snac1502.setFamilyId(0x0015);
    snac1502.setSubType(0x0002);
    snac1502.setFlags(0x0000);
    snac1502.setReqId(0x00000000);
    snac1502.setData(tlv1.toByteArray());

    return snac1502.toByteArray();
}

QByteArray QOSCARMetaInfo::createCLI_METAREQINFO(const QString &sSN,
                                                 const QString &sSelfSN)
{
    QByteArray baResult, baData, baFinalData;
    if ( sSN.length() < 5 || sSelfSN.length() < 5 )
        return baResult;

    baData.append(snToBALE(sSelfSN));
    baData.append(0xD0);
    baData.append(0x07);
    baData.append(0x02);
    baData.append((char) 0x00);
    baData.append(0xD0);
    baData.append(0x04);
    baData.append(snToBALE(sSN));
    baFinalData.append(u16ToBALE(baData.length()));
    baFinalData.append(baData);

    QTlv tlv0001;
    tlv0001.setType(0x0001);
    tlv0001.setLe(false);
    tlv0001.setData(baFinalData);

    QSnac snac1502(true, 0x0015, 0x0002);
    snac1502.setData(tlv0001.toByteArray());
    return snac1502.toByteArray();
}

void QOSCARMetaInfo::handleGeneral(const QByteArray &bafData)
{
    qDebug() << "Handling general...";
    if ( bafData.length() < 41 )
        return;

    QSNInfo snResult;
    QByteArray baData(bafData);
    baData.remove(0, 10);

    baData.remove(0, 1); // This is a "result" byte. Хуй знает, зачем нужен.
    quint16 u16Length = baData.at(0);

    qDebug() << "NickName array: " << baData.mid(2, u16Length - 1).toHex();
    snResult.sNickName = baData.mid(2, u16Length - 1);
    baData.remove(0, u16Length + 2);
    u16Length = baData.at(0);
    snResult.sFirstName = baData.mid(2, u16Length - 1);
    baData.remove(0, u16Length + 2);
    u16Length = baData.at(0);
    snResult.sLastName = baData.mid(2, u16Length - 1);
    baData.remove(0, u16Length + 2);
    u16Length = baData.at(0);
    snResult.sEMail = baData.mid(2, u16Length - 1);
    baData.remove(0, u16Length + 2);
    u16Length = baData.at(0);
    snResult.sHomeCity = baData.mid(2, u16Length - 1);
    baData.remove(0, u16Length + 2);
    u16Length = baData.at(0);
    snResult.sHomePhone = baData.mid(2, u16Length - 1);
    baData.remove(0, u16Length + 2);
    u16Length = baData.at(0);
    snResult.sHomeFax = baData.mid(2, u16Length - 1);
    baData.remove(0, u16Length + 2);
    u16Length = baData.at(0);
    snResult.sHomeStreet = baData.mid(2, u16Length - 1);
    baData.remove(0, u16Length + 2);
    u16Length = baData.at(0);
    snResult.sHomeCellular = baData.mid(2, u16Length - 1);
    baData.remove(0, u16Length + 2);
    u16Length = baData.at(0);
    snResult.sHomeZip = baData.mid(2, u16Length - 1);
    baData.remove(0, u16Length + 2);

    snResult.u16HomeCountry = baLEToU16(baData.mid(0, 2)); // !!! Ahtung!! check it!
    snResult.u8GMT = baData.at(2);
    snResult.u8AuthFlag = baData.at(3);
    snResult.u8WebAwareFlag = baData.at(4);
    snResult.u8DCPermissions = baData.at(5);
    snResult.u8PublishEMail = baData.at(6);

    emit onMetaInfo(snResult, META_GENERAL);
}

void QOSCARMetaInfo::handleMore(const QByteArray &bafData)
{
    QByteArray baData(bafData);
    QSNInfo snResult;
    baData.remove(0, 12);

    baData.remove(0, 1); // This is a "result" byte. Хуй знает, нафига нужен.
    snResult.u16UserAge = baLEToU16(baData.mid(0, 2));
    snResult.u8UserGender = baData.at(2);
    baData.remove(0, 3);
    quint16 u16Length = baLEToU16(baData.mid(0, 2));
    snResult.sHomePage = baData.mid(2, u16Length - 1);
    baData.remove(0, u16Length + 2);
    snResult.u8BirthYear = baData.at(0);
    snResult.u8BirthMonth = baData.at(1);
    snResult.u8BirthDay = baData.at(2);
    snResult.u8Lang1 = baData.at(3);
    snResult.u8Lang2 = baData.at(4);
    snResult.u8Lang3 = baData.at(5);
    baData.remove(0, 7); // Birth + Lang + 1 unknown

    u16Length = baLEToU16(baData.mid(0, 2));
    snResult.sOriginCity = baData.mid(2, u16Length - 1);
    baData.remove(0, u16Length + 2);
    u16Length = baLEToU16(baData.mid(0, 2));
    snResult.sOriginState = baData.mid(2, u16Length - 1);
    baData.remove(0, u16Length + 2);
    snResult.u16OriginCountry = baLEToU16(baData.mid(0, 2));
    snResult.u8TimeZone = baData.at(2);
    baData.remove(0, 7);
    u16Length = baLEToU16(baData.mid(0, 2));
    baData.remove(0, u16Length + 10);
    u16Length = baLEToU16(baData.mid(0, 2));
    snResult.sEMail = baData.mid(2, u16Length - 1);

    emit onMetaInfo(snResult, META_MORE);
}

void QOSCARMetaInfo::handleWork(const QByteArray &bafData)
{
    QByteArray baData(bafData);
    QSNInfo snResult;
    baData.remove(0, 13);

    quint16 u16Length = baLEToU16(baData.mid(0, 2));
    snResult.sWorkCity = baData.mid(2, u16Length - 1);
}

void QOSCARMetaInfo::handleLast(const QByteArray &bafData)
{
    if ( bafData.length() < 6 )
        return;
    QByteArray baData(bafData);
    QSNInfo snResult;
    bool ok;
    quint16 u16Length  = baData.mid(4, 2).toHex().toUInt(&ok, 16);
    baData.remove(0, 6);
    if ( baData.length() < u16Length )
        return;

    baLEToU32(baData.mid(0, 4));
    baData.remove(0, 15);
    snResult.sScreenName = QString::number(baLEToU32(baData.mid(0, 4)));
    u16Length = baLEToU16(baData.mid(0, 2));
    snResult.sNickName = baData.mid(2, u16Length).trimmed();
    baData.remove(0, u16Length + 2);
    u16Length = baLEToU16(baData.mid(0, 2));
    snResult.sFirstName = baData.mid(2, u16Length).trimmed();
    baData.remove(0, u16Length + 2);
    u16Length = baLEToU16(baData.mid(0, 2));
    snResult.sLastName = baData.mid(2, u16Length).trimmed();
    baData.remove(0, u16Length + 2);
    u16Length = baLEToU16(baData.mid(0, 2));
    snResult.sEMail = baData.mid(2, u16Length).trimmed();
    baData.remove(0, u16Length + 2);

    snResult.u8AuthFlag = baData.at(0);
    snResult.u16WAStatus = baLEToU16(baData.mid(1, 2));
    snResult.u8UserGender = baData.at(3);
    snResult.u16UserAge = baLEToU16(baData.mid(4, 2));
    snResult.u16FoundLeft = baLEToU16(baData.mid(6, 2));
    u16Length = baData.at(8);
    baData.remove(0, 9 + u16Length);
    snResult.u16Found = baLEToU16(baData.mid(0, 2));
    emit onMetaInfo(snResult, 0xAE);
};

void QOSCARMetaInfo::handleInfo(const QByteArray &bafData)
{
    if ( bafData.length() < 13 )
        return;

    QByteArray baData(bafData);
//    QString sSN;

    //quint16 u16Length = baLEToU16(baData.mid(0, 2));
    baData.remove(0, 6);
//    quint32 u32SN = baLEToU32(baData.mid(0, 4));
//    sSN.setNum(u32SN);

    qDebug() << "Type:" << baData.mid(8, 1).toHex();

    switch ( baData.at(8) ){

        case META_GENERAL:
            handleGeneral(baData);
            break;

        case META_LAST:
            handleLast(baData);
            break;
    }
}

void QOSCARMetaInfo::handlePacket(const QSnac &snac)
{
    switch ( snac.familySubType() ){
        case 0x03:
            handleInfo(snac.data());
            break;
    }
}

QByteArray QOSCARMetaInfo::createSearchBySN(const QString &sSN, const QString &selfSN)
{
    QByteArray baData;
    baData.append(snToBALE(selfSN));
    baData.append((char) 0xD0);
    baData.append((char) 0x07);
    baData.append((char) 0x02);
    baData.append((char) 0x00);
    baData.append((char) 0x69);
    baData.append((char) 0x05);
    baData.append((char) 0x36);
    baData.append((char) 0x01);
    baData.append((char) 0x09);
    baData.append((char) 0x00);
    baData.append(snToBALE(sSN));

    QByteArray baTlvData(u16ToBALE(baData.length()));
    baTlvData.append(baData);
    QTlv tlv0001;
    tlv0001.setType(0x0001);
    tlv0001.setData(baTlvData);
    QSnac snac1502(true, 0x15, 0x02, 0x0000, 0);
    snac1502.setData(tlv0001.toByteArray());
    return snac1502.toByteArray();
}
