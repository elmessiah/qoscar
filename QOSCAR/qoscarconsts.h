// QOSCAR constants
#ifndef OSCARCONST_H
#define OSCARCONST_H

#include <QString>

/* Error types */
enum QErrorType {qeConnection, qeServer, qeRateLimited, qeBadPass, qeOther};

/* Array for roasting passwords */
const unsigned char QRoastArray[16] = {0xF3, 0x26, 0x81, 0xC4, 0x39, 0x86,
                                       0xDB, 0x92, 0x71, 0xA3, 0xB9, 0xE6, 0x53,
                                       0x7A, 0x95, 0x7C};

/* Statuses */
enum QStatus {Q_OFFLINE, Q_CONNECTING, Q_CONNECTED, Q_LOGGING_OFF,
              Q_CONNECTING_TO_BOS, Q_ONLINE};

/***************************************/
/* Some constants */
/***************************************/

/* META received type */
const qint8 META_LAST          = 0xAE;
const qint8 META_GENERAL       = 0xC8;
const qint8 META_MORE          = 0xDC;
const qint8 META_MORE_EMAIL    = 0xEB;
const qint8 META_WORK          = 0xD2;
const qint8 META_ABOUT         = 0xE6;
const qint8 META_INTEREST      = 0xF0;

/* SNAC Groups */
const quint16 FOODGROUP_OSERVICE    = 0x0001;
const quint16 FOODGROUP_LOCATE      = 0x0002;
const quint16 FOODGROUP_BUDDY       = 0x0003;
const quint16 FOODGROUP_ICBM        = 0x0004;
const quint16 FOODGROUP_ADS         = 0x0005;
const quint16 FOODGROUP_INVITE      = 0x0006;
const quint16 FOODGROUP_ADMIN       = 0x0007;
const quint16 FOODGROUP_POPUP       = 0x0008;
const quint16 FOODGROUP_PD          = 0x0009;
const quint16 FOODGROUP_LOOKUP      = 0x000A;
const quint16 FOODGROUP_STATS       = 0x000B;
const quint16 FOODGROUP_ROOM        = 0x000D;
const quint16 FOODGROUP_CHAT        = 0x000E;
const quint16 FOODGROUP_BART        = 0x0010;
const quint16 FOODGROUP_FEEDBAG     = 0x0013;
const quint16 FOODGROUP_MDIR        = 0x0015;
const quint16 FOODGROUP_BUCP        = 0x0017;


/* Typing notifications */
const quint16 TYPING_BEGIN = 0x0002;
const quint16 TYPING_END   = 0x0000;

/* Identifiers */

const char FLAP_IDENT = 0x2A;

const quint16 TLV_BOS_IDENT     = 0x0005;
const quint16 TLV_COOKIE_IDENT  = 0x0006;


/* Connection types */

const char NEW_CHANNEL          = 0x01;
const char SNAC_CHANNEL         = 0x02;
const char FLAP_ERR_CHANNEL     = 0x03;
const char CLOSE_CHANNEL        = 0x04;
const char KEEP_ALIVE_CHANNEL   = 0x05;

/* Status Flags */

const quint16 STATUS_WEBAWARE       = 0x0001;
const quint16 STATUS_SHOWIP         = 0x0002;
const quint16 STATUS_BIRTHDAY       = 0x0008;
const quint16 STATUS_WEBFRONT       = 0x0020;
const quint16 STATUS_DCDISABLED     = 0x0100;
const quint16 STATUS_DCAUTH         = 0x1000;
const quint16 STATUS_DCCONT         = 0x2000;

/* Statuses */

const quint16 STATUS_ONLINE         = 0x0000;
const quint16 STATUS_AWAY           = 0x0001;
const quint16 STATUS_DND            = 0x0002;
const quint16 STATUS_NA             = 0x0004;
const quint16 STATUS_OCCUPIED       = 0x0010;
const quint16 STATUS_FREE4CHAT      = 0x0020;
const quint16 STATUS_INVISIBLE      = 0x0100;

/* OSERVICE DCINFO TYPES */
const quint8 DC_DISABLED                 = 0x00;
const quint8 DC_FIREWALL_PORT_USED       = 0x01;
const quint8 DC_FIREWALL_PORT_SOCKS_USED = 0x02;
const quint8 DC_NO_PORT_USED             = 0x03;
const quint8 DC_NO_FIREWALL              = 0x04;
const quint8 DC_FILL_PORT                = 0x05;
const quint8 DC_ONLY_SERVER              = 0x06;

