#include "qrostertools.h"

QRoster::QRoster()
{
    riItems = 0;
    u16Count = 0;
}

QRoster::~QRoster()
{
    if ( riItems != 0 )
        delete riItems;
}

/*************************************
        FUNCTIONS
*************************************/

QByteArray create_RequestCL()
{
    QSnac snac0013;
    snac0013.setFamilyId(0x0013);
    snac0013.setSubType(0x0004);
    snac0013.setReqId(0x0004);
    snac0013.setFlags(0x00000000);
    return snac0013.toByteArray();
}

void QRoster::handleItems(const QByteArray &baItems)
{
    if ( baItems.length() < 3 )
        return;

    mutex.lock();
    bool ok;
    QByteArray baData(baItems);

    if ( baData.length() < 17 )
        return;

    qDebug() << "Raw roster:" << baData.toHex();
    baData.remove(0, 9); // Remove "unknown" 0x00 byte
    qDebug() << "Raw roster2:" << baData.toHex();
    quint16 u16CLCount =  QString(baData.mid(0, 2).toHex()).toUInt(&ok, 16); // CL Items in packet
    baData.remove(0, 2); // Remove length 2 bytes
    qDebug() << "CL Count is " << u16CLCount;
    if ( !ok || u16CLCount < 1 ){
        mutex.unlock();
        qDebug() << "Ne ok =(";
        return;
    }

    QRawRosterItem *riTemp = new QRawRosterItem[u16CLCount];

    for ( quint16 i = 0; i < u16CLCount; i++ ){
        if ( baData.length() < 2 )
            break;

        riTemp[i].u16NameLength = baData.mid(0, 2).toHex().toUInt(&ok, 16);
        baData.remove(0, 2);
        qDebug() << "riTemp[" << i << "].u16NameLength =" << riTemp[i].u16NameLength;

        if ( baData.length() < riTemp[i].u16NameLength + 8 ){
            delete riTemp;
            return;
        }

        for ( quint16 j = 0; j < riTemp[i].u16NameLength; j++ )
            riTemp[i].baScreenName.append(baData[j]);

        baData.remove(0, riTemp[i].u16NameLength);
        riTemp[i].u16Group = QString(baData.mid(0, 2).toHex()).toUInt(&ok, 16);
        baData.remove(0, 2);
        qDebug() << "riTemp[" << i << "].u16Group =" << riTemp[i].u16Group;
        riTemp[i].u16Id = QString(baData.mid(0, 2).toHex()).toUInt(&ok, 16);
        baData.remove(0, 2);
        qDebug() << "riTemp[" << i << "].u16Id =" << riTemp[i].u16Id;
        riTemp[i].u16Type = QString(baData.mid(0, 2).toHex()).toUInt(&ok, 16);
        baData.remove(0, 2);
        qDebug() << "riTemp[" << i << "].u16Type =" << riTemp[i].u16Type;
        riTemp[i].u16DataLength = QString(baData.mid(0, 2).toHex()).toUInt(&ok, 16);
        baData.remove(0, 2);
        qDebug() << "riTemp[" << i << "].u16DataLength =" << riTemp[i].u16DataLength;

        for ( quint16 j = 0; j < riTemp[i].u16DataLength; j++ )
            riTemp[i].baData.append(baData[j]);

        baData.remove(0, riTemp[i].u16DataLength);
    }

    handleRawItems(riTemp, u16CLCount);
    mutex.unlock();
    if ( riTemp )
        delete riTemp;
}

