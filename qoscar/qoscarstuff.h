#ifndef QOSCARSTUFF_H
#define QOSCARSTUFF_H

#include <QMap>

#include "qoscarbasic.h"

enum QOscarError
{
    eNetwork,
    eLogonFailed,
    eServer,
    eRateLimit
};
enum QOscarState
{
    osOffline,
    osConnectingToBOS,
    osConnecting,
    osConnectedToBOS,
    osConnected,
    osError,
    osOnline
};

//! Array for roasting passwords
const quint8 QRoastArray[16] = { 0xF3, 0x26, 0x81, 0xC4, 0x39, 0x86,
				 0xDB, 0x92, 0x71, 0xA3, 0xB9, 0xE6, 0x53,
				 0x7A, 0x95, 0x7C };


/** *********************************** **/
/**	     Some constants		**/
/** *********************************** **/

//! META received type
const quint8 META_LAST          = 0xAE;
const quint8 META_GENERAL       = 0xC8;
const quint8 META_MORE          = 0xDC;
const quint8 META_MORE_EMAIL    = 0xEB;
const quint8 META_WORK          = 0xD2;
const quint8 META_ABOUT         = 0xE6;
const quint8 META_INTEREST      = 0xF0;

//! SNAC Groups
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


//! Typing notifications
const quint16 TYPING_BEGIN = 0x0002;
const quint16 TYPING_END   = 0x0000;

//! Identifiers
const quint8 FLAP_IDENT = 0x2A;

const quint16 TLV_BOS_IDENT     = 0x0005;
const quint16 TLV_COOKIE_IDENT  = 0x0006;


//! Connection types

const quint8 NEW_CHANNEL          = 0x01;
const quint8 SNAC_CHANNEL         = 0x02;
const quint8 FLAP_ERR_CHANNEL     = 0x03;
const quint8 CLOSE_CHANNEL        = 0x04;
const quint8 KEEP_ALIVE_CHANNEL   = 0x05;

//! Status Flags

const quint16 STATUS_WEBAWARE       = 0x0001;
const quint16 STATUS_SHOWIP         = 0x0002;
const quint16 STATUS_BIRTHDAY       = 0x0008;
const quint16 STATUS_WEBFRONT       = 0x0020;
const quint16 STATUS_DCDISABLED     = 0x0100;
const quint16 STATUS_DCAUTH         = 0x1000;
const quint16 STATUS_DCCONT         = 0x2000;

/** ********* **/
/** Statuses **/
/** ********* **/

//! Online statuses
const quint16 STATUS_ONLINE         = 0x0000;
const quint16 STATUS_AWAY           = 0x0001;
const quint16 STATUS_DND            = 0x0002;
const quint16 STATUS_NA             = 0x0004;
const quint16 STATUS_OCCUPIED       = 0x0010;
const quint16 STATUS_FREE4CHAT      = 0x0020;
const quint16 STATUS_INVISIBLE      = 0x0100;

//! Additional statuses
const quint16 STAUTS_EATING	    = 0x2001;
const quint16 STATUS_ANGRY	    = 0x3000;
const quint16 STATUS_DEPRESSION	    = 0x4000;
const quint16 STATUS_HOME	    = 0x5000;
const quint16 STATUS_WORK	    = 0x6000;

//! Statuses from QIP, work bad
const quint32 STATUS_QIP_HOME		= 0x10005000;
const quint32 STATUS_QIP_WORK		= 0x10006000;
const quint32 STATUS_QIP_DEPRESSION	= 0x10004000;
const quint32 STATUS_QIP_ANGRY		= 0x10003000;
const quint32 STATUS_QIP_EATING		= 0x10002001;
const quint32 STATUS_QIP_NA		= 0x10000004;
const quint32 STATUS_QIP_OCCUPIED	= 0x10000010;
const quint32 STATUS_QIP_DND		= 0x10000002;
const quint32 STATUS_QIP_INVISIBLE	= 0x10000100;


//! OSERVICE DCINFO TYPES
const quint8 DC_DISABLED                 = 0x00;
const quint8 DC_FIREWALL_PORT_USED       = 0x01;
const quint8 DC_FIREWALL_PORT_SOCKS_USED = 0x02;
const quint8 DC_NO_PORT_USED             = 0x03;
const quint8 DC_NO_FIREWALL              = 0x04;
const quint8 DC_FILL_PORT                = 0x05;
const quint8 DC_ONLY_SERVER              = 0x06;

//! DC Proto versions
const quint16 DCP_ICQ98     = 0x0004;
const quint16 DCP_ICQ99     = 0x0006;
const quint16 DCP_ICQ2000   = 0x0007;
const quint16 DCP_ICQ2001   = 0x0008;
const quint16 DCP_ICQLITE   = 0x0009;
const quint16 DCP_ICQ2003B  = 0x000A;

