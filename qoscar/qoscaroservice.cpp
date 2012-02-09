#include "qoscaroservice.h"

//! Handle OSERVICE packet
//! \param data
//! \param type
//! \sa QOscarBA
void QOscarOService::handlePacket(const QOscarBA &data, quint16 type)
{
    switch ( type ) {
	case OSERVICE__HOST_ONLINE:			// Logged in
            //  \todo: parsing the "Server Capabilities"
	    emit serverCapabilities();
	    break;
    }

}

//! Creating List of Client-Services (SNAC-Attachment)
QOscarBA QOscarOService::createServiceList()
{
    QOscarBA ba;
    // Wireshark SIM-IM
    ba.append(createServiceInfo(OCAP_GENERIC    ,0x0004));
    ba.append(createServiceInfo(OCAP_SSI        ,0x0004));
    ba.append(createServiceInfo(OCAP_LOCATION   ,0x0001));
    ba.append(createServiceInfo(OCAP_BUDDIES    ,0x0001));
    ba.append(createServiceInfo(OCAP_ICQ        ,0x0001));
    ba.append(createServiceInfo(OCAP_ICBM       ,0x0001));
    ba.append(createServiceInfo(OCAP_INVITATION ,0x0001));
    ba.append(createServiceInfo(OCAP_PRIVACY    ,0x0001));
    ba.append(createServiceInfo(OCAP_USER_LOOKUP,0x0001));
    ba.append(createServiceInfo(OCAP_USAGE_STATS,0x0001));
    return ba;
}


//! Creating OSERVICE packet
//! \param family
//! \param famVersion
//! \param toolId
//! \param toolVersion
//! \return
//! \sa QOscarBA
QOscarBA QOscarOService::createPacket(quint16 family, quint16 famVersion, quint16 toolId, quint16 toolVersion)
{
    QOscarBA ba(family);
    ba.addU16(famVersion);
    ba.addU16(toolId);
    ba.addU16(toolVersion);
    return ba;
}


//! Creating OSERVCE__CLIENT_ONLINE packet
//! \return
//! \sa QOscarBA
QOscarBA QOscarOService::createOSERVICE__CLIENT_ONLINE()
{
    QOscarBA ba(createPacket(0x0001, 0x0004, 0x0110, 0x08E4));
    ba.append(createPacket(0x0013, 0x0004, 0x0110, 0x08E4));
    ba.append(createPacket(0x0002, 0x0004, 0x0110, 0x08E4));
    ba.append(createPacket(0x0003, 0x0004, 0x0110, 0x08E4));
    ba.append(createPacket(0x0015, 0x0004, 0x0110, 0x08E4));
    ba.append(createPacket(0x0004, 0x0004, 0x0110, 0x08E4));
    ba.append(createPacket(0x0006, 0x0004, 0x0110, 0x08E4));
    ba.append(createPacket(0x0009, 0x0004, 0x0110, 0x08E4));
    ba.append(createPacket(0x000A, 0x0004, 0x0110, 0x08E4));
    ba.append(createPacket(0x000B, 0x0004, 0x0110, 0x08E4));

    return QSnac::toByteArray(0x0001, 0x0002, 0x00, 0x00, ba);
}

//! Creating OSERVICE__SET_NICKINFO_FIELDS packet
//! \param status
//! \param statusFlags
//! \return
//! \sa QOscarBA
QOscarBA QOscarOService::createOSERVICE__SET_NICKINFO_FIELDS(quint16 status, quint16 statusFlags)
{
    QOscarBA ba(statusFlags);
    ba.addU16(status);
    return QSnac::toByteArray(0x0001, 0x001E, 0x00, 0x00, QTlv::toByteArray(0x0006, ba));
}

//! Creating a OService-Service-Info-Package
QOscarBA QOscarOService::createServiceInfo(quint16 service, quint16 version)
{
    QOscarBA ba;
    ba.addU16(service);
    ba.addU16(version);
    return ba;
}
