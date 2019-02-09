#pragma once

#include "Int64.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Int64FunctionLibrary.generated.h"

// Whether to inline functions at all
#define KISMET_MATH_INLINE_ENABLED	(!UE_BUILD_DEBUG)

UCLASS()
class UInt64FunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/// Conversion functions

	/** Convert a Int64 to string */
	UFUNCTION( BlueprintPure, Category="Utilities", meta = (DisplayName = "ToString (Int64)", CompactNodeTitle = "->", Keywords = "string") )
	static FString Conv_Int64ToString( const FInt64& Int64 );

	/** Convert a Int32 to Int64 */
	UFUNCTION( BlueprintPure, Category = "Utilities", meta = (DisplayName = "ToInt64 (Int32)", CompactNodeTitle = "->", Keywords = "int32 int64") )
	static FInt64 Conv_Int32ToInt64( int32 Int32 );

	// Create a Int64
	UFUNCTION( BlueprintPure, Category = Utilities )
	static FInt64 MakeInt64( FString Int64 );
};