//! Message types
const quint8 MTYPE_PLAIN      = 0x01;
const quint8 MTYPE_CHAT       = 0x02;
const quint8 MTYPE_FILEREQ    = 0x03;
const quint8 MTYPE_URL        = 0x04;
const quint8 MTYPE_AUTHREQ    = 0x06;
const quint8 MTYPE_AUTHDENY   = 0x07;
const quint8 MTYPE_AUTHOK     = 0x08;
const quint8 MTYPE_SERVER     = 0x09;
const quint8 MTYPE_ADDED      = 0x0C;
const quint8 MTYPE_WWP        = 0x0D;
const quint8 MTYPE_EEXPRESS   = 0x0E;
const quint8 MTYPE_CONTACTS   = 0x13;
const quint8 MTYPE_PLUGIN     = 0x1A;
const quint8 MTYPE_AUTOAWAY   = 0xE8;
const quint8 MTYPE_AUTOBUSY   = 0xE9;
const quint8 MTYPE_AUTONA     = 0xEA;
const quint8 MTYPE_AUTODND    = 0xEB;
const quint8 MTYPE_AUTOFFC    = 0xEC;

//! Genders
const quint8 GENDER_NONE	= 0x00;
const quint8 GENDER_FEMALE	= 0x01;
const quint8 GENDER_MALE	= 0x02;


//! ROSTER Entries flags
const quint16 ENTRY_NORMAL	= 0x0000;   //!< Normal list entry
const quint16 ENTRY_VISIBLE	= 0x0002;   //!< Entry is in Visible list
const quint16 ENTRY_INVISIBLE	= 0x0003;   //!< Entry is in Invisible list
const quint16 ENTRY_IGNORE	= 0x000E;   //!< Entry is in Ignore list

//! MARITAL CONSTS
const quint8 MARITAL_NONE	= 0x00;	    //!< Not specefied
const quint8 MARITAL_SINGLE	= 0x0A;	    //!< Single
const quint8 MARITAL_LONGRS	= 0x0B;	    //!< Long relationship
const quint8 MARITAL_ENGAGED	= 0x0C;	    //!< Engaged
const quint8 MARITAL_MARRIED	= 0x14;	    //!< Married
const quint8 MARITAL_DIVORCED	= 0x1E;	    //!< Divorced
const quint8 MARITAL_SEPARATED	= 0x1F;	    //!< Separated
const quint8 MARITAL_WIDOWED	= 0x28;	    //!< Widowed

//! Buddy types
const quint16 BUDDY_NORMAL	= 0x0000;   //!< Normal buddy
const quint16 BUDDY_GROUP	= 0x0001;   //!< Group
const quint16 BUDDY_IGNORE	= 0x000E;   //!< Buddy is in Ignore list
const quint16 BUDDY_INVISIBLE	= 0x0003;   //!< Buddy is in Invisible list
const quint16 BUDDY_VISIBLE	= 0x0002;   //!< Buddy is in Visible list

//! SSL Errors
const quint16 ERRSSL_NOTFOUND	= 0x0002;   //!< User not found
const quint16 ERRSSL_EXISTS	= 0x0003;   //!< User already exists
const quint16 ERRSSL_AUTH	= 0x000E;   //!< User is not authorized
const quint16 ERRSSL_OTHER	= 0x000A;   //!< Other SSL error
const quint16 ERRSSL_NOERROR	= 0x0000;   //!< No error, that's ok



/** *************************************** **/
/**		UIDS			    **/
/** *************************************** **/

//! Clients
const QByteArray CAPS_CL_QIP2005	    = QByteArray::fromHex("563FC8090B6F41514950203230303561");
const QByteArray CAPS_CL_QIP_INFIUM	    = QByteArray::fromHex("7C737502C3BE4F3EA69F015313431E1A");
const QByteArray CAPS_CL_QIP_PDA_SYMBIAN    = QByteArray::fromHex("51ADD1907294473DA1A149F4A397A41F");
const QByteArray CAPS_CL_QIP_PDA_WINDOWS    = QByteArray::fromHex("563FC8090B6F41514950202020202021");
const QByteArray CAPS_CL_KOPETE		    = QByteArray::fromHex("4B6F70657465204943512020000C0001");
const QByteArray CAPS_CL_LICQ		    = QByteArray::fromHex("094913494C7F11D18222444553540000");
const QByteArray CAPS_CL_JIMM		    = QByteArray::fromHex("4A696D6D20302E352E31620000000000");
const QByteArray CAPS_CL_TRILLIAN	    = QByteArray::fromHex("F2E7C7F4F3AD4DFBB23536798BDF0000");
const QByteArray CAPS_CL_SIMM		    = QByteArray::fromHex("53494D20636C69656E74202000090480");
const QByteArray CAPS_CL_MACICQ		    = QByteArray::fromHex("DD16F20284E611D490DB0010DB9B4B7D");
const QByteArray CAPS_CL_ICQ6		    = QByteArray::fromHex("0138CA7B769A491588F213FC00979EA8");
const QByteArray CAPS_CL_MIRANDA_IM	    = QByteArray::fromHex("4D6972616E64614D0007070000030A0D");
const QByteArray CAPS_CL_MIRANDA2_IM	    = QByteArray::fromHex("4D6972616E64614D2222222233333333");

