#pragma once

// Our own easily changed inline options
#if INT64_MATH_INLINE_ENABLED
#define INT64_MATH_FORCEINLINE		FORCEINLINE_DEBUGGABLE
#define INT64_MATH_INLINE			inline
#else
#define INT64_MATH_FORCEINLINE		// nothing
#define INT64_MATH_INLINE			// nothing
#endif

INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Multiply_Int64Int64( const FInt64& A, const FInt64& B )
{
	return A.Value * B.Value;
}

INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Multiply_Int64Int32( const FInt64& A, int32 B )
{
	return A.Value * B;
}

INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Multiply_Int64Uint8( const FInt64& A, uint8 B )
{
	return A.Value * B;
}

INT64_MATH_FORCEINLINE float UInt64MathLibrary::Multiply_Int64Float( const FInt64& A, float B )
{
	return A.Value * B;
}


INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Add_Int64Int64( const FInt64& A, const FInt64& B )
{
	return A.Value + B.Value;
}

INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Add_Int64Int32( const FInt64& A, int32 B )
{
	return A.Value + B;
}

INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Add_Int64Uint8( const FInt64& A, uint8 B )
{
	return A.Value + B;
}

INT64_MATH_FORCEINLINE float UInt64MathLibrary::Add_Int64Float( const FInt64& A, float B )
{
	return A.Value + B;
}

INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Subtract_Int64Int64( const FInt64& A, const FInt64& B )
{
	return A.Value - B.Value;
}

INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Subtract_Int64Int32( const FInt64& A, int32 B )
{
	return A.Value - B;
}

INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Subtract_Int64Uint8( const FInt64& A, uint8 B )
{
	return A.Value - B;
}

INT64_MATH_FORCEINLINE float UInt64MathLibrary::Subtract_Int64Float( const FInt64& A, float B )
{
	return A.Value - B;
}