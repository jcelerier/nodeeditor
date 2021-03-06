#include <nodes/NodeData>
#include <nodes/FlowScene>
#include <nodes/FlowView>

#include <QtWidgets/QApplication>

#include "ImageShowModel.hpp"
#include "ImageLoaderModel.hpp"

static bool
registerDataModels()
{
  DataModelRegistry::registerModel<ImageShowModel>();

  DataModelRegistry::registerModel<ImageLoaderModel>();

  return true;
}


static bool registerOK = registerDataModels();

int
main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  FlowScene scene;

  FlowView view(&scene);

  view.setWindowTitle("Node-based flow editor");
  view.resize(800, 600);
  view.show();

  return app.exec();
}