void QRoster::handleRawItems(QRawRosterItem *rawItems, quint16 u16ItemsCount)
{
    if ( u16Count < 1 ){
        riItems = new QRosterItem[u16ItemsCount];

        for (quint16 u16i = 0; u16i < u16ItemsCount; u16i++ ){
            riItems[u16i].sScreenName = rawItems[u16i].baScreenName;
            qDebug() << "Raw:" << rawItems[u16i].baScreenName;
            qDebug() << "Done:" << riItems[u16i].sScreenName;
            riItems[u16i].u16DataLength = rawItems[u16i].u16DataLength;
            riItems[u16i].u16Group = rawItems[u16i].u16Group;
            riItems[u16i].u16Id = rawItems[u16i].u16Id;
            riItems[u16i].u16Type = rawItems[u16i].u16Type;
        }
    }else{
        QRosterItem *riTemp = new QRosterItem[u16Count];
        memcpy(riTemp, riItems, sizeof(riItems));
        delete riItems;
        riItems = new QRosterItem[u16ItemsCount];
        memcpy(riItems, riTemp, sizeof(riTemp));

        for (quint16 u16i = u16Count; u16i < u16ItemsCount + u16Count; u16i++ ){
            riItems[u16i].sScreenName = rawItems[u16i - u16Count].baScreenName;
            riItems[u16i].u16DataLength = rawItems[u16i - u16Count].u16DataLength;
            riItems[u16i].u16Group = rawItems[u16i - u16Count].u16Group;
            riItems[u16i].u16Id = rawItems[u16i - u16Count].u16Id;
            riItems[u16i].u16Type = rawItems[u16i - u16Count].u16Type;
        }
        u16ItemsCount += u16Count;
    }

    u16Count = u16ItemsCount;
    emit onCLHandled();
}

QByteArray QRoster::createFEEDBAG__INSERT_ITEM(const QString &sSN, const QString &sAlias,
                                              const QString &sNote, const quint16 u16fGroup)
{
    QByteArray baData, baTlvs;
    QSnac snac0304;
    snac0304.setFamilyId(0x0013);
    snac0304.setSubType(0x0008);
    snac0304.setFlags(0x0000);
    snac0304.setReqId(0x00000004);
    baData.append((char) 0x00);
    baData.append((char) sSN.length());
    baData.append(sSN);
    baData.append(u16ToBA(u16fGroup));
    baData.append((char) rand() % 255); // +
    baData.append((char) rand() % 255); // ItemId
    baData.append((char) 0x00); // +
    baData.append((char) 0x00); // ClassId

    QTlv Tlv0131;
    Tlv0131.setType(0x0131);
    Tlv0131.setData(u16ToBA(sAlias.length()) + sAlias);

    QTlv Tlv013C;
    Tlv013C.setType(0x013C);
    Tlv013C.setData(u16ToBA((quint16) sNote.length()) + sNote);

    QTlv Tlv0066;
    Tlv0066.setType(0x0066);

    baTlvs.append(Tlv0131.toByteArray());
    baTlvs.append(Tlv013C.toByteArray());
    baTlvs.append(Tlv0066.toByteArray());

    baData.append(u16ToBA((quint16) baTlvs.length()));
    baData.append(baTlvs);

    snac0304.setData(baData);
    return snac0304.toByteArray();
}

QByteArray QRoster::create__CLI_BUDDYLIST_REMOVE(const QString &sSN)
{
    QByteArray baData;
    QSnac snac0305;
    snac0305.setFamilyId(0x0003);
    snac0305.setSubType(0x0005);
    snac0305.setFlags(0x0000);
    snac0305.setReqId(0x00000004);
    baData.append((char) sSN.length());
    baData.append(sSN);

    snac0305.setData(baData);
    return snac0305.toByteArray();
}

QByteArray QRoster::createFEEDBAG__ADDSTART()
{
    QSnac snac1311;
    snac1311.setFamilyId(0x0013);
    snac1311.setSubType(0x0011);
    snac1311.setFlags(0x0000);
    return snac1311.toByteArray();
}

QByteArray QRoster::createFEEDBAG__ADDEND()
{
    QSnac snac1312;
    snac1312.setFamilyId(0x0013);
    snac1312.setSubType(0x0012);
    snac1312.setFlags(0x0000);
    return snac1312.toByteArray();
}

QByteArray QRoster::createFEEDBAG__AUTHORIZE_REQUEST(const QString &sSN,
                                                     const QString &sReason)
{
    QByteArray baData;
    baData.append((quint8)sSN.length());
    baData.append(sSN);
    baData.append(u16ToBA(sReason.length()));
    baData.append(sReason);
    baData.append((char)0x00);
    baData.append((char) 0x00);

    QSnac snac1318(true, 0x0013, 0x0018, 0x0000, 0x00000018);
    snac1318.setData(baData);
    return snac1318.toByteArray();
}

