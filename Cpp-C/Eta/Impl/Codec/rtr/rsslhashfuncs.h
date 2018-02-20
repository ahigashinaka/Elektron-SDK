/*|-----------------------------------------------------------------------------
 *|            This source code is provided under the Apache 2.0 license      --
 *|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
 *|                See the project's LICENSE.md for details.                  --
 *|           Copyright Thomson Reuters 2018. All rights reserved.            --
 *|-----------------------------------------------------------------------------
 */

#ifndef __RSSLHASHFUNCS_H
#define __RSSLHASHFUNCS_H

#ifdef __cplusplus
extern "C" {
#endif

	/* CRC32 table for polynomial 0xF3C5F6A9 */
#ifdef WIN32
rtrUInt32 __int_rssl_hash_crc_table[256] = {
#else
rtrUInt32 __rssl_hash_crc_table[256] = {
#endif
    0x00000000, 0xBC5C9CBF, 0x9F32D42D, 0x236E4892, 0xD9EE4509, 0x65B2D9B6, 
    0x46DC9124, 0xFA800D9B, 0x54576741, 0xE80BFBFE, 0xCB65B36C, 0x77392FD3, 
    0x8DB92248, 0x31E5BEF7, 0x128BF665, 0xAED76ADA, 0xA8AECE82, 0x14F2523D, 
    0x379C1AAF, 0x8BC08610, 0x71408B8B, 0xCD1C1734, 0xEE725FA6, 0x522EC319, 
    0xFCF9A9C3, 0x40A5357C, 0x63CB7DEE, 0xDF97E151, 0x2517ECCA, 0x994B7075, 
    0xBA2538E7, 0x0679A458, 0xB6D67057, 0x0A8AECE8, 0x29E4A47A, 0x95B838C5, 
    0x6F38355E, 0xD364A9E1, 0xF00AE173, 0x4C567DCC, 0xE2811716, 0x5EDD8BA9, 
    0x7DB3C33B, 0xC1EF5F84, 0x3B6F521F, 0x8733CEA0, 0xA45D8632, 0x18011A8D, 
    0x1E78BED5, 0xA224226A, 0x814A6AF8, 0x3D16F647, 0xC796FBDC, 0x7BCA6763, 
    0x58A42FF1, 0xE4F8B34E, 0x4A2FD994, 0xF673452B, 0xD51D0DB9, 0x69419106, 
    0x93C19C9D, 0x2F9D0022, 0x0CF348B0, 0xB0AFD40F, 0x8A270DFD, 0x367B9142, 
    0x1515D9D0, 0xA949456F, 0x53C948F4, 0xEF95D44B, 0xCCFB9CD9, 0x70A70066, 
    0xDE706ABC, 0x622CF603, 0x4142BE91, 0xFD1E222E, 0x079E2FB5, 0xBBC2B30A, 
    0x98ACFB98, 0x24F06727, 0x2289C37F, 0x9ED55FC0, 0xBDBB1752, 0x01E78BED, 
    0xFB678676, 0x473B1AC9, 0x6455525B, 0xD809CEE4, 0x76DEA43E, 0xCA823881, 
    0xE9EC7013, 0x55B0ECAC, 0xAF30E137, 0x136C7D88, 0x3002351A, 0x8C5EA9A5, 
    0x3CF17DAA, 0x80ADE115, 0xA3C3A987, 0x1F9F3538, 0xE51F38A3, 0x5943A41C, 
    0x7A2DEC8E, 0xC6717031, 0x68A61AEB, 0xD4FA8654, 0xF794CEC6, 0x4BC85279, 
    0xB1485FE2, 0x0D14C35D, 0x2E7A8BCF, 0x92261770, 0x945FB328, 0x28032F97, 
    0x0B6D6705, 0xB731FBBA, 0x4DB1F621, 0xF1ED6A9E, 0xD283220C, 0x6EDFBEB3, 
    0xC008D469, 0x7C5448D6, 0x5F3A0044, 0xE3669CFB, 0x19E69160, 0xA5BA0DDF, 
    0x86D4454D, 0x3A88D9F2, 0xF3C5F6A9, 0x4F996A16, 0x6CF72284, 0xD0ABBE3B, 
    0x2A2BB3A0, 0x96772F1F, 0xB519678D, 0x0945FB32, 0xA79291E8, 0x1BCE0D57, 
    0x38A045C5, 0x84FCD97A, 0x7E7CD4E1, 0xC220485E, 0xE14E00CC, 0x5D129C73, 
    0x5B6B382B, 0xE737A494, 0xC459EC06, 0x780570B9, 0x82857D22, 0x3ED9E19D, 
    0x1DB7A90F, 0xA1EB35B0, 0x0F3C5F6A, 0xB360C3D5, 0x900E8B47, 0x2C5217F8, 
    0xD6D21A63, 0x6A8E86DC, 0x49E0CE4E, 0xF5BC52F1, 0x451386FE, 0xF94F1A41, 
    0xDA2152D3, 0x667DCE6C, 0x9CFDC3F7, 0x20A15F48, 0x03CF17DA, 0xBF938B65, 
    0x1144E1BF, 0xAD187D00, 0x8E763592, 0x322AA92D, 0xC8AAA4B6, 0x74F63809, 
    0x5798709B, 0xEBC4EC24, 0xEDBD487C, 0x51E1D4C3, 0x728F9C51, 0xCED300EE, 
    0x34530D75, 0x880F91CA, 0xAB61D958, 0x173D45E7, 0xB9EA2F3D, 0x05B6B382, 
    0x26D8FB10, 0x9A8467AF, 0x60046A34, 0xDC58F68B, 0xFF36BE19, 0x436A22A6, 
    0x79E2FB54, 0xC5BE67EB, 0xE6D02F79, 0x5A8CB3C6, 0xA00CBE5D, 0x1C5022E2, 
    0x3F3E6A70, 0x8362F6CF, 0x2DB59C15, 0x91E900AA, 0xB2874838, 0x0EDBD487, 
    0xF45BD91C, 0x480745A3, 0x6B690D31, 0xD735918E, 0xD14C35D6, 0x6D10A969, 
    0x4E7EE1FB, 0xF2227D44, 0x08A270DF, 0xB4FEEC60, 0x9790A4F2, 0x2BCC384D, 
    0x851B5297, 0x3947CE28, 0x1A2986BA, 0xA6751A05, 0x5CF5179E, 0xE0A98B21, 
    0xC3C7C3B3, 0x7F9B5F0C, 0xCF348B03, 0x736817BC, 0x50065F2E, 0xEC5AC391, 
    0x16DACE0A, 0xAA8652B5, 0x89E81A27, 0x35B48698, 0x9B63EC42, 0x273F70FD, 
    0x0451386F, 0xB80DA4D0, 0x428DA94B, 0xFED135F4, 0xDDBF7D66, 0x61E3E1D9, 
    0x679A4581, 0xDBC6D93E, 0xF8A891AC, 0x44F40D13, 0xBE740088, 0x02289C37, 
    0x2146D4A5, 0x9D1A481A, 0x33CD22C0, 0x8F91BE7F, 0xACFFF6ED, 0x10A36A52, 
    0xEA2367C9, 0x567FFB76, 0x7511B3E4, 0xC94D2F5B
};

#ifdef WIN32
RTR_C_INLINE rtrUInt32* __rsslGetHashCrcTable()
{
	return __int_rssl_hash_crc_table;
}
#endif

    /* CRC32 table for polynomial 0xF3C5F6A9 */

RTR_C_INLINE rtrUInt32 rsslPolyHash(const char* buf, const rtrUInt32 length) 
{
	register rtrUInt32 crc = 0;
#ifdef WIN32
	register rtrUInt32* __rssl_hash_crc_table = __rsslGetHashCrcTable();
#endif

	register rtrUInt32 len=length;
	while (len-- > 0)
		crc = __rssl_hash_crc_table[(crc ^ *buf++) & 0xFF] ^ (crc >> 8);

	return crc;
}

#ifdef __cplusplus
}
#endif

#endif

