#include <QApplication>
#include <QLabel>

int main(int argc, char **argv)
{
  QApplication app(argc, argv);

  auto label = QLabel("I am Qt application");
  label.show();

  return app.exec();
}
