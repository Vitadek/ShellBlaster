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
//  std::vector<std::string> options = {
//    "Option 1",
//    "Option 2",
//    "Option 3",
//  };
  auto screen = ScreenInteractive::TerminalOutput();
  int selected = 0;
  MenuOption option;
  option.on_enter = screen.ExitLoopClosure();
  auto menu = Container::Vertical(
    {
      Renderer([]{return separator();}),
      MenuEntry("Option 1"),
      MenuEntry ("Option 2"),
      MenuEntry("Option 3"),
      Renderer([]{return separator();}),
    },
    &selected);
  
  auto renderer = Renderer(menu, [&]{
    return vbox({
      hbox(text("Selected ="), text(std::to_string(selected))),
        separator(),
      menu->Render() | frame | size(HEIGHT, LESS_THAN, 10),
    }) | border;
  });
  screen.Loop(renderer);
}
