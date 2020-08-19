#ifndef LTUI_ROUTER_H
#define LTUI_ROUTER_H

#include "./view.hpp"

#include "./screen_service.hpp"

#include <any>
#include <functional>
#include <map>
#include <memory>
#include <string>

namespace ltui {
class router {
public:
  using route_view_activator_t = std::function<std::shared_ptr<view>(std::any)>;
  using routes_t = std::map<std::string, route_view_activator_t>;

  explicit router(std::shared_ptr<screen_service> scren_srv);

  void navigate(const std::string &path, std::any route_params);

  router &add_route(const std::string &path, route_view_activator_t activator);

private:
  std::shared_ptr<screen_service> _screen_service;
  routes_t _routes;
};
} // namespace ltui

#endif
