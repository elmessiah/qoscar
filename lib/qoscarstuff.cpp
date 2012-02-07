#include "qoscarstuff.h"

/* Returns map with countries */ // May be static?
oscarMap countries()
{
    oscarMap map;

    map.insert(1, "USA");
    map.insert(7, "Russia");
    map.insert(20, "Egypt");
    map.insert(27, "South Africa");
    map.insert(30, "Greece");
    map.insert(31, "Netherlands");
    map.insert(32, "Belgium");
    map.insert(33, "France");
    map.insert(34, "Spain");
    map.insert(36, "Hungary");
    map.insert(39, "Italy");
    map.insert(40, "Romania");
    map.insert(41, "Switzerland");
    map.insert(42, "Chech Republic");
    map.insert(43, "Austria");
    map.insert(44, "United Kingdoms");
    map.insert(45, "Denmark");
    map.insert(46, "Sweden");
    map.insert(47, "Norway");
    map.insert(48, "Poland");
    map.insert(49, "Germany");
    map.insert(51, "Peru");
    map.insert(52, "Mexico");
    map.insert(53, "Cuba");
    map.insert(54, "Argentina");
    map.insert(55, "Brazil");
    map.insert(56, "Chile");
    map.insert(57, "Colombia");
    map.insert(58, "Venezuela");
    map.insert(60, "Malaysia");
    map.insert(61, "Australia");
    map.insert(62, "Indonesia");
    map.insert(63, "Philippines");
    map.insert(64, "New Zealand");
    map.insert(65, "Singapore");
    map.insert(66, "Thailand");
    map.insert(81, "Japan");
    map.insert(82, "Korea (republic of)");
    map.insert(84, "Vietnam");
    map.insert(86, "China");
    map.insert(90, "Turkey");
    map.insert(91, "India");
    map.insert(92, "Pakistan");
    map.insert(93, "Afganistan");
    map.insert(94, "Sri Lanka");
    map.insert(95, "Myanmar");
    map.insert(98, "Iran");
    map.insert(101, "Anguilla");
    map.insert(102, "Antigua");
    map.insert(103, "Bahamas");
    map.insert(104, "Barbados");
    map.insert(105, "Bermuda");
    map.insert(106, "British Virgin Islands");
    map.insert(107, "Canada");
    map.insert(108, "Cayman Islands");
    map.insert(109, "Dominica");
    map.insert(110, "Dominican Republic");
    map.insert(111, "Grenada");
    map.insert(112, "Jamaica");
    map.insert(113, "Montserrat");
    map.insert(114, "Nevis");
    map.insert(115, "St. Kitts");
    map.insert(116, "St. Vincent and the Grenadines");
    map.insert(117, "Trinidad and Tobago");
    map.insert(118, "Turks and Caicos Islands");
    map.insert(120, "Barbuda");
    map.insert(121, "Puerto Rico");
    map.insert(122, "Saint Lucia");
    map.insert(123, "United States Virgin Islands");
    map.insert(212, "Morocco");
    map.insert(213, "Algeria");
    map.insert(216, "Tunisia");
    map.insert(218, "Libya");
    map.insert(220, "Gambia");
    map.insert(221, "Senegal Republic");
    map.insert(222, "Mauritania");
    map.insert(223, "Mali");
    map.insert(224, "Guinea");
    map.insert(225, "Ivory Coast");
    map.insert(226, "Burkina Faso");
    map.insert(227, "Niger");
    map.insert(228, "Togo");
    map.insert(229, "Benin");
    map.insert(230, "Mauritius");
    map.insert(231, "Liberia");
    map.insert(232, "Sierra Leone");
    map.insert(233, "Ghana");
    map.insert(234, "Nigeria");
    map.insert(235, "Chad");
    map.insert(236, "Central African Republic");
    map.insert(237, "Cameroon");
    map.insert(238, "Cape Verde Islands");
    map.insert(239, "Sao Tome and Principe");
    map.insert(240, "Equatorial Guinea");
    map.insert(241, "Gabon");
    map.insert(242, "Congo");
    map.insert(243, "Dem. Rep. of Congo");
    map.insert(244, "Angola");
    map.insert(245, "Guinea-Bissau");
    map.insert(246, "Diego Garcia");
    map.insert(247, "Ascension Island");
    map.insert(248, "Seychelle Islands");
    map.insert(249, "Sudan");
    map.insert(250, "Rwanda");
    map.insert(251, "Ethiopia");
    map.insert(252, "Somalia");
    map.insert(253, "Djibouti");
    map.insert(254, "Kenya");
    map.insert(255, "Tanzania");
    map.insert(256, "Uganda");
    map.insert(257, "Burundi");
    map.insert(258, "Mozambique");
    map.insert(260, "Zambia");
    map.insert(261, "Madagascar");
    map.insert(262, "Reunion Island");
    map.insert(263, "Zimbabwe");
    map.insert(264, "Namibia");
    map.insert(265, "Malawi");
    map.insert(266, "Lesotho");
    map.insert(267, "Botswana");
    map.insert(268, "Swaziland");
    map.insert(269, "Mayotte Island");
    map.insert(290, "St. Helena");
    map.insert(291, "Eritrea");
    map.insert(297, "Aruba");
    map.insert(298, "Faeroe Islands");
    map.insert(299, "Greenland");
    map.insert(350, "Gibraltar");
    map.insert(351, "Portugal");
    map.insert(352, "Luxembourg");
    map.insert(353, "Ireland");
    map.insert(354, "Iceland");
    map.insert(355, "Albania");
    map.insert(356, "Malta");
    map.insert(357, "Cyprus");
    map.insert(358, "Finland");
    map.insert(359, "Bulgaria");
    map.insert(370, "Lithuania");
    map.insert(371, "Latvia");
    map.insert(372, "Estonia");
    map.insert(373, "Moldova");
    map.insert(374, "Armenia");
    map.insert(375, "Belarus");
    map.insert(376, "Andorra");
    map.insert(377, "Monaco");
    map.insert(378, "San Marino");
    map.insert(379, "Vatican City");
    map.insert(380, "Ukraine");
    map.insert(381, "Yugoslavia");
    map.insert(385, "Croatia");
    map.insert(386, "Slovania");
    map.insert(387, "Bosnia and Herzegovina");
    map.insert(389, "F.Y.R.O.M.");
    map.insert(500, "Falkland Islands");
    map.insert(501, "Belize");
    map.insert(502, "Guatemala");
    map.insert(503, "El Salvador");
    map.insert(504, "Honduras");
    map.insert(505, "Nicaragua");
    map.insert(506, "Costa Rica");
    map.insert(507, "Panama");
    map.insert(508, "St. Pierre and Miquelon");
    map.insert(509, "Haiti");
    map.insert(590, "Guadeloupe");
    map.insert(591, "Bolivia");
    map.insert(592, "Guyana");
    map.insert(593, "Ecuador");
    map.insert(594, "French Guiana");
    map.insert(595, "Paraguay");
    map.insert(596, "Martinique");
    map.insert(597, "Suriname");
    map.insert(598, "Uruguay");
    map.insert(599, "Netherlands Antilles");
    map.insert(670, "Saipan Island");
    map.insert(671, "Guam");
    map.insert(672, "Christmas Island");
    map.insert(673, "Brunei");
    map.insert(674, "Nauru");
    map.insert(675, "Papua New Guinea");
    map.insert(676, "Tonga");
    map.insert(677, "Solomon Islands");
    map.insert(678, "Vanuatu");
    map.insert(679, "Fiji Islands");
    map.insert(680, "Palau");
    map.insert(681, "Wallis and Futuna Islands");
    map.insert(682, "Cook Islands");
    map.insert(683, "Niue");
    map.insert(684, "American Samoa");
    map.insert(685, "Western Samoa");
    map.insert(686, "Kiribati Republic");
    map.insert(687, "New Caledonia");
    map.insert(688, "Tuvalu");
    map.insert(689, "French Polynesia");
    map.insert(690, "Tokelau");
    map.insert(691, "Micronesia, Federated States of");
    map.insert(692, "Marshall Islands");
    map.insert(705, "Kazakhstan");
    map.insert(706, "Kyrgyz Republic");
    map.insert(708, "Tajikistan");
    map.insert(709, "Turkmenistan");
    map.insert(711, "Uzbekistan");
    map.insert(800, "Int. Freephone Service");
    map.insert(850, "Korea (North)");
    map.insert(852, "Hong Kong");
    map.insert(853, "Macau");
    map.insert(855, "Cambodia");
    map.insert(856, "Laos");
    map.insert(870, "INMARSAT");
    map.insert(871, "INMARSAT (Atlantic-East)");
    map.insert(872, "INMARSAT (Pacific)");
    map.insert(873, "INMARSAT (Indian)");
    map.insert(874, "INMARSAT (Atlantic-West)");
    map.insert(880, "Bsangladesh");
    map.insert(886, "Taiwan, Rep. of China");
    map.insert(960, "Maldives");
    map.insert(961, "Lebanon");
    map.insert(962, "Jordan");
    map.insert(963, "Syria");
    map.insert(964, "Iraq");
    map.insert(965, "Kuwait");
    map.insert(966, "Saudi Arabia");
    map.insert(967, "Yemen");
    map.insert(968, "Oman");
    map.insert(971, "United Arab Emirates");
    map.insert(972, "Israel");
    map.insert(973, "Bahrain");
    map.insert(974, "Qatar");
    map.insert(975, "Bhutan");
    map.insert(976, "Mongolia");
    map.insert(977, "Nepal");
    map.insert(994, "Azerbaijan");
    map.insert(995, "Georgia");
    map.insert(2691, "Comoros");
    map.insert(4101, "Liechtenstein");
    map.insert(4201, "Slovak Republic");
    map.insert(5399, "Guantanamo Bay");
    map.insert(5901, "French Antilles");
    map.insert(6101, "Cocos-Keeling Islands");
    map.insert(6701, "Rota Island");
    map.insert(6702, "Tinian Island");
    map.insert(6721, "Australian Antarctic Territory");
    map.insert(6722, "Norfolk Island");
    map.insert(9999, "Unknown");

    return map;
}

