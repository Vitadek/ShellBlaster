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

  std::vector<std::string> menu_titles = {
    "SSH Connections",
    "SSH Configurations"
  };
  int selected_tab = 0;

  std::vector<std::string> ssh_connections = {
    "SSH placeholder 1",
    "SSH placeholder 2",
    "SSH Placeholder 3"
  };
  int selected_connection = 0;
  
  std::vector<std::string> menu_items = {
    "IP Address",
    "Password",
    "Public Key File",
  };
  int selected_menu_item = 0;

  //How could I add more ssh tab connections during runtime?
  std::string ssh_1, ssh_2, ssh_3;
  Component input_ssh_1 = Input(&ssh_1, "PlaceHolder Text for Tab 1");
  Component input_ssh_2 = Input(&ssh_2, "Placeholder Text for Tab 2");
  Component input_ssh_3 = Input(&ssh_3, "PlaceHolder Text for Tab 3");

  std::string ip, password, pub_key;
  Component ip_input = Input(&ip, "Placeholder IP");
  Component password_input = Input(&password, "Placeholder Password  - change to pass characters");
  Component pub_key_input = Input(&pub_key, "~/.ssh/id_something.pub");

  auto ssh_tabs = Container::Tab(
    {
      input_ssh_1,
      input_ssh_2,
      input_ssh_3,
    },
  &selected_connection);

  auto configuration_entries = Container::Tab(
    {
    ip_input,
    password_input,
    pub_key_input,
    },
  &selected_menu_item);


  auto ssh_toggle = Menu(&ssh_connections, &selected_connection);
  auto ssh_menu = Container::Horizontal({
    ssh_toggle,
    ssh_tabs,
  });
  
  auto configuration_menu = Menu(&menu_items,&selected_menu_item);
  auto ssh_configurations = Container::Horizontal({
    configuration_menu,
    configuration_entries,
  });

  auto menu_tabs = Container::Tab({
    ssh_menu,
    ssh_configurations,
  },
  &selected_tab);

  auto menu_toggle = Toggle(&menu_titles, &selected_tab);
  auto top_bar = Container::Horizontal({
    menu_toggle,
    menu_tabs
  });



  auto renderer = Renderer(menu_tabs, [&]{
    return vbox({
      menu_toggle->Render(),
      hbox({
          ssh_toggle->Render(),
          separator(),
          ssh_tabs->Render(),
        }),
      }) | border;
  });
  screen.Loop(renderer);
}
