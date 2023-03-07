#include "TextEditor.h"

TextEditor::TextEditor(QWidget* parent)
    :
      QTextEdit(parent),
      m_filename("")
{

}

TextEditor::TextEditor(const QString &text, QWidget* parent)
    :
    QTextEdit(text, parent),
    m_filename("")
{}

void TextEditor::set_filename(const QString& str)
{
    m_filename = str + ".pdf";
}

void TextEditor::save_as_pdf()
{
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    if (m_filename == "")
        m_filename = "output.pdf";
    printer.setOutputFileName(m_filename);
    document()->print(&printer);
}
