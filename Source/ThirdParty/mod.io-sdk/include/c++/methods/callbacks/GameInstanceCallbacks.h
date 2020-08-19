#include "../../ModioUtility.h"
#include <map>
#include "../../schemas/Game.h"

namespace modio
{
  struct GetGameCall
  {
    const std::function<void(const modio::Response&, const modio::Game& game)> callback;
  };

  extern std::map<u32, GetGameCall*> get_game_calls;

  void onGetGame(void* object, ModioResponse modio_response, ModioGame game);

  void clearGameRequestCalls();
} // namespace modio
