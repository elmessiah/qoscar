#ifndef QOSCARBASIC_H
#define QOSCARBASIC_H

#include <QObject>

class QSnac
{
    public:
        QSnac(const bool full = false , const quint16 family = 0,
              const quint16 subType = 0, const quint16 flags = 0,
              const quint32 reqId = 0);

        void setFamilyId(const quint16 fId){ u16FamilyId = fId; }
        void setSubType(const quint16 fST){ u16FamilySubType = fST; }
        void setFlags(const quint16 sFlags){ u16SnacFlags = sFlags; }
        void setReqId(const quint32 sReqId){ u32SnacReqId = sReqId; }
        void setData(const QByteArray &baData) { baSnacData = baData; }

        void handlePacket(const QByteArray &sData);

        quint16 familyId() const { return u16FamilyId; }
        quint16 familySubType() const { return u16FamilySubType; }
        quint16 snacFlags() const { return u16SnacFlags; }
        quint32 snacReqId() const { return u32SnacReqId; }
        QByteArray data() const { return baSnacData; }

        QByteArray toByteArray();

    private:
        quint16 u16FamilyId,
                u16FamilySubType,
                u16SnacFlags;
        quint32 u32SnacReqId;
        QByteArray baSnacData;
};

class QTlv
{
    public:
        QTlv();

        void handleTlv(const QByteArray &bafData);

        void setData(const QString &sData);
        void setData(const QByteArray &bafData);
        void setData(const quint8 u8Data);
        void setData(const quint16 u16Data);
        void setData(const quint32 u32Data);
        void setLe(const bool bfLE) { bLE = bfLE; }
        void setType(const quint16 u16fType){ u16Type = u16fType; }

        QByteArray toByteArray();

        bool notLast() const { return bNotLast; }
        quint16 length() const { return u16Length; }
        quint16 type() const { return u16Type; }
        QByteArray value() const { return baData; }

    private:
        quint16 u16Type,
                u16Length;
        QByteArray baData;
        bool bNotLast,
             bLE;
};

class QFlap
{
    public:
        QFlap(const QByteArray &bafData, const bool incoming = false);

        void setChannel(const quint8 fchannel) { u8Channel = fchannel; }
        void setSequence(const quint16 fseq) { u16Sequence = fseq; }
        void setData(const QByteArray &bafData) { baData = bafData; }

        quint8 channel() const { return u8Channel; }
        quint16 sequence() const { return u16Sequence; }
        quint16 size() const { return (quint16) baData.length(); }

        QByteArray data() const { return baData; }

        QByteArray toByteArray(const bool isFirst);

    private:
        quint8 u8Channel;
        quint16 u16Sequence,
                u16Size;
        QByteArray baData;
};

QByteArray u16ToBA(const quint16 u16Data);
QByteArray u32ToBa(const quint32 u32Data);
QByteArray u16ToBALE(const quint16 u16Data);
QByteArray snToBALE(const QString &sSN);

quint16 baLEToU16(const QByteArray &bafData);
quint32 baLEToU32(const QByteArray &bafData);

#endif // QOSCARBASIC_H
