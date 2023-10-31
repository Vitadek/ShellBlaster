#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/component/component.hpp>
#include <string>
#include <vector>
#include <functional>
#include <memory>
//#include <vector>

#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
//#include "ftxui/component/renderer.hpp`"

int main() {
//  std::vector<std::string> options = {
//    "Option 1",
//    "Option 2",
//    "Option 3",
//  };
  using namespace ftxui;
  auto screen = ScreenInteractive::TerminalOutput();
  int selected = 0;
  MenuOption option;

  option.on_enter = screen.ExitLoopClosure();
  auto menu = Container::Vertical(
    {
      MenuEntry("Option 1"),
      MenuEntry ("Option 2"),
      MenuEntry("Option 3"),
    },
    &selected);
  )
  auto renderer = Renderer(menu, [&]{
    return vbox({
      hbox(text("Selected ="),
           text(std::to_string(selected))),
        seperator(),
      menu->Render() | frame | size(HEGIHT, LESS_THAN, 10),
    })
  });
  screen.Loop(renderer);
}
