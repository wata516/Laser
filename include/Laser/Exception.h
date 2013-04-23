#pragma once

#include <TGUL/String.h>
#include <exception>

namespace Laser
{
	class Exception : public std::exception
    {
    protected:
		int mNumber;
		TGUL::String mDescription;
		TGUL::String mSource;
        TGUL::String mFile;
		long mLine;

	public:
        enum ExceptionCodes {
			EXCEPTION_ASSERT,
			EXCEPTION_INVALIED_ACCESS,
        };

		Exception( int number, const TGUL::String& description, const TGUL::String& source, const char* type, const char* file, long line )
			: mNumber( number )
			, mDescription(description)
			, mSource( source )
			, mFile( file )
			, mLine( line )
		{ }

		~Exception() throw() {}

		long getLine() const { return mLine; }
		int GetErrorNumber( ) const { return mNumber; }
		const TGUL::String &getDescription(void) const { return mDescription; }
		const TGUL::String &getSource() const { return mSource; }
        const TGUL::String &getFile() const { return mFile; }
    };

	template < int id >
	struct ExceptionCodeType
	{
		enum { number = id };
	};

	class AssertException : public Exception 
	{
	public:
		AssertException(int id, const TGUL::String& description, const TGUL::String& source, const char * pFilename, long line)
			: Exception(id, description, source, "Assert", pFilename, line ) {}
	};
	class InvaliedAccessException : public Exception
	{
	public:
		InvaliedAccessException(int id, const TGUL::String& description, const TGUL::String& source, const char * pFilename, long line)
		: Exception(id, description, source, "Invalied Access", pFilename, line ) {}
	};

	class ExceptionFactory
	{
	private:
		/// Private constructor, no construction
		ExceptionFactory() {}
	public:
		static AssertException Create(
			ExceptionCodeType< Exception::EXCEPTION_ASSERT > code, 
			const TGUL::String& desc, 
			const TGUL::String& src, const char* file, long line)
		{
			return AssertException(code.number, desc, src, file, line);
		}
		static InvaliedAccessException Create(
									  ExceptionCodeType< Exception::EXCEPTION_INVALIED_ACCESS > code,
									  const TGUL::String& desc,
									  const TGUL::String& src, const char* file, long line)
		{
			return InvaliedAccessException(code.number, desc, src, file, line);
		}
		
	};


	#define EXCEPT( cond, id, description, src ) if( cond ) throw Laser::ExceptionFactory::Create( \
	ExceptionCodeType< id >(), description, src, __FILE__, __LINE__ )

	#define ASSERT( cond, description ) EXCEPT( !cond, Exception::EXCEPTION_ASSERT, (description), __FUNC__ ) 

}