/* DC Proto versions */

const quint16 DCP_ICQ98     = 0x0004;
const quint16 DCP_ICQ99     = 0x0006;
const quint16 DCP_ICQ2000   = 0x0007;
const quint16 DCP_ICQ2001   = 0x0008;
const quint16 DCP_ICQLITE   = 0x0009;
const quint16 DCP_ICQ2003B  = 0x000A;

/* Message types */

const char MTYPE_PLAIN      = 0x01;
const char MTYPE_CHAT       = 0x02;
const char MTYPE_FILEREQ    = 0x03;
const char MTYPE_URL        = 0x04;
const char MTYPE_AUTHREQ    = 0x06;
const char MTYPE_AUTHDENY   = 0x07;
const char MTYPE_AUTHOK     = 0x08;
const char MTYPE_SERVER     = 0x09;
const char MTYPE_ADDED      = 0x0C;
const char MTYPE_WWP        = 0x0D;
const char MTYPE_EEXPRESS   = 0x0E;
const char MTYPE_CONTACTS   = 0x13;
const char MTYPE_PLUGIN     = 0x1A;
const char MTYPE_AUTOAWAY   = 0xE8;
const char MTYPE_AUTOBUSY   = 0xE9;
const char MTYPE_AUTONA     = 0xEA;
const char MTYPE_AUTODND    = 0xEB;
const char MTYPE_AUTOFFC    = 0xEC;

/* UUIDs */



/******************/
/* Error codes */
/****************/

/* SNAC ERRORS */
const quint16 INVALID_SNAC              = 0x0001;
const quint16 RATE_TO_HOST              = 0x0002;
const quint16 RATE_TO_CLIENT            = 0x0003;
const quint16 NOT_LOGGED_ON             = 0x0004;
const quint16 SERVICE_UNAVAILABLE       = 0x0005;
const quint16 SERVICE_NOT_DEFINED       = 0x0006;
const quint16 OBSOLETE_SNAC             = 0x0007;
const quint16 NOT_SUPPORTED_BY_HOST     = 0x0008;
const quint16 NOT_SUPPORTED_BY_CLIENT   = 0x0009;
const quint16 REFUSED_BY_CLIENT         = 0x000A;
const quint16 REPLY_TOO_BIG             = 0x000B;
const quint16 RESPONSES_LOST            = 0x000C;
const quint16 REQUEST_DENIED            = 0x000D;
const quint16 BUSTED_SNAC_PAYLOAD       = 0x000E;
const quint16 INSUFFICIENT_RIGHTS       = 0x000F;
const quint16 IN_LOCAL_PERMIT_DENY      = 0x0010;
const quint16 TOO_EVIL_SENDER           = 0x0011;
const quint16 TOO_EVIL_RECEIVER         = 0x0012;
const quint16 USER_TEMP_UNAVAIL         = 0x0013;
const quint16 NO_MATCH                  = 0x0014;
const quint16 LIST_OVERFLOW             = 0x0015;
const quint16 REQUEST_AMBIGOUS          = 0x0016;
const quint16 QUEUE_FULL                = 0x0017;
const quint16 NOT_WHILE_ON_AOL          = 0x0018;
const quint16 QUERY_FAIL                = 0x0019;
const quint16 TIMEOUT                   = 0x001A;
const quint16 ERROR_TEXT                = 0x001B;
const quint16 GENERAL_FAILURE           = 0x001C;
const quint16 PROGRESS                  = 0x001D;
const quint16 IN_FREE_AREA              = 0x001E;
const quint16 RESTRICTED_BY_PC          = 0x001F;
const quint16 REMOTE_RESTRICTED_BY_PC   = 0x0020;

/* OTHER */

const quint16 ERROR_PAGE = 0x0004;
const quint16 AUTH_ERROR = 0x0008;

