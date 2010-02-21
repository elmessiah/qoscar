#include "qoscarbasic.h"

QByteArray u16ToBA(const quint16 u16Data)
{
    QByteArray baResult;
    baResult[0] = (u16Data / 0x100);
    baResult[1] = (u16Data % 0x100);
    return baResult;
}

QByteArray u32ToBa(const quint32 u32Data)
{
    QByteArray baResult;
    baResult[0] = (u32Data / 0x1000000);
    baResult[1] = (u32Data / 0x10000);
    baResult[2] = (u32Data / 0x100);
    baResult[3] = (u32Data % 0x100);
    return baResult;
}

QByteArray u16ToBALE(const quint16 u16Data)
{
    QByteArray baResult;
    baResult[1] = (u16Data / 0x100);
    baResult[0] = (u16Data % 0x100);
    return baResult;
}

QByteArray snToBALE(const QString &sSN)
{
    QByteArray baResult;
    quint32 tmpSN = sSN.toUInt();
    baResult[0] = tmpSN % 0x100;
    baResult[1] = tmpSN % 0x10000 / 0x100;
    baResult[2] = tmpSN % 0x1000000 / 0x10000;
    baResult[3] = tmpSN / 0x1000000;
    return baResult;
}

quint16 baLEToU16(const QByteArray &bafData)
{
    if ( bafData.length() != 2 )
        return 0;
    bool ok;
    quint16 tmp = bafData.toHex().toUInt(&ok,16);
    return ((tmp % 0x100) * 0x100 + (tmp) / 0x100);
}

quint32 baLEToU32(const QByteArray &bafData)
{
    if ( bafData.length() != 4 )
        return 0;

    bool ok;
    quint32 tmp = bafData.toHex().toUInt(&ok,16);
    return ((tmp % 0x100) * 0x1000000 +
            (tmp % 0x10000 / 0x100) * 0x10000 +
            (tmp % 0x1000000 / 0x10000) * 0x100 +
            (tmp)/0x1000000);
}

/////////////////////////////////////////////////////////

QSnac::QSnac(bool full, quint16 family, quint16 subType,
             quint16 flags, quint32 reqId)
{
    if ( !full )
        return;

    u16FamilyId = family;
    u16FamilySubType = subType;
    u16SnacFlags = flags;
    u32SnacReqId = reqId;
}

QByteArray QSnac::toByteArray()
{
    QByteArray baResult;
    baResult.append(u16ToBA(u16FamilyId));
    baResult.append(u16ToBA(u16FamilySubType));
    baResult.append(u16ToBA(u16SnacFlags));
    baResult.append(u32ToBa(u32SnacReqId));
    baResult.append(baSnacData);
    return baResult;
}

void QSnac::handlePacket(const QByteArray &sData)
{
    QByteArray tmp;
    bool ok;

    if ( sData.length() < 10 )
        return;

    tmp = sData.mid(0, 2);
    u16FamilyId = tmp.toHex().toUInt(&ok, 16);
    tmp = sData.mid(2, 2);
    u16FamilySubType = tmp.toHex().toUInt(&ok, 16);
    tmp = sData.mid(4, 2);
    u16SnacFlags = tmp.toHex().toUInt(&ok, 16);
    tmp = sData.mid(6, 4);
    u32SnacReqId = tmp.toHex().toUInt(&ok, 32);

    if ( sData.length() < 11 )
        return;

    baSnacData = sData;
    baSnacData.remove(0, 10);
}

/*************************************************
                TLV
*************************************************/

QTlv::QTlv()
{
    bNotLast = true;
    bLE = false;
    u16Type = u16Length = 0;
}

QByteArray QTlv::toByteArray()
{
    QByteArray baResult;

    if ( bLE ){
        baResult[1] = u16Type / 0x100;
        baResult[0] = u16Type % 0x100;
        baResult[3] = u16Length / 0x100;
        baResult[2] = u16Length % 0x100;
    }else{
        baResult.append(u16ToBA(u16Type));
        baResult.append(u16ToBA(u16Length));
    }
    baResult.append(baData);
    return baResult;
}

void QTlv::setData(const QString &sData)
{
    if (sData.length() > 65536)
        return;

    baData = sData.toAscii();

    u16Length = (quint16) sData.length();
}

void QTlv::setData(const QByteArray &bafData)
{
    if (bafData.length() > 65536)
        return;

    baData = bafData;
    u16Length = (quint16) bafData.length();
}

void QTlv::setData(const quint8 u8Data)
{
    baData.clear();
    u16Length = 1;
    baData[0] = u8Data;
}

void QTlv::setData(const quint16 u16Data)
{
    u16Length = 2;
    baData = u16ToBA(u16Data);
}

void QTlv::setData(const quint32 u32Data)
{
    u16Length = 4;
    baData = u32ToBa(u32Data);
}

void QTlv::handleTlv(const QByteArray &bafData)
{
    QByteArray baTmp;
    bool ok;

    if ( bafData.length() < 4 )
        return;

    baTmp = bafData.mid(0, 2);
    u16Type = baTmp.toHex().toUInt(&ok, 16);

    baTmp = bafData.mid(2, 2);
    u16Length = baTmp.toHex().toUInt(&ok, 16);

    bNotLast = (u16Length + 4) < bafData.length();

    if ( bafData.length() < u16Length + 4 )
        return;

    baData = bafData.mid(4, u16Length);
}

/*****************************************************
            FLAP
*****************************************************/

QFlap::QFlap(const QByteArray &bafData, const bool incoming)
{
    if ( incoming ){
        if ( bafData.length() < 6 )
            return;

        u8Channel = bafData[1];
        QByteArray baTmp;
        bool ok;
        baTmp = bafData.mid(2, 2);
        u16Sequence = baTmp.toHex().toUInt(&ok, 16);
        baTmp = bafData.mid(4, 2);
        u16Size = baTmp.toHex().toUInt(&ok, 16);
        if ( bafData.length() > u16Size + 5 )
            baData = bafData.mid(6, u16Size);
    }else{
        baData = bafData;
        u16Size = baData.length();
    }
}

QByteArray QFlap::toByteArray(const bool isFirst)
{
    QByteArray baResult;
    baResult.append((quint8) 0x2A);
    baResult.append(u8Channel);
    baResult.append(u16ToBA(u16Sequence));

    if ( isFirst ){
        baResult.append(u16ToBA((quint16) baData.length() + 4));
        baResult.append((char) 0x00);
        baResult.append((char) 0x00);
        baResult.append((char) 0x00);
        baResult.append((char) 0x01);
    }else
        baResult.append(u16ToBA((quint16) baData.length()));
    baResult.append(baData);
    return baResult;
}
