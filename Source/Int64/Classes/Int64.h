// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Int64.generated.h"

USTRUCT(BlueprintType, Category="Utilities", meta=(HasNativeMake = "Int64.Int64FunctionLibrary.MakeInt64") )
struct FInt64
{
	GENERATED_BODY()

	// The actual int64
	UPROPERTY(EditAnywhere, Category="Utilities")
	int64 Value;

	/** Display a int64 as a string */
	FORCEINLINE FString ToString() const { return FString::Printf( TEXT( "%lld" ), Value ); }

	FORCEINLINE operator int64() const{ return Value; }

	FORCEINLINE FInt64& operator=( int64 Other )
	{ 
		Value = Other; 
		return *this;
	}

	FInt64() :
		Value( 0 )
	{
	}

	FInt64( float FromFloat ) :
		Value( FromFloat )
	{
	}

	FInt64( int64 FromInt64 ) :
		Value( FromInt64 )
	{
	}

	FInt64( int32 FromInt32 ) :
		Value( FromInt32 )
	{
	}
};