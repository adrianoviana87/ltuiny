#include "../inc/router.hpp"

#include <memory>

namespace ltui
{
  router::router(std::shared_ptr<screen_service> scren_srv)
    : _screen_service(std::move(scren_srv))
  {
  }

  void router::navigate(const std::string& path, std::any route_params)
  {
    if (_routes.find(path) != _routes.end())
    {
      auto view = _routes.at(path)(std::move(route_params));
      _screen_service->render(view);
    }
  }

  router& router::add_route(const std::string& path, router::route_view_activator_t activator)
  {
    _routes[path] = activator;

    return *this;
  }
}
