#include <string>
#include <functional>
#include <memory>
#include <iostream>
#include <vector>

#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/component/component_options.hpp"

using namespace ftxui;
int main(){
  auto screen = ScreenInteractive::TerminalOutput();
  std::vector<std::string> ssh_connections = {
    "SSH placeholder 1",
    "SSH placeholder 2",
    "SSH Placeholder 3"
  };
  int selected_connection = 0;
  int ssh_tab_1, ssh_tab_2, ssh_tab_3 = 0;
  //How could I add more ssh tab connections during runtime?
  std::string ssh_1, ssh_2, ssh_3;

  Component input_ssh_1 = Input(&ssh_1, "PlaceHolder Text for Tab 1");
  Component input_ssh_2 = Input(&ssh_2, "Placeholder Text for Tab 2");
  Component input_ssh_3 = Input(&ssh_3, "PlaceHolder Text for Tab 3");


  auto ssh_tabs = Container::Tab(
    {
      input_ssh_1,
      input_ssh_2,
      input_ssh_3,
    },
  &selected_connection);

  auto ssh_toggle = Menu(&ssh_connections, &selected_connection);
  auto component = Container::Horizontal({
    ssh_toggle,
    ssh_tabs,
  });
  auto renderer = Renderer(component, [&]{
    return hbox({
      ssh_toggle->Render(),
      separator(),
      ssh_tabs->Render(),
    
    }) | border;
  });
  screen.Loop(renderer);
}
