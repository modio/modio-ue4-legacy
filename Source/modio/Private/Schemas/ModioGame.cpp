#include "Schemas/ModioGame.h"

#include "Schemas/ModioLogo.h"
#include "Schemas/ModioUser.h"

#include "c/schemas/ModioIcon.h"
#include "c/schemas/ModioHeader.h"

void InitializeGame(FModioGame& game, const ModioGame& modio_game)
{
  game.ApiAccessOptions = modio_game.api_access_options;
  game.CommunityOptions = modio_game.community_options;
  game.CurationOption = modio_game.curation_option;
  game.DateAdded = modio_game.date_added;
  game.DateLive = modio_game.date_live;
  game.DateUpdated = modio_game.date_updated;
  InitializeHeaderImage(game.Header, modio_game.header);
  InitializeIcon(game.Icon, modio_game.icon );
  game.Id = modio_game.id;
  game.Instructions = TCHAR_TO_UTF8(modio_game.instructions);
  game.InstructionsUrl = TCHAR_TO_UTF8(modio_game.instructions_url);
  InitializeLogo(game.Logo, modio_game.logo);
  game.MaturityOptions = modio_game.maturity_options;
  game.Name = modio_game.name;
  game.NameId = modio_game.name_id;
  game.PresentationOption = modio_game.presentation_option;
  game.ProfileUrl = modio_game.profile_url;
  game.RevenueOptions = modio_game.revenue_options;
  game.Status = modio_game.status;
  game.SubmissionOption = modio_game.submission_option;
  InitializeUser(game.SubmittedBy, modio_game.submitted_by);
  game.Summary = modio_game.summary;
  {
    game.TagOptions.Reset(modio_game.game_tag_option_array_size);
    game.TagOptions.SetNum(modio_game.game_tag_option_array_size);
    for( size_t i = 0; i < modio_game.game_tag_option_array_size; ++i )
    {
      InitializeGameTagOption(game.TagOptions[i], modio_game.game_tag_option_array[i]);
    }
  }
  game.UGCName = UTF8_TO_TCHAR(modio_game.ugc_name);
}

void InitializeHeaderImage(FModioHeaderImage& headerImage, const ModioHeader& modio_header_image)
{
  headerImage.Filename = UTF8_TO_TCHAR(modio_header_image.filename);
  headerImage.Original = UTF8_TO_TCHAR(modio_header_image.original);
}

void InitializeIcon(FModioIcon& icon, const ModioIcon& modio_icon)
{
  icon.Filename = UTF8_TO_TCHAR(modio_icon.filename);
  icon.Original = UTF8_TO_TCHAR(modio_icon.original);
  icon.Thumb64x64 = UTF8_TO_TCHAR(modio_icon.thumb_64x64);
  icon.Thumb128x128 = UTF8_TO_TCHAR(modio_icon.thumb_128x128);
  icon.Thumb256x256 = UTF8_TO_TCHAR(modio_icon.thumb_256x256);
}