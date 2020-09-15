// Copyright 2020 modio. All Rights Reserved.
// Released under MIT.

#include "Schemas/ModioError.h"

void InitializeError(FModioError &error, const ModioError &modio_error)
{
  error.Code = modio_error.code;
  error.Message = UTF8_TO_TCHAR(modio_error.message);

  for (u32 i = 0; i < modio_error.errors_array_size; i++)
  {
    FString error_str = UTF8_TO_TCHAR(modio_error.errors_array[i]);
    error.Errors.Add(error_str);
  }
}