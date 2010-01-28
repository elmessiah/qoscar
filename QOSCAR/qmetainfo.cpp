#include "qmetainfo.h"

QByteArray QOSCARMetaData::toByteArray()
{
    QByteArray baResult;
    QByteArray baBody;
    for ( qint32 i = 0; i < 4; i++ )
        baBody.append((char) 0x00);
    baBody.append(u16ToBA(usDataType));
    baBody.append((char) 0x02);
    baBody.append((char) 0x00);
    baBody.append(u16ToBA(usDataSubType));
    baBody.append(baData);

    usDataSize = baBody.length();
    baResult.append(u16ToBA(usDataSize));
    baResult.append(baBody);
    return baResult;
}

QByteArray convertUinToArray(const QString &uin)
{
         quint32 tmpUin = uin.toUInt();
         QByteArray packet;
         packet[0] = tmpUin % 0x100;
         packet[1] = tmpUin % 0x10000 / 0x100;
         packet[2] = tmpUin % 0x1000000 / 0x10000;
         packet[3] = tmpUin / 0x1000000;
         return packet;
}

QByteArray createSend_Full_Info(const QString &basicNick,
                                 const QString &basicFirst,
                                 const QString &basicLast,
                                 const QString &basicEmail,
                                 const QString &publishEmail,
                                 const char country,
                                 const QString &basicCity,
                                 const QString &basicState,
                                 const QString &basicAddress,
                                 const char zip,
                                 const QString &basicPhone,
                                 const QString &basicFax,
                                 const QString &basicCell,
                                 const char moreCountry,
                                 const QString &moreCity,
                                 const QString &moreState,
                                 const char workCountry,
                                 const QString &workCity,
                                 const QString &workState,
                                 const char wzip,
                                 const QString &workPhone,
                                 const QString &workFax,
                                 const QString &workCell,
                                 const QString &workCompany,
                                 const quint16 workOccupation,
                                 const QString &workDepartment,
                                 const QString &workAddress,
                                 const QString &workPosition,
                                 const QString &workWebPage,
                                 const quint16 foundedGender,
                                 const QString &homepage,
                                 const quint16 moreBirthYear,
                                 const quint16 moreBirthMonth,
                                 const quint16 moreBirthDay,
                                 const quint16 moreLang1,
                                 const quint16 moreLang2,
                                 const quint16 moreLang3,
                                 const quint16 interCode1,
                                 const QString &interKeyWords1,
                                 const quint16 interCode2,
                                 const QString &interKeyWords2,
                                 const quint16 interCode3,
                                 const QString &interKeyWords3,
                                 const quint16 interCode4,
                                 const QString &interKeyWords4,
                                 const QString &about,
                                 const bool webAware,
                                 const bool authFlag,
                                 const QString &myUin,
                                 const quint16 flapReq)
{
    QByteArray packet;
    packet[0] = 0x2a;
    packet[1] = 0x02;
    packet.append(u16ToBA((quint16)flapReq));


    QByteArray metaData;

    metaData.append(u16ToBALE(myUin.length()));
    //metaData.append((quint16) myUin.length());
    metaData.append(myUin);
    QTlv nickTlv;
    nickTlv.setLe(true);
    nickTlv.setType(0x0154);
    QByteArray nickArray;
    nickArray.append(u16ToBALE((quint16)(basicNick.length() + 1)));
    nickArray.append(basicNick);
    nickArray.append(QChar(0x00));
    nickTlv.setData(nickArray);

    metaData.append(nickTlv.toByteArray());


    QTlv firstTlv;
    firstTlv.setLe(true);
    firstTlv.setType(0x0140);

    QByteArray firstArray;
    firstArray.append(u16ToBALE((quint16)(basicFirst.length() + 1)));
    firstArray.append(basicFirst);
    firstArray.append(QChar(0x00));

    firstTlv.setData(firstArray);

    metaData.append(firstTlv.toByteArray());


    QTlv lastTlv;
    lastTlv.setLe(true);
    lastTlv.setType(0x014a);

    QByteArray lastArray;
    lastArray.append(u16ToBALE((quint16)(basicLast.length() + 1)));
    lastArray.append(basicLast);
    lastArray.append(QChar(0x00));


    lastTlv.setData(lastArray);

    metaData.append(lastTlv.toByteArray());


    QTlv emailTlv;
    emailTlv.setType(0x015e);
    emailTlv.setLe(true);
    QByteArray mailArray;

    mailArray.append(u16ToBALE((quint16)(basicEmail.length() + 2)));
    mailArray.append(basicEmail);
    mailArray.append(QChar(0x00));
    mailArray.append(publishEmail);

    emailTlv.setData(mailArray);

    metaData.append(emailTlv.toByteArray());


    QTlv countryTlv;
    countryTlv.setType(0x01a4);
    countryTlv.setLe(true);
    countryTlv.setData(u16ToBALE(country));

    metaData.append(countryTlv.toByteArray());


    QTlv cityTlv;
    cityTlv.setLe(true);
    cityTlv.setType(0x0190);

    QByteArray cityArray;
    cityArray.append(u16ToBALE((quint16)(basicCity.length() + 1)));
    cityArray.append(basicCity);
    cityArray.append(QChar(0x00));


    cityTlv.setData(cityArray);

    metaData.append(cityTlv.toByteArray());

    QTlv stateTlv;
    stateTlv.setLe(true);
    stateTlv.setType(0x019a);

    QByteArray stateArray;
    stateArray.append(u16ToBALE((quint16)(basicState.length() + 1)));
    stateArray.append(basicState);
    stateArray.append(QChar(0x00));


    stateTlv.setData(stateArray);

    metaData.append(stateTlv.toByteArray());


    QTlv zipTlv;
    zipTlv.setType(0x026c);
    zipTlv.setLe(true);

    zipTlv.setData(convertUinToArray(&zip));

    metaData.append(zipTlv.toByteArray());


    QTlv phoneTlv;
    phoneTlv.setLe(true);
    phoneTlv.setType(0x0276);

    QByteArray phoneArray;
    phoneArray.append(u16ToBALE((quint16)(basicPhone.length() + 1)));
    phoneArray.append(basicPhone);
    phoneArray.append(QChar(0x00));


    phoneTlv.setData(phoneArray);

    metaData.append(phoneTlv.toByteArray());

    QTlv faxTlv;
    faxTlv.setLe(true);
    faxTlv.setType(0x0280);

    QByteArray faxArray;
    faxArray.append(u16ToBALE((quint16)(basicFax.length() + 1)));
    faxArray.append(basicFax);
    faxArray.append(QChar(0x00));


    faxTlv.setData(faxArray);

    metaData.append(faxTlv.toByteArray());

    QTlv cellTlv;
    cellTlv.setLe(true);
    cellTlv.setType(0x028a);

    QByteArray cellArray;
    cellArray.append(u16ToBALE((quint16)(basicCell.length() + 1)));
    cellArray.append(basicCell);
    cellArray.append(QChar(0x00));


    cellTlv.setData(cellArray);

    metaData.append(cellTlv.toByteArray());


    QTlv streetTlv;
    streetTlv.setLe(true);
    streetTlv.setType(0x0262);

    QByteArray streetArray;
    streetArray.append(u16ToBALE((quint16)(basicAddress.length() + 1)));
    streetArray.append(basicAddress);
    streetArray.append(QChar(0x00));


    streetTlv.setData(streetArray);

    metaData.append(streetTlv.toByteArray());




    QTlv mcountryTlv;
    mcountryTlv.setType(0x0334);
    mcountryTlv.setLe(true);
    mcountryTlv.setData(u16ToBALE(moreCountry));

    metaData.append(mcountryTlv.toByteArray());


    QTlv ocityTlv;
    ocityTlv.setLe(true);
    ocityTlv.setType(0x0320);

    QByteArray ocityArray;
    ocityArray.append(u16ToBALE((quint16)(moreCity.length() + 1)));
    ocityArray.append(moreCity);
    ocityArray.append(QChar(0x00));


    ocityTlv.setData(ocityArray);

    metaData.append(ocityTlv.toByteArray());


    QTlv ostateTlv;
    ostateTlv.setLe(true);
    ostateTlv.setType(0x032a);

    QByteArray ostateArray;
    ostateArray.append(u16ToBALE((quint16)(moreState.length() + 1)));
    ostateArray.append(moreState);
    ostateArray.append(QChar(0x00));


    ostateTlv.setData(ostateArray);

    metaData.append(ostateTlv.toByteArray());


    QTlv wcountryTlv;
    wcountryTlv.setType(0x02b2);
    wcountryTlv.setLe(true);
    wcountryTlv.setData(u16ToBALE(workCountry));

    metaData.append(wcountryTlv.toByteArray());


    QTlv wcityTlv;
    wcityTlv.setLe(true);
    wcityTlv.setType(0x029e);

    QByteArray wcityArray;
    wcityArray.append(u16ToBALE((quint16)(workCity.length() + 1)));
    wcityArray.append(workCity);
    wcityArray.append(QChar(0x00));


    wcityTlv.setData(wcityArray);

    metaData.append(wcityTlv.toByteArray());

    QTlv wstateTlv;
    wstateTlv.setLe(true);
    wstateTlv.setType(0x02a8);

    QByteArray wstateArray;
    wstateArray.append(u16ToBALE((quint16)(workState.length() + 1)));
    wstateArray.append(workState);
    wstateArray.append(QChar(0x00));


    wstateTlv.setData(wstateArray);

    metaData.append(wstateTlv.toByteArray());


            QTlv wzipTlv;
            wzipTlv.setType(0x02bc);
            wzipTlv.setLe(true);

            wzipTlv.setData(convertUinToArray(&wzip));

            metaData.append(wzipTlv.toByteArray());


            QTlv wphoneTlv;
            wphoneTlv.setLe(true);
            wphoneTlv.setType(0x02c6);

            QByteArray wphoneArray;
            wphoneArray.append(u16ToBALE((quint16)(workPhone.length() + 1)));
            wphoneArray.append(workPhone);
            wphoneArray.append(QChar(0x00));


            wphoneTlv.setData(wphoneArray);

            metaData.append(wphoneTlv.toByteArray());

            QTlv wfaxTlv;
            wfaxTlv.setLe(true);
            wfaxTlv.setType(0x02d0);

            QByteArray wfaxArray;
            wfaxArray.append(u16ToBALE((quint16)(workFax.length() + 1)));
            wfaxArray.append(workFax);
            wfaxArray.append(QChar(0x00));


            wfaxTlv.setData(wfaxArray);

            metaData.append(wfaxTlv.toByteArray());


            QTlv wstreetTlv;
            wstreetTlv.setLe(true);
            wstreetTlv.setType(0x0294);

            QByteArray wstreetArray;
            wstreetArray.append(u16ToBALE((quint16)(workAddress.length() + 1)));
            wstreetArray.append(workAddress);
            wstreetArray.append(QChar(0x00));


            wstreetTlv.setData(wstreetArray);

            metaData.append(wstreetTlv.toByteArray());

            QTlv companyTlv;
            companyTlv.setLe(true);
            companyTlv.setType(0x01ae);

            QByteArray companyArray;
            companyArray.append(u16ToBALE((quint16)(workCompany.length() + 1)));
            companyArray.append(workCompany);
            companyArray.append(QChar(0x00));


            companyTlv.setData(companyArray);

            metaData.append(companyTlv.toByteArray());




            QTlv occuptionTlv;
            occuptionTlv.setType(0x01cc);
            occuptionTlv.setLe(true);
            occuptionTlv.setData(u16ToBALE(workOccupation));

            metaData.append(occuptionTlv.toByteArray());


            QTlv depTlv;
            depTlv.setLe(true);
            depTlv.setType(0x01b8);

            QByteArray depArray;
            depArray.append(u16ToBALE((quint16)(workDepartment.length() + 1)));
            depArray.append(workDepartment);
            depArray.append(QChar(0x00));


            depTlv.setData(depArray);

            metaData.append(depTlv.toByteArray());


            QTlv positionTlv;
            positionTlv.setLe(true);
            positionTlv.setType(0x01c2);

            QByteArray positionArray;
            positionArray.append(u16ToBALE((quint16)(workPosition.length() + 1)));
            positionArray.append(workPosition);
            positionArray.append(QChar(0x00));


            positionTlv.setData(positionArray);

            metaData.append(positionTlv.toByteArray());

            QTlv websiteTlv;
            websiteTlv.setLe(true);
            websiteTlv.setType(0x02da);

            QByteArray websiteArray;
            websiteArray.append(u16ToBALE((quint16)(workWebPage.length() + 1)));
            websiteArray.append(workWebPage);
            websiteArray.append(QChar(0x00));


            websiteTlv.setData(websiteArray);

            metaData.append(websiteTlv.toByteArray());



            QTlv genderTlv;
            genderTlv.setType(0x017c);
            genderTlv.setLe(true);
            genderTlv.setData((quint8) foundedGender);
            metaData.append(genderTlv.toByteArray());

            QTlv homePageTlv;
            homePageTlv.setLe(true);
            homePageTlv.setType(0x0213);

            QByteArray homePageArray;
            homePageArray.append(u16ToBALE((quint16)(homepage.length() + 1)));
            homePageArray.append(homepage);
            homePageArray.append(QChar(0x00));


            homePageTlv.setData(homePageArray);

            metaData.append(homePageTlv.toByteArray());

            QTlv birthTlv;
            birthTlv.setType(0x023a);
            birthTlv.setLe(true);
            QByteArray birthDay;

            //if ( setBirth )
            //{
                    birthDay.append(u16ToBALE((quint16)moreBirthYear));
                    birthDay.append(u16ToBALE((quint16)moreBirthMonth));
                    birthDay.append(u16ToBALE((quint16)moreBirthDay));
            /*} else
            {
                    birthDay.append(convertu16ToBA((quint16)0x0000));
                    birthDay.append(convertu16ToBA((quint16)0x0000));
                    birthDay.append(convertu16ToBA((quint16)0x0000));
            }*/

            birthTlv.setData(birthDay);
            metaData.append(birthTlv.toByteArray());

            QTlv langTlv;
            langTlv.setType(0x0186);
            langTlv.setLe(true);

            langTlv.setData(u16ToBALE(moreLang1));


            metaData.append(langTlv.toByteArray());

            QTlv langTlv2;
            langTlv2.setType(0x0186);
            langTlv2.setLe(true);

            langTlv2.setData(u16ToBALE(moreLang2));


            metaData.append(langTlv2.toByteArray());

            QTlv langTlv3;
            langTlv3.setType(0x0186);
            langTlv3.setLe(true);

            langTlv3.setData(u16ToBALE(moreLang3));


            metaData.append(langTlv3.toByteArray());


            QTlv interest1Tlv;
            interest1Tlv.setLe(true);
            interest1Tlv.setType(0x01ea);

            QByteArray interst1Array;
            interst1Array.append(u16ToBALE((quint16)interCode1));
            interst1Array.append(u16ToBALE((quint16)(interKeyWords1.length() + 1)));
            interst1Array.append(interKeyWords1);
            interst1Array.append(QChar(0x00));


            interest1Tlv.setData(interst1Array);

            metaData.append(interest1Tlv.toByteArray());

            QTlv interest2Tlv;
            interest2Tlv.setLe(true);
            interest2Tlv.setType(0x01ea);

            QByteArray interst2Array;
            interst2Array.append(u16ToBALE((quint16)interCode2));
            interst2Array.append(u16ToBALE((quint16)(interKeyWords2.length() + 1)));
            interst2Array.append(interKeyWords2);
            interst2Array.append(QChar(0x00));


            interest2Tlv.setData(interst2Array);

            metaData.append(interest2Tlv.toByteArray());

            QTlv interest3Tlv;
            interest3Tlv.setLe(true);
            interest3Tlv.setType(0x01ea);

            QByteArray interst3Array;
            interst3Array.append(u16ToBALE((quint16)interCode3));
            interst3Array.append(u16ToBALE((quint16)(interKeyWords3.length() + 1)));
            interst3Array.append(interKeyWords3);
            interst3Array.append(QChar(0x00));


            interest3Tlv.setData(interst3Array);

            metaData.append(interest3Tlv.toByteArray());

            QTlv interest4Tlv;
            interest4Tlv.setLe(true);
            interest4Tlv.setType(0x01ea);

            QByteArray interst4Array;
            interst4Array.append(u16ToBALE((quint16)interCode4));
            interst4Array.append(u16ToBALE((quint16)(interKeyWords4.length() + 1)));
            interst4Array.append(interKeyWords4);
            interst4Array.append(QChar(0x00));


            interest4Tlv.setData(interst4Array);

            metaData.append(interest4Tlv.toByteArray());


            QTlv aboutTlv;
            aboutTlv.setLe(true);
            aboutTlv.setType(0x0258);

            QByteArray aboutArray;
            aboutArray.append(u16ToBALE((quint16)(about.length() + 1)));
            aboutArray.append(about);
            aboutArray.append(QChar(0x00));


            aboutTlv.setData(aboutArray);

            metaData.append(aboutTlv.toByteArray());

            QTlv authTlv;
            authTlv.setType(0x030c);
            authTlv.setLe(true);
            authTlv.setData((quint8)webAware);
            metaData.append(authTlv.toByteArray());

            QTlv webTlv;
            webTlv.setType(0x02f8);
            webTlv.setLe(true);
            webTlv.setData((quint8) !authFlag);
            metaData.append(webTlv.toByteArray());

            packet.append(u16ToBA((quint16)(26 + metaData.length())));
            QSnac snac1502;
            snac1502.setFamilyId(0x0015);
            snac1502.setSubType(0x0002);
            snac1502.setReqId(0x00000000);
            packet.append(snac1502.toByteArray());
            packet.append(u16ToBA((quint16)0x0001));
            packet.append(u16ToBA((quint16)(12 +metaData.length())));

            packet.append(u16ToBALE((quint16)(metaData.length() + 10 )));
            packet.append(convertUinToArray(myUin));
            packet.append(u16ToBA((quint16)0xd007));
            packet.append(u16ToBALE((quint16)0x0001));
            packet.append(u16ToBA((quint16)0x3a0c));
            packet.append(metaData);

    return packet;
}

