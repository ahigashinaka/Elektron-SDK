/*|-----------------------------------------------------------------------------
 *|            This source code is provided under the Apache 2.0 license      --
 *|  and is provided AS IS with no warranty or guarantee of fit for purpose.  --
 *|                See the project's LICENSE.md for details.                  --
 *|           Copyright Thomson Reuters 2015. All rights reserved.            --
 *|-----------------------------------------------------------------------------
 */

#ifndef __thomsonreuters_ema_access_FilterListEncoder_h
#define __thomsonreuters_ema_access_FilterListEncoder_h

#include "FilterEntry.h"
#include "Encoder.h"
#include "ComplexType.h"
#include "EmaPool.h"
#include "rtr/rsslFilterList.h"

namespace thomsonreuters {

namespace ema {

namespace access {

class OmmArray;
class ElementList;
class FieldList;
class FilterList;
class Map;
class Series;
class Vector;
class AckMsg;
class GenericMsg;
class PostMsg;
class ReqMsg;
class RespMsg;
class OmmAnsiPage;
class OmmOpaque;
class OmmXml;

class FilterListEncoder : public Encoder
{
public :

	FilterListEncoder();

	virtual ~FilterListEncoder();

	void clear();

	void totalCountHint( UInt8 totalCountHint );

	void add( UInt8 filterId, FilterEntry::FilterAction action, 
				const ComplexType& complexType, const EmaBuffer& permission );

	void complete();

private :

	void initEncode( UInt8 dataType );

	void addEncodedEntry( UInt8 filterId, UInt8 action, UInt8 dataType, const EmaBuffer& permission, const char* , const RsslBuffer& );

	void startEncodingEntry( UInt8 filterId, UInt8 action, UInt8 dataType, const EmaBuffer& permission, const char* );

	void endEncodingEntry() const;

	RsslFilterList			_rsslFilterList;

	RsslFilterEntry			_rsslFilterEntry;

	bool					_containerInitialized;
};


class FilterListEncoderPool : public EncoderPool< FilterListEncoder >
{
public :

	FilterListEncoderPool( unsigned int size = 5 ) : EncoderPool< FilterListEncoder >( size ) {};

	virtual ~FilterListEncoderPool() {}

private :

	FilterListEncoderPool( const FilterListEncoderPool& );
	FilterListEncoderPool& operator=( const FilterListEncoderPool& );
};

}

}

}

#endif // __thomsonreuters_ema_access_FilterListEncoder_h
