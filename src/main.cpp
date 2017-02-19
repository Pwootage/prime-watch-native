#include <iostream>
#include <string>

//Eigen is evil and is giving me deprecated warnings SO TAKE THAT NERD
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

#include <nanogui/nanogui.h>

#pragma GCC diagnostic pop

using namespace std;
using namespace nanogui;

int main() {

  nanogui::init();
  Screen *screen = new Screen(Eigen::Vector2i(720, 480), "PrimeWatch",
      /*resizable*/true, /*fullscreen*/false, /*colorBits*/8,
      /*alphaBits*/8, /*depthBits*/24, /*stencilBits*/8,
      /*nSamples*/0, /*glMajor*/3, /*glMinor*/3);

  screen->setLayout(new BoxLayout(Orientation::Horizontal, Alignment::Fill));

  auto leftPanel = new Widget(screen);
  leftPanel->setLayout(new BoxLayout(Orientation::Vertical));
  new Label(leftPanel, "GL goes here");

  auto rightScroll = new VScrollPanel(screen);
  auto rightPanel = new Widget(rightScroll);
  rightPanel->setLayout(new BoxLayout(Orientation::Vertical));
  rightPanel->setWidth(200);
  for (int i = 0; i < 500; i++) {
    auto b = new Button(rightPanel, "Test " + to_string(i));
    b->setCallback([&b]() {
        b->setVisible(false);
    });
  }

  screen->setVisible(true);
  screen->performLayout();

  nanogui::mainloop();
  nanogui::shutdown();

  cout << "Shutting down" << endl;
  return 0;
}