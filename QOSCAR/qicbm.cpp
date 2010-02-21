#include "qicbm.h"

QByteArray QICBM::createICBM__MESSAGE_TO_HOST(const QString &SN,
                                              const QString &Message)
{
    QByteArray bArr;

    QTlv Tlv0501;
    Tlv0501.setType(0x0501);
    Tlv0501.setData((quint16) 0x0001);
    bArr.append(Tlv0501.toByteArray());

    QTlv Tlv0101;
    Tlv0101.setType(0x0101);
    QByteArray baTmp((quint16) 0x0000);
    for (int i = 0; i < 4; i++)
        baTmp.append((char) 0x00);
//    QTextCodec* textCodec = QTextCodec::codecForName("Windows-1251");
    baTmp.append(/*textCodec->fromUnicode(*/Message);
    Tlv0101.setData(baTmp);

    bArr.append(Tlv0101.toByteArray());

    QTlv Tlv2;
    Tlv2.setType(0x0002);
    Tlv2.setData(bArr);

    QTlv Tlv3;
    Tlv3.setType(0x0003);

    QTlv Tlv6;
    Tlv6.setType(0x0006);

    QByteArray baSnac;
    QSnac Snac0406;
    Snac0406.setFamilyId(0x04);
    Snac0406.setSubType(0x06);
    Snac0406.setReqId(0x00000000);
    Snac0406.setFlags(0x0000);
    baSnac.append(Snac0406.toByteArray());

    for (int i = 0; i < 9; i++)
        baSnac.append((char) 0x00);

    baSnac.append((quint16) 0x01);
    baSnac.append((quint8) SN.length());
    baSnac.append(SN);
    baSnac.append(Tlv2.toByteArray());
    baSnac.append(Tlv3.toByteArray());
    baSnac.append(Tlv6.toByteArray());

    return baSnac;
}



/* Handling incoming message */
void QICBM::handleMessage(const QByteArray &baMessage, const QString &sEncoding)
{
    QMessage mResult;
    QByteArray bArr(baMessage);
    QByteArray baTemp;
    bArr.remove(0, 16); // Delete Cookie and channel
    for (int i = 0; i < bArr[0]; i++)
        mResult.sSender.append(bArr.at(i + 1));

    while (bArr.size() > 0){
        if (((bArr.at(0) == (char) 0x01) && (bArr.at(1) == (char) 0x01) &&
            (bArr.at(2) != (char) 0x01) && bArr.at(3) != (char) 0x01))
            break;
        bArr.remove(0, 1);
    }

    QTlv Tlv0101;
    Tlv0101.handleTlv(bArr);
    bArr.remove(0, 8);
    for (int i = 0; i < Tlv0101.length() - 4; i++)
        baTemp.append(bArr.at(i));

    qDebug() << "baTemp: " << baTemp.toHex();
//    QTextCodec* codec = QTextCodec::codecForName("Windows-1251");

    mResult.sMessage.append(baTemp);
    emit onMessage(mResult);
}

QByteArray QICBM::createICBM__CLIENT_EVENT(const QString &sScreenName,
                                    const quint16 u16State)
{
    QByteArray baData;

    for ( qint32 i = 0; i < 9; i++ )
        baData.append((char) 0x00);
    baData.append((char) 0x01);
    baData.append((char) sScreenName.length());
    baData.append(sScreenName);
    baData.append(u16ToBA(u16State));
    QSnac snac0414(true, 0x0004, 0x0014, 0x0000, 0x00000014);
    snac0414.setData(baData);
    return snac0414.toByteArray();
}

QByteArray QICBM::createICBM__EVIL_REQUEST(const QString &sSN, bool bAnonymous)
{
    QByteArray baData;
    if ( bAnonymous )
        baData.append(u16ToBA(0x0001));
    else
        baData.append(u16ToBA(0x0000));

    baData.append(sSN);
    QSnac snac0408(true, 0x0004, 0x0008, 0x0000, 0x00000000);
    snac0408.setData(baData);
    return snac0408.toByteArray();
}