/* Return country code by name */
quint16 countryCodeByName(const QString &name)
{
    return countries().key(name, 9999);
}

/* Return country name by code */
QString countryNameByCode(quint16 code)
{
    return countries().value(code, "-");
}


/* Returns map with languages */
oscarMap languages()
{
    oscarMap map;

    map.insert(1, "Arabic");
    map.insert(2, "Bhojpuri");
    map.insert(3, "Bulgarian");
    map.insert(4, "Burmese");
    map.insert(5, "Cantonese");
    map.insert(6, "Catalan");
    map.insert(7, "Chinese");
    map.insert(8, "Croatian");
    map.insert(9, "Czech");
    map.insert(10, "Danish");
    map.insert(11, "Dutch");
    map.insert(12, "English");
    map.insert(13, "Esperanto");
    map.insert(14, "Estonian");
    map.insert(15, "Farci");
    map.insert(16, "Finnish");
    map.insert(17, "French");
    map.insert(18, "Gaelic");
    map.insert(19, "German");
    map.insert(20, "Greek");
    map.insert(21, "Hebrew");
    map.insert(22, "Hindi");
    map.insert(23, "Hungarian");
    map.insert(24, "Icelandic");
    map.insert(25, "Indonesian");
    map.insert(26, "Italian");
    map.insert(27, "Japanese");
    map.insert(28, "Khmer");
    map.insert(29, "Korean");
    map.insert(30, "Lao");
    map.insert(31, "Latvian");
    map.insert(32, "Lithuanian");
    map.insert(33, "Malay");
    map.insert(34, "Norwegian");
    map.insert(35, "Polish");
    map.insert(36, "Portuguese");
    map.insert(37, "Romanian");
    map.insert(38, "Russian");
    map.insert(39, "Serbo-Chroatian");
    map.insert(40, "Slovak");
    map.insert(41, "Slovenian");
    map.insert(42, "Somali");
    map.insert(43, "Spanish");
    map.insert(44, "Swahili");
    map.insert(45, "Swedish");
    map.insert(46, "Tagalog");
    map.insert(47, "Tatar");
    map.insert(48, "Thai");
    map.insert(49, "Turkish");
    map.insert(50, "Ukrainian");
    map.insert(51, "Urdu");
    map.insert(52, "Vietnamese");
    map.insert(53, "Yiddish");
    map.insert(54, "Yoruba");
    map.insert(55, "Afrikaans");
    map.insert(56, "Bosnian");
    map.insert(57, "Persian");
    map.insert(58, "Albanian");
    map.insert(59, "Armenian");
    map.insert(60, "Punjabi");
    map.insert(61, "Chamorro");
    map.insert(62, "Mongolian");
    map.insert(63, "Mandarin");
    map.insert(64, "Taiwanese");
    map.insert(65, "Macedonian");
    map.insert(66, "Singhi");
    map.insert(67, "Welsh");
    map.insert(68, "Azerbaijani");
    map.insert(69, "Kurdish");
    map.insert(70, "Gujarati");
    map.insert(71, "Tamil");
    map.insert(72, "Belorussian");
    map.insert(255, "Unknown");

    return map;
}

