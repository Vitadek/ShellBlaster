//#include <ftxui/dom/elements.hpp>
//#include <ftxui/screen/screen.hpp>
//#include <ftxui/component/component.hpp>
#include <string>
  //client.server_capabilities.signatureHelpProvider = false
#include <functional>
#include <memory>
#include <string>
#include <iostream>
//#include <vector>
//
#include "ftxui/component/component_base.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "ftxui/component/component_options.hpp"
//#include "ftxui/component/renderer.hpp`"

using namespace ftxui;
int main() {
  std::vector<std::string> ssh_options = {
    "SSH Connection 1",
    "SSH Connection 2",
    "SSH Connection 3",
  };
  std::string ssh_placeholder_text = "Place Holder Text: ****SSH_Connection*****"
  auto screen = ScreenInteractive::TerminalOutput();
  int ssh_selected = 0;
  MenuOption select;
  select.on_enter = screen.ExitLoopClosure();
  Component ssh_menu = 
    Menu(&ssh_options, &ssh_selected, select);
//  auto menu = Container::Vertical(
//    {
//
//    },
//    &ssh_selected);
  Component ssh_connection_container = Container::Vertical({
    ssh_placeholder_text,
  });
  Component ssh_container = Container::Vertical({
    ssh_menu
  });
  Component container = Container::Horizontal({
    ssh_container,
    ssh_connection_container,
  });


  auto renderer = Renderer(ssh_container, [&]{
    return vbox({
      hbox(text("Selected ="), text(std::to_string(ssh_selected))),
      ssh_menu->Render() | frame | size(HEIGHT, LESS_THAN, 10),
    }) | border;
  });
  screen.Loop(renderer);
}