QByteArray QICBM::createICBM__DELETE_PARAMETERS(quint16 u16Channel)
{
    QSnac snac0403(true, 0x0004, 0x0003, 0x0000, 0x00000000);
    snac0403.setData(u16ToBA(u16Channel));
    return snac0403.toByteArray();
}

QByteArray QICBM::createICBM__ADD_PARAMETERS(quint16 u16Channel, quint32 u32Flags,
                                      quint16 u16MaxIncomingLen,
                                      quint16 u16MaxSourceEvil,
                                      quint16 u16MaxDestEvil,
                                      quint16 u16MinInterval)
{
    QByteArray baData;
    baData.append(u16ToBA(u16Channel));
    baData.append(u32ToBa(u32Flags));
    baData.append(u16ToBA(u16MaxIncomingLen));
    baData.append(u16ToBA(u16MaxSourceEvil));
    baData.append(u16ToBA(u16MaxDestEvil));
    baData.append(u16ToBA(u16MinInterval));
    baData.append((char) 0x00);
    baData.append((char) 0x00);

    QSnac snac0402(true, 0x0004, 0x0002, 0x0000, 0x000002);
    snac0402.setData(baData);
    return snac0402.toByteArray();
}

void QICBM::handleClientEvent(const QByteArray &bafData)
{
    if ( bafData.length() < 11 )
        return;
    QByteArray baData(bafData);
    bool ok;
    baCookie = baData.mid(0, 8);
    baData.remove(0, 8);
    quint16 u16Channel = baData.mid(0, 2).toHex().toUInt(&ok, 16);
    quint8 u8Length = baData.at(2);
    if ( baData.length() < u8Length + 5 )
        return;
    QString sSN(baData.mid(3, u8Length));
    quint16 u16Event = baData.mid(u8Length + 3, 2).toHex().toUInt(&ok, 16);
    emit onClientEvent(u16Channel, sSN, u16Event);
}

QByteArray QICBM::createICBM__QUERY_SMS_INFO(const QString &sPhoneNum)
{
    QSnac snac0424(true, 0x0004, 24, 0x0000, 0x00000000);
    snac0424.setData(QByteArray(sPhoneNum.toAscii()));
    return snac0424.toByteArray();
}

QSMSInfoReply QICBM::handleSMSInfoReply(const QByteArray &bafData)
{
    QSMSInfoReply infoResult;
    if ( bafData.length() < 8 )
        return infoResult;

    QByteArray baData(bafData);
    bool ok;
    infoResult.u16Free = baData.mid(2, 2).toHex().toUInt(&ok, 16);
    baData.remove(0, 6);
    quint8 u8Length = baData.at(0);
    if ( baData.length() < u8Length + 2 )
        return infoResult;
    infoResult.sCarrier = baData.mid(1, u8Length);
    baData.remove(0, u8Length + 1);
    u8Length = baData.at(0);
    if ( baData.length() < u8Length + 8 )
        return infoResult;
    infoResult.sCarrierURL = baData.mid(1, u8Length);
    baData.remove(0, u8Length + 1);
    infoResult.u16AsciiLength = baData.mid(0, 2).toHex().toUInt(&ok, 16);
    infoResult.u16Utf8Length = baData.mid(2, 2).toHex().toUInt(&ok, 16);
    baData.remove(0, 6);
    u8Length = baData.at(0);
    if ( baData.length() < u8Length + 1 )
        return infoResult;
    infoResult.sPhoneCode = baData.mid(1, u8Length);
    return infoResult;
}

void QICBM::handlePacket(const QByteArray &bafData, const quint16 u16SubType)
{
    switch ( u16SubType ){

        case 0x0007:
            handleMessage(bafData, "Windows-1251");
            break;
    }
}
