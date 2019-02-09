#pragma once

#include "Int64.generated.h"

USTRUCT(BlueprintType, meta=(HasNativeMake = "Int64.Int64FunctionLibrary.MakeInt64") )
struct FInt64
{
	GENERATED_BODY()

	// The actual int64
	UPROPERTY(EditAnywhere)
	int64 Value;

	/** Display a int64 as a string */
	FORCEINLINE FString ToString() const { return FString::Printf( TEXT( "%lld" ), Value ); }

	FInt64() :
		Value( 0 )
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