//! Capabilities
const QByteArray CAPS_XTRAZ		    = QByteArray::fromHex("1A093C6CD7FD4EC59D51A6474E34F5A0");
const QByteArray CAPS_TYPING_NOTIFICATIONS  = QByteArray::fromHex("563FC8090B6F41BD9F79422609DFA2F3");
const QByteArray CAPS_TZERS		    = QByteArray::fromHex("B2EC8F167C6F451BBD79DC58497888B9");
const QByteArray CAPS_UTF8		    = QByteArray::fromHex("0946134E4C7F11D18222444553540000");
const QByteArray CAPS_AVATAR		    = QByteArray::fromHex("094600004C7F11D18222444553540000");
const QByteArray CAPS_FILE_TRANSFER	    = QByteArray::fromHex("0946134C4C7F11D18222444553540000");
const QByteArray CAPS_QIP_PROTECTMSG	    = QByteArray::fromHex("D3D453198B32403BACC7D1A9E2B5813E");
const QByteArray CAPS_RTF_MESSAGES	    = QByteArray::fromHex("97B12751243C4334AD22D6ABF73F1492");
const QByteArray CAPS_LITE		    = QByteArray::fromHex("178C2D9BDAA545BB8DDBF3BDBD53A10A");

//! X-STATUSES
const QByteArray X_ANGRY	= QByteArray::fromHex("01D8D7EEAC3B492AA58DD3D877E66B92");
const QByteArray X_BATH		= QByteArray::fromHex("01D8D7EEAC3B492AA58DD3D877E66B92");
const QByteArray X_TIRED	= QByteArray::fromHex("83C9B78E77E74378B2C5FB6CFCC35BEC");
const QByteArray X_PARTY	= QByteArray::fromHex("E601E41C33734BD1BC06811D6C323D81");
const QByteArray X_BEER		= QByteArray::fromHex("8C50DBAE81ED4786ACCA16CC3213C7B7");
const QByteArray X_THINKING	= QByteArray::fromHex("3FB0BD36AF3B4A609EEFCF190F6A5A7F");
const QByteArray X_EATING	= QByteArray::fromHex("F8E8D7B282C4414290F810C6CE0A89A6");
const QByteArray X_TV		= QByteArray::fromHex("80537DE2A4674A76B3546DFD075F5EC6");
const QByteArray X_MEETING	= QByteArray::fromHex("F18AB52EDC57491D99DC6444502457AF");
const QByteArray X_COFFEE	= QByteArray::fromHex("1B78AE31FA0B4D3893D1997EEEAFB218");
const QByteArray X_MUSIC	= QByteArray::fromHex("61BEE0DD8BDD475D8DEE5F4BAACF19A7");
const QByteArray X_BUSINESS	= QByteArray::fromHex("488E14898ACA4A0882AA77CE7A165208");
const QByteArray X_SHOOTING	= QByteArray::fromHex("107A9A1812324DA4B6CD0879DB780F09");
const QByteArray X_FUN		= QByteArray::fromHex("6F4930984F7C4AFFA27634A03BCEAEA7");
const QByteArray X_PHONE	= QByteArray::fromHex("1292E5501B644F66B206B29AF378E48D");
const QByteArray X_GAMING	= QByteArray::fromHex("D4A611D08F014EC09223C5B6BEC6CCF0");
const QByteArray X_STUDYING	= QByteArray::fromHex("609D52F8A29A49A6B2A02524C5E9D260");
const QByteArray X_SHOPPING	= QByteArray::fromHex("63627337A03F49FF80E5F709CDE0A4EE");
const QByteArray X_SICK		= QByteArray::fromHex("1F7A4071BF3B4E60BC324C5787B04CF1");
const QByteArray X_SLEEPING	= QByteArray::fromHex("785E8C4840D34C65886F04CF3F3F43DF");
const QByteArray X_SURFING	= QByteArray::fromHex("A6ED557E6BF744D4A5D4D2E7D95CE81F");
const QByteArray X_BROWSING	= QByteArray::fromHex("12D07E3EF885489E8E97A72A6551E58D");
const QByteArray X_WORKING	= QByteArray::fromHex("BA74DB3E9E24434B87B62F6B8DFEE50F");
const QByteArray X_TYPING	= QByteArray::fromHex("634F6BD8ADD24AA1AAB9115BC26D05A1");
const QByteArray X_PICNIC	= QByteArray::fromHex("2CE0E4E57C6443709C3A7A1CE878A7DC");
const QByteArray X_COOKING	= QByteArray::fromHex("101117C9A3B040F981AC49E159FBD5D4");
const QByteArray X_SMOKING	= QByteArray::fromHex("160C60BBDD4443F39140050F00E6C009");
const QByteArray X_HIGH		= QByteArray::fromHex("6443C6AF22604517B58CD7DF8E290352");
const QByteArray X_WC		= QByteArray::fromHex("16F5B76FA9D240358CC5C084703C98FA");
const QByteArray X_TOBEORNOT	= QByteArray::fromHex("631436ff3f8a40d0a5cb7b66e051b364");
const QByteArray X_PRO7		= QByteArray::fromHex("B70867F538254327A1FFCF4CC1939797");
const QByteArray X_LOVE		= QByteArray::fromHex("DDCF0EA971954048A9C6413206D6F280");
const QByteArray X_RUSEARCH	= QByteArray::fromHex("D4E2B0BA334E4FA598D0117DBF4D3CC8");
const QByteArray X_RULOVE	= QByteArray::fromHex("CD5643A2C94C4724B52CDC0124A1D0CD");
const QByteArray X_RUJOURNAL	= QByteArray::fromHex("0072D9084AD143DD91996F026966026F");


