#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QTextEdit>

#include <QtPrintSupport>

class TextEditor: public QTextEdit
{
    Q_OBJECT
private:
    QString m_filename;
public:
    explicit TextEditor(QWidget* parent = nullptr);
    explicit TextEditor(const QString &text, QWidget *parent = nullptr);
public slots:
    void save_as_pdf();
    void set_filename(const QString& str);
};


#endif // TEXTEDITOR_H
