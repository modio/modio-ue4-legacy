// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

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

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 * float", CompactNodeTitle = "*", Keywords = "* multiply"), Category = "Math|Int64" )
	static float Multiply_Int64Float( const FInt64& A, float B );

	/// Add

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 + int64", CompactNodeTitle = "+", Keywords = "+ add", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|Int64" )
	static FInt64 Add_Int64Int64( const FInt64& A, const FInt64& B );

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 + float", CompactNodeTitle = "+", Keywords = "+ add"), Category = "Math|Int64" )
	static float Add_Int64Float( const FInt64& A, float B );

	/// Subtract

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 - int64", CompactNodeTitle = "-", Keywords = "- subtract"), Category = "Math|Int64" )
	static FInt64 Subtract_Int64Int64( const FInt64& A, const FInt64& B );

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 - float", CompactNodeTitle = "-", Keywords = "- subtract"), Category = "Math|Int64" )
	static float Subtract_Int64Float( const FInt64& A, float B );

	/// Division

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 / int64", CompactNodeTitle = "/", Keywords = "/ divide"), Category = "Math|Int64" )
	static FInt64 Divide_Int64Int64( const FInt64& A, const FInt64& B );

	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 / int64", CompactNodeTitle = "/", Keywords = "/ divide"), Category = "Math|Int64" )
	static float Divide_Int64Float( const FInt64& A, float B );

	/// Min/Max

	/** Returns the minimum value of A and B */
	UFUNCTION( BlueprintPure, meta = (DisplayName = "Min (int64)", CompactNodeTitle = "MIN", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|int64" )
	static FInt64 Min( FInt64 A, FInt64 B );

	/** Returns the maximum value of A and B */
	UFUNCTION( BlueprintPure, meta = (DisplayName = "Max (int64)", CompactNodeTitle = "MAX", CommutativeAssociativeBinaryOperator = "true"), Category = "Math|int64" )
	static FInt64 Max( FInt64 A, FInt64 B );

	/** Returns the absolute (positive) value of A */
	UFUNCTION( BlueprintPure, meta = (DisplayName = "Absolute (int64)", CompactNodeTitle = "ABS"), Category = "Math|int64" )
	static FInt64 Abs_Int( const FInt64& A );

	/** Modulo (A % B) */
	UFUNCTION( BlueprintPure, meta = (DisplayName = "% (int64)", CompactNodeTitle = "%", Keywords = "% modulus"), Category = "Math|int64" )
	static FInt64 Percent_Int64Int64( const FInt64& A, const FInt64& B );

	/** Returns true if A is less than B (A < B) */
	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 < int64", CompactNodeTitle = "<", Keywords = "< less"), Category = "Math|int64" )
	static bool Less_Int64Int64( const FInt64& A, const FInt64& B );

	/** Returns true if A is greater than B (A > B) */
	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 > int64", CompactNodeTitle = ">", Keywords = "> greater"), Category = "Math|int64" )
	static bool Greater_Int64Int64( const FInt64& A, const FInt64& B );

	/** Returns true if A is less than or equal to B (A <= B) */
	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 <= int64", CompactNodeTitle = "<=", Keywords = "<= less"), Category = "Math|int64" )
	static bool LessEqual_Int64Int64( const FInt64& A, const FInt64& B );

	/** Returns true if A is greater than or equal to B (A >= B) */
	UFUNCTION( BlueprintPure, meta = (DisplayName = "int64 >= int64", CompactNodeTitle = ">=", Keywords = ">= greater"), Category = "Math|int64" )
	static bool GreaterEqual_Int64Int64( const FInt64& A, const FInt64& B );

	/** Returns true if A is equal to B (A == B) */
	UFUNCTION( BlueprintPure, meta = (DisplayName = "Equal (int64)", CompactNodeTitle = "==", Keywords = "== equal"), Category = "Math|int64" )
	static bool EqualEqual_Int64Int64( const FInt64& A, const FInt64& B );

	/** Returns true if A is not equal to B (A != B) */
	UFUNCTION( BlueprintPure, meta = (DisplayName = "NotEqual (int64)", CompactNodeTitle = "!=", Keywords = "!= not equal"), Category = "Math|int64" )
	static bool NotEqual_Int64Int64( const FInt64& A, const FInt64& B );

};

#if INT64_MATH_INLINE_ENABLED
#include "Int64Math.inl"
#endif