QByteArray createIMD__REQUEST_AUTH_INFO(const QString &sSN,
                                         const bool webAware,
                                         const bool authFlag)
{
    QByteArray baResult, baMiddle;

    QTlv authTlv;
    authTlv.setType(0x030c);
    authTlv.setLe(true);
    authTlv.setData(u16ToBA((quint8)webAware));
    baMiddle.append(authTlv.toByteArray());

    QTlv webTlv;
    webTlv.setType(0x02f8);
    webTlv.setLe(true);
    webTlv.setData(u16ToBA((quint8)!authFlag));
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
    baResult.append(convertUinToArray(sSN));
    baResult.append(u16ToBA((quint16)0xd007));
    baResult.append(u16ToBALE((quint16)0x0001));
    baResult.append(u16ToBA((quint16)0x3a0c));
    baResult.append(baMiddle);
    return baResult;
}

QByteArray createSEND_BASIC_INFO(const QSNInfo &snInfo, const QString &sScreenName)
{

    QByteArray baResult;
    QStructMetaData metaData;
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
    baTmp.append(snInfo.usHomeCountry);
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
    Tlv017C.setData(snInfo.us8UserGender);

    baResult.append(Tlv017C.toByteArray());

    QTlv Tlv0172; // User Age
    Tlv0172.setType(0x0172);
    Tlv0172.setLe(true);
    Tlv0172.setData(u16ToBALE(snInfo.usUserAge));

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

    baTmp.append(u16ToBALE(snInfo.usBirthYear));
    baTmp.append(u16ToBALE(snInfo.usBirthMonth));
    baTmp.append(u16ToBALE(snInfo.usBirthDay));
    Tlv023A.setData(baTmp);
    baTmp.clear();

    baResult.append(Tlv023A.toByteArray());

    baMetaData.append(u16ToBALE(8 + baResult.size()));
    baMetaData.append(convertUinToArray(sScreenName));

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
