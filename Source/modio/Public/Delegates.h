// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#pragma once

#include "Schemas/FModioResponse.h"
#include "Delegates.generated.h"

DECLARE_DELEGATE_OneParam(
    FEmailRequestDelegate,
    FModioResponse);

struct EmailRequestStruct
{
  FEmailRequestDelegate Delegate;
};

UCLASS()
class MODIO_API UDelegates : public UObject
{
  GENERATED_BODY()
};