#ifndef QOSCARBA_H
#define QOSCARBA_H

#include <QByteArray>
#include <QString>

//! A class for a work with ICQ raw data
class QOscarBA : public QByteArray
{
    public:
	explicit QOscarBA();
	explicit QOscarBA(const quint8 data);
	explicit QOscarBA(const quint16 data);
	explicit QOscarBA(bool le, const quint16 data);
	explicit QOscarBA(const quint32 data);
	explicit QOscarBA(const QString &data);
	explicit QOscarBA(const QByteArray &ba);

	void addU8(const quint8 data = 0, const qint32 to = -1);
	void addU16(const quint16 data = 0, const qint32 to = -1);
	void addU32(const quint32 data = 0, const qint32 to = -1);
	void addU16LE(const quint16 data = 0, const qint32 to = -1);
	void addU32LE(const quint32 data = 0, const qint32 to = -1);
	void addString(const QString &data = QString(), const qint32 to = -1);
	void addSnLE(const QString &sn = QString(),const qint32 to = -1);

	quint8 readU8(const quint32 from = 0);
	quint16 readU16(const quint32 from = 0);
	quint32 readU32(const quint32 from = 0);
	quint16 readU16LE(const quint32 from = 0);
	quint32  readU32LE(const quint32 from = 0);

	QOscarBA inline readData(const quint32 from, const quint32 len);

	static QOscarBA fromStringLE(const QString &str = QString(), bool zero = true);
};

#endif // QOSCARBA_H
