#ifndef _LTUI_DISPATCHER_H_
#define _LTUI_DISPATCHER_H_

#include "./view.hpp"

#include <any>
#include <functional>
#include <map>
#include <string>

namespace ltui
{
  class router
  {
  public:
    using route_view_activator_t = std::function<std::shared_ptr<view>(std::any)>;
    using routes_t = std::map<std::string, route_view_activator_t>;

    void navigate(const std::string &path, std::any route_params);

    router& add_route(const std::string& path, route_view_activator_t activator);

    private:
      routes_t _routes;
  };
} // namespace ltui

#endif