/* Return lang code by lang name */
quint16 languageCodeByName(const QString &name)
{
    return languages().key(name, 255);
}

/* Return language by code */
QString languageNameByCode(quint16 code)
{
    return languages().value(code, "-");
}


/* Returns map with interests categories */
oscarMap interests()
{
    oscarMap map;

    map.insert(100, "Art");
    map.insert(101, "Cars");
    map.insert(102, "Celebrity Fans");
    map.insert(103, "Collections");
    map.insert(104, "Computers");
    map.insert(105, "Culture and Literature");
    map.insert(106, "Fitness");
    map.insert(107, "Games");
    map.insert(108, "Hobbies");
    map.insert(109, "ICQ - Providing Help");
    map.insert(110, "Internet");
    map.insert(111, "Lifestyle");
    map.insert(112, "Movies/TV");
    map.insert(113, "Music");
    map.insert(114, "Outdoor Activities");
    map.insert(115, "Parenting");
    map.insert(116, "Pets/Animals");
    map.insert(117, "Religion");
    map.insert(118, "Science/Technology");
    map.insert(119, "Skills");
    map.insert(120, "Sports");
    map.insert(121, "Web Design");
    map.insert(122, "Nature and Environment");
    map.insert(123, "News and Media");
    map.insert(124, "Government");
    map.insert(125, "Business and Economy");
    map.insert(126, "Mystics");
    map.insert(127, "Travel");
    map.insert(128, "Astronomy");
    map.insert(129, "Space");
    map.insert(130, "Clothing");
    map.insert(131, "Parties");
    map.insert(132, "Women");
    map.insert(133, "Social Science");
    map.insert(134, "60\'s");
    map.insert(135, "70\'s");
    map.insert(136, "80\'s");
    map.insert(137, "50\'s");
    map.insert(138, "Finance and corporate");
    map.insert(139, "Entertainment");
    map.insert(140, "Consumer electronics");
    map.insert(141, "Retail stores");
    map.insert(142, "Health and beuty");
    map.insert(143, "Media");
    map.insert(144, "Household products");
    map.insert(145, "Mail order catalog");
    map.insert(146, "Business services");
    map.insert(147, "Audio and visual");
    map.insert(148, "Sporting and athletic");
    map.insert(149, "Publishing");
    map.insert(150, "Home automation");

    return map;
}