/** ************************** **/
/**	  COUNTRIES	       **/
/** ************************* **/

typedef QMap<quint16, QString> oscarMap;

/** ****************************************** **/
/**		 Error codes		       **/
/** ****************************************** **/

//! SNAC ERRORS
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

//! OTHER
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

/** *********************************** **/
/**		 ICBM			**/
/** *********************************** **/

//! ICBM ERRORS
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

//! ICBM CHANNELS
const quint16 IM            = 0x0001;
const quint16 RENDEZVOUS    = 0x0002;
const quint16 CHAT          = 0x0003;
const quint16 GAIMING       = 0x000D;

//! ICBM PARAMETER FLAGS
const quint32 CHANNEL_MSGS_ALLOWED  = 0x00000001;
const quint32 MISSED_CALLS_ENABLED  = 0x00000002;
const quint32 EVENTS_ALLOWED        = 0x00000008;
const quint32 SMS_SUPPORTED         = 0x00000010;
const quint32 SMS_LEGAL_TEXT_SUPP   = 0x00000020; //!< SMS EULA ACCEPTED!!!!
const quint32 SMS_SEGMENTS_SUPP     = 0x00000040;
const quint32 CHAT_SUPPORTED        = 0x00000080;
const quint32 OFFLINE_MSGS_ALLOWED  = 0x00000100;
const quint32 SIP_CHANNEL_SUPPORTED = 0x00000200;

//! ICBM EVENTS
const quint8 NONE       = 0x00;
const quint8 TYPED      = 0x01;
const quint8 TYPING     = 0x02;
const quint8 RESERVED   = 0x03;
const quint8 CLOSED     = 0x0F; //!< CLOSED MESSAGE TAB

//! OSERVICE TYPES
const quint16 OSERVICE__HOST_ONLINE	= 0x0003;



/** ************************************** **/
/**	    FUNCTIONS			   **/
/** ************************************** **/

oscarMap countries();
oscarMap pasts();
oscarMap occupations();
oscarMap languages();
oscarMap interests();
oscarMap organizations();
oscarMap maritals();
quint16 countryCodeByName(const QString &name);
quint16 pastsCodeByName(const QString &name);
quint16 occupationCodeByName(const QString &name);
quint16 languageCodeByName(const QString &name);
quint16 interestCodeByName(const QString &name);
quint16 organizationCodeByName(const QString &name);
quint16 maritalCodeByName(const QString &name);
QString countryNameByCode(quint16 code);
QString pastsNameByCode(quint16 code);
QString occupationNameByCode(quint16 code);
QString languageNameByCode(quint16 code);
QString interestNameByCode(quint16 code);
QString organizationNameByCode(quint16 code);
QString maritalNameByCode(quint16 code);


#endif // QOSCARSTUFF_H