const quint16 INVALID_NICK_OR_PASSWORD          = 0x0001;
const quint16 SERVICE_TEMP_ANAVAILABLE          = 0x0002;
const quint16 OTHER                             = 0x0003;
const quint16 INCORRECT_NICK_OR_PASSWORD        = 0x0004;
const quint16 MISMATCH_NICK_OR_PASSWORD         = 0x0005;
const quint16 INTERNAL_CLIENT_ERROR             = 0x0006;
const quint16 INVALID_ACCOUNT                   = 0x0007;
const quint16 DELETED_ACCOUNT                   = 0x0008;
const quint16 EXPIRED_ACCOUNT                   = 0x0009;
const quint16 NO_ACCESS_TO_DB                   = 0x000A;
const quint16 NO_ACCESS_TO_RESOLVER             = 0x000B;
const quint16 INVALID_DB_FIELDS                 = 0x000C;
const quint16 BAD_DB_STATUS                     = 0x000D;
const quint16 BAD_RESOLVER_STATUS               = 0x000E;
const quint16 INTERNAL_ERROR                    = 0x000F;
const quint16 SERVICE_TEMP_OFFLINE              = 0x0010;
const quint16 SUSPENDED_ACCOUNT                 = 0x0011;
const quint16 DB_SEND_ERROR                     = 0x0012;
const quint16 DB_LINK_ERROR                     = 0x0013;
const quint16 RESERVATION_MAP_ERROR             = 0x0014;
const quint16 RESERVATION_LINK_ERROR            = 0x0015;
const quint16 MAX_NUMS_FROM_IP                  = 0x0016;
const quint16 MAX_NUM_FROM_IP_RESERV            = 0x0017;
const quint16 RATE_LIMIT_EXCEEDED_RESERVATION   = 0x0018;
const quint16 TOO_HEAVELY_WARNED                = 0x0019;
const quint16 RESERVATION_TIMEOUT               = 0x001A;
const quint16 CLIENT_UPDATE_REQUIRED            = 0x001B;
const quint16 CLIENT_UPDATE_RECOMMENDED         = 0x001C;
const quint16 RATE_LIMIT_EXCEEDED               = 0x001D;
const quint16 CANNOT_REGISTER                   = 0x001E;
const quint16 INVALID_SECURID                   = 0x0020;
const quint16 SUSPENDED_BY_AGE                  = 0x0022;

/********/
/* ICBM */
/********/

/* ICBM ERRORS */
//const quint16 REMOTE_RESTRICTED_BY_PC   = 0x0002;
const quint16 NEED_SMS_LEGAL_TO_SEND    = 0x0003;
const quint16 SMS_WITHOUT_DISCLAIMER    = 0x0004;
const quint16 SMS_COUNTRY_NOT_ALLOWED   = 0x0005;
const quint16 SMS_UNKNOWN_COUNTRY       = 0x0008;
const quint16 CANNOT_INITIATE_IM        = 0x0009;
const quint16 IM_NOT_ALLOWED            = 0x000A;
const quint16 CANNOT_IM_USAGE_LIMITED   = 0x000B;
const quint16 CANNOT_IM_DUSAGE_LIMITED  = 0x000C;
const quint16 CANNOT_IM_MUSAGE_LIMITED  = 0x000D;
const quint16 OFFLINE_IM_NOT_ACCEPTED   = 0x000E;
const quint16 OFFLINE_IM_EXCEED_MAX     = 0x000F;

/* ICBM CHANNELS */
const quint16 IM            = 0x0001;
const quint16 RENDEZVOUS    = 0x0002;
const quint16 CHAT          = 0x0003;
const quint16 GAIMING       = 0x000D;

/* ICBM PARAMETER FLAGS */
const quint32 CHANNEL_MSGS_ALLOWED  = 0x00000001;
const quint32 MISSED_CALLS_ENABLED  = 0x00000002;
const quint32 EVENTS_ALLOWED        = 0x00000008;
const quint32 SMS_SUPPORTED         = 0x00000010;
const quint32 SMS_LEGAL_TEXT_SUPP   = 0x00000020; // SMS EULA ACCEPTED!!!!
const quint32 SMS_SEGMENTS_SUPP     = 0x00000040;
const quint32 CHAT_SUPPORTED        = 0x00000080;
const quint32 OFFLINE_MSGS_ALLOWED  = 0x00000100;
const quint32 SIP_CHANNEL_SUPPORTED = 0x00000200;

/* ICBM EVENTS */
const quint8 NONE       = 0x00;
const quint8 TYPED      = 0x01;
const quint8 TYPING     = 0x02;
const quint8 RESERVED   = 0x03;
const quint8 CLOSED     = 0x0F; // CLOSED MESSAGE TAB


#endif
