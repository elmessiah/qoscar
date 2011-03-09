#include "qoscarfeedbag.h"


//! Request Roster
//! \return
//! \sa QOscarBA
QOscarBA QOscarFeedbag::createFEEDBAG__QUERY()
{
    return QSnac::toByteArray(0x13, 0x04, 0x00, 0x00010004, QOscarBA());
}

//! Parsing FEEDBAG packet
//! \param snac
//! \sa QSnac
void QOscarFeedbag::handlePacket(const QSnac &snac)
{
    QSnac tempSnac = snac;

    switch ( tempSnac.getType() ) {

	case 0x06:				    // Roster received
	    handleRosterPacket(tempSnac.data());
	    break;

	case 0x0B:
	    handleBuddyArrived(tempSnac.data());    // Buddy arrived
	    break;

	case 0x0C:
	    handleBuddyDeparted(tempSnac.data());   // Buddy departed
	    break;

	default:
	    break;
    }
}

//! Parsing BUDDY_ARRIVED packet
//! \param data
//! \sa QOscarBA
void QOscarFeedbag::handleBuddyArrived(const QOscarBA &data)
{
    if ( data.length() < 7 )
	return;

    QOscarBA ba(data);

    quint8 length = ba.readU8();
    if ( (length > 9) || (! length) )		// 9 digits max now
	return;

    QRosterEntry entry;
    entry.name = ba.mid(1, length);
    ba.remove(0, 1 + length);
    entry.warnLevel = ba.readU16();
    quint16 count = ba.readU16(2);  // TLV's count
    ba.remove(0, 4);

    for ( quint16 i = 0; i < count; i++ ) {
	QTlv tlv(ba);
	if ( ! tlv.isValid() )
	    break;

        switch ( tlv.getType() ) {

	    case 0x0006:	// Status
                if ( tlv.getLength() == 4 )
                    entry.status = tlv.getData().readU32();
		break;

	    default:	    // Another TLV's are not implemented yet
		break;

	}

        if ( (tlv.isLast()) || (tlv.getLength() + 4 > ba.length()) )
	    break;

        ba.remove(0, tlv.getLength() + 4);
    }
    emit onBuddyArrived(entry);
}

//! Parsing BUDDY_DEPARTED packet
//! \param data
//! \sa QOscarBA
void QOscarFeedbag::handleBuddyDeparted(const QOscarBA &data)
{
    if ( data.length() < 7 )
	return;

    QOscarBA ba(data);

    quint8 length = ba.readU8();
    if ( (length > 9) || (! length) )		// 9 digits max now
	return;

    QRosterEntry entry;
    entry.name = ba.mid(1, length);
    ba.remove(0, 1 + length);
    entry.warnLevel = ba.readU16();
    emit onBuddyDeparted(entry);
}

//! Parsing Roster packet part
//! \param data
//! \sa QOscarBA
void QOscarFeedbag::handleRosterPacket(const QOscarBA &data)
{
    if ( data.length() < 3 )
	return;

    QOscarBA ba(data);

    ba.remove(0, 8); // Fucking HACK!!
    quint16 count = ba.readU16(1);  // Items count
    ba.remove(0, 3);

    for ( quint16 i = 0; i < count; i++ ) {

	if ( ((quint32) ba.length()) < 5 * sizeof(quint16) )
	    break;

	QRosterEntry entry;

	quint16 length = ba.readU16();
	if ( length > 0 )
	    entry.name = ba.mid(2, length);

	if ( ba.length() < 10 + length )
	    break;

	ba.remove(0, 2 + length);
	entry.group = ba.readU16();
	entry.id = ba.readU16(2);
	entry.type = ba.readU16(4);
	length = ba.readU16(6);
	ba.remove(0, 8);

	if ( ba.length() < length )
	    break;

	QOscarBA tlvsBa(ba.mid(0, length));
	ba.remove(0, length);

	while ( ! tlvsBa.isEmpty() ) {

	    QTlv tlv(tlvsBa);
	    if ( ! tlv.isValid() )
		break;

            switch ( tlv.getType() ) {

		case 0x013A:			 // Buddy's phone number for sms (local)
                    entry.sms = tlv.getData();
		    break;

		case 0x013C:			 // Buddy's comment (local)
                    entry.comment = tlv.getData();
		    break;

		case 0x0137:			 // Buddy's email (local)
                    entry.email = tlv.getData();
		    break;

		case 0x0131:			// Buddy's nickname (local)
                    entry.nick = tlv.getData();
		    break;

		case 0x00C8:			// Items in group
                    for ( quint16 a = 0; a < tlv.getLength(); a += 2 )
                        entry.items.append(tlv.getData().readU16(a));
		    break;

		default:
		    break;
	    }

            if ( tlv.isLast() || (tlvsBa.length() < tlv.getLength() + 4) )
		break;

            tlvsBa.remove(0, tlv.getLength() + 4);
	}

	oscarRoster.append(entry);
    }

    emit onRosterReceived();
}

//! FEEDBAG_USE
//! \return
//! \sa QOscarBA
QOscarBA QOscarFeedbag::createFEEDBAG__USE()
{
    return QSnac::toByteArray(0x13, 0x07, 0x00, 0x00000007, QOscarBA());
}
