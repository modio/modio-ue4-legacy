// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "BlueprintCallbackProxies/CallbackProxy_SubmitReport.h"
#include "ModioSubsystem.h"
#include "Engine/Engine.h"

UCallbackProxy_SubmitReport::UCallbackProxy_SubmitReport(const FObjectInitializer &ObjectInitializer)
    : Super(ObjectInitializer)
{
}

UCallbackProxy_SubmitReport *UCallbackProxy_SubmitReport::SubmitReport( UObject *WorldContext, TEnumAsByte<EModioResourceType> Resource, int32 Id, TEnumAsByte<EModioReportType> Report, const FString &Name, const FString &Summary )
{
  UCallbackProxy_SubmitReport *Proxy = NewObject<UCallbackProxy_SubmitReport>();
  Proxy->SetFlags(RF_StrongRefOnFrame);
  Proxy->WorldContextObject = WorldContext;
  Proxy->Resource = Resource;
  Proxy->Id = Id;
  Proxy->Report = Report;
  Proxy->Name = Name;
  Proxy->Summary = Summary;
  return Proxy;
}

void UCallbackProxy_SubmitReport::Activate()
{
  UWorld* World = GEngine->GetWorldFromContextObject( WorldContextObject, EGetWorldErrorMode::LogAndReturnNull );
  FModioSubsystemPtr Modio = FModioSubsystem::Get( World );
  if( Modio.IsValid() )
  {
    Modio->SubmitReport( Resource, Id, Report, Name, Summary, FModioGenericDelegate::CreateUObject( this, &UCallbackProxy_SubmitReport::OnSubmitReportDelegate ) );
  }
  else
  {
    // @todonow: Make something more pretty than this
    FModioResponse Response;
    OnFailure.Broadcast( Response );
  }
}

void UCallbackProxy_SubmitReport::OnSubmitReportDelegate(FModioResponse Response)
{
  if (Response.Code >= 200 && Response.Code < 300)
  {
    OnSuccess.Broadcast(Response);
  }
  else
  {
    OnFailure.Broadcast(Response);
  }
}