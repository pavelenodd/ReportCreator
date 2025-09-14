#pragma once
#include "data.h"
#include <QJsonObject>
#include <QObject>
#include <QString>
#include <fstream>
#include <qcontainerfwd.h>
#include <string>

class ReaderSample : public QObject {
  Q_OBJECT
private:
  std::string text_;
  Data data_;
private slots:
  /**
   * @brief Construct the text from the file content
   *
   */
  void ConstructText() {}

  /**
   * @brief update the document and insert the key data
   *
   * @param key
   * @param value
   */
  void UpdateText(const std::string &key) {}
public slots:
  /**
   * @brief Open the file
   *
   * @param filePath
   */
  void ReadFile(const std::string &filePath) {
    std::ifstream file(filePath);
    if (file.is_open()) {
      std::string line;
      text_.clear();
      while (std::getline(file, line)) {
        text_ += line + "\n";
      }
      file.close();
    }
  }
  /**
   * @brief Save the file
   *
   * @param filePath
   */
  void SaveFile(const std::string &filePath) {
    std::ofstream file(filePath);
    if (file.is_open()) {
      file << text_;
      file.close();
    }
  }
  /**
   * @brief Get the Text to preview
   *
   * @return QString
   */
  QString GetText() { return QString::fromStdString(text_); }

  /**
   * @brief Set the value for the Data object
   *
   * @param key
   * @param value
   */
  void SetData(const QString &key, const QString &value) {
    data_.json[key] = value;
  }
};