/* Return interest code by name */
quint16 interestCodeByName(const QString &name)
{
    return interests().key(name, 0);
}

/* Return interest name by code */
QString interestNameByCode(quint16 code)
{
    return interests().value(code, "-");
}

/* Returns map with organizations */
oscarMap organizations()
{
    oscarMap map;

    map.insert(200, "Alumni org.");
    map.insert(201, "Charity org.");
    map.insert(202, "Club/Social org.");
    map.insert(203, "Community org.");
    map.insert(204, "Cultural org.");
    map.insert(205, "Fan Clubs");
    map.insert(206, "Fraternity/Sorority");
    map.insert(207, "Hobbyists org.");
    map.insert(208, "International org.");
    map.insert(209, "Nature and Enviroment org.");
    map.insert(210, "Professional org");
    map.insert(211, "Scientific/Technical org.");
    map.insert(212, "Self Improvement Group");
    map.insert(213, "Spiritual/Religious org.");
    map.insert(214, "Sports org.");
    map.insert(215, "Support org.");
    map.insert(216, "Trade and Business org.");
    map.insert(217, "Union");
    map.insert(218, "Volunteer org.");
    map.insert(299, "Other");

    return map;
}

/* Return organization code by name */
quint16 organizationCodeByName(const QString &name)
{
    return organizations().key(name, 299);
}