void QRoster::handleAuthRequest(const QByteArray &bafData)
{
    QByteArray baData(bafData);
    if ( baData.at(0) == 0x00 ){
        if ( baData.length() < 5 )
            return;

        bool ok;
        quint16 u16Length = baData.mid(0, 2).toHex().toUInt(&ok, 16);
        baData.remove(0, u16Length);
    }
    if ( baData.length() < 5 )
        return;
    quint8 u8Length = baData.at(0);
    if ( baData.length() < u8Length + 2 )
        return;

    QString sSN(baData.mid(1, u8Length));
    baData.remove(0, u8Length + 1);
    u8Length = baData.at(0);
    if ( baData.length() < u8Length + 1)
        return;
    QString sReason(baData.mid(1, u8Length));
    emit onAuthRequest(sSN, sReason);
}

QByteArray QRoster::createFEEDBAG__AUTHORIZE(const QString &sSN,
                                             const QString &sReason,
                                             const quint8 u8Flag)
{
    QByteArray baData;
    baData.append((quint8) sSN.length());
    baData.append(sSN);
    baData.append(u8Flag);
    baData.append(u16ToBA(sReason.length()));
    if ( sReason.length() > 0 )
        baData.append(sReason);

    QSnac snac131A(true, 0x0013, 0x001A, 0x0000, 0x0000001A);
    snac131A.setData(baData);
    return snac131A.toByteArray();
}

void QRoster::handleBuddyArrived(const QByteArray &bafData)
{
    QByteArray baData(bafData);
    bool ok;

    quint8 u8Length = baData.at(0);
    QBuddy buddy;
    buddy.sScreenName = baData.mid(1, u8Length);
    baData.remove(0, u8Length + 1);
    buddy.u16WarnLevel = baData.mid(0, 2).toUInt(&ok, 16);
    quint16 u16Count = baData.mid(2, 2).toUInt(&ok, 16);
    baData.remove(0, 4);

    for ( quint16 i = 0; i < u16Count; i++ ){
        QTlv tlv;
        tlv.handleTlv(baData);

        switch ( tlv.type() ){

            case 0x0006: // Status
                buddy.u16StatusFlags = tlv.value().mid(0, 2).toUInt(&ok, 16);
                buddy.u16Status = tlv.value().mid(2, 2).toUInt(&ok, 16);
                break;

                //case 0x000C // DC Info, fuck it
            case 0x0005: // Registered
                buddy.dtRegistered.fromTime_t(tlv.value().mid(0, 4).toUInt(&ok, 16));
                break;

            case 0x0027: // Away update
                buddy.dtAwayUpdate.fromTime_t(tlv.value().mid(0, 4).toUInt(&ok, 16));
                break;

            case 0x0003: // Online since
                buddy.dtOnlineSince.fromTime_t(tlv.value().mid(0, 4).toUInt(&ok, 16));
                break;

            case 0x000D: // Capabilities
                buddy.baCapabilities = tlv.value();
                break;

            case 0x0019: // Small capabilities
                buddy.baNewCapabilities = tlv.value();
                break;

            default:
                break;
        }

        baData.remove(0, tlv.length() + 4);    
    }

    qDebug() << "Buddy arrived: " << buddy.sScreenName << ';' << buddy.dtRegistered
             << ';' << buddy.dtOnlineSince << ';' << buddy.u16Status << ';'
             << buddy.u16StatusFlags;
    emit onBuddyArrivedOrDeparted(buddy, true);
}

void QRoster::handleBuddyDeparted(const QByteArray &bafData)
{
    QByteArray baData(bafData);
    bool ok;

    if ( baData.length() < 10 )
        return;

    quint8 u8Length = baData.at(0);
    QBuddy buddy;
    buddy.sScreenName = baData.mid(1, u8Length);
    baData.remove(0, u8Length + 1);
    if ( baData.length() > 1 )
        buddy.u16WarnLevel = baData.mid(0, 2).toUInt(&ok, 16);

    /// хуй с ним, все равно юзер-классы никому не нужны

    qDebug() << "Buddy departed: " << buddy.sScreenName << ';' << buddy.dtRegistered
             << ';' << buddy.dtOnlineSince << ';' << buddy.u16Status << ';'
             << buddy.u16StatusFlags;
    emit onBuddyArrivedOrDeparted(buddy, false);
}

void QRoster::handlePacket(const QByteArray &bafData, quint16 u16Family, quint16 u16SubType)
{
    switch ( u16Family ){
        case FOODGROUP_FEEDBAG:
            switch ( u16SubType ){
                case 0x0006:
                    handleItems(bafData);
            }
    }
}
