// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

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
	return A * B;
}

INT64_MATH_FORCEINLINE float UInt64MathLibrary::Multiply_Int64Float( const FInt64& A, float B )
{
	return A * B;
}


INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Add_Int64Int64( const FInt64& A, const FInt64& B )
{
	return A + B;
}

INT64_MATH_FORCEINLINE float UInt64MathLibrary::Add_Int64Float( const FInt64& A, float B )
{
	return A + B;
}

INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Subtract_Int64Int64( const FInt64& A, const FInt64& B )
{
	return A - B;
}

INT64_MATH_FORCEINLINE float UInt64MathLibrary::Subtract_Int64Float( const FInt64& A, float B )
{
	return A - B;
}

INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Divide_Int64Int64( const FInt64& A, const FInt64& B )
{
	return A / B;
}

INT64_MATH_FORCEINLINE float UInt64MathLibrary::Divide_Int64Float( const FInt64& A, float B )
{
	return A / B;
}

INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Min( FInt64 A, FInt64 B )
{
	return FMath::Min( A, B );
}

INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Max( FInt64 A, FInt64 B )
{
	return FMath::Max( A, B );
}


INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Abs_Int( const FInt64& A )
{
	if(A < 0)
		return A * -1;
	return A;
}


INT64_MATH_FORCEINLINE FInt64 UInt64MathLibrary::Percent_Int64Int64( const FInt64& A, const FInt64& B )
{
	return A % B;
}

INT64_MATH_FORCEINLINE bool UInt64MathLibrary::Less_Int64Int64( const FInt64& A, const FInt64& B )
{
	return A < B;
}

INT64_MATH_FORCEINLINE bool UInt64MathLibrary::Greater_Int64Int64( const FInt64& A, const FInt64& B )
{
	return A > B;
}

INT64_MATH_FORCEINLINE bool UInt64MathLibrary::LessEqual_Int64Int64( const FInt64& A, const FInt64& B )
{
	return A <= B;
}

INT64_MATH_FORCEINLINE bool UInt64MathLibrary::GreaterEqual_Int64Int64( const FInt64& A, const FInt64& B )
{
	return A >= B;
}

INT64_MATH_FORCEINLINE bool UInt64MathLibrary::EqualEqual_Int64Int64( const FInt64& A, const FInt64& B )
{
	return A == B;
}

INT64_MATH_FORCEINLINE bool UInt64MathLibrary::NotEqual_Int64Int64( const FInt64& A, const FInt64& B )
{
	return A != B;
}