// Copyright 2019 modio. All Rights Reserved.
// Released under MIT.

#include "ModioCallbacks.h"

void onModInstalled(u32 response_code, u32 mod_id)
{
  UModioComponent::OnModDownloadDelegate.Broadcast((int32)response_code, (int32)mod_id);
}

void onAddModfile(u32 response_code, u32 mod_id)
{
  UModioComponent::OnModfileUploadDelegate.Broadcast((int32)response_code, (int32)mod_id);
}

void onEmailExchange(void *object, ModioResponse modio_response)
{
  EmailRequestStruct *email_request_struct = (EmailRequestStruct *) object;
  FModioResponse response;
  InitializeResponse(response, modio_response);
  email_request_struct->Delegate.ExecuteIfBound(response);
  delete email_request_struct;
}