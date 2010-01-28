#ifndef XSTATUS_H
#define XSTATUS_H

#include <QString>
#include <QMap>

struct sxStatus { QByteArray baCapability;
                 QString    sName,
                            sHeader,
                            sText; };

class XStatus
{
    public:
        XStatus();

        QString getCapabilityName(const QByteArray &baData) { return mapCapabilities.value(baData); }
        sxStatus getXStatus(const QByteArray &baData);

        sxStatus xStatus() const { return myXStatus; }

        void setXStatus(const sxStatus &status) { myXStatus = status; }

    private:
        sxStatus myXStatus;
        QMap<QByteArray, QString > mapCapabilities;
        QMap<QByteArray, QString > mapXStatuses;
};

#endif // XSTATUS_H
