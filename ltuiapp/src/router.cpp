#include "../inc/router.hpp"

#include <memory>

namespace ltui
{
    void router::navigate(const std::string& path, std::any route_params)
    {
        if (_routes.find(path) != _routes.end())
        {
            auto& view = _routes.at(path)(std::move(route_params));
            view->show();
        }
    }

    router& router::add_route(const std::string& path, router::route_view_activator_t activator)
    {
        _routes[path] = activator;

        return *this;
    }
}