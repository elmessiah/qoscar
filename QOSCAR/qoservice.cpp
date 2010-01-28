#include "qoservice.h"

QByteArray QOService::createPacket(const quint16 famNum, const quint16 famVersion,
                                   const quint16 toolId, const quint16 toolVersion)
{
    QByteArray baResult;
    baResult.append(u16ToBA(famNum));
    baResult.append(u16ToBA(famVersion));
    baResult.append(u16ToBA(toolId));
    baResult.append(u16ToBA(toolVersion));
    return baResult;
}

QByteArray QOService::createOSERVICE__CLIENT_ONLINE()
{
    QByteArray baResult;

    baResult.append(createPacket(0x0001, 0x0004, 0x0110, 0x08E4));
    baResult.append(createPacket(0x0013, 0x0004, 0x0110, 0x08E4));
    baResult.append(createPacket(0x0002, 0x0001, 0x0110, 0x08E4));
    baResult.append(createPacket(0x0003, 0x0001, 0x0110, 0x08E4));
    baResult.append(createPacket(0x0015, 0x0001, 0x0110, 0x08E4));
    baResult.append(createPacket(0x0004, 0x0001, 0x0110, 0x08E4));
    baResult.append(createPacket(0x0006, 0x0001, 0x0110, 0x08E4));
    baResult.append(createPacket(0x0009, 0x0001, 0x0110, 0x08E4));
    baResult.append(createPacket(0x000A, 0x0001, 0x0110, 0x08E4));
    baResult.append(createPacket(0x000B, 0x0001, 0x0110, 0x08E4));
    return baResult;
}

QByteArray QOService::createOSERVICE__SET_NICKINFO_FIELDS(const quint16 u16Status,
                                               const quint16 u16StatusFlags)
{
    QTlv tlv;
    QByteArray baData;
    tlv.setType(0x0006);
    baData.append(u16ToBA(u16StatusFlags));
    baData.append(u16ToBA(u16Status));
    tlv.setData(baData);
    return tlv.toByteArray();
}

void QOService::handleEvilNotification(const QByteArray &bafData)
{
    bool ok;
    quint16 u16Level = bafData.mid(0, 2).toHex().toUInt(&ok, 16);
    emit onEvilNotification(u16Level);
}