/* Return organization name by code */
QString organizationNameByCode(quint16 code)
{
    return organizations().value(code, "-");
}

/* Returns map with Pasts categories */
oscarMap pasts()
{
    oscarMap map;

    map.insert(300, "Elementary school");
    map.insert(301, "High School");
    map.insert(302, "College");
    map.insert(303, "University");
    map.insert(304, "Military");
    map.insert(305, "Past Work Place");
    map.insert(306, "Past Organization");
    map.insert(399, "Other");

    return map;
}

/* Return pasts code by name */
quint16 pastsCodeByName(const QString &name)
{
    return pasts().key(name, 299);
}

/* Return pasts name by code */
QString pastsNameByCode(quint16 code)
{
    return pasts().value(code, "-");
}

/* Returns map with Occupations cats. */
oscarMap occupations()
{
    oscarMap map;

    map.insert(1, "Academic");
    map.insert(2, "Administrative");
    map.insert(3, "Art/Entertainment");
    map.insert(4, "College Student");
    map.insert(5, "Computers");
    map.insert(6, "Community and Social");
    map.insert(7,"Education");
    map.insert(8, "Engineering");
    map.insert(9, "Financial Services");
    map.insert(10, "Government");
    map.insert(11, "High School Student");
    map.insert(12, "Home");
    map.insert(13, "ICQ - Providing Help");
    map.insert(14, "Law");
    map.insert(15, "Managerial");
    map.insert(16, "Manufacturing");
    map.insert(17, "Medical/Health");

    return map;
}

/* Return occupation code by name */
quint16 occupationCodeByName(const QString &name)
{
    return occupations().key(name, 0);
}

/* Return occupation name by code */
QString occupationNameByCode(quint16 code)
{
    return occupations().value(code, "-");
}

/* Returns marital map */
oscarMap maritals()
{
    oscarMap map;

    map.insert(0x00, "None");
    map.insert(0x0A, "Single");
    map.insert(0x0B, "Long Relationship");
    map.insert(0x0C, "Engaged");
    map.insert(0x14, "Married");
    map.insert(0x1E, "Divorced");
    map.insert(0x1F, "Separated");
    map.insert(0x28, "Widowed");

    return map;
}

/* Return marital code by name */
quint16 maritalCodeByName(const QString &name)
{
    return maritals().key(name, 0x00);
}

/* Return marital name by code */
QString maritalNameByCode(quint16 code)
{
    return maritals().value(code, "-");
}
