#pragma once

#include "Int64.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Int64MathLibrary.generated.h"

// Whether to inline functions at all
#define INT64_MATH_INLINE_ENABLED	(!UE_BUILD_DEBUG)

UCLASS()
class UInt64MathLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/// Multiply

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 * int64", CompactNodeTitle = "*", Keywords = "* multiply", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int64" )
	static FInt64 Multiply_Int64Int64( const FInt64& A, const FInt64& B );

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 * int32", CompactNodeTitle = "*", Keywords = "* multiply"), Category = "Math|Int64" )
	static FInt64 Multiply_Int64Int32( const FInt64& A, int32 B );

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 * uint8", CompactNodeTitle = "*", Keywords = "* multiply"), Category = "Math|Int64" )
	static FInt64 Multiply_Int64Uint8( const FInt64& A, uint8 B );

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 * float", CompactNodeTitle = "*", Keywords = "* multiply"), Category = "Math|Int64" )
	static float Multiply_Int64Float( const FInt64& A, float B );

	/// Add

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 + int64", CompactNodeTitle = "+", Keywords = "+ add", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int64" )
	static FInt64 Add_Int64Int64( const FInt64& A, const FInt64& B );

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 + int32", CompactNodeTitle = "+", Keywords = "+ add"), Category = "Math|Int64" )
	static FInt64 Add_Int64Int32( const FInt64& A, int32 B );

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 + uint8", CompactNodeTitle = "+", Keywords = "+ add"), Category = "Math|Int64" )
	static FInt64 Add_Int64Uint8( const FInt64& A, uint8 B );

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 + float", CompactNodeTitle = "+", Keywords = "+ add"), Category = "Math|Int64" )
	static float Add_Int64Float( const FInt64& A, float B );

	/// Subtract

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 - int64", CompactNodeTitle = "-", Keywords = "- subtract"), Category = "Math|Int64" )
	static FInt64 Subtract_Int64Int64( const FInt64& A, const FInt64& B );

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 - int32", CompactNodeTitle = "-", Keywords = "- subtract"), Category = "Math|Int64" )
	static FInt64 Subtract_Int64Int32( const FInt64& A, int32 B );

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 - int8", CompactNodeTitle = "-", Keywords = "- subtract"), Category = "Math|Int64" )
	static FInt64 Subtract_Int64Uint8( const FInt64& A, uint8 B );

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 - float", CompactNodeTitle = "-", Keywords = "- subtract"), Category = "Math|Int64" )
	static float Subtract_Int64Float( const FInt64& A, float B );
};

#if INT64_MATH_INLINE_ENABLED
#include "Int64Math.inl"
#endif