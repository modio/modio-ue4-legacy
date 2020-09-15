// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Int64FunctionLibrary.h"

FString UInt64FunctionLibrary::Conv_Int64ToString( const FInt64& Int64 )
{
	return Int64.ToString();
}

int32 UInt64FunctionLibrary::Conv_Int64ToInt32( const FInt64& Int64 )
{
	return Int64.Value;
}

float UInt64FunctionLibrary::Conv_Int64ToFloat( const FInt64& Int64 )
{
	return Int64.Value;
}

FInt64 UInt64FunctionLibrary::Conv_Int32ToInt64( int32 Int32 )
{
	return FInt64( Int32 );
}

FInt64 UInt64FunctionLibrary::Conv_FloatToInt64( float Float )
{
	return FInt64( FMath::FloorToFloat( Float ) );
}

FInt64 UInt64FunctionLibrary::MakeInt64( FString Int64 )
{
	return FInt64( FCString::Atoi64( *Int64 ) );
}