#pragma once

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include "TextData.hpp"

#include <nodes/NodeDataModel>

#include <iostream>

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class TextDisplayDataModel : public NodeDataModel
{
  Q_OBJECT

public:
  TextDisplayDataModel();

  virtual ~TextDisplayDataModel() {}

public:

  QString
  caption() const override
  { return QString("Text Display"); }

  bool captionVisible() const { return false; }

  static QString
  name()
  { return QString("TextDisplayDataModel"); }


public:

  void
  save(Properties &p) const override
  {
    p.put("model_name", TextDisplayDataModel::name());
  }


public:

  unsigned int nPorts(PortType portType) const override;

  NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

  std::shared_ptr<NodeData>outData(PortIndex port) override;

  void setInData(std::shared_ptr<NodeData> data, int) override
  {
    auto textData = std::dynamic_pointer_cast<TextData>(data);

    if (textData)
    {
      _label->setText(textData->text());
    }
    else
    {
      _label->clear();
    }

    _label->adjustSize();
  }

  QWidget * embeddedWidget() override { return _label; }

private:

  QLabel * _label;
};
