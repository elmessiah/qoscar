#include "qoscarident.h"

QByteArray createCLI_Cookie(const QByteArray &baCookie)
{
    QTlv tlv;
    tlv.setType(0x0006);
    tlv.setData(baCookie);
    return tlv.toByteArray();
}

QByteArray createCLI_GOODBYE()
{
    QByteArray baData;
    return baData;
}

QByteArray createCLI_IDENT(QIdent ident, const QString &ScreenName,
                            const QString &Password)
{
    QByteArray bArr;
    QTlv Tlv;
    Tlv.setData(ScreenName);
    Tlv.setType(0x01);
    bArr.append(Tlv.toByteArray());

    Tlv.setData(Password);
    Tlv.setType(0x02);
    bArr.append(Tlv.toByteArray());

    Tlv.setData(ident.clientName);
    Tlv.setType(0x03);
    bArr.append(Tlv.toByteArray());

    Tlv.setData(ident.majorVersion);
    Tlv.setType(0x17);
    bArr.append(Tlv.toByteArray());

    Tlv.setData(ident.minorVersion);
    Tlv.setType(0x18);
    bArr.append(Tlv.toByteArray());

    Tlv.setData(ident.lesserVersion);
    Tlv.setType(0x19);
    bArr.append(Tlv.toByteArray());

    Tlv.setData(ident.build);
    Tlv.setType(0x1A);
    bArr.append(Tlv.toByteArray());

    Tlv.setData(ident.unknown);
    Tlv.setType(0x16);
    bArr.append(Tlv.toByteArray());

    Tlv.setData(ident.subBuild);
    Tlv.setType(0x14);
    bArr.append(Tlv.toByteArray());

    Tlv.setData(ident.language);
    Tlv.setType(0x0F);
    bArr.append(Tlv.toByteArray());

    Tlv.setData(ident.country);
    Tlv.setType(0x0E);
    bArr.append(Tlv.toByteArray());
    return bArr;
};

QByteArray createChangePassword(const QString &sNewPassword, const QString &ScreenName)
{
//    QStructMetaData metaData;
//    QByteArray baMetaData;
//    QByteArray baTemp;
//    baTemp.append(convertToLEByteArray(sNewPassword.length() + 1));
//    baTemp.append(sNewPassword);
//    baTemp.append((char) 0x00);
//    metaData.baData.append(baTemp);
//
//    baMetaData.append(convertToLEByteArray(10 + baTemp.size()));
//    baMetaData.append(convertUinToArray(ScreenName));
//
//    baMetaData.append((char) 0xD0);
//    baMetaData.append((char) 0x07);
//    baMetaData.append((char) 0x02);
//    baMetaData.append((char) 0x00);
//    baMetaData.append((char) 0x2E);
//    baMetaData.append((char) 0x04);
//    baMetaData.append(baTemp);
//
//    QTlv tlv1;
//    tlv1.setType(0x0001);
//    tlv1.setData(baMetaData);
//
//    QSnac snac1502;
//    snac1502.setFamilyId(0x0015);
//    snac1502.setSubType(0x0002);
//    snac1502.setFlags(0x0000);
//    snac1502.setReqId(0x00000000);
//    snac1502.setData(tlv1.toByteArray());
//    return snac1502.toByteArray();
}

