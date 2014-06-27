#ifndef TOKENS_H
#define TOKENS_H

#include <QString>

#define QT_TRANSLATE_NOOP3(context,string,comment) (string)

const QString kTranslationOpenImageFileTitle = QT_TRANSLATE_NOOP3("interface","OPEN_IMAGE_FILE_TITLE","String from the open file dialog.");
const QString kTranslationNewImageFileTitle = QT_TRANSLATE_NOOP3("interface","NEW_IMAGE_FILE_TITLE","String from the new image file dialog.");
const QString kTranslationCursorOptionsTitle = QT_TRANSLATE_NOOP3("interface","CURSOR_OPTIONS_TITLE","String from the cursor options dialog.");

#endif // TOKENS_H
