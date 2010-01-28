#include "xstatus.h"

char caps[][16] = { {0x1A093C6CD7FD4EC59D51A6474E34F5A0},
                {0x0946134D4C7F11D18222444553540000},
                {0x094600004C7F11D18222444553540000},
                {0x0946134D4C7F11D18222444553540000},
                {0x094613434C7F11D18222444553540000},
                {0x0946134E4C7F11D18222444553540000},
                {0x0946134C4C7F11D18222444553540000},
                {0x563FC8090B6F41514950203230303561},
                {0x0946134D4C7F11D18222444553540000} };

char statuses[][16] = { {0x3FB0BD36AF3B4A609EEFCF190F6A5A7F} };

XStatus::XStatus()
{
    mapCapabilities.insert(QByteArray(caps[0], 16), "XTRAZ");
    mapCapabilities.insert(QByteArray(caps[1], 16), "AIM_INTEROPERATE");
    mapCapabilities.insert(QByteArray(caps[2], 16), "AVATAR");
    mapCapabilities.insert(QByteArray(caps[3], 16), "ICQ_SERVER_RELAY");
    mapCapabilities.insert(QByteArray(caps[4], 16), "AIM_SENDFILE");
    mapCapabilities.insert(QByteArray(caps[5], 16), "UTF8_MESSAGE");
    mapCapabilities.insert(QByteArray(caps[6], 16), "TYPE_NOTIFICATION");
    mapCapabilities.insert(QByteArray(caps[7], 16), "QIP_2005");
    mapCapabilities.insert(QByteArray(caps[8], 16), "AIM_IS_ICQ");

    mapXStatuses.insert(QByteArray(statuses[0], 16), "SMOKE");
}

sxStatus XStatus::getXStatus(const QByteArray &baData)
{
    sxStatus status;
    status.baCapability = baData;
    status.sName = mapXStatuses.value(baData, "ERROR");
    return status;
}
